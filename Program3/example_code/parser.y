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
} | '{' { symtab.push(); }  statement_list '}' {
	symtab.pop();
} | type IDENTIFIER '=' expression ';' {
} | type IDENTIFIER ';' {
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
} | expression '-' expression {
} | expression '*' expression {
} | expression '/' expression {
} | expression '%' expression {
} | expression '=' expression {
} | '-' expression %prec UMINUS {
} | '(' expression ')' {
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

	//std::cout << "val: " << val << std::endl;

	if(val == "\\n"){
		std::cout << "slash-n" << std::endl;
		char_val = '\n';
	}
	else if(val == "\\\\")
		char_val = '\\';
	else if(val == "\\'")
		char_val = '\'';
	else
		char_val = val[0];

	std::cout << "char_val: " << char_val << std::endl;

	$$.addr = symtab.make_char_const(char_val);

	$$.type = Type::Char;
} | IDENTIFIER {
	$$.code = "";
	std::cout << "ID: " << $1.code << std::endl;
	$$.addr = symtab.make_variable($1.code);
	$$.type = $$.addr->type();
	//std::cout << "Type: " << $$.addr->type() << std::endl;
};


%%

int main()
{
	int result = yyparse();
	yylex_destroy();
	return result;
}
