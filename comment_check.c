#include <stdio.h>

int main() {
    char line[100];

    printf("Enter a line of code: ");
    fgets(line, sizeof(line), stdin);


    if (line[0] == '/' && line[1] == '/') {
        printf("This is a single-line comment.\n");
    }

    else if (line[0] == '/' && line[1] == '*') {
        int i = 2;
        while (line[i] != '\0') {
            if (line[i] == '*' && line[i + 1] == '/') {
                printf("This is a multi-line comment.\n");
                return 0;
            }
            i++;
        }
        printf("This looks like the start of a multi-line comment but doesn't close.\n");
    }
    else {
        printf("This is NOT a comment.\n");
    }

    return 0;
}


