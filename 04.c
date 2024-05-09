#include <stdio.h>

void encrypt(char message[], int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' + shift) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' + shift) % 26 + 'a';
        }

        message[i] = ch;
    }
}

void decrypt(char message[], int shift) {
    for (int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];

        if (ch >= 'A' && ch <= 'Z') {
            ch = (ch - 'A' - shift + 26) % 26 + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = (ch - 'a' - shift + 26) % 26 + 'a';
        }

        message[i] = ch;
    }
}

int main() {
    char message[100];
    int shift;

    // Input message and shift value
    printf("Enter message: ");
    scanf("%s", message); // Read a string without spaces
    printf("Enter shift value: ");
    scanf("%d", &shift);

    // Encryption
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);

    // Decryption
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);

    return 0;
}
