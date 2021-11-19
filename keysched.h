#ifndef _KEYSCHED_H_

#ifndef WORD_LEN
    #define WORD_LEN 32
#endif

typedef struct
{
    int keySize;
    unsigned char** roundKeys;
} KeySchedule;

int get_R(const int*);

int set_key_size(int*, const char*);

int expand_key(KeySchedule*, const char*);

#endif