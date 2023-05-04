#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cstring>

using namespace std;

long RSA(char* m, long* ed, long n, bool Type);
void computeED(long* ed, long t);

int main() {
    // Set the file names and user-defined keys
    const char* plain_file = "plain.txt";
    const char* cipher_file = "ciphertext.txt";
    //


    // Open the plain text file
    ifstream in_file(plain_file);
    if (!in_file.is_open()) {
        cerr << "Error opening plain text file." << endl;
        return 1;
    }
    
    // Open the cipher text file
    ofstream out_file(cipher_file);
    if (!out_file.is_open()) {
        cerr << "Error opening cipher text file." << endl;
        return 1;
    }
    
    // Encrypt or decrypt the plain text file and write the result to the cipher text file
    while (in_file.good()) {
        char m[256];
        in_file.getline(m, 256);
        
        // Encrypt or decrypt the message and write the result to the output file
        long c = RSA(m, ed, n, encrypt);
        out_file << c << endl;
    }
    
    // Close the files
    in_file.close();
    out_file.close();
    
    return 0;
}

// RSA encryption and decryption function
long RSA(char* m, long* ed, long n, bool Type) {
    long c = 0;
    
    // Convert the message to a number
    long m_num = 0;
    for (int i = 0; i < strlen(m); i++) {
        m_num += (long) m[i] * pow(256, i);
    }
    
    // Encrypt or decrypt the message using the public or private key
    if (Type) {
        // Encrypt
        c = (long) fmod(pow(m_num, ed[0]), n);
    } else {
        // Decrypt
        c = (long) fmod(pow(m_num, ed[1]), n);
    }
    
    return c;
}

// Calculate the public and private keys given the parameter t=((p-1)*(q-1))
void computeED(long* ed, long t) {
    long e = 3;  // Start with a small prime number
    while (true) {
        // Calculate d
        long d = 0;
        while ((d * e) % t != 1) {
            d++;
        }
        
        // Check if d and e are valid keys
        if (d != e && d > 1 && e > 1) {
            ed[0] = e;
            ed[1] = d;
            break;
        }
        
        // Try the next prime number
        e += 2;
    }
}
