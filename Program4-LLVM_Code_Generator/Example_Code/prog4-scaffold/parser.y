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
%token '+' '-' '*' '/' '%' '=' '(' ')' '{' '}' ';' INT FLOAT CHAR RETURN


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
} | %empty {
};

statement: expression ';' {
} | '{' { symtab.push(); }  statement_list '}' {
	symtab.pop();
} | type IDENTIFIER '=' expression ';' {
} | type IDENTIFIER ';' {
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
} | FLOAT_LITERAL {
} | CHAR_LITERAL {
} | IDENTIFIER {
};


%%

int main()
{
	int result = yyparse();
	yylex_destroy();
	return result;
}
