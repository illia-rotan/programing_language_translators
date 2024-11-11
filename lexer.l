%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Tokens {
    IDENTIFIER_TOKEN = 256,
    INT_LITERAL_TOKEN,
    IF_TOKEN,
    FUNCTION_TOKEN,
    ELSE_TOKEN,
    FOR_TOKEN,
    RETURN_TOKEN,
    TRUE_TOKEN,
    FALSE_TOKEN,
    PLUS_TOKEN,
    MINUS_TOKEN,
    MULTIPLY_TOKEN,
    DIVIDE_TOKEN,
    MODULO_TOKEN,
    INCREMENT_TOKEN,
    DECREMENT_TOKEN,
    ASSIGN_TOKEN,
    EQUAL_TOKEN,
    NOT_EQUAL_TOKEN,
    LESS_TOKEN,
    LESS_EQUAL_TOKEN,
    GREATER_TOKEN,
    GREATER_EQUAL_TOKEN,
    AND_TOKEN,
    OR_TOKEN,
    LEFT_PAREN_TOKEN,
    RIGHT_PAREN_TOKEN,
    LEFT_BRACE_TOKEN,
    RIGHT_BRACE_TOKEN,
    SEMICOLON_TOKEN,
    COMMA_TOKEN
};

void yyerror(const char *s);
int yylex(void);
%}

%%


[a-zA-Z_][a-zA-Z0-9_]* {
    if (strcmp(yytext, "function") == 0) {
        printf("<FUNCTION_TOKEN, 'function'>\n");
    }
    else if (strcmp(yytext, "if") == 0) {
        printf("<IF_TOKEN, 'if'>\n");
    }
    else if (strcmp(yytext, "else") == 0) {
        printf("<ELSE_TOKEN, 'else'>\n");
    }
    else if (strcmp(yytext, "for") == 0) {
        printf("<FOR_TOKEN, 'for'>\n");
    }
    else if (strcmp(yytext, "return") == 0) {
        printf("<RETURN_TOKEN, 'return'>\n");
    }
    else if (strcmp(yytext, "true") == 0) {
        printf("<TRUE_TOKEN, 'true'>\n");
    }
    else if (strcmp(yytext, "false") == 0) {
        printf("<FALSE_TOKEN, 'false'>\n");
    }
    else {
        printf("<IDENTIFIER_TOKEN, '%s'>\n", yytext);
    }
}

[0-9]+ {
    printf("<INT_LITERAL_TOKEN, '%s'>\n", yytext);
}

[0-9]+[a-zA-Z_][a-zA-Z0-9_]* {
    printf("Error: Invalid identifier '%s'\n", yytext);
}

"++" { printf("<INCREMENT_TOKEN, '++'>\n"); }
"--" { printf("<DECREMENT_TOKEN, '--'>\n"); }
"==" { printf("<EQUAL_TOKEN, '=='>\n"); }
"!=" { printf("<NOT_EQUAL_TOKEN, '!='>\n"); }
"<=" { printf("<LESS_EQUAL_TOKEN, '<='>\n"); }
">=" { printf("<GREATER_EQUAL_TOKEN, '>='>\n"); }
"&&" { printf("<AND_TOKEN, '&&'>\n"); }
"||" { printf("<OR_TOKEN, '||'>\n"); }
"="  { printf("<ASSIGN_TOKEN, '='>\n"); }
"<"  { printf("<LESS_TOKEN, '<'>\n"); }
">"  { printf("<GREATER_TOKEN, '>'>\n"); }
"+"  { printf("<PLUS_TOKEN, '+'>\n"); }
"-"  { printf("<MINUS_TOKEN, '-'>\n"); }
"*"  { printf("<MULTIPLY_TOKEN, '*'>\n"); }
"/"  { printf("<DIVIDE_TOKEN, '/'>\n"); }
"%"  { printf("<MODULO_TOKEN, '%%'>\n"); }

"\(" { printf("<LEFT_PAREN_TOKEN, '('>\n"); }
"\)" { printf("<RIGHT_PAREN_TOKEN, ')'>\n"); }
"\{" { printf("<LEFT_BRACE_TOKEN, '{'>\n"); }
"\}" { printf("<RIGHT_BRACE_TOKEN, '}'>\n"); }
";"  { printf("<SEMICOLON_TOKEN, ';'>\n"); }
","  { printf("<COMMA_TOKEN, ','>\n"); }

[ \t\r\n]+ { }

. { printf("Error: Unrecognized character '%s'\n", yytext); }

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            fprintf(stderr, "Cannot open file %s\n", argv[1]);
            exit(1);
        }
        yyin = file;
    }
    yylex();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}
