#include <stdio.h>
#include <ctype.h>

void transform_string(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if ((i + 1) % 2 == 1) {
            str[i] = toupper((unsigned char) str[i]);
        }
        else {
            str[i] = tolower((unsigned char) str[i]);
        }
    }
}

int main() {
    char str[] = "Hello, world!";
    printf("Original string: %s\n", str);
    transform_string(str);
    printf("Transformed string: %s\n", str);
}
