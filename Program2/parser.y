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
%token IF ELSE WHILE FOR INT FLOAT CHAR ID INT_LIT FP_LIT CHAR_LIT STRING_LIT EQUAL PLUS MINUS STAR FORWARD_SLASH EQUAL_EQUAL NOT_EQUAL LESS_THAN LESS_THAN_OR_EQUAL GREATER_THAN GREATER_THAN_OR_EQUAL AND OR SEMICOLON OPEN_PARANTHESIS CLOSE_PARANTHESIS OPEN_BRACE CLOSE_BRACE EMPTY_STRING

/* How to free discarded tokens during error recovery. */
%destructor { delete $$; } <>

/* Which nonterminal is at the top of the parse tree? */
%start program

%%

program : statementList {
	print_tree($1);
	delete $1;
	$$ = nullptr;
};

statementList : statementList statement {
	$$ = new tree_node("statementList", $1, $2);
} | EMPTY_STRING {
	$$ = new tree_node("statementList", $1);
};

statement : OPEN_BRACE statementList CLOSE_BRACE {
	$$ = new tree_node("statement", $1, $2 $3);
} | type ID EQUAL expression SEMICOLON {
	$$ = new tree_node("statement", $1, $2 $3, $4, $5);
} | type ID SEMICOLON {
		$$ = new tree_node("statement", $1, $2 $3);
} | expression SEMICOLON {
	$$ = new tree_node("statement", $1, $2);
} | WHILE OPEN_PARANTHESIS expression CLOSE_PARANTHESIS statement {
	$$ = new tree_node("statement", $1, $2 $3, $4, $5);
} | IF OPEN_PARANTHESIS expression CLOSE_PARANTHESIS statement {
	$$ = new tree_node("statement", $1, $2 $3, $4, $5);
} | IF OPEN_PARANTHESIS expression CLOSE_PARANTHESIS statement ELSE statement {
	$$ = new tree_node("statement", $1, $2 $3, $4, $5, $6, $7);
} | FOR OPEN_PARANTHESIS expression SEMICOLON expression SEMICOLON expression CLOSE_PARANTHESIS statement {
	$$ = new tree_node("statement", $1, $2 $3, $4, $5, $6, $7, $8, $9);
};

type : INT {
	$$ = new tree_node("type", $1);
} | FLOAT {
	$$ = new tree_node("type", $1);
} | CHAR {
	$$ = new tree_node("type", $1);
};

expression : OPEN_PARANTHESIS expression CLOSE_PARANTHESIS {
	$$ = new tree_node("expression", $1, $2, $3);
} | expression PLUS expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression MINUS expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression STAR expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression FORWARD_SLASH expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression EQUAL expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression AND expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression OR expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression LESS_THAN expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression LESS_THAN_OR_EQUAL expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression GREATER_THAN expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression GREATER_THAN_OR_EQUAL expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression EQUAL_EQUAL expression {
	$$ = new tree_node("expression", $1, $2, $3);
} expression NOT_EQUAL expression {
	$$ = new tree_node("expression", $1, $2, $3);
} ID {
	$$ = new tree_node("expression", $1);
} INT_LIT {
	$$ = new tree_node("expression", $1);
} FP_LIT {
	$$ = new tree_node("expression", $1);
} CHAR_LIT {
	$$ = new tree_node("expression", $1);
} STRING_LIT {
	$$ = new tree_node("expression", $1);
}; 

%%

int main()
{
	int result = yyparse();
	yylex_destroy();
	return result;
}
