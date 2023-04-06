#ifndef GLOBALS_H_INCLUDED
#define GLOBALS_H_INCLUDED

// Make sure yylex gets C++ linkage, which -lfl expects.
#define YY_DECL extern "C" int yylex()
// And make it visible to the parser.
YY_DECL;

// Declarations for line and column, defined in lexer.l
extern int CurrLine;
extern int CurrColumn;

#endif // GLOBALS_H_INCLUDED
