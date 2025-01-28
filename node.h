/* node.h */
#ifndef NODE_H
#define NODE_H

#include <stdarg.h>

/* Define the possible node types */
typedef enum {
    NODE_PROGRAM,
    NODE_FUNCTION_DEFINITION,
    NODE_FUNCTION_LIST,
    NODE_PARAM_LIST,
    NODE_STATEMENT_LIST,
    NODE_STATEMENT,
    NODE_EXPRESSION_STATEMENT,
    NODE_IF_STATEMENT,
    NODE_ELSE_STATEMENT,
    NODE_FOR_STATEMENT,
    NODE_RETURN_STATEMENT,
    NODE_EXPRESSION,
    NODE_ASSIGNMENT,
    NODE_BINARY_OP,
    NODE_UNARY_OP,
    NODE_POSTFIX_EXPRESSION,
    NODE_PRIMARY_EXPRESSION,
    NODE_IDENTIFIER,
    NODE_INT_LITERAL,
    NODE_BOOL_LITERAL,
    /* Add more node types as needed */
} NodeType;

/* Define the node structure */
typedef struct node {
    NodeType type;
    char*     strval;      /* For identifiers and literals */
    int       intval;      /* For integer literals */
    struct node** children;
    int       n_children;
} Node;

/* Function declarations */
Node* create_node(NodeType type, int n_children, ...);
Node* create_leaf_node(NodeType type, const char* strval, int intval);
void print_tree(Node* node, int indent);
void free_tree(Node* node);

#endif /* NODE_H */