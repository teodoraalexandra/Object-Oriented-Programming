#include <stdio.h>

int main() {
    char a;

    printf("Hello, World!\n");

    printf("Please enter a value: ");

    scanf("%s", &a);
    printf("You entered: %s\n", &a);

    return 0;
}
