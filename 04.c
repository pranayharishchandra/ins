#include <stdio.h>

int main() {
    char message[100];
    int shift;

    // Input message and shift value
    printf("Enter message: ");
    scanf("%s", message); // Read a string without spaces
    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Encryption
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }

        message[i] = ch;
    }

    // Output the encrypted message
    printf("Encrypted message: %s\n", message);

    return 0;
}
