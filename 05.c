#include <stdio.h>

#define MATRIX_SIZE 3
#define ALPHABET_SIZE 26

void multiply(int a[MATRIX_SIZE][MATRIX_SIZE], int b[MATRIX_SIZE], int result[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        result[i] = 0;
        for (int j = 0; j < MATRIX_SIZE; j++) {
            result[i] += a[i][j] * b[j];
        }
        result[i] %= ALPHABET_SIZE;
    }
}

int main() {
    int key_a[MATRIX_SIZE][MATRIX_SIZE] = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};
    int key_b[MATRIX_SIZE][MATRIX_SIZE] = {{8, 5, 10}, {21, 8, 21}, {21, 12, 8}};
    char plaintext[20];
    int encrypted[MATRIX_SIZE] = {0}, decrypted[MATRIX_SIZE] = {0};

    printf("Enter plain text: ");
    scanf("%s", plaintext);

    for (int i = 0; plaintext[i] != '\0'; i++) plaintext[i] -= 'A';

    multiply(key_a, plaintext, encrypted);
    multiply(key_b, encrypted, decrypted);

    printf("\nEncrypted Cipher Text:");
    for (int i = 0; i < MATRIX_SIZE; i++) printf(" %c", encrypted[i] + 'A');

    printf("\nDecrypted Plain Text:");
    for (int i = 0; i < MATRIX_SIZE; i++) printf(" %c", decrypted[i] + 'A');

    return 0;
}
