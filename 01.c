#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "010010";
    char result[strlen(str) + 1]; // +1 for null terminator
    int i, len;

    len = strlen(str);
    for (i = 0; i < len; i++) {
        result[i] = str[i] ^ 1; // XOR with 1 to swap 0 and 1
        printf("%c", result[i]);
    }
    result[len] = '\0'; // Adding null terminator to the result string
    printf("\n");

    return 0;
}

/*
Input (sample string): "010010"

Output: "101101"

*/
