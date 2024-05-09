#include <stdio.h>

// Function to calculate (base^exp) % mod
int power(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp / 2;
        base = (base * base) % mod;
    }
    return result;
}

// Function to perform Diffie-Hellman key exchange
void diffieHellman(int p, int g, int a, int b) {
    // Calculate public keys
    int A = power(g, a, p); // Alice's public key
    int B = power(g, b, p); // Bob's public key

    // Shared secret key
    int secretKey_Alice = power(B, a, p); // Calculated by Alice
    int secretKey_Bob = power(A, b, p);   // Calculated by Bob

    // Both should have the same secret key
    printf("Shared Secret Key (by Alice): %d\n", secretKey_Alice);
    printf("Shared Secret Key (by Bob): %d\n", secretKey_Bob);
}

int main() {
    // Publicly agreed upon prime number and primitive root
    int p = 23; // Prime number
    int g = 5;  // Primitive root

    // Alice's private key
    int a = 6; // Chosen by Alice

    // Bob's private key
    int b = 15; // Chosen by Bob

    // Perform Diffie-Hellman key exchange
    diffieHellman(p, g, a, b);

    return 0;
}
