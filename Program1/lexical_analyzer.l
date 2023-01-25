/* Declarations section */
%{
#include <iostream>
#include <string>

// Need for C++
#define YY_DECL extern "C" int yylex()

// All the different tokens that are evaluated by this lexical analyzer
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
    INT_LIT,
    FP_LIT,
    CHAR_LIT,
    STRING_LIT,
    EQUAL,
    PLUS,
    MINUS,
    STAR,
    FORWARD_SLASH,
    PERCENT,
    EQUAL_EQUAL,
    NOT_EQUAL,
    LESS_THAN,
    LESS_THAN_OR_EQUAL,
    GREATER_THAN,
    GREATER_THAN_OR_EQUAL,
    AND,
    OR,
    COMMA,
    PERIOD,
    SEMICOLON,
    OPEN_PARANTHESIS,
    CLOSE_PARANTHESIS,
    OPEN_BRACE,
    CLOSE_BRACE,
    OPEN_BRACKET,
    CLOSE_BRACKET,
    NOT_IMPORTANT,
    UNRECOGNIZED
};
%}

/* Don't generate the yyunput() function to prevent -Wall warning */
%option nounput
/* Track line number for reporting purposes */
%option yylineno

/* Pattern definitions */
alpha [a-zA-Z]
digits [0-9]

%top{
}




%%


%{
/* Rules section 
   Defines the regex for the different tokens handled by this analyzer
*/
%}

"if" {return IF;}

"else" {return ELSE;}

"while" {return WHILE;}

"do" {return DO;}

"for" {return FOR;}

"int" {return INT;}

"float" {return FLOAT;}

"char" {return CHAR;}

"void" {return VOID;}

"return" {return RETURN;}

"struct" {return STRUCT;}

({alpha}|_)+({alpha}|{digits}|_)* {
    return ID;
}

{digits}+ {
    return INT_LIT;
}

({digits}*"."{digits}+)|({digits}+"."{digits}*) {
    // For floating point without exponents
    return FP_LIT;
}

(({digits}*"."?{digits}+)|({digits}+"."{digits}*))("e"|"E")("+"|"-")?{digits}+ {
    // For floating point with exponents
    return FP_LIT;
}

("'"."'")|("'""\\""\'""'")|("'""\\""\\""'") {
    return CHAR_LIT;
}

(\")([^\"]|\\.)*(\") {
    return STRING_LIT;
}

"=" {return EQUAL;}

"+" {return PLUS;}

"-" {return MINUS;}

"*" {return STAR;}

"/" {return FORWARD_SLASH;}

"%" {return PERCENT;}

"==" {return EQUAL_EQUAL;}

"!=" {return NOT_EQUAL;}

"<" {return LESS_THAN;}

"<=" {return LESS_THAN_OR_EQUAL;}

">" {return GREATER_THAN;}

">=" {return GREATER_THAN_OR_EQUAL;}

"&&" {return AND;}

"||" {return OR;}

"," {return COMMA;}

"." {return PERIOD;}

";" {return SEMICOLON;}

"(" {return OPEN_PARANTHESIS;}

")" {return CLOSE_PARANTHESIS;}

"{" {return OPEN_BRACE;}

"}" {return CLOSE_BRACE;}

"[" {return OPEN_BRACKET;}

"]" {return CLOSE_BRACKET;}

[ \t\r]+ {
    // NOT_IMPORTANT is a token type that isn't printed but still needs to be looked at for column number tracking
    return NOT_IMPORTANT;
}       

[\n]+ {}       

("//".*) {return NOT_IMPORTANT;}

("/*")[^*]*("*")+([^/*][^*]*("*")+)*("/") {return NOT_IMPORTANT;}

. {return UNRECOGNIZED;}


%%


/* User code section */

using namespace std;

// Givens: Token to be evaluated
// Returns: String name of token
// Description: Determines the correct string name for the type of token being looked at
string token_name(int tok){
    switch(tok) {
        case IF:                    return "if";                     break;
        case ELSE:                  return "else";                   break;
        case WHILE:                 return "while";                  break;
        case DO:                    return "do";                     break;
        case FOR:                   return "for";                    break;
        case INT:                   return "int";                    break;
        case FLOAT:                 return "float";                  break;
        case CHAR:                  return "char";                   break;
        case VOID:                  return "void";                   break;
        case RETURN:                return "return";                 break;
        case STRUCT:                return "struct";                 break;
        case ID:                    return "identifier";             break;
        case INT_LIT:               return "integer-literal";        break;  
        case FP_LIT:                return "floating-point-literal"; break;
        case CHAR_LIT:              return "character-literal";      break;
        case STRING_LIT:            return "string-literal";         break;
        case EQUAL:                 return "=";                      break;
        case PLUS:                  return "+";                      break;
        case MINUS:                 return "-";                      break;
        case STAR:                  return "*";                      break;
        case FORWARD_SLASH:         return "/";                      break;
        case PERCENT:               return "%";                      break;
        case EQUAL_EQUAL:           return "==";                     break;
        case NOT_EQUAL:             return "!=";                     break;
        case LESS_THAN:             return "<";                      break;
        case LESS_THAN_OR_EQUAL:    return "<=";                     break;
        case GREATER_THAN:          return ">";                      break;
        case GREATER_THAN_OR_EQUAL: return ">=";                     break;
        case AND:                   return "&&";                     break;
        case OR:                    return "||";                     break;
        case COMMA:                 return ",";                      break;
        case PERIOD:                return ".";                      break;
        case SEMICOLON:             return ";";                      break;
        case OPEN_PARANTHESIS:      return "(";                      break;
        case CLOSE_PARANTHESIS:     return ")";                      break;
        case OPEN_BRACE:            return "{";                      break;
        case CLOSE_BRACE:           return "}";                      break;
        case OPEN_BRACKET:          return "[";                      break;
        case CLOSE_BRACKET:         return "]";                      break;
        case NOT_IMPORTANT:         return "not-important";          break;
        case UNRECOGNIZED:          return "unrecognized";           break;
        default:                    return "????";                   break;
    }
}

// Main function of code. Handles overall flow of lexical analysis
int main(){
    // To hold current token
    int token;
    // Track column number
    int column_num = 1;
    // Used to track when there's a new line for column number reporting purposes
    int old_row_num = 1;

    // Retrieving next token
    while ((token = yylex()) != 0) {
        // Obtain the type of token
        string token_type = token_name(token);
        
        //cout << "Lexeme: " << yytext << "   Token: " << token_type << endl;

        // Resetting column number on new lines
        if(yylineno != old_row_num){
            old_row_num = yylineno;
            column_num = 1;
        }

        // If token is a comment or whitespace, still need to account for column number, but not print
        if(token_type == "not-important"){
            column_num += strlen(yytext);
            continue;
        }
        
        // If a token is unrecognized, inform the user
        if(token_type == "unrecognized"){
            cout << "Unrecognized character: " << yytext << ": " << yylineno << ", " << column_num << endl;
            column_num += strlen(yytext);
            continue;
        }

        // Printing token, lexeme if needed, row number, and column number
        cout << token_type;
        if(token_type == "identifier" || token_type == "integer-literal" || token_type == "floating-point-literal" || token_type == "character-literal" || token_type == "string-literal"){
            cout << ": " << yytext;
        }
        cout << ": " << yylineno << ", " << column_num << endl;

        // Updating column number
        column_num += strlen(yytext);
        
    }

    // Freeing memory to prevent memory leaks
    yylex_destroy();
}