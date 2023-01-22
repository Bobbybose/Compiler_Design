    /* Declarations section */
%{
#include <iostream>
#include <string>

// Need for C++
#define YY_DECL extern "C" int yylex()

enum Token {
    IF,
    ELSE,
    WHILE,
    DO,
    FOR,
    INT,
    FLOAT,
    CHAR,
    VOID,
    RETURN,
    STRUCT,
    ID,
    INTLIT = 1,
    FPLIT,
    CHARLIT,
    STRINGLIT,
    OPERATOR,
    PUNCTUATION
};
%}

/* Don't generate the yyunput() function to prevent -Wall warning */
%option nounput

/* Pattern definitions */
alpha [a-zA-Z]
ws [ \t\n]
comments [\\\\]

%top{
}




%%


%{
/* Rules section */
%}

[0-9]+  {
    return INTEGER;
}




%%


/* User code section */

using namespace std;

string token_name(int tok){
    switch(tok){
        case IF: 
            return "if"; break;
        case ELSE: 
            return "else"; break;
        case WHILE: 
            return "while"; break;
        case DO: 
            return "do"; break;
        case FOR: 
            return "for"; break;
        case INT: 
            return "int"; break;
        case FLOAT: 
            return "float"; break;
        case CHAR: 
            return "char"; break;
        case VOID: 
            return "void"; break;
        case RETURN: 
            return "return"; break;
        case STRUCT: 
            return "struct"; break;
        case ID: 
            return yytext; break;
        case INTLIT: 
            return yytext; break;
        case FPLIT: 
            return yytext; break;
        case CHARLIT: 
            return yytext; break;
        case STRINGLIT: 
            return yytext; break;
        case OPERATOR: 
            return yytext; break;
        case PUNCTUATION: 
            return yytext; break;      
    }
}

int main(){
}