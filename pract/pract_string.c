#include <stdio.h>
#include <ctype.h>

void transform_string(char *str) {
    if (str == NULL) {
        return;
    }

    for (int i = 0; str[i] != '\0'; i++) {
        if (!isalpha((unsigned char) str[i])) {
            continue;
        }
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
    printf("Transformed string: %s\n\n", str);

    char str2[] = "Hello, world! 123456!@#$%^&*()_+";
    printf("Original string: %s\n", str2);
    transform_string(str2);
    printf("Transformed string: %s\n\n", str2);

    char *str3 = NULL;
    printf("Original string: %s\n", str3);
    transform_string(str3);
    printf("Transformed string: %s\n", str3);
}
