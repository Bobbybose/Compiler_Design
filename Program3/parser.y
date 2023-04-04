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

%}

/* Put this into the generated header file, too */
%code requires {
  #include "types.h"
  #include "globals.h"
}

/* Semantic value for grammar symbols.  See definition in types.h */
%define api.value.type {clukcs::parser_val}

%token IDENTIFIER INT_LITERAL FLOAT_LITERAL CHAR_LITERAL
%token '+' '-' '*' '/' '%' '=' '(' ')' '{' '}' ';' INT FLOAT CHAR


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
	Address* temp = symtab.make_temp($1.type);

	$$.code = $4.code;
	// t0 = num
	$$.code += temp->name() + " = " + $4.addr->name() + "\n";
	// id = t0
	$$.code += $2.code + " = " + temp->name() + "\n";

	symtab.put($2.code, $1.type);

} | type IDENTIFIER ';' {
	$$.code = "";
	symtab.put($2.code, $1.type);

} | error ';' { // error is a special token defined by bison
	yyerrok;
};

type: INT {
	$$.type = Type::Int;
} | FLOAT {
	$$.type = Type::Float;
} | CHAR {
	$$.type = Type::Char;
};

expression: expression '+' expression {
	$$.code = $1.code + $3.code;

	// Getting types of LHS and RHS
	Type E1_type = symtab.get($1.addr->name())->type;
	Type E2_type = symtab.get($3.addr->name())->type;
	
	if(E1_type == E2_type){
		$$.type = E1_type;
		$$.addr = symtab.make_temp(E1_type);
	}
	else{
		if(E1_type == Type::Float){
			if(E2_type == Type::Int){
				Address* temp = symtab.make_temp(E1_type);
				$$.code += temp->name() + " = int2float " + $3.addr->name() + "\n";
				
				$$.type = E1_type;
				$$.addr = symtab.make_temp(E1_type);

				$$.code += $$.addr->name() + " = " + $1.addr->name() + " + " + temp->name() + "\n";
			}
			if(E2_type == Type::Char){
				Address* temp = symtab.make_temp(Type::Int);
				$$.code += temp->name() + " = char2int " + $3.addr->name() + "\n";
					
				Address* temp2 = symtab.make_temp(E1_type);
				$$.code += temp2->name() + " = int2float " + temp->name() + "\n";

				$$.type = E1_type;
				$$.addr = symtab.make_temp(E1_type);

				$$.code += $$.addr->name() + " = " + $1.addr->name() + " + " + temp2->name() + "\n";
			}
		}

		else if(E2_type == Type::Float){
			if(E1_type == Type::Int){
				Address* temp = symtab.make_temp(E2_type);
				$$.code += temp->name() + " = int2float " + $1.addr->name() + "\n";

				$$.type = E2_type;
				$$.addr = symtab.make_temp(E2_type);

				$$.code += $$.addr->name() + " = " + temp->name() + " + " + $3.addr->name() + "\n";
			}
			if(E1_type == Type::Char){
				Address* temp = symtab.make_temp(Type::Int);
				$$.code += temp->name() + " = char2int " + $1.addr->name() + "\n";
					
				Address* temp2 = symtab.make_temp(E2_type);
				$$.code += temp2->name() + " = int2float " + temp->name() + "\n";

				$$.type = E2_type;
				$$.addr = symtab.make_temp(E2_type);

				$$.code += $$.addr->name() + " = " + temp->name() + " + " + $3.addr->name() + "\n";
			}
		}

		else if(E1_type == Type::Int){
			Address* temp = symtab.make_temp(E1_type);
			$$.code += temp->name() + " = char2int " + $3.addr->name() + "\n";
			
			$$.type = E1_type;
			$$.addr = symtab.make_temp(E1_type);

			$$.code += $$.addr->name() + " = " + $1.addr->name() + " + " + temp->name() + "\n";
		}
		
		else if(E2_type == Type::Int){
			Address* temp = symtab.make_temp(E2_type);
			$$.code += temp->name() + " = char2int " + $1.addr->name() + "\n";
			
			$$.type = E2_type;
			$$.addr = symtab.make_temp(E2_type);

			$$.code += $$.addr->name() + " = " + temp->name() + " + " + $3.addr->name() + "\n";
		}	
	}

} | expression '-' expression {
} | expression '*' expression {
} | expression '/' expression {
} | expression '%' expression {

} | expression '=' expression {
	// Getting types of LHS and RHS
	Type E1_type = symtab.get($1.addr->name())->type;
	Type E2_type = symtab.get($3.addr->name())->type;
	
	// Type is same as LHS
	$$.type = E1_type;
	$$.addr = $1.addr;
	$$.code = $1.code + $3.code;
	
	// If RHS is a different type, do type conversion
	if(E1_type != E2_type){
		std::cout << "Here " << std::endl;
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
	//std::cout << "char_val: " << char_val << std::endl;

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
