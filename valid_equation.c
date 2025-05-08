#include <stdio.h>

int main() {
    float a, b, c, x;

    // Input values
    printf("Equation format: ax + b = c\n");
    printf("Enter a: ");
    scanf("%f", &a);
    printf("Enter b: ");
    scanf("%f", &b);
    printf("Enter c: ");
    scanf("%f", &c);

    if (a == 0) {
        if (b == c) {
            printf("The equation is always true (infinite solutions).\n");
        } else {
            printf("No solution exists (unsolvable equation).\n");
        }
    } else {
        x = (c - b) / a;
        printf("The equation is solvable. x = %.2f\n", x);
    }

    return 0;
}
