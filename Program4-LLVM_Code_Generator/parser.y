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

// Givens: Pointers to result and operand symbols, and type of operation being computed
// Returns: None. Symbols are passed in by reference so nothing needs to be returned
// Description: Does type checking for expression operations and sets code, addr, and type for result
void operation_type_checking(parser_val &E0, parser_val &E1, parser_val &E2, std::string op){
	E0.code = E1.code + E2.code;
	
	// Types of LHS and RHS
	Type E1_type;
	Type E2_type;

	// Obtaining E1 operand type
	if(symtab.get(E1.addr->name()) == nullptr)			// If LHS is a literal
		E1_type = E1.type;
	else
		E1_type = symtab.get(E1.addr->name())->type;	
	// Obtaining E2 operand type
	if(symtab.get(E2.addr->name()) == nullptr)			// If RHS is a literal
		E2_type = E2.type;
	else
		E2_type = symtab.get(E2.addr->name())->type;	

	// If both operands are the same type
	if(E1_type == E2_type){
		E0.type = E1_type;
		E0.addr = symtab.make_temp(E1_type);
		E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + E2.addr->name() + "\n";
	}
	// If operands have different types
	else{
		// If E1 is a float, must convert E2 to float
		if(E1_type == Type::Float){
			if(E2_type == Type::Int){
				// Converting E2 from int to float
				Address* temp = symtab.make_temp(E1_type);
				E0.code += temp->name() + " = int2float " + E2.addr->name() + "\n";
				E0.type = E1_type;
				E0.addr = symtab.make_temp(E1_type);
				E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + temp->name() + "\n";
			}
			if(E2_type == Type::Char){
				// Converting E2 from char to int
				Address* temp = symtab.make_temp(Type::Int);
				E0.code += temp->name() + " = char2int " + E2.addr->name() + "\n";
				
				// Converting from int to float
				Address* temp2 = symtab.make_temp(E1_type);
				E0.code += temp2->name() + " = int2float " + temp->name() + "\n";
				E0.type = E1_type;
				E0.addr = symtab.make_temp(E1_type);
				E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + temp2->name() + "\n";
			}
		}
		// If E2 is a float, must convert E1 to float
		else if(E2_type == Type::Float){
			if(E1_type == Type::Int){
				// Converting E1 from int to float
				Address* temp = symtab.make_temp(E2_type);
				E0.code += temp->name() + " = int2float " + E1.addr->name() + "\n";
				E0.type = E2_type;
				E0.addr = symtab.make_temp(E2_type);
				E0.code += E0.addr->name() + " = " + temp->name() + " " + op + " " + E2.addr->name() + "\n";
			}
			if(E1_type == Type::Char){
				// Converting E1 from char to int
				Address* temp = symtab.make_temp(Type::Int);
				E0.code += temp->name() + " = char2int " + E1.addr->name() + "\n";
				
				// Converting from int to float
				Address* temp2 = symtab.make_temp(E2_type);
				E0.code += temp2->name() + " = int2float " + temp->name() + "\n";
				E0.type = E2_type;
				E0.addr = symtab.make_temp(E2_type);
				E0.code += E0.addr->name() + " = " + temp->name() + " " + op + " " + E2.addr->name() + "\n";
			}
		}
		// If E1 is an int, must convert E2 to int
		else if(E1_type == Type::Int){
			// Converting E2 from char to int
			Address* temp = symtab.make_temp(E1_type);
			E0.code += temp->name() + " = char2int " + E2.addr->name() + "\n";
			E0.type = E1_type;
			E0.addr = symtab.make_temp(E1_type);
			E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + temp->name() + "\n";
		}
		// If E2 is an int, must convert E1 to int		
		else if(E2_type == Type::Int){
			// Converting E1 from char to int
			Address* temp = symtab.make_temp(E2_type);
			E0.code += temp->name() + " = char2int " + E1.addr->name() + "\n";
			E0.type = E2_type;
			E0.addr = symtab.make_temp(E2_type);
			E0.code += E0.addr->name() + " = " + temp->name() + " " + op + " " + E2.addr->name() + "\n";
		}	
	}
} // operation_type_checking()


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
	std::string header1 = "target datalayout = \"e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128\"\n" ;
	std::string header2 = + "target triple = \"x86_64-pc-linux-gnu\"\n\n";
	std::string header3 = + "define dso_local i32 @main() {\n";

	std::string converted_code = output_conversion($1.code);
	
	std::cout << "Code:\n" << header1 << header2 << header3 << converted_code << "}" << "\n";
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
	
	// Obtaining RHS
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
		switch(LHS_type){
			case Type::Int:
				if(RHS_type == Type::Float){
					// Converting RHS from float to int
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = fptosi float " + RHS_name + " to i64\n";
					RHS_name = temp->name();
					RHS_type = temp->type();
				}
				else if(RHS_type == Type::Char){
					// Converting RHS from char to int
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = sext i8 " + RHS_name + " to i64\n";
					RHS_name = temp->name();
					RHS_type = temp->type();
				}
				break;		
			case Type::Float:
				if(RHS_type == Type::Int){
					// Converting RHS from int to float
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = sitofp i64 " + RHS_name + " to float\n";
					RHS_name = temp->name();
					RHS_type = temp->type();
				}
				else if(RHS_type == Type::Char){
					// Converting RHS from char to float
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = sitofp i8 " + RHS_name + " to float\n";
					RHS_name = temp->name();
					RHS_type = temp->type();
				}
				break;
			case Type::Char:
				if(RHS_type == Type::Int){
					// Converting RHS from int to char
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = trunc i64 " + RHS_name + " to i8\n";
					RHS_name = temp->name();
					RHS_type = temp->type();
				}
				else if(RHS_type == Type::Float){
					// Converting RHS from float to char
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = fptosi float " + RHS_name + " to i8\n";
					RHS_name = temp->name();
					RHS_type = temp->type();
				}
				break;
			default:
				break;
		}
	}

	// Adding new variable to symbol table
	symtab.put($2.code, LHS_type);

	// Allocating space for variable
	Variable* var2 = symtab.make_variable($2.code);	
	$$.code += var2->location()->name() + " = alloca " + get_type_string(LHS_type) + "\n";

	//Storing value
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

// The +, -, *, and / operations are all handled by operation_type_checking()
expression: expression '+' expression {			
} | expression '-' expression {
} | expression '*' expression {
} | expression '/' expression {
} | expression '%' expression {
} | expression '=' expression {
} | '-' expression %prec UMINUS {
	$$.code = "";
	std::string exp_type = get_type_string($2.type);

	// If negated expression is a variable, must load first
	if(dynamic_cast<Variable *>($2.addr) != nullptr){
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
		// Initializing and setting new temp
		$$.addr = symtab.make_temp($2.type);
		if($2.type == Type::Float)
			$$.code += $$.addr->name() + " = fneg float " + $2.addr->name() + "\n";
		else
			$$.code += $$.addr->name() + " = sub " + exp_type + " 0, " + $2.addr->name() + "\n";
	}

	$$.type = $2.type;

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
