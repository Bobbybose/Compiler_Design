%{
#include <iostream> // cerr, cout
#include "globals.h"

/* Note: C and C++ zero-initialize global variables. */
double variables[256];

void yyerror(const char *msg)
{
	std::cerr << msg << " at line " << CurrLine << ", column "
	          << CurrColumn << "\n";
}
%}

/* Three types for tokens and nonterminals:
 *   1. numbers
 *   2. single-letter variable names
 *   3. no type (but still track line/column)
 */
%union {
	struct {
		int line;
		int column;
		double val;
	} numval;

	struct {
		int line;
		int column;
		unsigned char name;
	} varname;

	struct {
		int line;
		int column;
	} noval;
}

/* What are the tokens and their types?
 *
 * These are the values that your lexer should return.  The ones
 * with NAMEs will be defined in the generated parser.hh.  bison
 * will ensure they don't overlap with ASCII symbols, so are distinct
 * from the 'x' tokens.
 *
 * In addition to returning a token type, the lexer should assign
 * to the appropriate member of the union yylval.  So, for example:
 *    yylval.numval.line = CurrLine;
 *    yylval.numval.column = CurrColumn;
 *    yylval.numval.val = (convert yytext to a number);
 */
%token <varname> VAR
%token <numval>  NUMBER
%token <noval>   '+' '-' '*' '/' '(' ')' '=' '\n'

/* What are the types of nonterminals? */
%type <numval> expression term factor
%type <noval>  input statement

/* Which nonterminal is at the top of the parse tree? */
%start input

%%

input: statement | input statement;

statement: expression '\n' {
	/* $$ is the value of the LHS.  $1 is the value of the first
	 * symbol (token or nonterminal) on the RHS.  Since yy
	 */
	$$.line = $1.line;
	$$.column = $1.column;

	std::cout << "\t" << $1.val << "\n\n";
} | VAR '=' expression '\n' {
	$$.line = $1.line;
	$$.column = $1.column;

	variables[$1.name] = $3.val;
	std::cout << "\t" << $1.name << " = " << $3.val << "\n\n";
} | error '\n' { // error is a special token defined by bison
	yyerrok; // Mark that we handled the error (and don't abort).
};

expression: expression '+' term {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = $1.val + $3.val;
} | expression '-' term {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = $1.val - $3.val;
} | term {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = $1.val;
};

term: term '*' factor {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = $1.val * $3.val;
} | term '/' factor {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = $1.val / $3.val;
} | factor {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = $1.val;
};

factor: '-' factor {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = -$2.val;
} | '(' expression ')' {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = $2.val;
} | NUMBER {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = $1.val;
} | VAR {
	$$.line = $1.line;
	$$.column = $1.column;

	$$.val = variables[$1.name];
};


%%

int main()
{
	return yyparse();
}
