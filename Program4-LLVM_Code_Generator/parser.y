%{
#include <iostream> // cerr, cout
#include "types.h"
using namespace clukcs;

/* Prototype for a function defined by flex. */
void yylex_destroy();

void yyerror(const char *msg)
{
	std::cerr << msg << '\n';
}

// The unique global symbol table.
symbol_table symtab;

// Tracks whether a return statement has been translated already
int return_statement = 0;


// Givens: Type to get string of
// Returns: String representation of type passed in
// Description: Returns a  string representation of a Type t
std::string get_type_string(Type t){
	switch(t){
		case Type::Int:
			return "i32";
			break;
		case Type::Char:
			return "i8";
			break;
		case Type::Float:
			return "float";
			break;
		default:
			return "i32";				// Incorrect Auto var; declarations use this
			break;
	}
} // get_type_string()


// Givens: Pointers to result and operand symbols, and type of operation being computed (op1 is for int/char, op2 is for floats)
// Returns: None. Symbols are passed in by reference so nothing needs to be returned
// Description: Does type checking for expression operations and sets code, addr, and type for result
void operation_type_checking(parser_val &E0, parser_val &E1, parser_val &E2, std::string op1, std::string op2){
	E0.code = E1.code + E2.code;

	// Types of E1 and E2
	Type E1_type;
	Type E2_type;

	// Names of E1 and E2 (might be temps if variable needs to be loaded first)
	std::string E1_name = E1.addr->name();
	std::string E2_name = E2.addr->name();
	
	// Obtaining E1 type and name
	if(dynamic_cast<Variable *>(E1.addr) != nullptr){
		E1_type = symtab.get(E1_name)->type;

		// Loading variable
		Address* temp = symtab.make_temp(E1_type);
		E1_name = temp->name();
		Variable* var = symtab.make_variable(E1.addr->name());
		E0.code += temp->name() + " = load " + get_type_string(E1_type) + ", " + get_type_string(E1_type) + " *" + var->location()->name() + "\n";
	}
	else
		E1_type = E1.type;

	// Obtaining E2 type and name
	if(dynamic_cast<Variable *>(E2.addr) != nullptr){
		E2_type = symtab.get(E2_name)->type;

		// Loading variable
		Address* temp = symtab.make_temp(E2_type);
		E2_name = temp->name();
		Variable* var = symtab.make_variable(E2.addr->name());
		E0.code += temp->name() + " = load " + get_type_string(E2_type) + ", " + get_type_string(E2_type) + " *" + var->location()->name() + "\n";
	}
	else
		E2_type = E2.type;

	// If operation is modulus, operands cannot be floats
	if( (op1 == "srem") && (E1_type == Type::Float || E2_type == Type::Float)){
		// If an operand is a float, assume answer is 0
		std::cerr << "ERROR: % (Modulus) operation does not work on floats. Assuming answer is 0." << std::endl;
		E0.type = Type::Int;
		E0.addr = symtab.make_temp(Type::Int);
		E0.code += E0.addr->name() + " = " + op1 + " " + get_type_string(E0.type) + " " + E1_name + ", " + E2_name + "\n";
		return;
	}

	// If both operands are the same type
	if(E1_type == E2_type){
		E0.type = E1_type;
		E0.addr = symtab.make_temp(E1_type);
		
		if(E0.type == Type::Float)
			E0.code += E0.addr->name() + " = " + op2 + " " + get_type_string(E0.type) + " " + E1_name + ", " + E2_name + "\n";
		else
			E0.code += E0.addr->name() + " = " + op1 + " " + get_type_string(E0.type) + " " + E1_name + ", " + E2_name + "\n";
	}
	// If operands have different types
	else{
		// If E1 is a float, must convert E2 to float
		if(E1_type == Type::Float){
			if(E2_type == Type::Int){
				// Converting E2 from int to float
				Address* temp = symtab.make_temp(E1_type);
				E0.code += temp->name() + " = sitofp i32 " + E2_name + " to float\n";
				E2_name = temp->name();
				E2_type = temp->type();
				
				E0.type = E1_type;
				E0.addr = symtab.make_temp(E1_type);
				E0.code += E0.addr->name() + " = " + op2 + " " + get_type_string(E0.type) + " " + E1_name + ", " + E2_name + "\n";
			}
			if(E2_type == Type::Char){
				// Converting E2 from char to float
				Address* temp = symtab.make_temp(E1_type);
				E0.code += temp->name() + " = sitofp i8 " + E2_name + " to float\n";
				E2_name = temp->name();
				E2_type = temp->type();
				
				E0.type = E1_type;
				E0.addr = symtab.make_temp(E1_type);
				E0.code += E0.addr->name() + " = " + op2 + " " + get_type_string(E0.type) + " " + E1_name + ", " + E2_name + "\n";
			}
		}
		// If E2 is a float, must convert E1 to float
		else if(E2_type == Type::Float){
			if(E1_type == Type::Int){
				// Converting E1 from int to float
				Address* temp = symtab.make_temp(E2_type);
				E0.code += temp->name() + " = sitofp i32 " + E1_name + " to float\n";
				E1_name = temp->name();
				E1_type = temp->type();
				
				E0.type = E2_type;
				E0.addr = symtab.make_temp(E2_type);
				E0.code += E0.addr->name() + " = " + op2 + " " + get_type_string(E0.type) + " " + E1_name + ", " + E2_name + "\n";
			}
			if(E1_type == Type::Char){
				// Converting E1 from char to float
				Address* temp = symtab.make_temp(E2_type);
				E0.code += temp->name() + " = sitofp i8 " + E1_name + " to float\n";
				E1_name = temp->name();
				E1_type = temp->type();
				
				E0.type = E2_type;
				E0.addr = symtab.make_temp(E2_type);
				E0.code += E0.addr->name() + " = " + op2 + " " + get_type_string(E0.type) + " " + E1_name + ", " + E2_name + "\n";
			}
		}
		// If E1 is an int, must convert E2 to int
		else if(E1_type == Type::Int){
			// Converting E2 from char to int
				Address* temp = symtab.make_temp(E1_type);
				E0.code += temp->name() + " = sext i8 " + E2_name + " to i32\n";
				E2_name = temp->name();
				E2_type = temp->type();
				
				E0.type = E1_type;
				E0.addr = symtab.make_temp(E1_type);
				E0.code += E0.addr->name() + " = " + op1 + " " + get_type_string(E0.type) + " " + E1_name + ", " + E2_name + "\n";
		}
		// If E2 is an int, must convert E1 to int		
		else if(E2_type == Type::Int){
			// Converting E1 from char to int
				Address* temp = symtab.make_temp(E2_type);
				E0.code += temp->name() + " = sext i8 " + E1_name + " to i32\n";
				E1_name = temp->name();
				E1_type = temp->type();
				
				E0.type = E2_type;
				E0.addr = symtab.make_temp(E2_type);
				E0.code += E0.addr->name() + " = " + op1 + " " + get_type_string(E0.type) + " " + E1_name + ", " + E2_name + "\n";
		}	
	}
} // operation_type_checking()


// Givens: Output code to convert
// Returns: Converted output code
// Description: Modifies the body of the main to be tabbed (2 spaces)
std::string output_conversion(std::string output){
	std::vector<std::string> split_output;
	std::string output_copy = output;
	std::string final_output = "";
	
	// Splitting the output by lines
	while(output_copy.size() > 0){
		split_output.push_back(output_copy.substr(0, output_copy.find("\n")));
		output_copy = output_copy.substr(output_copy.find("\n")+1);
	}

	// Adding the tabbing
	for(unsigned long i = 0; i < split_output.size(); i++){
		final_output += "  " + split_output[i] + "\n";
	}

	return final_output;
} // output_conversion


%}

/* Put this into the generated header file, too */
%code requires {
  #include "types.h"
  #include "globals.h"
}

/* Semantic value for grammar symbols.  See definition in types.h */
%define api.value.type {clukcs::parser_val}

%token IDENTIFIER INT_LITERAL FLOAT_LITERAL CHAR_LITERAL
%token '+' '-' '*' '/' '%' '=' '(' ')' '{' '}' ';' INT FLOAT CHAR AUTO RETURN


/* Which nonterminal is at the top of the parse tree? */
%start program

/* Precedence */
%right '='
%left '+' '-'
%left '*' '/' '%'
%left UMINUS

%%

program: statement_list {
	// Header text for llvm file
	std::string header1 = "target datalayout = \"e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128\"\n" ;
	std::string header2 = "target triple = \"x86_64-pc-linux-gnu\"\n\n";
	std::string header3 = "define dso_local i32 @main() {\n";
	// Might need to add return statement at the end
	std::string return_text = "  ret i32 0\n";

	std::string converted_code = output_conversion($1.code);

	// Printing llvm code to stdout
	if(return_statement == 1)
		std::cout << header1 << header2 << header3 << converted_code << "}" << "\n";
	else
		std::cout << header1 << header2 << header3 << converted_code << return_text << "}" << "\n";
};

statement_list: statement_list statement {
	$$.code = $1.code + $2.code;
} | %empty {
	$$.code = "";
};

statement: expression ';' {
	$$.code = $1.code;
} | '{' { symtab.push(); }  statement_list '}' {
	$$.code = $3.code;
	symtab.pop();

} | type IDENTIFIER '=' expression ';' {
	$$.code = $4.code;
	
	// If type conversion is needed, will need to store temp name for code output
	std::string RHS_name = $4.addr->name();
	// Tracking RHS type
	Type RHS_type;
	// Tracking LHS type
	Type LHS_type;
	
	// Obtaining RHS type
	if(dynamic_cast<Variable *>($4.addr) != nullptr){	// If RHS is a variable
		RHS_type = symtab.get(RHS_name)->type;

		// Loading variable
		Address* temp = symtab.make_temp($4.type);
		RHS_name = temp->name();
		Variable* var = symtab.make_variable($4.addr->name());
		$$.code += temp->name() + " = load " + get_type_string(RHS_type) + ", " + get_type_string(RHS_type) + " *" + var->location()->name() + "\n";
	}
	else
		RHS_type = $4.type;

	// Obtaining LHS type
	if($1.type == Type::Auto)		// Variable being declared with auto as type
		LHS_type = RHS_type;
	else
		LHS_type = $1.type;


	// Type conversion if they are not the same
	if(LHS_type != RHS_type){
		// Conversion needed
		std::string conversion_op = "";

		switch(LHS_type){
			case Type::Int:
				if(RHS_type == Type::Float)
					conversion_op = "fptosi float";
				else if(RHS_type == Type::Char)
					conversion_op = "sext i8";
				break;		
			case Type::Float:
				if(RHS_type == Type::Int)
					conversion_op = "sitofp i32";
				else if(RHS_type == Type::Char)
					conversion_op = "sitofp i8";
				break;
			case Type::Char:
				if(RHS_type == Type::Int)
					conversion_op = "trunc i32";
				else if(RHS_type == Type::Float)
					conversion_op = "fptosi float";				
				break;
			default:
				break;
		}

		// Type converting the expression
		Address* temp = symtab.make_temp(LHS_type);
		$$.code += temp->name() + " = " + conversion_op + " " + RHS_name + " to " + get_type_string(LHS_type) + "\n";
		RHS_name = temp->name();
		RHS_type = temp->type();
	}

	// Adding new variable to symbol table
	symtab.put($2.code, LHS_type);

	// Allocating space for variable
	Variable* var2 = symtab.make_variable($2.code);	
	$$.code += var2->location()->name() + " = alloca " + get_type_string(LHS_type) + "\n";

	// Storing value
	$$.code += "store " + get_type_string(RHS_type) + " " + RHS_name + ", " + get_type_string(LHS_type) + "* " + var2->location()->name() + "\n";

} | type IDENTIFIER ';' {
	$$.code = "";
	std::string var_type = get_type_string($1.type);

	// If auto is incorrectly being used here, throw error and assume it's an int
	if($1.type == Type::Auto){
		std::cerr << "ERROR: Semantic error from auto " + $2.code + " being declared without assignment. Assuming it is an int." << std::endl;		
		symtab.put($2.code, Type::Int);
	}
	else{
		symtab.put($2.code, $1.type);
	}

	// Allocating space for variable
	Variable* var = symtab.make_variable($2.code);	
	$$.code += var->location()->name() + " = alloca " + var_type + "\n";

} | RETURN expression ';' {
	$$.code = $2.code;

	// Tracking type of returning value
	Type return_type;
	// Tracking name of returning value or variable
	std::string return_name = $2.addr->name();
	
	// Marking that a return statement is present
	return_statement = 1;
	
	// If returning a variable
	if(dynamic_cast<Variable *>($2.addr) != nullptr){
		return_type = symtab.get(return_name)->type;

		// Loading variable
		Address* temp = symtab.make_temp($2.type);
		return_name = temp->name();
		Variable* var = symtab.make_variable($2.addr->name());
		$$.code += temp->name() + " = load " + get_type_string(return_type) + ", " + get_type_string(return_type) + " *" + var->location()->name() + "\n";
	}
	else
		return_type = $2.type;

	// Type converting return statement if needed
	if(return_type != Type::Int){
		if(return_type == Type::Float){
			// Converting value from float to int
			Address* temp = symtab.make_temp(Type::Int);
			$$.code += temp->name() + " = fptosi float " + return_name + " to i32\n";
			return_name = temp->name();
			return_type = temp->type();
		}
		else if(return_type == Type::Char){
			// Converting value from char to int
			Address* temp = symtab.make_temp(Type::Int);
			$$.code += temp->name() + " = sext i8 " + return_name + " to i32\n";
			return_name = temp->name();
			return_type = temp->type();
		}
	}

	// Adding return statement
	$$.code += "ret " + get_type_string(return_type) + " " + return_name + "\n";
	

} | error ';' { // error is a special token defined by bison
	yyerrok;
};

type: INT {
	$$.type = Type::Int;
} | FLOAT {
	$$.type = Type::Float;
} | CHAR {
	$$.type = Type::Char;
} | AUTO {
	$$.type = Type::Auto;
};

// The +, -, *, /, and % operations are all handled by operation_type_checking()
expression: expression '+' expression {	
	operation_type_checking($$, $1, $3, "add", "fadd");
} | expression '-' expression {
	operation_type_checking($$, $1, $3, "sub", "fsub");
} | expression '*' expression {
	operation_type_checking($$, $1, $3, "mul", "fmul");
} | expression '/' expression {
	operation_type_checking($$, $1, $3, "sdiv", "fdiv");
} | expression '%' expression {
	operation_type_checking($$, $1, $3, "srem", "");
} | expression '=' expression {
	// If LHS is not a variable
	if((symtab.get($1.addr->name()) == nullptr)){
		std::cerr << "ERROR: LHS of assignment " + $1.addr->name() + " = " + $3.addr->name() + " is not a variable." << std::endl;
	}

	$$.code = $1.code + $3.code;

	// Types of E1 and E2
	Type E1_type;
	Type E2_type;

	// Names of E1 and E2
	std::string E1_name = $1.addr->name();
	std::string E2_name = $3.addr->name();
	
	// Obtaining E1 type and name
	if(dynamic_cast<Variable *>($1.addr) != nullptr){			// If RHS is a variable
		E1_type = symtab.get(E1_name)->type;
		Variable* var = symtab.make_variable($1.addr->name());
		E1_name = var->location()->name();
	}
	else
		E1_type = $1.type;

	// Obtaining E2 type and name
	if(dynamic_cast<Variable *>($3.addr) != nullptr){
		E2_type = symtab.get(E2_name)->type;

		// Loading variable
		Address* temp = symtab.make_temp(E2_type);
		E2_name = temp->name();
		Variable* var = symtab.make_variable($3.addr->name());
		$$.code += temp->name() + " = load " + get_type_string(E2_type) + ", " + get_type_string(E2_type) + " *" + var->location()->name() + "\n";
	}
	else
		E2_type = $3.type;

	// Result is same type as LHS
	$$.type = E1_type;
	$$.addr = $1.addr;

	// If types are different, must perform type conversion
	if(E1_type != E2_type){
		// Conversion needed
		std::string conversion_op = "";

		switch(E1_type){
			case Type::Int:
				if(E2_type == Type::Float)
					conversion_op = "fptosi float";
				if(E2_type == Type::Char)
					conversion_op = "sext char";
				break;
			case Type::Float:
				if(E2_type == Type::Int)
					conversion_op = "sitofp i32";
				if(E2_type == Type::Char)
					conversion_op = "sitofp i8";
				break;
			case Type::Char:
				if(E2_type == Type::Float)
					conversion_op = "fptosi float";
				if(E2_type == Type::Int)
					conversion_op = "trunc char";
				break;
			default:
				break;
		}

		// Type converting the expression
		Address* temp = symtab.make_temp(E1_type);
		$$.code += temp->name() + " = " + conversion_op + " " + E2_name + " to " + get_type_string(E1_type) + "\n";
		E2_name = temp->name();
	}

	// Storing in variable
	$$.code += "store " + get_type_string(E1_type) + " " + E2_name + ", " + get_type_string(E1_type) + "* " + E1_name + "\n";
	

} | '-' expression %prec UMINUS {
	$$.code = "";
	std::string exp_type = get_type_string($2.type);

	// If negated expression is a variable, must load first
	if(dynamic_cast<Variable *>($2.addr) != nullptr){
		$$.type = symtab.get($2.addr->name())->type;

		// Load variable
		Address* temp = symtab.make_temp($2.type);
		Variable* var = symtab.make_variable($2.addr->name());
		$$.code += temp->name() + " = load " + exp_type + ", " + exp_type + " *" + var->location()->name() + "\n";
		
		// Initializing and setting new temp
		$$.addr = symtab.make_temp($2.type);
		if($2.type == Type::Float)
			$$.code += $$.addr->name() + " = fneg float " + temp->name() + "\n";
		else
			$$.code += $$.addr->name() + " = sub " + exp_type + " 0, " + temp->name() + "\n";
	}
	// Else it is a constant
	else{
		$$.type = $2.type;
		
		// Initializing and setting new temp
		$$.addr = symtab.make_temp($2.type);
		if($2.type == Type::Float)
			$$.code += $$.addr->name() + " = fneg float " + $2.addr->name() + "\n";
		else
			$$.code += $$.addr->name() + " = sub " + exp_type + " 0, " + $2.addr->name() + "\n";
	}

} | '(' expression ')' {
	$$.code = $2.code;
	$$.addr = $2.addr;
	$$.type = $2.type;

} | INT_LITERAL {
	$$.code = "";
	// Converting input to an int
	int val = std::stoi($1.code);
	$$.addr = symtab.make_int_const(val);
	$$.type = Type::Int;

} | FLOAT_LITERAL {
	$$.code = "";
	// Converting input to a float
	float val = std::stof($1.code);
	$$.addr = symtab.make_float_const(val);
	$$.type = Type::Float;

} | CHAR_LITERAL {
	$$.code = "";
	
	// Removing single quotes
	std::string val = $1.code.substr(1, $1.code.size()-2);
	
	// Doing some string editing to get correct value for symbol
	char char_val;
	if(val == "\\n"){
		char_val = '\n';
	}
	else if(val == "\\\\"){
		char_val = '\\';
	}
	else if(val == "\\'"){
		char_val = '\'';
	}
	else
		char_val = val[0];

	$$.addr = symtab.make_char_const(char_val);
	$$.type = Type::Char;

} | IDENTIFIER {
	$$.code = "";
	
	// If ID does not exist, make a new symtab entry and variable for it
	if(symtab.get($1.code) == nullptr){
		std::cerr << "ERROR: Variable " << $1.code << " does not exist in this scope. It will now be declared as an int." << std::endl;
		symtab.put($1.code, Type::Int);
		Variable* var = symtab.make_variable($1.code);	
		
		$$.code += var->location()->name() + " = alloca i32\n";
		$$.addr = var;
	}
	else{
		$$.addr = symtab.make_variable($1.code);	
	}
	
	$$.type = $1.type;
};


%%

int main()
{
	int result = yyparse();
	yylex_destroy();
	return result;
}
