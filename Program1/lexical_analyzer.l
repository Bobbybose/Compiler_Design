/* Declarations section */
%{
#include <iostream>
#include <string>

// Need for C++
#define YY_DECL extern "C" int yylex()

enum Token {
    IF = 1,
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
    EQUAL,
    PLUS,
    MINUS,
    STAR,
    FORWARDSLASH,
    PERCENT,
    EQUALEQUAL,
    NOTEQUAL,
    LESSTHAN,
    LESSTHANOREQUAL,
    GREATERTHAN,
    GREATERTHANOREQUAL,
    AND,
    OR,
    COMMA,
    PERIOD,
    SEMICOLON,
    OPENPARANTHESIS,
    CLOSEPARANTHESIS,
    OPENBRACE,
    CLOSEBRACE,
    OPENBRACKET,
    CLOSEBRACKET
};
%}

/* Don't generate the yyunput() function to prevent -Wall warning */
%option nounput

/* Pattern definitions */
alpha [a-zA-Z]
digits [0-9]
ws [ \t\n]
comments [\\\\]

%top{
}




%%


%{
/* Rules section */
%}

"if" {
    return IF;
}

"else" {
    return ELSE;
}

"while" {
    return WHILE;
}

"do" {
    return DO;
}

"for" {
    return FOR;
}

"int" {
    return INT;
}

"float" {
    return FLOAT;
}

"char" {
    return CHAR;
}

"void" {
    return VOID;
}

"return" {
    return RETURN;
}

"struct" {
    return STRUCT;
}

({alpha}|_)+({alpha}|{digits}|_)* {
    return ID;
}

{digits} {
    return INTLIT;
}

{ws}+ { }       

. {
    std::cout << "Unrecognized character: " << yytext << "\n";
}


%%


/* User code section */

using namespace std;

string token_name(int tok){
    switch(tok){
        case IF:                 return "if"; break;
        case ELSE:               return "else"; break;
        case WHILE:              return "while"; break;
        case DO:                 return "do"; break;
        case FOR:                return "for"; break;
        case INT:                return "int"; break;
        case FLOAT:              return "float"; break;
        case CHAR:               return "char"; break;
        case VOID:               return "void"; break;
        case RETURN:             return "return"; break;
        case STRUCT:             return "struct"; break;
        case ID:                 return "identifier"; break;
        /*case INTLIT:             return "integer-literal"; break;
        case FPLIT:              return "floating-point-literal"; break;
        case CHARLIT:            return "character-literal"; break;
        case STRINGLIT:          return "string-literal"; break;
        case EQUAL:              return "="; break;
        case PLUS:               return "+"; break;      
        case MINUS:              return "-"; break;      
        case STAR:               return "*"; break;      
        case FORWARDSLASH:       return "/"; break;      
        case PERCENT:            return "%%"; break;      
        case EQUALEQUAL:         return "=="; break;      
        case NOTEQUAL:           return "!="; break;      
        case LESSTHAN:           return "<"; break;      
        case LESSTHANOREQUAL:    return "<="; break;      
        case GREATERTHAN:        return ">"; break;      
        case GREATERTHANOREQUAL: return ">="; break;      
        case AND:                return "&&"; break;      
        case OR:                 return "||"; break;      
        case COMMA:              return ","; break;      
        case PERIOD:             return "."; break;      
        case SEMICOLON:          return ";"; break;      
        case OPENPARANTHESIS:    return "("; break;      
        case CLOSEPARANTHESIS:   return ")"; break;      
        case OPENBRACE:          return "{"; break;      
        case CLOSEBRACE:         return "}"; break;      
        case OPENBRACKET:        return "["; break;      
        case CLOSEBRACKET:       return "]"; break;        */      
        default:                 return "????"; break;
    }
}

int main(){
    // To hold current token
    int token;
    
    while ((token = yylex()) != 0){
        string token_type = token_name(token);

        cout << token_type;
        
        if(token_type == "identifier" || token_type == "integer-literal" || token_type == "floating-point-literal" || token_type == "character-literal" || token_type == "string-literal"){
            cout << ": " << yytext << "\n";
        }
        else{
            cout << "\n";
        }
    }

    cout << "End of input.\n";

    // Freeing memory to prevent memory leaks
    yylex_destroy();
}