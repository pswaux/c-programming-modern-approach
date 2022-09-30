# C Programming: A Modern Approach 2nd Edition

<p align="center">
   <img src="https://user-images.githubusercontent.com/24891489/163218014-ca60a738-ea95-47d1-b9e7-998f1c2d5c0d.jpg" />
</p>


This repository contains my own solutions to programming projects (not exercises) in this book. 
Because of the Chapters 14, 18, and 24 don't have the programming projects, those chapters have been skipped.

My system is 64-bit Fedora-35 running GCC 11.3.1. I used Vim as an editor and CLI to compile programs.

Disclaimer: I don't have a degree from any computer or related fields. I'm not even a professional programmer.
            Beware that if you want to use my codes. :)

## Some compiler commands
```bash
  $ gcc foo.c -o foo
  $ gcc -std=c99 foo.c -o foo    // for C99
  $ gcc -Wall -g foo.c -o foo    // all warnings enabled and debug information generated
  $ gcc src/foo.c -o bin/foo     // separate source codes and binaries
```

Also I've added a Makefile into each chapter.
## Usage
```bash
  $ make             // builds all files
  $ make p8_01 p8_04 // builds file(s) individually
  $ make clean       // cleans all executables
```

## Table of Contents
* Chapter 1 - Introducing C
   * History of C
   * Strengths and Weaknesses of C
* [Chapter 2 - C Fundamentals](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/02)
   * Writing a Simple Program
   * The General Form of a Simple Program
   * Comments
   * Variables and Assignment
   * Reading Input
   * Defining Names for Constants
   * Identifiers
   * Layout of a C Program
* [Chapter 3 - Formatted Input/Output](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/03)
   * The printf Function
   * The scanf Function
* [Chapter 4 - Expressions](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/04)
   * Arithmetic Operators
   * Assignment Operators
   * Increment and Decrement Operators
   * Expression Evaluation
   * Expression Statements
* [Chapter 5 - Selection Statements](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/05)
   * Logical Expressions
   * The if Statement
   * The switch Statement
* [Chapter 6 - Loops](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/06)
   * The while Statement
   * The do Statement
   * The for Statement
   * Exiting from a Loop
* [Chapter 7 - Basic Types](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/07)
   * Integer Types
   * Floating Types
   * Character Types
   * Type Conversion
   * Type Definitions
   * The sizeof Operator
* [Chapter 8 - Arrays](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/08)
   * One-Dimensional Arrays
   * Multidimensional Arrays
   * Variable-Length Arrays (C99)
* [Chapter 9 - Functions](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/09)
   * Defining and Calling Functions
   * Function Declarations
   * Arguments
   * The return Statement
   * Program Termination
   * Recursion
* [Chapter 10 - Program Organization](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/10)
   * Local Variables
   * External Variables
   * Blocks
   * Scope
   * Organizing a C Program
* [Chapter 11 - Pointers](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/11)
   * Pointer Variables
   * The Address and Indirection Operators
   * Pointer Assignment
   * Pointers as Arguments
   * Pointers as Return Values
* [Chapter 12 - Pointers and Arrays](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/12)
   * Pointer Arithmetic
   * Using Pointers for Array Processing
   * Using an Array Name as a Pointer
   * Pointers and Multidimensional Arrays
   * Pointers and Variable-Length Arrays (C99)
* [Chapter 13 - Strings](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/13)
   * String Literals
   * String Variables
   * Reading and Writing Strings
   * Accessing the Characters in a String
   * Using the C String Library
   * String Idioms
   * Arrays of Strings
* [Chapter 14 - The Preprocessor (skipped)](https://github.com/pswaux/c-programming-modern-approach/tree/main/Projects/14)
   * How the Preprocessor Works
   * Preprocessing Directives
   * Macro Definitions
   * Conditional Compilation
   * Miscellaneous Directives
* Chapter 15 - Writing Large Programs
   * Source Files
   * Header Files
   * Dividing a Program into Files
   * Building a Multiple-File Program
* Chapter 16 - Structures, Unions, and Enumerations
   * Structure Variables
   * Structure Types
   * Nested Arrays and Structures
   * Unions
   * Enumerations
* Chapter 17 - Advanced Uses of Pointers
   * Dynamic Storage Allocation
   * Dynamically Allocated Strings
   * Dynamically Allocated Arrays
   * Deallocating Storage
   * Linked Lists
   * Pointers to Pointers
   * Pointers to Functions
   * Restricted Pointers (C99)
   * Flexible Array Members (C99)
* Chapter 18 - Declerations (skipped)
   * Declaration Syntax
   * Storage Classes
   * Type Qualifiers
   * Declarators
   * Initializers
   * Inline Functions (C99)
* Chapter 19 - Program Design
   * Modules
   * Information Hiding
   * Abstract Data Types
   * A Stack Abstract Data Type
   * Design Issues for Abstract Data Types
* Chapter 20 - Low-Level Programming
   * Bitwise Operators
   * Bit-Fields in Structures
   * Other Low-Level Techniques
* Chapter 21 - The Standard Library
   * Using the Library
   * C89 Library Overview
   * C99 Library Changes
   * The <stddef.h> Header: Common Definitions
   * The <stdbool.h> Header (C99): Boolean Type and Values
* Chapter 22 - Input/Output
   * Streams
   * File Operations
   * Formatted I/O
   * Character I/O
   * Line I/O
   * Block I/O
   * File Positioning
   * String I/O
* Chapter 23 - Library Support for Numbers and Characters
   * The <float.h> Header: Characteristics of Floating Types
   * The <limits.h> Header: Sizes of Integer Types
   * The <math.h> Header (C89): Mathematics
   * The <math.h> Header (C99): Mathematics
   * The <ctype.h> Header: Character Handling
   * The <string.h> Header: String Handling
* Chapter 24 - Error Handling (skipped)
   * The <assert.h> Header: Diagnostics
   * The <errno.h> Header: Errors
   * The <signal.h> Header: Signal Handling
   * The <setjmp.h> Header: Nonlocal Jumps
* Chapter 25 - International Features
   * The <locale.h> Header: Localization
   * Multibyte Characters and Wide Characters
   * Digraphs and Trigraphs
   * Universal Character Names (C99)
   * The <wchar.h> Header (C99): Extended Multibyte and Wide-Character Utilities
   * The <wctype.h> Header (C99): Wide-Character
* Chapter 26 - Miscellaneous Library Functions
   * The <stdarg.h> Header: Variable Arguments
   * The <stdlib.h> Header: General Utilities
   * The <time.h> Header: Date and Time
* Chapter 27 - Additional C99 Support for Mathematics
   * The <stdint.h> Header (C99): Integer Types
   * The <inttypes.h> Header (C99): Format Conversion of Integer Types
   * Complex Numbers (C99)
   * The <complex.h> Header (C99): Complex Arithmetic
   * The <tgmath.h> Header (C99): Type-Generic Math
   * The <fenv.h> Header (C99): Floating-Point Environment
