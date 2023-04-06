# CS541 Program 3 - Type Checker and Code Generator
## Description
**Author:** Bobby Bose

**Final Version Date:** April 6, 2023

**Course:** CS541 - Compiler Design

**Assignment:** Program 3 - Type Checked and Code Generator

- This is a code-generator for the CLUKCS language

- Program reads from standard input and prints to standard output

- Intermediate code is generated in a 3-address-code (3AC) format
    - Addresses are either names of variables from the syntax tree, a temporary, or an integer, floating point, or character constant
    - A symbol table is used to store variables

- The code for the lexer, parser, 3AC classes, and symbol table were provided by Dr. Moore
    - Flex and bison are used for the lexer and parser

- The Makefile was also provided by Dr. Moore

- A set of tests is included in /tests in order to test different possibilities for every production

## Citations
**[Flex Manual](https://westes.github.io/flex/manual/)**

**[Bison Manual](https://www.gnu.org/software/bison/manual/html_node/index.html)**

## Package Requirments
No external packages required beyond Flex and Bison.

[iostream](https://en.cppreference.com/w/cpp/header/iostream), [vector](https://cplusplus.com/reference/vector/vector/), [list](https://cplusplus.com/reference/list/list/), [unordered_map](https://cplusplus.com/reference/list/list/), and [string](https://en.cppreference.com/w/cpp/string) from C++ standard library are required. 

## How to Build
To build, run 'make' or 'make all'

'make clean' will remove generated files

## How to Run
To run without input file, do './code_gen'

To run with input file, do './code_gen < input-file'

## Program Design
Program consists of three main parts: lexical analyzer, parser, and 3AC/symbol table classes

### Lexical analyzer (lexer.l)
- Sets the regular expression rule/match for each token type
- Returns the correct token_type based on the regex match

### Parser (parser.y)
- Productions are written for a subset of the CLUKCS language
- Ambiguity is solved by declaring precedence levels at the top of the file with Bison's %left, %right, and %precedence options
- Symbols are used to represent the tokens and non-terminals
- Type checking is implemented to handle type conversions for operations and assignments, as necessary
- 3AC code is generated as parsing is done
    - Printed to standard output after input ends
- **int main()** 
    - Handles parsing of input
- **void yyerror(const char msg)**
    - Prints out error messages as needed
- **void operation_type_checking(parser_val &E0, parser_val &E1, parser_val &E2, std::string op)**
    - Used for type checking and conversion for +, -, *, and / operations
#### Possible Errors:
- Declaring a variable with auto and no assignment (ex: "auto a;")
    - Assumes variable is an int
- Attempting to perform a modulus operation with float operand(s) (ex: "2.1 % 3.4;")
    - Assumes result is 0
- Left hand side of an assignment is not a variable
    - Only semantic error
- Trying to use a variable that doesn't exist in the scope
    - Variable is declared as an int

### 3AC Classes and symbol table (types.h)
- Used to manage and generate 3AC code for the input
- Addresses are either a varaible, temporary, integer, floating point, or character
    - Variables are stored in the symbol table
    - Temporaries are uniquely generated as needed

### Additional Files
- **globals.h**
    - Helps link lexer to parser

## Bugs/limitations
- No known bugs or limitations
