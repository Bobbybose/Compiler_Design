%{
#include <iostream> // cerr, cout
#include "globals.h"

/* Note: C and C++ zero-initialize global variables. */
double variables[256];

/* Prototype for a function defined by flex. */
void yylex_destroy();

/* Report error messages */
void yyerror(const char *msg)
{
	std::cerr << msg << " at line " << CurrLine << ", column "
	          << CurrColumn << "\n";
}
%}

/* Put this into the generated header file, too */
%code requires {
  #include "tree_node.h"
}

/* Instead of a union, we have just one type for all symbols */
%define api.value.type {tree_node *}

/* What are the tokens?  Since we aren't using %union, we don't
 * have to specify their types.
 */
%token VAR NUMBER '+' '-' '*' '/' '(' ')' '=' '\n'

/* How to free discarded tokens during error recovery. */
%destructor { delete $$; } <>

/* Which nonterminal is at the top of the parse tree? */
%start input

%%

input: statement {
	print_tree($1);
	delete $1;
	$$ = nullptr; // Avoid a warning.
} | input statement {
	print_tree($2);
	delete $2;
	$$ = $1;  // Avoid two warnings.
};

statement: expression '\n' {
	$$ = new tree_node("statement", $1, $2);
} | VAR '=' expression '\n' {
	$$ = new tree_node("statement", $1, $2, $3, $4);
} | error '\n' { // error is a special token defined by bison
	$$ = new tree_node("ERROR", $2);
	yyerrok; // Mark that we handled the error (and don't abort).
};

expression: expression '+' term {
	$$ = new tree_node("expression", $1, $2, $3);
} | expression '-' term {
	$$ = new tree_node("expression", $1, $2, $3);
} | term {
	$$ = new tree_node("expression", $1);
};

term: term '*' factor {
	$$ = new tree_node("term", $1, $2, $3);
} | term '/' factor {
	$$ = new tree_node("term", $1, $2, $3);
} | factor {
	$$ = new tree_node("term", $1);
};

factor: '-' factor {
	$$ = new tree_node("factor", $1, $2);
} | '(' expression ')' {
	$$ = new tree_node("factor", $1, $2, $3);
} | NUMBER {
	$$ = new tree_node("factor", $1);
} | VAR {
	$$ = new tree_node("factor", $1);
};


%%

int main()
{
	int result = yyparse();
	yylex_destroy();
	return result;
}
