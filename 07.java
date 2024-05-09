#include <stdio.h>

// Function to calculate (base^exp) % mod
int power(int base, int exp, int mod) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result = (result * base) % mod;
    }
    return result;
}

// Function to perform RSA encryption
int encrypt(int plaintext, int e, int n) {
    return power(plaintext, e, n);
}

// Function to perform RSA decryption
int decrypt(int ciphertext, int d, int n) {
    return power(ciphertext, d, n);
}

int main() {
    // Public and private keys
    int p = 61; // Prime number
    int q = 53; // Prime number
    int n = p * q; // Modulus
    int phi = (p - 1) * (q - 1); // Euler's totient function

    // Public exponent (commonly used value)
    int e = 17;

    // Private exponent
    int d;
    for (d = 1; d < phi; d++) {
        if ((d * e) % phi == 1) {
            break;
        }
    }

    // Plaintext message
    int plaintext = 123;

    // Encryption
    int ciphertext = encrypt(plaintext, e, n);
    printf("Encrypted ciphertext: %d\n", ciphertext);

    // Decryption
    int decrypted_plaintext = decrypt(ciphertext, d, n);
    printf("Decrypted plaintext: %d\n", decrypted_plaintext);

    return 0;
}

// ============================================================================================
import java.util.Scanner;

public class RSAExample {

    static int mult(int x, int y, int n) {
        int k = 1;
        int j;
        for (j = 1; j <= y; j++) 
            k = (k * x) % n;
        return k;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter two prime numbers p and q:");
        int p = scanner.nextInt();
        int q = scanner.nextInt();
        int n = p * q;
        int Z = (p - 1) * (q - 1);

        System.out.println("Enter the value of e (must be coprime with Z):");
        int e = scanner.nextInt();

        int d;
        for (d = 1; d < Z; ++d)
            if (((e * d) % Z) == 1)
                break;

        System.out.println("p = " + p + "\tq = " + q + "\tn = " + n + "\tZ = " + Z + "\te = " + e + "\td = " + d);

        System.out.println("Enter the message:");
        String message = scanner.next();

        int[] pt = new int[message.length()];
        int[] ct = new int[message.length()];

        for (int i = 0; i < message.length(); i++)
            pt[i] = message.charAt(i);

        System.out.println("Cipher Text:");
        for (int i = 0; i < message.length(); i++) {
            ct[i] = mult(pt[i], e, n);
            System.out.print("\t" + ct[i]);
        }
        System.out.println("\nDecrypted Plain Text:");
        for (int i = 0; i < message.length(); i++) {
            pt[i] = mult(ct[i], d, n);
            System.out.print((char) pt[i]);
        }

        scanner.close();
    }
}


/*
3 11 
7
*/
import java.util.*;
import java.io.*;
class rsa
{
static int mult(int x,int y,int n)
{
int k=1;
int j;
for (j=1; j<=y; j++) 
k = (k * x) % n;
return ( int) k;
}
public static void main (String arg[])throws Exception
{
Scanner s=new Scanner(System.in);
InputStreamReader r=new InputStreamReader(System.in);
BufferedReader br=new BufferedReader(r);
String msg1;
int pt[]=new int[100];
int ct[]=new int[100];
int a,b, n, d, e,Z, p, q, i,temp,et;
System.out.println("Enter prime No.s p,q :");
p=s.nextInt();
q=s.nextInt();
n = p*q;
Z=(p-1)*(q-1);
System.out.println("\nSelect e value:");
e=s.nextInt();
System.out.printf("Enter message : ");
msg1=br.readLine();
char msg[]=msg1.toCharArray();
for(i=0;i<msg.length;i++)
pt[i]=msg[i];
for(d=1;d<Z;++d)
if(((e*d)%Z)==1) break;
System.out.println("p="+""+p+"\tq="+q+"\tn="+n+"\tz="+Z+"\te="+e+"\td="+d);
System.out.println("\nCipher Text = ");
for(i=0; i<msg.length; i++)
ct[i] = mult(pt[i], e,n);
for(i=0; i<msg.length; i++)
System.out.print("\t"+ct[i]);
System.out.println("\nPlain Text = ");
for(i=0; i<msg.length; i++)
pt[i] = mult(ct[i], d,n) ;
for(i=0; i<msg.length; i++)
System.out.print((char)pt[i]);
}
}

/*
Key Generation Algorithm
1. Generate two large random primes, p and q, of approximately equal size such that their product n = p*q 
2. Compute n = p*q and Euler‘s totient function (φ) phi(n) = (p-1)(q-1). 
3. Choose an integer e, 1 < e < phi, such that gcd(e, phi) = 1. 
4. Compute the secret exponent d, 1 < d < phi, such that e*d ≡ 1 (mod phi). 
5. The public key is (e, n) and the private key is (d, n). The values of p, q, and phi should also be kept secret. 

Encryption 
Sender A does the following:- 
1. Using the public key (e,n) 
2. Represents the plaintext message as a positive integer M 
3. Computes the cipher text C = M^e mod n. 4. Sends the cipher text C to B (Receiver). 

Decryption 
Recipient B does the following:- 
1. Uses his private key (d, n) to compute M = C^d mod n. 
2. Extracts the plaintext from the integer representative m.

*/
