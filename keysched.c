#include "keysched.h"

int set_key_size(int* keySize, const char* cipherKey)
{
    int size = sizeof(cipherKey)/sizeof(char);

    switch (size)
    {
        case 128:
        case 196:
        case 256:
            *keySize = size;
            return 0;
        default:
            return -1;
    }
}

int get_R(const int* keySize)
{
    switch (*keySize)
    {
        case 128:
            return 11;
        case 196:
            return 13;
        case 256:
            return 15;
        default:
            return -1;
    }
}
// https://en.wikipedia.org/wiki/AES_key_schedule
int expand_key(KeySchedule* keySchedule, const char* cipherKey)
{
    int result = set_cipher_key_size(&(keySchedule->keySize), cipherKey);
    if (result < 0) return result;

    // Length of key as 32-bit word
    int N = keySchedule->keySize / 32;

    // Amount of round keys needed
    int R = get_R(&(keySchedule->keySize));

    unsigned char** roundKeys = (unsigned char**) malloc(R * (4 * sizeof(unsigned char)));

    for (int i = 0; i < R; i++)
    {
        if (i < N)
        {
            *roundKeys[i] = *cipherKey;
        }
        else if ((i >= N) && (i % N == 0))
        {
            
        }
        else if ((i >= N) && (N > 6) && (i % N == 4))
        {
            
        }
        else
        {

        }
    }
}