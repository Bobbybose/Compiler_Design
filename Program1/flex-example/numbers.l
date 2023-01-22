    /*******************
     * Declarations section.  Any indented text, or unindented comments,
     * here are copied verbatim to the output file.
     */

%{
/* Text in %{ %} (which must appear on their own lines) is also copied
 * verbatim to the output.  Here is where we might #include necessary
 * header files, unless we also want them to affect flex's boilerplate.
 */
#include <iostream>
#include <string>

/* Needed for C++, not C */
#define YY_DECL extern "C" int yylex()

/* It is important that none of these enumerators are zero, since yylex()
 * returns 0 to indicate the end of input.  You could use const ints or
 * #defines instead.
 */
enum Token {
	INTEGER = 1,
	FLOAT,
	WORD
};
%}


    /* Options.  Specifically, don't generate the yyunput() function: Since we
    * don't use it, we'd get a -Wall warning about an unused static function.
    */
%option nounput


/* Define named patterns. */
alpha [a-zA-Z]
ws [ \t\n]


%top{
/* Code inside %top{ } is copied verbatim to the very top of the output.
 * Usually not needed unless you want to affect the boilerplate code.
 */
}



%%

%{
    /*******************
     * Rules section.  Any indented text or text in %{ %} is copied to the
     * output.  BUT note that:
     *   1) this goes inside a generated function (so no #include etc.)
     *   2) You shouldn't do that after the first rule, since your code
     *      would go to an unspecified place in the middle of a function!
     */
%}

[0-9]+  {
        return INTEGER;
}

[0-9]+\.[0-9]+ {
        return FLOAT;
}

{alpha}+ { /* {alpha} is the named pattern we defined above */
        return WORD;
}

{ws}+ { }  /* skip whitespace entirely */

. {        /* Anything else.  Must be the last rule! */
    std::cerr << "Unrecognized character: " << yytext << "\n";
}





%%

/*******************
 * User code section.  Copied verbatim.
 */
std::string token_name(int tok)
{
    switch(tok) {
        case INTEGER: return "INTEGER"; break;
        case FLOAT:   return "FLOAT";   break;
        case WORD:    return "WORD";    break;
        default:      return "????";    break;
    }
}

int main()
{
    int token;

    // The usual way of calling the lexer in a loop, when the lexer uses "return".
    while ((token = yylex()) != 0) {
        std::cout << "Got token: " << token_name(token)
                  << ": " << yytext << "\n";
    }
    std::cout << "End of input.\n";

    /* Free memory.  Not usually needed, but the assignment asks for
     * no memory leaks!
     */
    yylex_destroy();
}
