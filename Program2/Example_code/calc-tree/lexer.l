%{
#include <iostream> // std::cerr
#include <string>   // std::string
#include <stdlib.h> // atof()
#include "parser.hh"
#include "globals.h"

/* Global variables for current line and column. */
int CurrLine = 1;
int CurrColumn = 1;

%}

/* Don't generate yyunput(), since we don't use it. */
%option nounput


%%


([0-9]*\.)?[0-9]+  {
	std::cout << "digit" << std::endl;
	CurrColumn += yyleng;
	yylval = new tree_node(std::string("number: ") + yytext);
	return NUMBER;
}

[a-zA-Z] {
	CurrColumn += yyleng;
	yylval = new tree_node(std::string("var: ") + yytext);
	return VAR;
}


"+"|"-"|"*"|"/"|"("|")"|"=" {
	CurrColumn += yyleng;
	yylval = new tree_node(yytext);

	/* These tokens are represented by single characters as their
	 * token ID.
	 */
	return yytext[0];
}

\n {
	CurrColumn = 1;
	++CurrLine;
	yylval = new tree_node("newline");

	/* Must return this, because it is part of the grammar */
	return '\n';
}

	/* Skip horizontal whitespace entirely */
[ \t]+ {
	CurrColumn += yyleng;
}

. {        /* Anything else.  Must be the last rule! */
	CurrColumn += yyleng;
	std::cerr << "Unrecognized character: " << yytext << "\n";
}
