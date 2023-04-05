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

// Does type checking for expression operations and sets code, addr, and type
void operation_type_checking(parser_val &E0, parser_val &E1, parser_val &E2, std::string op){
	E0.code = E1.code + E2.code;
	
	// Types of LHS and RHS
	Type E1_type;
	Type E2_type;

	// If LHS is a literal
	if(symtab.get(E1.addr->name()) == nullptr){
		E1_type = E1.type;
	}
	else{
		E1_type = symtab.get(E1.addr->name())->type;	
	}
	
	// If RHS is a literal
	if(symtab.get(E2.addr->name()) == nullptr){
		E2_type = E2.type;
	}
	else{
		E2_type = symtab.get(E2.addr->name())->type;	
	}


	if(E1_type == E2_type){
		E0.type = E1_type;
		E0.addr = symtab.make_temp(E1_type);
		E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + E2.addr->name() + "\n";
	}
	else{
		if(E1_type == Type::Float){
			if(E2_type == Type::Int){
				Address* temp = symtab.make_temp(E1_type);
				E0.code += temp->name() + " = int2float " + E2.addr->name() + "\n";
				
				E0.type = E1_type;
				E0.addr = symtab.make_temp(E1_type);

				E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + temp->name() + "\n";
			}
			if(E2_type == Type::Char){
				Address* temp = symtab.make_temp(Type::Int);
				E0.code += temp->name() + " = char2int " + E2.addr->name() + "\n";
					
				Address* temp2 = symtab.make_temp(E1_type);
				E0.code += temp2->name() + " = int2float " + temp->name() + "\n";

				E0.type = E1_type;
				E0.addr = symtab.make_temp(E1_type);

				E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + temp2->name() + "\n";
			}
		}
		else if(E2_type == Type::Float){
			if(E1_type == Type::Int){
				Address* temp = symtab.make_temp(E2_type);
				E0.code += temp->name() + " = int2float " + E1.addr->name() + "\n";

				E0.type = E2_type;
				E0.addr = symtab.make_temp(E2_type);

				E0.code += E0.addr->name() + " = " + temp->name() + " " + op + " " + E2.addr->name() + "\n";
			}
			if(E1_type == Type::Char){
				Address* temp = symtab.make_temp(Type::Int);
				E0.code += temp->name() + " = char2int " + E1.addr->name() + "\n";
					
				Address* temp2 = symtab.make_temp(E2_type);
				E0.code += temp2->name() + " = int2float " + temp->name() + "\n";

				E0.type = E2_type;
				E0.addr = symtab.make_temp(E2_type);

				E0.code += E0.addr->name() + " = " + temp->name() + " " + op + " " + E2.addr->name() + "\n";
			}
		}
		else if(E1_type == Type::Int){
			Address* temp = symtab.make_temp(E1_type);
			E0.code += temp->name() + " = char2int " + E2.addr->name() + "\n";
			
			E0.type = E1_type;
			E0.addr = symtab.make_temp(E1_type);

			E0.code += E0.addr->name() + " = " + E1.addr->name() + " " + op + " " + temp->name() + "\n";
		}		
		else if(E2_type == Type::Int){
			Address* temp = symtab.make_temp(E2_type);
			E0.code += temp->name() + " = char2int " + E1.addr->name() + "\n";
			
			E0.type = E2_type;
			E0.addr = symtab.make_temp(E2_type);

			E0.code += E0.addr->name() + " = " + temp->name() + " " + op + " " + E2.addr->name() + "\n";
		}	
	}
}


%}

/* Put this into the generated header file, too */
%code requires {
  #include "types.h"
  #include "globals.h"
}

/* Semantic value for grammar symbols.  See definition in types.h */
%define api.value.type {clukcs::parser_val}

%token IDENTIFIER INT_LITERAL FLOAT_LITERAL CHAR_LITERAL
%token '+' '-' '*' '/' '%' '=' '(' ')' '{' '}' ';' INT FLOAT CHAR AUTO


/* Which nonterminal is at the top of the parse tree? */
%start program

/* Precedence */
%right '='
%left '+' '-'
%left '*' '/' '%'
%left UMINUS

%%

program: statement_list {
	std::cout << "Code:\n" << $1.code << "\n";
};

statement_list: statement_list statement {
	$$.code = $1.code + $2.code;
} | %empty {
	$$.code = "";
};

statement: expression ';' {
	$$.code = $1.code;

} | '{' { symtab.push(); }  statement_list '}' {
	symtab.pop();

} | type IDENTIFIER '=' expression ';' {
	$$.code = $4.code;

	// If type conversion is needed, store temp name for code output
	std::string RHS_label = "";
	Type LHS_type;
	Type RHS_type;
	
	// If RHS is a literal
	if(symtab.get($4.addr->name()) == nullptr){
		RHS_type = $4.type;
	}
	else{
		RHS_type = symtab.get($4.addr->name())->type;	
	}

	// Variable being declared with auto as type
	if($1.type == Type::Auto){
		LHS_type = RHS_type;
	}
	else{
		LHS_type = $1.type;
	}

	// Type checking
	if(LHS_type != RHS_type){
		switch(LHS_type){
			case Type::Int:
				if(RHS_type == Type::Float){
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = float2int " + $4.addr->name() + "\n";
					RHS_label = temp->name();
				}
				else if(RHS_type == Type::Char){
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = char2int " + $4.addr->name() + "\n";
					RHS_label = temp->name();
				}
				break;		
			case Type::Float:
				if(RHS_type == Type::Int){
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = int2float " + $4.addr->name() + "\n";
					RHS_label = temp->name();
				}
				else if(RHS_type == Type::Char){
					Address* temp = symtab.make_temp(Type::Int);
					$$.code += temp->name() + " = char2int " + $4.addr->name() + "\n";
					
					Address* temp2 = symtab.make_temp(LHS_type);
					$$.code += temp2->name() + " = int2float " + temp->name() + "\n";
					RHS_label = temp->name();
				}
				break;
			case Type::Char:
				if(RHS_type == Type::Int){
					Address* temp = symtab.make_temp(LHS_type);
					$$.code += temp->name() + " = int2char " + $4.addr->name() + "\n";
					RHS_label = temp->name();
				}
				else if(RHS_type == Type::Float){
					Address* temp = symtab.make_temp(Type::Int);
					$$.code += temp->name() + " = float2int " + $4.addr->name() + "\n";
					
					Address* temp2 = symtab.make_temp(LHS_type);
					$$.code += temp2->name() + " = int2char " + temp->name() + "\n";
					RHS_label = temp->name();
				}
				break;
			default:
				break;
		}
	}
	
	if(RHS_label == ""){
		Address* temp3 = symtab.make_temp($1.type);
		// t0 = num
		$$.code += temp3->name() + " = " + $4.addr->name() + "\n";
		// id = t0
		$$.code += $2.code + " = " + temp3->name() + "\n";
	}
	else{
		$$.code += $2.code + " = " + RHS_label + "\n";
	}
	
	symtab.put($2.code, LHS_type);

} | type IDENTIFIER ';' {
	$$.code = "";
	symtab.put($2.code, $1.type);

	if($1.type == Type::Auto){
		std::cerr << "" << std::endl;
	}

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

expression: expression '+' expression {
	operation_type_checking($$, $1, $3, "+");
} | expression '-' expression {
	operation_type_checking($$, $1, $3, "-");
} | expression '*' expression {
	operation_type_checking($$, $1, $3, "*");
} | expression '/' expression {
	operation_type_checking($$, $1, $3, "/");
} | expression '%' expression {
	$$.code = $1.code + $3.code;

	// Getting types of LHS and RHS
	Type E1_type = symtab.get($1.addr->name())->type;
	Type E2_type = symtab.get($3.addr->name())->type;

	if(E1_type == Type::Float || E2_type == Type::Float){
		std::cerr << "" << std::endl;
	}

	if(E1_type == E2_type){
		$$.type = E1_type;
		$$.addr = symtab.make_temp(E1_type);
		$$.code += $$.addr->name() + " = " + $1.addr->name() + " " + '%' + " " + $3.addr->name() + "\n";

	}
	else{
		if(E1_type == Type::Int){
			Address* temp = symtab.make_temp(E1_type);
			$$.code += temp->name() + " = char2int " + $3.addr->name() + "\n";
			
			$$.type = E1_type;
			$$.addr = symtab.make_temp(E1_type);

			$$.code += $$.addr->name() + " = " + $1.addr->name() + " " + '%' + " " + temp->name() + "\n";
		}		
		else if(E2_type == Type::Int){
			Address* temp = symtab.make_temp(E2_type);
			$$.code += temp->name() + " = char2int " + $1.addr->name() + "\n";
			
			$$.type = E2_type;
			$$.addr = symtab.make_temp(E2_type);

			$$.code += $$.addr->name() + " = " + temp->name() + " " + '%' + " " + $3.addr->name() + "\n";
		}
	}

} | expression '=' expression {

	// If LHS is not a variable
	if((symtab.get($1.addr->name()) != nullptr)){
		std::cerr << "" << std::endl;
	}
	
	// Getting types of LHS and RHS
	Type E1_type;
	Type E2_type;

	// If E1 is a literal
	if(symtab.get($1.addr->name()) == nullptr){
		E1_type = $1.type;
	}
	else{
		E1_type = symtab.get($1.addr->name())->type;	
	}
	
	// If E2 is a literal
	if(symtab.get($3.addr->name()) == nullptr){
		E2_type = $3.type;
	}
	else{
		E2_type = symtab.get($3.addr->name())->type;	
	}
	
	// Type is same as LHS
	$$.type = E1_type;
	$$.addr = $1.addr;
	$$.code = $1.code + $3.code;
	
	if(E1_type == E2_type){
		Address* temp = symtab.make_temp(E1_type);
		$$.code += temp->name() + " = " + $3.addr->name() + "\n";
		$$.code += $1.addr->name() + " = " + temp->name() + "\n";
	}
	// If RHS is a different type, do type conversion
	else{
		switch(E1_type){
			case Type::Int:
				if(E2_type == Type::Float){
					Address* temp = symtab.make_temp(E1_type);
					$$.code += temp->name() + " = float2int " + $3.addr->name() + "\n";
					$$.code += $1.addr->name() + " = " + temp->name() + "\n";
				}
				else if(E2_type == Type::Char){
					Address* temp = symtab.make_temp(E1_type);
					$$.code += temp->name() + " = char2int " + $3.addr->name() + "\n";
					$$.code += $1.addr->name() + " = " + temp->name() + "\n";
				}
				break;		
			case Type::Float:
				if(E2_type == Type::Int){
					Address* temp = symtab.make_temp(E1_type);
					$$.code += temp->name() + " = int2float " + $3.addr->name() + "\n";
					$$.code += $1.addr->name() + " = " + temp->name() + "\n";
				}
				else if(E2_type == Type::Char){
					Address* temp = symtab.make_temp(Type::Int);
					$$.code += temp->name() + " = char2int " + $3.addr->name() + "\n";
					
					Address* temp2 = symtab.make_temp(E1_type);
					$$.code += temp2->name() + " = int2float " + temp->name() + "\n";
					$$.code += $1.addr->name() + " = " + temp2->name() + "\n";
				}
				break;
			case Type::Char:
				if(E2_type == Type::Int){
					Address* temp = symtab.make_temp(E1_type);
					$$.code += temp->name() + " = int2char " + $3.addr->name() + "\n";
					$$.code += $1.addr->name() + " = " + temp->name() + "\n";
				}
				else if(E2_type == Type::Float){
					Address* temp = symtab.make_temp(Type::Int);
					$$.code += temp->name() + " = float2int " + $3.addr->name() + "\n";
					
					Address* temp2 = symtab.make_temp(E1_type);
					$$.code += temp2->name() + " = int2char " + temp->name() + "\n";
					$$.code += $1.addr->name() + " = " + temp2->name() + "\n";
				}
				break;
			default:
				break;
		}
	}

} | '-' expression %prec UMINUS {
	$$.addr = symtab.make_temp($2.type);
	$$.code = $$.addr->name() + " = -" + $2.addr->name() + "\n";
	$$.type = $2.type;

} | '(' expression ')' {
	$$.code = $2.code;
	$$.addr = $2.addr;
	$$.type = $2.type;

} | INT_LITERAL {
	$$.code = "";
	int val = std::stoi($1.code);
	$$.addr = symtab.make_int_const(val);
	$$.type = Type::Int;

} | FLOAT_LITERAL {
	$$.code = "";
	float val = std::stof($1.code);
	$$.addr = symtab.make_float_const(val);
	$$.type = Type::Float;

} | CHAR_LITERAL {
	$$.code = "";
	
	// Removing single quotes
	std::string val = $1.code.substr(1, $1.code.size()-2);
	
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
	$$.addr = symtab.make_variable($1.code);
	$$.type = $1.type;
};


%%

int main()
{
	int result = yyparse();
	yylex_destroy();
	return result;
}
