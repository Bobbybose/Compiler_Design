# CS541 Program 1 - Lexical Analyzer
## Description
**Author:** Bobby Bose

**Final Version Date:** January 26, 2023

**Course:** CS541 - Compiler Design

**Assignment:** Program 1 - Lexicial Analyzer

- This is a lexical analyzer designed to read in input and separate it into tokens

- Code for program is based off of Dr. Moore's example

- Makefile is also written based off of Dr. Moore's example

- A set of tests is included in /tests in order to test different possibilities for every token type

## Citations
**[Flex Manual](https://westes.github.io/flex/manual/)**

**[Regex Guide](https://cheatography.com/davechild/cheat-sheets/regular-expressions/)**

## Package Requirments
No external packages required beyond Flex.

[iostream](https://en.cppreference.com/w/cpp/header/iostream) and [string](https://en.cppreference.com/w/cpp/string) from C++ standard library are required. 

## How to Build
To build, run 'make' or 'make all'

'make clean' will remove executable and .cc file

## How to Run
To run without input file, do './lexical_analyzer'

To run with input file, do './lexical_analyzer < input-file'

## Program Design
Program consists of three main parts: declarations section, rules section, and user code section.

### Declarations section
- Libraries for program are included here (iostream and string)
- Enumerator for Token is declared with all token types possible
- Necessary Flex options are set
- Common patterns for rules are declared

### Rules section
- Sets the regular expression rule/match for each token type
- Returns the correct token_type based on the regex match

### User code section
- Program uses namespace std
- Two functions are present in this section:
    - **string token_name(int tok)**
        - Function is just a big switch statement
        - Takes in the current token being looked at and returns it's string value representation
    - **int main()**
        - Main function of the program
        - Handles overall execution flow
        - Reads in next token from standard input and then prints it out to standard output with the associated line and column number
            - If token is an identifier, integer literal, floating point literal, character literal, or string literal, then the lexeme is also printed out
        - Memory is freed up at end of execution to prevent memory leaks
        

## Bugs/limitations
No bugs currently present in code