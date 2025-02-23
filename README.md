# Alan Compiler

**A compiler for the Alan programming language, implemented in C++ using Flex and Bison.**  
Supports **lexical, syntax, and semantic analysis**, generating an **AST** for the Alan language.

Developer: Papanikolaou Ariadni
Developed for the "Compilers" course of the National Technical University of Athens.

---

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Alan Language Overview](#alan-language-overview)

---

## Introduction
The Alan compiler is designed to analyze and compile programs written in the Alan programming language.  
It performs **lexical analysis**, **parsing**, **AST construction**, and **semantic analysis**, making it a full-fledged front-end compiler.

---

## Features
✔ **Lexical Analysis:** Tokenizing Alan source code using Flex  
✔ **Syntax Analysis:** Parsing Alan programs using Bison  
✔ **Abstract Syntax Tree (AST):** Constructs an AST representation  
✔ **Semantic Analysis:** Type checking and error detection  
✔ **Modular Design:** Organized into lexer, parser, AST with semantic analysis 
✔ **Error Handling:** Detects and reports syntax and semantic errors  

---

## Installation
### Prerequisites
Ensure you have the following installed:
- **GNU Make** (`sudo apt install make`)
- **Flex** (`sudo apt install flex`)
- **Bison** (`sudo apt install bison`)
- **C++ Compiler (g++)** (`sudo apt install g++`)

### Build Instructions
Clone the repository and compile the project:

```sh
git clone https://github.com/yourusername/Alan-Compiler.git
cd Alan-Compiler
make
```
---

## Usage
### Running the Compiler
To compile and test an Alan source file:
```sh
./alanc < <input_file.alan>
```

Example:
```sh
./alanc < tests/knapsack.alan
```

If the compilation is successful, the compiler will parse the input, construct the AST, and perform semantic analysis. If any errors are detected, they will be reported.

---

## Alan Language Overview
Alan is a simple procedural programming language supporting:
- **Basic Types:** `int`, `byte`
- **Functions (`proc`)** with parameters and return types
- **Control Structures:** `if`, `while`, `return`
- **Operators:** Arithmetic (`+`, `-`, `*`, `/`, `%`), Logical (`&`, `|`, `!`), Comparison (`==`, `!=`, `<`, `>`, `<=`, `>=`)
- **Arrays & References**
- **Comments:** `-- single-line` and `(* multi-line *)`
