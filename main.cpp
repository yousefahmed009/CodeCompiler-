#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 32

int isKeyword(char *buffer) {
    char keywords[MAX_KEYWORDS][10] = {"auto", "break", "case", "char", "const", "continue", "default",
                                       "do", "double", "else", "enum", "extern", "float", "for", "goto",
                                       "if", "int", "long", "register", "return", "short", "signed",
                                       "sizeof", "static", "struct", "switch", "typedef", "union",
                                       "unsigned", "void", "volatile", "while"};

    for (int i = 0; i < MAX_KEYWORDS; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            return 1;
        }
    }

    return 0;
}

int main() {
    char ch, buffer[15];
    int j = 0;

    printf("Enter Your operation (press Ctrl+D on a new line to end input):\n");

    while ((ch = getchar()) != EOF) {
        if (isalnum(ch) || ch == '_') {
            buffer[j++] = ch;
        } else if (j != 0) {
            buffer[j] = '\0';
            j = 0;

            if (isKeyword(buffer)) {
                printf("Keyword: %s\n", buffer);
            } else {
                printf("Identifier: %s\n", buffer);
            }
        }

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' || ch == '&' || ch == '|') {
            printf("Operator: %c\n", ch);
        }

        if (isdigit(ch)) {
            printf("Numerical Value: %c", ch);

            while ((ch = getchar()) != EOF && isdigit(ch)) {
                printf("%c", ch);
            }

            printf("\n");
        }
    }

    return 0;
}
