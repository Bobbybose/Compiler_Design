# CS541 Program 4 - LLVM Code-Generator
## Description
**Author:** Bobby Bose

**Final Version Date:** April 20, 2023

**Course:** CS541 - Compiler Design

**Assignment:** Program 4 - LLVM Code-Generator

- This is a code-generator for the CLUKCS language

- Program reads from standard input and prints to standard output

- Intermediate LLVM code is generated
    - LLVM Version 10 is used
    - A symbol table is used to store variables
    - Addresses are either names of variables from the syntax tree, a temporary, or an integer, floating point, or character constant

- The code for the lexer, parser, symbol and address classes, and symbol table were provided by Dr. Moore
    - Flex and bison are used for the lexer and parser

- The Makefile was also provided by Dr. Moore

- A set of tests is included in /tests in order to test different possibilities for every production

## Citations
**[Flex Manual](https://westes.github.io/flex/manual/)**

**[Bison Manual](https://www.gnu.org/software/bison/manual/html_node/index.html)**

**[LLVM Manual](https://releases.llvm.org/10.0.0/docs/index.html)**

## Package Requirments
No external packages required beyond Flex, Bison, and LLVM.

[iostream](https://en.cppreference.com/w/cpp/header/iostream), [vector](https://cplusplus.com/reference/vector/vector/), [list](https://cplusplus.com/reference/list/list/), [unordered_map](https://cplusplus.com/reference/list/list/), and [string](https://en.cppreference.com/w/cpp/string) from C++ standard library are required. 

## How to Build
To build, run 'make' or 'make all'

'make clean' will remove generated files

## How to Run
To run without input file, do './c2ll'

To run with input file, do './c2ll < input-file'

## Program Design
Program consists of three main parts: lexical analyzer, parser, and address/symbol table classes

### Lexical Analyzer (lexer.l)
- Sets the regular expression rule/match for each token type
- Returns the correct token_type based on the regex match

### Parser (parser.y)
- Productions are written for a subset of the CLUKCS language
- Ambiguity is solved by declaring precedence levels with Bison's %left, %right, and %prec options
- Symbols are used to represent the tokens and non-terminals
- Type checking is implemented to handle type conversions for operations and assignments, as necessary
- LLVM code is generated as parsing is done
    - Printed to standard output after input ends
- Variable accesses use the load instruction to load the value into a temporary
- Variable assignments use the store instruction to store the value in the variable's location in the stack
- **int main()** 
    - Handles parsing of input
- **void yyerror(const char msg)**
    - Prints out error messages as needed
- **void operation_type_checking(parser_val &E0, parser_val &E1, parser_val &E2, std::string op)**
    - Used for type checking and conversion for +, -, *, /, and % operations
- **std::string get_type_string(Type t)**
    - Used to get string representation for the different types
- **std::string output_conversion(std::string output)**
    - Modifies the body of the main function to add the tab (2 spaces) spacing
#### Possible User Errors:
- Declaring a variable with auto and no assignment (ex: "auto a;")
    - Solution: Assumes variable is an int
- Attempting to perform a modulus operation with float operand(s)
    - Solution: Assumes result is 0
- Left hand side of an assignment is not a variable
    - Only semantic error
- Trying to use a variable that doesn't exist in the scope
    - Solution: Variable is declared as an int

### LLVM Address Classes and Symbol Table (types.h)
- Used to manage and generate LLVM code for the input
- Addresses are either a variable, temporary, integer, floating point, or character
    - Variables are stored in the symbol table
    - Each variable is allocated space in the stack
        - A temporary points to this location
    - Temporaries are uniquely generated as needed

### Additional Files
- **globals.h**
    - Helps link lexer to parser

## Bugs/limitations
- No known bugs or limitations
