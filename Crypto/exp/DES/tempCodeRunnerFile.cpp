#include <iostream>
#include <cstring>

using namespace std;

const int KEY_LENGTH = 8;   // 64-bit key
const int BLOCK_LENGTH = 8; // 64-bit blocks
const int ROUND_COUNT = 16; // 16 rounds of DES
const int MAX_SIZE = 1000;  // max size of input
// Tables used in DES
const int IP[] = {58, 50, 42, 34, 26, 18, 10, 2,
                  60, 52, 44, 36, 28, 20, 12, 4,
                  62, 54, 46, 38, 30, 22, 14, 6,
                  64, 56, 48, 40, 32, 24, 16, 8,
                  57, 49, 41, 33, 25, 17, 9, 1,
                  59, 51, 43, 35, 27, 19, 11, 3,
                  61, 53, 45, 37, 29, 21, 13, 5,
                  63, 55, 47, 39, 31, 23, 15, 7};

const int IP_INV[] = {40, 8, 48, 16, 56, 24, 64, 32,
                      39, 7, 47, 15, 55, 23, 63, 31,
                      38, 6, 46, 14, 54, 22, 62, 30,
                      37, 5, 45, 13, 53, 21, 61, 29,
                      36, 4, 44, 12, 52, 20, 60, 28,
                      35, 3, 43, 11, 51, 19, 59, 27,
                      34, 2, 42, 10, 50, 18, 58, 26,
                      33, 1, 41, 9, 49, 17, 57, 25};

const int E[] = {32, 1, 2, 3, 4, 5,
                 4, 5, 6, 7, 8, 9,
                 8, 9, 10, 11, 12, 13,
                 12, 13, 14, 15, 16, 17,
                 16, 17, 18, 19, 20, 21,
                 20, 21, 22, 23, 24, 25,
                 24, 25, 26, 27, 28, 29,
                 28, 29, 30, 31, 32, 1};

const int P[] = {16, 7, 20, 21, 29, 12, 28, 17,
                 1, 15, 23, 26, 5, 18, 31, 10,
                 2, 8, 24, 14, 32, 27, 3, 9,
                 19, 13, 30, 6, 22, 11, 4, 25};

const int PC1[] = {57, 49, 41, 33, 25, 17, 9,
                   1, 58, 50, 42, 34, 26, 18,
                   10, 2, 59, 51, 43, 35, 27,
                   19, 11, 3, 60, 52, 44, 36,
                   63, 55, 47, 39, 31, 23, 15,
                   7, 62, 54, 46, 38, 30, 22,
                   14, 6, 61, 53, 45, 37, 29,
                   21, 13, 5, 28, 20, 12, 4};
// subkeys
const int PC2[] = {14, 17, 11, 24, 1, 5,
                   3, 28, 15, 6, 21, 10,
                   23, 19, 12, 4, 26, 8,
                   16, 7, 27, 20, 13, 2,
                   41, 52, 31, 37, 47, 55,
                   30, 40, 51, 45, 33, 48,
                   44, 49, 39, 56, 34, 53,
                   46, 42, 50, 36, 29, 32};

const int S[8][4][16] = {
    // S1
    {
        {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
        {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
        {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
        {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}},
    // S2
    {
        {15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},
        {3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},
        {0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},
        {13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9}},
    // S3
    {
        {10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},
        {13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},
        {13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},
        {1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12}},
    // S4
    {
        {7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},
        {13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},
        {10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},
        {3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14}},
    // S5
    {
        {2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},
        {14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},
        {4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},
        {11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3}},
    // S6
    {
        {12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},
        {10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},
        {9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},
        {4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13}},
    // S7
    {
        {4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},
        {13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},
        {1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},
        {6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12}},
    // S8
    {
        {13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},
        {1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},
        {7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},
        {2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11}}};
// Function to perform permutation operation
void Transform(const bool *input, bool *output, const int *table, int table_len)
{
    for (int i = 0; i < table_len; i++)
    {
        output[i] = input[table[i] - 1];
    }
}

// Function to perform XOR operation
void Xor(bool *a, const bool *b, int len)
{
    for (int i = 0; i < len; i++)
    {
        a[i] ^= b[i];
    }
}

// Function to perform left circular shift operation
void RotateL(bool *input, int len, int offset)
{
    bool temp[MAX_SIZE];
    for (int i = 0; i < len; i++)
    {
        temp[i] = input[i];
    }
    for (int i = 0; i < len; i++)
    {
        input[i] = temp[(i + offset) % len];
    }
}

// Function to perform substitution operation
void S_func(bool *input, int len, const int (*sbox)[16], bool *output)
{
    int row = (input[0] << 1) + input[5];
    int col = (input[1] << 3) + (input[2] << 2) + (input[3] << 1) + input[4];
    int val = sbox[row][col];
    for (int i = 0; i < 4; i++)
    {
        output[i] = (val >> (3 - i)) & 1;
    }
}

// Function to perform F function
void F_func(const bool *input, const bool *subkey, bool *output)
{
    bool expanded[MAX_SIZE];
    Transform(input, expanded, E, 48);
    Xor(expanded, subkey, 48);
    bool substituted[MAX_SIZE / 8];
    for (int i = 0; i < 8; i++)
    {
        S_func(&expanded[i * 6], 6, S[i], &substituted[i * 4]);
    }
    Transform(substituted, output, P, 32);
}

// Function to generate subkeys from key
void SetSubKey(const bool *key, bool subkeys[][48])
{
    bool OFFSET[16];
    bool permuted_key[MAX_SIZE];
    Transform(key, permuted_key, PC1, 56);
    bool left[28], right[28];
    for (int i = 0; i < 28; i++)
    {
        left[i] = permuted_key[i];
        right[i] = permuted_key[i + 28];
    }
    for (int i = 0; i < 16; i++)
    {
        RotateL(left, 28, OFFSET[i]);
        RotateL(right, 28, OFFSET[i]);
        bool temp[MAX_SIZE];
        for (int j = 0; j < 28; j++)
        {
            temp[j] = left[j];
            temp[j + 28] = right[j];
        }
        Transform(temp, subkeys[i], PC2, 48);
    }
}

// Function to perform DES encryption/decryption
void DES(const bool *input, const bool *key, bool *output, bool mode)
{
    bool subkeys[16][48];
    SetSubKey(key, subkeys);
    bool permuted_input[64];
    Transform(input, permuted_input, IP, 64);
    bool left[32], right[32], temp[32];
    for (int i = 0; i < 32; i++)
    {
        left[i] = permuted_input[i];
        right[i] = permuted_input[i + 32];
    }
    for (int i = 0; i < 16; i++)
    {
        bool new_left[32];
        for (int j = 0; j < 32; j++)
        {
            new_left[j] = right[j];
        }
        bool temp[32];
        F_func(right, subkeys[mode ? i : 15 - i], temp);
        Xor(right, temp, 32);
        for (int j = 0; j < 32; j++)
        {
            right[j] = left[j];
            left[j] = new_left[j];
        }
    }
    for (int i = 0; i < 32; i++)
    {
        permuted_input[i] = right[i];
        permuted_input[i + 32] = left[i];
    }
    Transform(permuted_input, output, IP_INV, 64);
}
void BitToHex(const bool *input, char *output, int len)
{
    for (int i = 0; i < len; i++)
    {
        int val = 0;
        for (int j = 0; j < 4; j++)
        {
            val += input[i * 4 + j] << (3 - j);
        }
        output[i] = val < 10 ? val + '0' : val - 10 + 'A';
    }
    output[len] = '\0';
}
int main()
{
    bool input[64], key[64], output[64];
    char input_str[9], key_str[9];
    // Input string
    cout << "Input string: ";
    cin >> input_str;
    // Key string
    cout << "Key string: ";
    cin >> key_str;
    // Convert input string to bits
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            input[i * 8 + j] = (input_str[i] >> (7 - j)) & 1;
        }
    }
    // Convert key string to bits
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            key[i * 8 + j] = (key_str[i] >> (7 - j)) & 1;
        }
    }
    // Input bytes
    cout << "Input: ";
    cout << "Binary: ";
    for (int i = 0; i < 64; i++)
    {
        cout << input[i];
    }
    cout << endl
         << "Hex: ";
    char input_hex[16];
    BitToHex(input, input_hex, 16);
    cout << input_hex << endl;
    // Encryption
    DES(input, key, output, true);
    // Output bytes
    cout << "Output: ";
    cout << "Binary: ";
    for (int i = 0; i < 64; i++)
    {
        cout << output[i];
    }
    cout << endl
         << "Hex: ";
    char output_hex[16];
    BitToHex(output, output_hex, 16);
    cout << output_hex << endl;
    // Decryption
    DES(output, key, input, false);
    // Output bytes
    cout << "Output: ";
    cout << "Binary: ";
    for (int i = 0; i < 64; i++)
    {
        cout << input[i];
    }
    cout << endl
         << "Hex: ";
    BitToHex(input, input_hex, 16);
    cout << input_hex << endl;
    return 0;
}