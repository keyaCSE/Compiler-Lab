#include <stdio.h>
#include <ctype.h>

int main() {
    char str[100];
    int i = 0, valid = 1;

    printf("Enter an identifier: ");
    scanf("%s", str);

    
    if (!isalpha(str[0]) && str[0] != '_') {
        valid = 0;
    }

   
    while (str[i] != '\0') {
        if (!isalnum(str[i]) && str[i] != '_') {
            valid = 0;
            break;
        }
        i++;
    }

    
    if (valid) {
        printf("Valid identifier.\n");
    } else {
        printf("Invalid identifier.\n");
    }

    return 0;
}
