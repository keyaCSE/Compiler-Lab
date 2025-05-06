#include <stdio.h>

int main() {
    char str[100];
    int i = 0, state = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    while (str[i] != '\0') {
        switch(state) {
            case 0:
                if (str[i] == 'a')
                    state = 1;
                else if (str[i] == 'b')
                    state = 3;
                else
                    state = -1;
                break;

            case 1:
                if (str[i] == 'a')
                    state = 2;
                else if (str[i] == 'b')
                    state = 3;
                else
                    state = -1;
                break;

            case 2:
                if (str[i] == 'b')
                    state = 4;
                else
                    state = -1;
                break;

            case 3:
            case 4:
                if (str[i] == 'b')
                    state = 3;
                else
                    state = -1;
                break;

            default:
                state = -1;
        }

        if (state == -1)
            break;

        i++;
    }


    if (state == 0 && i == 1 && str[0] == 'a')
        printf("String matches pattern 'a'\n");
    else if (state == 4 && str[i] == '\0')
        printf("String matches pattern 'aab'\n");
    else if ((state == 3) && str[i] == '\0')
        printf("String matches pattern 'a*b+'\n");
    else
        printf("String does NOT match any pattern\n");

    return 0;
}

