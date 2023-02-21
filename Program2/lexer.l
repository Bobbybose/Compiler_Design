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
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return IF;
}

"else" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return ELSE;
}

"while" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return WHILE;
}

"for" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return FOR;
}

"int" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return INT;
}

"float" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return FLOAT;
}

"char" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return CHAR;
}

({alpha}|_)+({alpha}|{digits}|_)* {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return ID;
}

{digits}+ {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return INT_LIT;
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

"=" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return EQUAL;
}

"+" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return PLUS;
}

"-" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return MINUS;
}

"*" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return STAR;
}

"/" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return FORWARD_SLASH;
}

"==" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return EQUAL_EQUAL;
}

"!=" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return NOT_EQUAL;
}

"<" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return LESS_THAN;
}

"<=" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return LESS_THAN_OR_EQUAL;
}

">" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return GREATER_THAN;
}

">=" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return GREATER_THAN_OR_EQUAL;
}

"&&" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return AND;
}

"||" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return OR;
}

"," {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return COMMA;
}

";" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return SEMICOLON;
}

"(" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return OPEN_PARANTHESIS;
}

")" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return CLOSE_PARANTHESIS;
}

"{" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return OPEN_BRACE;
}

"}" {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return CLOSE_BRACE;
}

[ \t\r]+ {
    CurrColumn += yyleng;
}       

\n {
    CurrColumn = 1;
    ++CurrLine;
    yylval = new tree_node("newline");

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

    if(contains_newline){
        CurrColumn = 1;
        CurrLine++;
    }
    else{
        CurrColumn += yyleng;
    }
}

""/. {
    CurrColumn += yyleng;
	yylval = new tree_node(yytext);
    return EMPTY_STRING;
}

. {
    std::cout << "Nothing matches" << std::endl;
    CurrColumn += yyleng;
    std::cerr << "Unrecognized character: " << yytext << "\n";
}
