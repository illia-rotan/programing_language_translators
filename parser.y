%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"

/* Function implementations for node creation and manipulation */

#include <stdarg.h>

/* Function to create a new node */
Node* create_node(NodeType type, int n_children, ...) {
    Node* node = malloc(sizeof(Node));
    node->type = type;
    node->strval = NULL;
    node->intval = 0;
    node->n_children = n_children;
    node->children = malloc(sizeof(Node*) * n_children);

    va_list args;
    va_start(args, n_children);
    for (int i = 0; i < n_children; i++) {
        node->children[i] = va_arg(args, Node*);
    }
    va_end(args);

    return node;
}

/* Function to create a leaf node */
Node* create_leaf_node(NodeType type, const char* strval, int intval) {
    Node* node = malloc(sizeof(Node));
    node->type = type;
    node->strval = strval ? strdup(strval) : NULL;
    node->intval = intval;
    node->n_children = 0;
    node->children = NULL;
    return node;
}

/* Function to print the parse tree */
void print_tree(Node* node, int indent) {
    if (!node) return;

    for (int i = 0; i < indent; i++)
        printf("  ");
    switch (node->type) {
        case NODE_PROGRAM:
            printf("Program\n");
            break;
        case NODE_FUNCTION_DEFINITION:
            printf("FunctionDefinition (%s)\n", node->children[0]->strval);
            break;
        case NODE_FUNCTION_LIST:
            printf("FunctionList\n");
            break;
        case NODE_PARAM_LIST:
            printf("ParamList\n");
            break;
        case NODE_STATEMENT_LIST:
            printf("StatementList\n");
            break;
        case NODE_STATEMENT:
            printf("Statement\n");
            break;
        case NODE_EXPRESSION_STATEMENT:
            printf("ExpressionStatement\n");
            break;
        case NODE_IF_STATEMENT:
            printf("IfStatement\n");
            break;
        case NODE_ELSE_STATEMENT:
            printf("ElseStatement\n");
            break;
        case NODE_FOR_STATEMENT:
            printf("ForStatement\n");
            break;
        case NODE_RETURN_STATEMENT:
            printf("ReturnStatement\n");
            break;
        case NODE_EXPRESSION:
            printf("Expression\n");
            break;
        case NODE_ASSIGNMENT:
            printf("AssignmentExpression\n");
            break;
        case NODE_BINARY_OP:
            printf("BinaryOp (%s)\n", node->strval);
            break;
        case NODE_UNARY_OP:
            printf("UnaryOp (%s)\n", node->strval);
            break;
        case NODE_POSTFIX_EXPRESSION:
            printf("PostfixExpression\n");
            break;
        case NODE_PRIMARY_EXPRESSION:
            printf("PrimaryExpression\n");
            break;
        case NODE_IDENTIFIER:
            printf("Identifier (%s)\n", node->strval);
            break;
        case NODE_INT_LITERAL:
            printf("IntLiteral (%d)\n", node->intval);
            break;
        case NODE_BOOL_LITERAL:
            printf("BoolLiteral (%s)\n", node->intval ? "true" : "false");
            break;
        default:
            printf("Unknown Node\n");
            break;
    }
    for (int i = 0; i < node->n_children; i++) {
        print_tree(node->children[i], indent + 1);
    }
}

/* Function to free the parse tree */
void free_tree(Node* node) {
    if (!node) return;
    for (int i = 0; i < node->n_children; i++) {
        free_tree(node->children[i]);
    }
    if (node->strval) free(node->strval);
    if (node->children) free(node->children);
    free(node);
}

int yylex(void);
void yyerror(const char *s);

/* The root of the parse tree */
Node* root_node;

%}

/* Inform Bison that we expect one shift/reduce conflict due to the dangling else problem */
%expect 1

/* Define the semantic value types */
%union {
    int intval;
    char* strval;
    Node* nodeptr;
}

/* Declare tokens to Bison. These must match the names used in the lexer. */
%token <strval> IDENTIFIER_TOKEN
%token <intval> INT_LITERAL_TOKEN
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

%type <nodeptr> Program FunctionDefinitionList FunctionDefinition ParamListOpt ParamList
%type <nodeptr> StatementList Statement Block
%type <nodeptr> ExpressionStatement IfStatement ElseOpt ForStatement ForInit ForCondition ForStep
%type <nodeptr> ReturnStatement ExpressionOpt
%type <nodeptr> Expression AssignmentExpression LogicalOrExpression LogicalAndExpression EqualityExpression
%type <nodeptr> RelationalExpression AdditiveExpression MultiplicativeExpression UnaryExpression
%type <nodeptr> PostfixExpression ArgumentListOpt ArgumentList PrimaryExpression

/* The start rule: a program with one or more function definitions */
%%
Program:
    FunctionDefinitionList
    {
        root_node = create_node(NODE_PROGRAM, 1, $1);
    }
    ;

FunctionDefinitionList:
    FunctionDefinitionList FunctionDefinition
    {
        $$ = create_node(NODE_FUNCTION_LIST, 2, $1, $2);
    }
    | FunctionDefinition
    {
        $$ = create_node(NODE_FUNCTION_LIST, 1, $1);
    }
    ;

/* function name(args) { statements } */
FunctionDefinition:
      FUNCTION_TOKEN IDENTIFIER_TOKEN LEFT_PAREN_TOKEN ParamListOpt RIGHT_PAREN_TOKEN LEFT_BRACE_TOKEN StatementList RIGHT_BRACE_TOKEN
    {
        /* $2 is the function name */
        $$ = create_node(NODE_FUNCTION_DEFINITION, 3,
                         create_leaf_node(NODE_IDENTIFIER, $2, 0),
                         $4, /* Parameters */
                         $7  /* Statements */
                         );
    }
    ;

ParamListOpt:
    /* empty */
    {
        $$ = create_node(NODE_PARAM_LIST, 0);
    }
    | ParamList
    {
        $$ = $1;
    }
    ;

ParamList:
    IDENTIFIER_TOKEN
    {
        $$ = create_node(NODE_PARAM_LIST, 1, create_leaf_node(NODE_IDENTIFIER, $1, 0));
    }
    | ParamList COMMA_TOKEN IDENTIFIER_TOKEN
    {
        /* Add the new parameter to the existing list */
        Node** new_children = realloc($1->children, sizeof(Node*) * ($1->n_children + 1));
        if (!new_children) {
            yyerror("Out of memory");
            exit(1);
        }
        $1->children = new_children;
        $1->children[$1->n_children++] = create_leaf_node(NODE_IDENTIFIER, $3, 0);
        $$ = $1;
    }
    ;

/* Zero or more statements */
StatementList:
    /* empty */
    {
        $$ = create_node(NODE_STATEMENT_LIST, 0);
    }
    | StatementList Statement
    {
        /* Add the new statement to the list */
        Node** new_children = realloc($1->children, sizeof(Node*) * ($1->n_children + 1));
        if (!new_children) {
            yyerror("Out of memory");
            exit(1);
        }
        $1->children = new_children;
        $1->children[$1->n_children++] = $2;
        $$ = $1;
    }
    ;

/* Different possible statements */
Statement:
      ExpressionStatement
    {
        $$ = create_node(NODE_STATEMENT, 1, $1);
    }
    | IfStatement
    {
        $$ = create_node(NODE_STATEMENT, 1, $1);
    }
    | ForStatement
    {
        $$ = create_node(NODE_STATEMENT, 1, $1);
    }
    | ReturnStatement
    {
        $$ = create_node(NODE_STATEMENT, 1, $1);
    }
    | Block
    {
        $$ = create_node(NODE_STATEMENT, 1, $1);
    }
    ;

/* { StatementList } */
Block:
    LEFT_BRACE_TOKEN StatementList RIGHT_BRACE_TOKEN
    {
        $$ = $2;
    }
    ;

ExpressionStatement:
      Expression SEMICOLON_TOKEN
    {
        $$ = create_node(NODE_EXPRESSION_STATEMENT, 1, $1);
    }
    | SEMICOLON_TOKEN
    {
        $$ = create_node(NODE_EXPRESSION_STATEMENT, 0);
    }
    ;

IfStatement:
    IF_TOKEN LEFT_PAREN_TOKEN Expression RIGHT_PAREN_TOKEN Statement ElseOpt
    {
        if ($6)
            $$ = create_node(NODE_IF_STATEMENT, 3, $3, $5, $6);
        else
            $$ = create_node(NODE_IF_STATEMENT, 2, $3, $5);
    }
    ;

ElseOpt:
    /* empty */
    {
        $$ = NULL;
    }
    | ELSE_TOKEN Statement
    {
        $$ = create_node(NODE_ELSE_STATEMENT, 1, $2);
    }
    ;

/* for (init; condition; step) statement */
ForStatement:
    FOR_TOKEN LEFT_PAREN_TOKEN ForInit ForCondition ForStep RIGHT_PAREN_TOKEN Statement
    {
        $$ = create_node(NODE_FOR_STATEMENT, 4, $3, $4, $5, $7);
    }
    ;

ForInit:
    ExpressionStatement
    {
        $$ = $1;
    }
    ;

ForCondition:
    ExpressionStatement
    {
        $$ = $1;
    }
    ;

ForStep:
    /* empty */
    {
        $$ = NULL;
    }
    | Expression
    {
        $$ = $1;
    }
    ;

/* return expression?; */
ReturnStatement:
    RETURN_TOKEN ExpressionOpt SEMICOLON_TOKEN
    {
        if ($2)
            $$ = create_node(NODE_RETURN_STATEMENT, 1, $2);
        else
            $$ = create_node(NODE_RETURN_STATEMENT, 0);
    }
    ;

ExpressionOpt:
    /* empty */
    {
        $$ = NULL;
    }
    | Expression
    {
        $$ = $1;
    }
    ;

/* Expression grammar (very simplified) */
Expression:
    AssignmentExpression
    {
        $$ = $1;
    }
    ;

/* Assignment or logical-or expression */
AssignmentExpression:
      IDENTIFIER_TOKEN ASSIGN_TOKEN Expression
    {
        $$ = create_node(NODE_ASSIGNMENT, 2,
                         create_leaf_node(NODE_IDENTIFIER, $1, 0),
                         $3);
    }
    | LogicalOrExpression
    {
        $$ = $1;
    }
    ;

/* Logical OR (||) */
LogicalOrExpression:
    LogicalOrExpression OR_TOKEN LogicalAndExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("||");
    }
    | LogicalAndExpression
    {
        $$ = $1;
    }
    ;

/* Logical AND (&&) */
LogicalAndExpression:
    LogicalAndExpression AND_TOKEN EqualityExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("&&");
    }
    | EqualityExpression
    {
        $$ = $1;
    }
    ;

/* == and != */
EqualityExpression:
    EqualityExpression EQUAL_TOKEN RelationalExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("==");
    }
    | EqualityExpression NOT_EQUAL_TOKEN RelationalExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("!=");
    }
    | RelationalExpression
    {
        $$ = $1;
    }
    ;

/* <, <=, >, >= */
RelationalExpression:
    RelationalExpression LESS_TOKEN AdditiveExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("<");
    }
    | RelationalExpression LESS_EQUAL_TOKEN AdditiveExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("<=");
    }
    | RelationalExpression GREATER_TOKEN AdditiveExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup(">");
    }
    | RelationalExpression GREATER_EQUAL_TOKEN AdditiveExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup(">=");
    }
    | AdditiveExpression
    {
        $$ = $1;
    }
    ;

/* +, - */
AdditiveExpression:
    AdditiveExpression PLUS_TOKEN MultiplicativeExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("+");
    }
    | AdditiveExpression MINUS_TOKEN MultiplicativeExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("-");
    }
    | MultiplicativeExpression
    {
        $$ = $1;
    }
    ;

/* *, /, % */
MultiplicativeExpression:
    MultiplicativeExpression MULTIPLY_TOKEN UnaryExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("*");
    }
    | MultiplicativeExpression DIVIDE_TOKEN UnaryExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("/");
    }
    | MultiplicativeExpression MODULO_TOKEN UnaryExpression
    {
        $$ = create_node(NODE_BINARY_OP, 2, $1, $3);
        $$->strval = strdup("%");
    }
    | UnaryExpression
    {
        $$ = $1;
    }
    ;

/* unary operators: -, ++, -- */
UnaryExpression:
      MINUS_TOKEN UnaryExpression   %prec UMINUS
    {
        $$ = create_node(NODE_UNARY_OP, 1, $2);
        $$->strval = strdup("-");
    }
    | INCREMENT_TOKEN UnaryExpression
    {
        $$ = create_node(NODE_UNARY_OP, 1, $2);
        $$->strval = strdup("++");
    }
    | DECREMENT_TOKEN UnaryExpression
    {
        $$ = create_node(NODE_UNARY_OP, 1, $2);
        $$->strval = strdup("--");
    }
    | PostfixExpression
    {
        $$ = $1;
    }
    ;

/* postfix operators: ++, --, or function call ( ) */
PostfixExpression:
    PrimaryExpression
    {
        $$ = $1;
    }
    | PostfixExpression INCREMENT_TOKEN
    {
        $$ = create_node(NODE_UNARY_OP, 1, $1);
        $$->strval = strdup("++");
    }
    | PostfixExpression DECREMENT_TOKEN
    {
        $$ = create_node(NODE_UNARY_OP, 1, $1);
        $$->strval = strdup("--");
    }
    | PostfixExpression LEFT_PAREN_TOKEN ArgumentListOpt RIGHT_PAREN_TOKEN
    {
        $$ = create_node(NODE_POSTFIX_EXPRESSION, 2, $1, $3);
    }
    ;

/* optional arguments in a function call */
ArgumentListOpt:
    /* empty */
    {
        $$ = create_node(NODE_EXPRESSION, 0);
    }
    | ArgumentList
    {
        $$ = $1;
    }
    ;

ArgumentList:
    Expression
    {
        $$ = create_node(NODE_EXPRESSION, 1, $1);
    }
    | ArgumentList COMMA_TOKEN Expression
    {
        /* Add the new expression to the existing list */
        Node** new_children = realloc($1->children, sizeof(Node*) * ($1->n_children + 1));
        if (!new_children) {
            yyerror("Out of memory");
            exit(1);
        }
        $1->children = new_children;
        $1->children[$1->n_children++] = $3;
        $$ = $1;
    }
    ;

PrimaryExpression:
    IDENTIFIER_TOKEN
    {
        $$ = create_leaf_node(NODE_IDENTIFIER, $1, 0);
    }
    | INT_LITERAL_TOKEN
    {
        $$ = create_leaf_node(NODE_INT_LITERAL, NULL, $1);
    }
    | TRUE_TOKEN
    {
        $$ = create_leaf_node(NODE_BOOL_LITERAL, NULL, 1);
    }
    | FALSE_TOKEN
    {
        $$ = create_leaf_node(NODE_BOOL_LITERAL, NULL, 0);
    }
    | LEFT_PAREN_TOKEN Expression RIGHT_PAREN_TOKEN
    {
        $$ = $2;
    }
    ;

%%

/* Error-handling */
void yyerror(const char *s) {
    fprintf(stderr, "Parser Error: %s\n", s);
}

/* After parsing is complete, print and free the parse tree */
int main(int argc, char **argv) {
    if (argc > 1) {
        extern FILE* yyin;
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Cannot open file: %s\n", argv[1]);
            return 1;
        }
    }
    if (yyparse() == 0) { /* Parsing succeeded */
        if (root_node) {
            printf("Parse Tree:\n");
            print_tree(root_node, 0);
            free_tree(root_node);
        }
    }
    return 0;
}