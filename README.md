# PLT Lexer

## Installation

Install the necessary tools using the following command:

```bash
brew install bison
brew install flex
```

*Note: Bison is not required for the lexer alone. It is typically used for parser generation.*

## Compile the Lexer

Generate the lexer and compile it with the following commands:
Use Bison to generate the parser implementation (`parser.tab.c`) and parser header (`parser.tab.h`):

```bash
bison -d parser.y
```

```bash
flex lexer.l
```

```bash
gcc lex.yy.c parser.tab.c -o plt_parser -ll
```

Run the Parser
```bash
./plt_parser plt_example.txt
```

---

## Syntax Analysis with Bison

If you want to extend this project to include a **parser** for syntactic analysis of PLT, follow these steps (assuming you have a grammar file named `parser.y` and a modified or separate lexer file for parsing, e.g., `lexer2.l`):



```

## Defined Tokens

Below is a comprehensive list of the tokens defined in the lexer, along with their descriptions and example lexemes. This table serves as a reference for understanding how different elements in the PLT language are tokenized.

| **Token Name**          | **Description**                                         | **Example Lexeme** |
|-------------------------|---------------------------------------------------------|---------------------|
| **IDENTIFIER_TOKEN**    | Variable or function names                              | `n`, `isPrime`     |
| **INT_LITERAL_TOKEN**   | Integer constant                                        | `0`, `1`, `2`      |
| **FUNCTION_TOKEN**      | Keyword for defining a function                         | `function`         |
| **IF_TOKEN**            | Keyword for conditional branching                       | `if`               |
| **ELSE_TOKEN**          | Keyword for alternative conditional branch              | `else`             |
| **FOR_TOKEN**           | Keyword for looping                                     | `for`              |
| **RETURN_TOKEN**        | Keyword for returning a value from a function           | `return`           |
| **TRUE_TOKEN**          | Boolean literal representing true                       | `true`             |
| **FALSE_TOKEN**         | Boolean literal representing false                      | `false`            |
| **PLUS_TOKEN**          | Arithmetic addition operator                            | `+`                |
| **MINUS_TOKEN**         | Arithmetic subtraction operator                         | `-`                |
| **MULTIPLY_TOKEN**      | Arithmetic multiplication operator                      | `*`                |
| **DIVIDE_TOKEN**        | Arithmetic division operator                            | `/`                |
| **MODULO_TOKEN**        | Arithmetic remainder operator                           | `%`                |
| **INCREMENT_TOKEN**     | Increment operator                                      | `++`               |
| **DECREMENT_TOKEN**     | Decrement operator                                      | `--`               |
| **ASSIGN_TOKEN**        | Assignment operator                                     | `=`                |
| **EQUAL_TOKEN**         | Relational equality operator                            | `==`               |
| **NOT_EQUAL_TOKEN**     | Relational inequality operator                          | `!=`               |
| **LESS_TOKEN**          | Relational less-than operator                           | `<`                |
| **LESS_EQUAL_TOKEN**    | Relational less-than-or-equal-to operator               | `<=`               |
| **GREATER_TOKEN**       | Relational greater-than operator                        | `>`                |
| **GREATER_EQUAL_TOKEN** | Relational greater-than-or-equal-to operator            | `>=`               |
| **AND_TOKEN**           | Logical AND operator                                    | `&&`               |
| **OR_TOKEN**            | Logical OR operator                                     | `||`               |
| **LEFT_PAREN_TOKEN**    | Left parenthesis used in expressions and function calls | `(`                |
| **RIGHT_PAREN_TOKEN**   | Right parenthesis used in expressions and function calls| `)`                |
| **LEFT_BRACE_TOKEN**    | Left brace marking start of block                       | `{`                |
| **RIGHT_BRACE_TOKEN**   | Right brace marking end of block                        | `}`                |
| **SEMICOLON_TOKEN**     | Semicolon used to terminate statements                  | `;`                |
| **COMMA_TOKEN**         | Comma used in argument lists                            | `,`                |

---
## Example Usage

Given a PLT source file `plt_example_error.txt` with the following content:

```
function isPrime(n) {
  if (n == 2) return true;
    else if (n<2 || n%2==0) return false;
  for (d=3; d*d <= n; d=d+2) {
    if (n%d == 0) {
      return fal@@@se;
    }
  }
}

function main() {
  1n = input_int();
  for (i=0; i<=n-1; ++i) {
    if (isPrime(i)) {
      output_int(i);
    }
  }
  return 0;
}

```

Running the lexer will produce the following output:

```
<FUNCTION_TOKEN, 'function'>
<IDENTIFIER_TOKEN, 'isPrime'>
<LEFT_PAREN_TOKEN, '('>
<IDENTIFIER_TOKEN, 'n'>
<RIGHT_PAREN_TOKEN, ')'>
<LEFT_BRACE_TOKEN, '{'>
<IF_TOKEN, 'if'>
<LEFT_PAREN_TOKEN, '('>
<IDENTIFIER_TOKEN, 'n'>
<EQUAL_TOKEN, '=='>
<INT_LITERAL_TOKEN, '2'>
<RIGHT_PAREN_TOKEN, ')'>
<RETURN_TOKEN, 'return'>
<TRUE_TOKEN, 'true'>
<SEMICOLON_TOKEN, ';'>
<ELSE_TOKEN, 'else'>
<IF_TOKEN, 'if'>
<LEFT_PAREN_TOKEN, '('>
<IDENTIFIER_TOKEN, 'n'>
<LESS_TOKEN, '<'>
<INT_LITERAL_TOKEN, '2'>
<OR_TOKEN, '||'>
<IDENTIFIER_TOKEN, 'n'>
<MODULO_TOKEN, '%'>
<INT_LITERAL_TOKEN, '2'>
<EQUAL_TOKEN, '=='>
<INT_LITERAL_TOKEN, '0'>
<RIGHT_PAREN_TOKEN, ')'>
<RETURN_TOKEN, 'return'>
<FALSE_TOKEN, 'false'>
<SEMICOLON_TOKEN, ';'>
<FOR_TOKEN, 'for'>
<LEFT_PAREN_TOKEN, '('>
<IDENTIFIER_TOKEN, 'd'>
<ASSIGN_TOKEN, '='>
<INT_LITERAL_TOKEN, '3'>
<SEMICOLON_TOKEN, ';'>
<IDENTIFIER_TOKEN, 'd'>
<MULTIPLY_TOKEN, '*'>
<IDENTIFIER_TOKEN, 'd'>
<LESS_EQUAL_TOKEN, '<='>
<IDENTIFIER_TOKEN, 'n'>
<SEMICOLON_TOKEN, ';'>
<IDENTIFIER_TOKEN, 'd'>
<ASSIGN_TOKEN, '='>
<IDENTIFIER_TOKEN, 'd'>
<PLUS_TOKEN, '+'>
<INT_LITERAL_TOKEN, '2'>
<RIGHT_PAREN_TOKEN, ')'>
<LEFT_BRACE_TOKEN, '{'>
<IF_TOKEN, 'if'>
<LEFT_PAREN_TOKEN, '('>
<IDENTIFIER_TOKEN, 'n'>
<MODULO_TOKEN, '%'>
<IDENTIFIER_TOKEN, 'd'>
<EQUAL_TOKEN, '=='>
<INT_LITERAL_TOKEN, '0'>
<RIGHT_PAREN_TOKEN, ')'>
<LEFT_BRACE_TOKEN, '{'>
<RETURN_TOKEN, 'return'>
<IDENTIFIER_TOKEN, 'fal'>
Error: Unrecognized character '@'
Error: Unrecognized character '@'
Error: Unrecognized character '@'
<IDENTIFIER_TOKEN, 'se'>
<SEMICOLON_TOKEN, ';'>
<RIGHT_BRACE_TOKEN, '}'>
<RIGHT_BRACE_TOKEN, '}'>
<RIGHT_BRACE_TOKEN, '}'>
<FUNCTION_TOKEN, 'function'>
<IDENTIFIER_TOKEN, 'main'>
<LEFT_PAREN_TOKEN, '('>
<RIGHT_PAREN_TOKEN, ')'>
<LEFT_BRACE_TOKEN, '{'>
<IDENTIFIER_TOKEN, 'n'>
<ASSIGN_TOKEN, '='>
<IDENTIFIER_TOKEN, 'input_int'>
<LEFT_PAREN_TOKEN, '('>
<RIGHT_PAREN_TOKEN, ')'>
<SEMICOLON_TOKEN, ';'>
<FOR_TOKEN, 'for'>
<LEFT_PAREN_TOKEN, '('>
<IDENTIFIER_TOKEN, 'i'>
<ASSIGN_TOKEN, '='>
<INT_LITERAL_TOKEN, '0'>
<SEMICOLON_TOKEN, ';'>
<IDENTIFIER_TOKEN, 'i'>
<LESS_EQUAL_TOKEN, '<='>
<IDENTIFIER_TOKEN, 'n'>
<MINUS_TOKEN, '-'>
<INT_LITERAL_TOKEN, '1'>
<SEMICOLON_TOKEN, ';'>
<INCREMENT_TOKEN, '++'>
<IDENTIFIER_TOKEN, 'i'>
<RIGHT_PAREN_TOKEN, ')'>
<LEFT_BRACE_TOKEN, '{'>
<IF_TOKEN, 'if'>
<LEFT_PAREN_TOKEN, '('>
<IDENTIFIER_TOKEN, 'isPrime'>
<LEFT_PAREN_TOKEN, '('>
<IDENTIFIER_TOKEN, 'i'>
<RIGHT_PAREN_TOKEN, ')'>
<RIGHT_PAREN_TOKEN, ')'>
<LEFT_BRACE_TOKEN, '{'>
<IDENTIFIER_TOKEN, 'output_int'>
<LEFT_PAREN_TOKEN, '('>
<IDENTIFIER_TOKEN, 'i'>
<RIGHT_PAREN_TOKEN, ')'>
<SEMICOLON_TOKEN, ';'>
<RIGHT_BRACE_TOKEN, '}'>
<RIGHT_BRACE_TOKEN, '}'>
<RETURN_TOKEN, 'return'>
<INT_LITERAL_TOKEN, '0'>
<SEMICOLON_TOKEN, ';'>
<RIGHT_BRACE_TOKEN, '}'>
```

*Note: The lexer correctly identifies `1n` as an invalid identifier and reports an error.*

