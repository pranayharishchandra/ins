#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to calculate (base^exp) % mod
long long int power(long long int base, long long int exp, long long int mod) {
    long long int result = 1;
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
void diffieHellman() {
    // Publicly agreed upon prime number and primitive root
    long long int p = 23; // Prime number
    long long int g = 5;  // Primitive root

    // Alice's private key
    long long int a = rand() % p; // Randomly chosen by Alice
    printf("Alice's private key: %lld\n", a);

    // Bob's private key
    long long int b = rand() % p; // Randomly chosen by Bob
    printf("Bob's private key: %lld\n", b);

    // Calculate public keys
    long long int A = power(g, a, p); // Alice's public key
    long long int B = power(g, b, p); // Bob's public key

    // Shared secret key
    long long int secretKey_Alice = power(B, a, p); // Calculated by Alice
    long long int secretKey_Bob = power(A, b, p);   // Calculated by Bob

    // Both should have the same secret key
    printf("Shared Secret Key (by Alice): %lld\n", secretKey_Alice);
    printf("Shared Secret Key (by Bob): %lld\n", secretKey_Bob);
}

int main() {
    // Seed for random number generation
    srand(time(NULL));

    // Perform Diffie-Hellman key exchange
    diffieHellman();

    return 0;
}
