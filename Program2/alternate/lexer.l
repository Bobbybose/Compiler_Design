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


/* Pattern definitions */
alpha [a-zA-Z]
digits [0-9]


%%


([0-9]*\.)?[0-9]+  {
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

"if" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return IF;}

"else" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return ELSE;}

"while" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return WHILE;}

"for" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return FOR;}

"int" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return INT;}

"float" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return FLOAT;}

"char" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return CHAR;}

({alpha}|_)+({alpha}|{digits}|_)* {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return ID;
}

({digits}*"."{digits}+)|({digits}+"."{digits}*) {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return FP_LIT;
}

(({digits}*"."?{digits}+)|({digits}+"."{digits}*))("e"|"E")("+"|"-")?{digits}+ {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return FP_LIT;
}

'[^\n'\\]'|'\\.' {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return CHAR_LIT;
}

\"([^\n"\\]|\\.)*\" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return STRING_LIT;
}

"==" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return EQUAL_EQUAL;}

"!=" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return NOT_EQUAL;}

"<" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return LESS_THAN;}

"<=" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return LESS_THAN_OR_EQUAL;}

">" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return GREATER_THAN;}

">=" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return GREATER_THAN_OR_EQUAL;}

"&&" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return AND;}

"||" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return OR;}

";" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return SEMICOLON;}

"{" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return OPEN_BRACE;}

"}" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return CLOSE_BRACE;}

("//".*) {
    CurrColumn = 1;
    CurrLine++;
}

("/*")[^*]*("*")+([^/*][^*]*("*")+)*("/") {
    bool contains_newline = false;
    // Checking if block has newlines
    for( int i = 0; i < yyleng; i++){
        if(yytext[i] == '\n'){
            contains_newline = true;
        }
    }

    if(contains_newline){
        CurrColumn = 1;
        CurrLine++;
    }
    else{
        CurrColumn += yyleng;
    }
}

"" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return EMPTY_STRING;
}

. {        /* Anything else.  Must be the last rule! */
	CurrColumn += yyleng;
	std::cerr << "Unrecognized character: " << yytext << "\n";
}
