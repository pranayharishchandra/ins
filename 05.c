#include <stdio.h>
#include <string.h>

#define MATRIX_SIZE 3
#define ALPHABET_SIZE 26

// Function to encrypt the plain text using matrix 'a'
void encrypt(unsigned int plaintext[], unsigned int encrypted[], unsigned int matrix_a[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j, t;

    // Encrypt the plain text using matrix 'a'
    for (i = 0; i < MATRIX_SIZE; i++) {
        t = 0;
        for (j = 0; j < MATRIX_SIZE; j++) {
            t += matrix_a[i][j] * plaintext[j];
        }
        encrypted[i] = t % ALPHABET_SIZE;
    }
}

// Function to decrypt the encrypted text using matrix 'b'
void decrypt(unsigned int encrypted[], unsigned int decrypted[], unsigned int matrix_b[MATRIX_SIZE][MATRIX_SIZE]) {
    int i, j, t;

    // Decrypt the encrypted text using matrix 'b'
    for (i = 0; i < MATRIX_SIZE; i++) {
        t = 0;
        for (j = 0; j < MATRIX_SIZE; j++) {
            t += matrix_b[i][j] * encrypted[j];
        }
        decrypted[i] = t % ALPHABET_SIZE;
    }
}

int main() {
    unsigned int matrix_a[MATRIX_SIZE][MATRIX_SIZE] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    unsigned int matrix_b[MATRIX_SIZE][MATRIX_SIZE] = {{8, 5, 10}, {21, 8, 21},  {21, 12, 8}};
    unsigned int plaintext[MATRIX_SIZE] = {0};
    unsigned int encrypted[MATRIX_SIZE] = {0};
    unsigned int decrypted[MATRIX_SIZE] = {0};
    char msg[20];
    int i;

    // Prompt the user to enter plain text
    printf("Enter plain text: ");
    scanf("%s", msg);

    // Convert characters to integers
    for (i = 0; i < strlen(msg); i++) {
        plaintext[i] = msg[i] - 'A';
    }

    // Encrypt the plain text
    encrypt(plaintext, encrypted, matrix_a);

    // Print the encrypted cipher text
    printf("\nEncrypted Cipher Text:");
    for (i = 0; i < MATRIX_SIZE; i++) {
        printf(" %c", encrypted[i] + 'A');
    }

    // Decrypt the encrypted cipher text
    decrypt(encrypted, decrypted, matrix_b);

    // Print the decrypted plain text
    printf("\nDecrypted Plain Text:");
    for (i = 0; i < MATRIX_SIZE; i++) {
        printf(" %c", decrypted[i] + 'A');
    }

    return 0;
}
