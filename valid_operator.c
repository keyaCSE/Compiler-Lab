#include <stdio.h>
#include <string.h>

int main() {
    char op[3];

    printf("Enter an operator (max 2 characters): ");
    scanf("%s", op);

    switch(op[0]) {
        case '+':
        case '-':
        case '*':
        case '/':
        case '%':
            if (op[1] == '\0')
                printf("Valid arithmetic operator\n");
            else
                printf("Invalid operator\n");
            break;

        case '=':
            if (op[1] == '=')
                printf("Valid relational operator (==)\n");
            else if (op[1] == '\0')
                printf("Valid assignment operator (=)\n");
            else
                printf("Invalid operator\n");
            break;

        case '!':
            if (op[1] == '=')
                printf("Valid relational operator (!=)\n");
            else if (op[1] == '\0')
                printf("Valid logical operator (!)\n");
            else
                printf("Invalid operator\n");
            break;

        case '>':
        case '<':
            if (op[1] == '=')
                printf("Valid relational operator (%c=)\n", op[0]);
            else if (op[1] == '\0')
                printf("Valid relational operator (%c)\n", op[0]);
            else
                printf("Invalid operator\n");
            break;

        case '&':
            if (op[1] == '&')
                printf("Valid logical operator (&&)\n");
            else
                printf("Invalid operator\n");
            break;

        case '|':
            if (op[1] == '|')
                printf("Valid logical operator (||)\n");
            else
                printf("Invalid operator\n");
            break;

        default:
            printf("Invalid operator\n");
    }

    return 0;
}
