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
	yylval = new tree_node(std::string("number: ") + yytext, CurrColumn, CurrLine);
	CurrColumn += yyleng;
	return NUMBER;
}

[a-zA-Z] {
	yylval = new tree_node(std::string("var: ") + yytext, CurrColumn, CurrLine);
	CurrColumn += yyleng;
	return VAR;
}


"+"|"-"|"*"|"/"|"("|")"|"=" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
	CurrColumn += yyleng;

	/* These tokens are represented by single characters as their
	 * token ID.
	 */
	return yytext[0];
}

\n {
	yylval = new tree_node("newline", CurrColumn, CurrLine);
	CurrColumn = 1;
	//++CurrLine;

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
