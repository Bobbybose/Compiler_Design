%{
#include <iostream> // cerr
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
	yylval.numval.line = CurrLine;
	yylval.numval.column = CurrColumn;
	CurrColumn += yyleng;

	yylval.numval.val = atof(yytext);

	return NUMBER;
}

[a-zA-Z] {
	yylval.varname.line = CurrLine;
	yylval.varname.column = CurrColumn;
	CurrColumn += yyleng;

	yylval.varname.name = (unsigned char)yytext[0];

	return VAR;
}


"+"|"-"|"*"|"/"|"("|")"|"=" {
	yylval.noval.line = CurrLine;
	yylval.noval.column = CurrColumn;
	CurrColumn += yyleng;

	/* These tokens are represented by single characters as their
	 * token ID.
	 */
	return yytext[0];
}

\n {
	yylval.noval.line = CurrLine;
	yylval.noval.column = CurrColumn;
	CurrColumn = 1;
	++CurrLine;

	/* Must return this, because it is part of the grammar */
	return '\n';
}

[ \t]+ { CurrColumn += yyleng; } /* skip non-newline whitespace entirely */

. {        /* Anything else.  Must be the last rule! */
    std::cerr << "Unrecognized character: " << yytext << "\n";
}
