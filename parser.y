%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Forward declarations for yylval. These will be used by the lexer. */
int yylval_int;
char* yylval_str;

int yylex(void);
void yyerror(const char *s);

/* We could build an AST or parse tree structures here.
   For simplicity, we're just going to parse and print success/failure. */
%}

/* Inform Bison that we expect one shift/reduce conflict due to the dangling else problem */
%expect 1

/* Define the semantic value types */
%union {
    int intval;
    char* strval;
}

/* Declare tokens to Bison. These must match the names used in the lexer. */
%token IDENTIFIER_TOKEN
%token INT_LITERAL_TOKEN
%token IF_TOKEN
%token FUNCTION_TOKEN
%token ELSE_TOKEN
%token FOR_TOKEN
%token RETURN_TOKEN
%token TRUE_TOKEN
%token FALSE_TOKEN
%token PLUS_TOKEN
%token MINUS_TOKEN
%token MULTIPLY_TOKEN
%token DIVIDE_TOKEN
%token MODULO_TOKEN
%token INCREMENT_TOKEN
%token DECREMENT_TOKEN
%token ASSIGN_TOKEN
%token EQUAL_TOKEN
%token NOT_EQUAL_TOKEN
%token LESS_TOKEN
%token LESS_EQUAL_TOKEN
%token GREATER_TOKEN
%token GREATER_EQUAL_TOKEN
%token AND_TOKEN
%token OR_TOKEN
%token LEFT_PAREN_TOKEN
%token RIGHT_PAREN_TOKEN
%token LEFT_BRACE_TOKEN
%token RIGHT_BRACE_TOKEN
%token SEMICOLON_TOKEN
%token COMMA_TOKEN

/* Precedence & associativity */
%right ASSIGN_TOKEN             /* Lowest precedence */
%left OR_TOKEN
%left AND_TOKEN
%left EQUAL_TOKEN NOT_EQUAL_TOKEN
%left LESS_TOKEN LESS_EQUAL_TOKEN GREATER_TOKEN GREATER_EQUAL_TOKEN
%left PLUS_TOKEN MINUS_TOKEN
%left MULTIPLY_TOKEN DIVIDE_TOKEN MODULO_TOKEN
%right UMINUS /* unary minus has right associativity */
%right INCREMENT_TOKEN DECREMENT_TOKEN

/* The start rule: a program with one or more function definitions */
%%
Program:
    FunctionDefinitionList
    ;

FunctionDefinitionList:
    FunctionDefinitionList FunctionDefinition
    | FunctionDefinition
    ;

/* function name(args) { statements } */
FunctionDefinition:
      FUNCTION_TOKEN IDENTIFIER_TOKEN LEFT_PAREN_TOKEN ParamListOpt RIGHT_PAREN_TOKEN LEFT_BRACE_TOKEN StatementList RIGHT_BRACE_TOKEN
    ;

ParamListOpt:
    /* empty */
    | ParamList
    ;

ParamList:
    IDENTIFIER_TOKEN
    | ParamList COMMA_TOKEN IDENTIFIER_TOKEN
    ;

/* Zero or more statements */
StatementList:
    /* empty */
    | StatementList Statement
    ;

/* Different possible statements */
Statement:
      ExpressionStatement
    | IfStatement
    | ForStatement
    | ReturnStatement
    | Block
    ;

/* { StatementList } */
Block:
    LEFT_BRACE_TOKEN StatementList RIGHT_BRACE_TOKEN
    ;

ExpressionStatement:
      Expression SEMICOLON_TOKEN
    | SEMICOLON_TOKEN  /* an empty statement */
    ;

IfStatement:
    IF_TOKEN LEFT_PAREN_TOKEN Expression RIGHT_PAREN_TOKEN Statement ElseOpt
    ;

ElseOpt:
    /* empty */
    | ELSE_TOKEN Statement
    ;

/* for (init; condition; step) statement */
ForStatement:
    FOR_TOKEN LEFT_PAREN_TOKEN ForInit ForCondition ForStep RIGHT_PAREN_TOKEN Statement
    ;

ForInit:
    ExpressionStatement
    ;

ForCondition:
    ExpressionStatement
    ;

ForStep:
    /* empty */
    | Expression
    ;

/* return expression?; */
ReturnStatement:
    RETURN_TOKEN ExpressionOpt SEMICOLON_TOKEN
    ;

ExpressionOpt:
    /* empty */
    | Expression
    ;

/* Expression grammar (very simplified) */
Expression:
    AssignmentExpression
    ;

/* Assignment or logical-or expression */
AssignmentExpression:
      IDENTIFIER_TOKEN ASSIGN_TOKEN Expression
    | LogicalOrExpression
    ;

/* Logical OR (||) */
LogicalOrExpression:
    LogicalOrExpression OR_TOKEN LogicalAndExpression
    | LogicalAndExpression
    ;

/* Logical AND (&&) */
LogicalAndExpression:
    LogicalAndExpression AND_TOKEN EqualityExpression
    | EqualityExpression
    ;

/* == and != */
EqualityExpression:
    EqualityExpression EQUAL_TOKEN RelationalExpression
    | EqualityExpression NOT_EQUAL_TOKEN RelationalExpression
    | RelationalExpression
    ;

/* <, <=, >, >= */
RelationalExpression:
    RelationalExpression LESS_TOKEN AdditiveExpression
    | RelationalExpression LESS_EQUAL_TOKEN AdditiveExpression
    | RelationalExpression GREATER_TOKEN AdditiveExpression
    | RelationalExpression GREATER_EQUAL_TOKEN AdditiveExpression
    | AdditiveExpression
    ;

/* +, - */
AdditiveExpression:
    AdditiveExpression PLUS_TOKEN MultiplicativeExpression
    | AdditiveExpression MINUS_TOKEN MultiplicativeExpression
    | MultiplicativeExpression
    ;

/* *, /, % */
MultiplicativeExpression:
    MultiplicativeExpression MULTIPLY_TOKEN UnaryExpression
    | MultiplicativeExpression DIVIDE_TOKEN UnaryExpression
    | MultiplicativeExpression MODULO_TOKEN UnaryExpression
    | UnaryExpression
    ;

/* unary operators: -, ++, -- */
UnaryExpression:
      MINUS_TOKEN UnaryExpression   %prec UMINUS
    | INCREMENT_TOKEN UnaryExpression
    | DECREMENT_TOKEN UnaryExpression
    | PostfixExpression
    ;

/* postfix operators: ++, --, or function call ( ) */
PostfixExpression:
    PrimaryExpression
    | PostfixExpression INCREMENT_TOKEN
    | PostfixExpression DECREMENT_TOKEN
    | PostfixExpression LEFT_PAREN_TOKEN ArgumentListOpt RIGHT_PAREN_TOKEN
    ;

/* optional arguments in a function call */
ArgumentListOpt:
    /* empty */
    | ArgumentList
    ;

ArgumentList:
    Expression
    | ArgumentList COMMA_TOKEN Expression
    ;

PrimaryExpression:
    IDENTIFIER_TOKEN
    | INT_LITERAL_TOKEN
    | TRUE_TOKEN
    | FALSE_TOKEN
    | LEFT_PAREN_TOKEN Expression RIGHT_PAREN_TOKEN
    ;

%%

/* Error-handling */
void yyerror(const char *s) {
    fprintf(stderr, "Parser Error: %s\n", s);
}
