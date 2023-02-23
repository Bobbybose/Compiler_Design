/* Declarations section */
%{
#include <iostream>
#include <string>
#include <stdlib.h>
#include "parser.hh"
#include "globals.h"

/* Global variables for current line and column. */
int CurrLine = 1;
int CurrColumn = 1;
%}

/* Don't generate the yyunput() function to prevent -Wall warning */
%option nounput


/* Pattern definitions */
alpha [a-zA-Z]
digits [0-9]


%%


%{
/* Rules section 
   Defines the regex for the different tokens handled by this analyzer
*/
%}

"if" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return IF;
}

"else" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return ELSE;
}

"while" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return WHILE;
}

"for" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return FOR;
}

"int" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return INT;
}

"float" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return FLOAT;
}

"char" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return CHAR;
}

({alpha}|_)+({alpha}|{digits}|_)* {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return ID;
}

{digits}+ {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return INT_LIT;
}

({digits}*"."{digits}+)|({digits}+"."{digits}*) {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return FP_LIT;
}

(({digits}*"."?{digits}+)|({digits}+"."{digits}*))("e"|"E")("+"|"-")?{digits}+ {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return FP_LIT;
}

'[^\n'\\]'|'\\.' {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return CHAR_LIT;
}

\"([^\n"\\]|\\.)*\" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return STRING_LIT;
}

"=" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return EQUAL;
}

"+" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return PLUS;
}

"-" {
    yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return MINUS;
}

"*" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return STAR;
}

"/" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return FORWARD_SLASH;
}

"==" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return EQUAL_EQUAL;
}

"!=" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return NOT_EQUAL;
}

"<" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return LESS_THAN;
}

"<=" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return LESS_THAN_OR_EQUAL;
}

">" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return GREATER_THAN;
}

">=" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return GREATER_THAN_OR_EQUAL;
}

"&&" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return AND;
}

"||" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return OR;
}

"," {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return COMMA;
}

";" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return SEMICOLON;
}

"(" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return OPEN_PARANTHESIS;
}

")" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return CLOSE_PARANTHESIS;
}

"{" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return OPEN_BRACE;
}

"}" {
	yylval = new tree_node(yytext, CurrColumn, CurrLine);
    CurrColumn += yyleng;
    return CLOSE_BRACE;
}

[ \t\r]+ {
    CurrColumn += yyleng;
}       

\n {
    yylval = new tree_node("newline", CurrColumn, CurrLine);
    CurrColumn = 1;
    return '\n';
}       

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
    // If there's a newline, increment row number and reset column number
    if(contains_newline){
        CurrColumn = 1;
        CurrLine++;
    }
    else{
        CurrColumn += yyleng;
    }
}

. {
    CurrColumn += yyleng;
    std::cerr << "Unrecognized character: " << yytext << "\n";
}
