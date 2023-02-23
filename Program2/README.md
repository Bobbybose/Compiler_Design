# CS541 Program 2 - Parser
## Description
**Author:** Bobby Bose

**Final Version Date:** February 23, 2023

**Course:** CS541 - Compiler Design

**Assignment:** Program 2 - Parser

- This is a parser designed to create a parse tree of user input based on predefined production

- A lexical analyzer is included to parse input and generate tokens

- Code for program is based off of Dr. Moore's examples

- Makefile is also written based off of Dr. Moore's example

- A set of tests is included in /tests in order to test different possibilities for every production

## Citations
**[Flex Manual](https://westes.github.io/flex/manual/)**

**[Bison Manual](https://www.gnu.org/software/bison/manual/html_node/index.html)**

**[Regex Guide](https://cheatography.com/davechild/cheat-sheets/regular-expressions/)**

**[C++ Operator Precedence Guide](https://en.cppreference.com/w/cpp/language/operator_precedence)**

## Package Requirments
No external packages required beyond Flex.

[iostream](https://en.cppreference.com/w/cpp/header/iostream), [vector](https://cplusplus.com/reference/vector/vector/), [stdlib](https://cplusplus.com/reference/cstdlib/), and [string](https://en.cppreference.com/w/cpp/string) from C++ standard library are required. 

## How to Build
To build, run 'make' or 'make all'

'make clean' will remove generated files

## How to Run
To run without input file, do './clukcs_parser'

To run with input file, do './clukcs_parser < input-file'

## Program Design
Program consists of three main parts: lexical analyzer, parser, and tree_node structure

### Lexical analyzer
- Sets the regular expression rule/match for each token type
- Returns the correct token_type based on the regex match

### Parser
- Productions are written for a subset of the CLUKCS language
- Ambiguity is solved by declaring precedence levels at the top of the file with Bison's %left, %right, and %precedence options 
- Parser gracefully handles syntax errors
    - Recovers by synchronizing at the next semicolon
    - An error message is printed to inform the user
    - A tree node is be created to represent the error
- Unrecognized characters are ignored
    - Can potentially cause error that is handled gracefully
- **int main()** 
    - Handles parsing of input
- **void yyerror(const char msg)**
    - Prints out error message mentioned above

### tree_node
- Class that creates and maintains a tree structure in order to print a parse tree
- Code mostly same from example provided by Dr. Moore
    - Has been edited to include line and column numbers as part of the output/label for nodes
        
### Additional Files
- **global.h**
    - Helps link lexer to parser
    - Where column and line number variables are declared

## Bugs/limitations
- Column number for errors in parse tree match synchronizing semicolon's column number and not beginning of error token