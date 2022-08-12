#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "aes.h"
#include "counter_mode.h"

#define NUMBER_OF_PARTS 2
#define BLOCK_SIZE 16
#define ENCRYPT_MODE

void set_multiple_line_data_from_file(uint8_t (*data)[BLOCK_SIZE], const char *file_path)
{
    FILE *input = fopen(file_path, "r");
    if (NULL == input)
    {
        fprintf(stderr, "File opening failed: %s\n", file_path);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < NUMBER_OF_PARTS; ++i)
    {
        for (int j = 0; j < BLOCK_SIZE; ++j)
            fscanf(input, "%hhX", &data[i][j]);
    }
    fclose(input);
}

void set_data_from_file(uint8_t *data, int data_size, const char *file_path)
{
    FILE *input = fopen(file_path, "r");
    if (NULL == input)
    {
        fprintf(stderr, "File opening failed: %s\n", file_path);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < data_size; ++i)
    {
        fscanf(input, "%hhX", &data[i]);
    }
    fclose(input);
}

void print(uint8_t (*output)[BLOCK_SIZE])
{
    for (int i = 0; i < NUMBER_OF_PARTS; ++i)
    {
        for (int j = 0; j < BLOCK_SIZE; ++j)
        {
            printf("%02X", output[i][j]);
            ( (BLOCK_SIZE - 1) == j ) ? putchar('\n') : putchar(' ');
        }
    }
}

int main()
{
    uint8_t plaintext[NUMBER_OF_PARTS][BLOCK_SIZE] = {};
    uint8_t key[BLOCK_SIZE] = {};
    uint8_t ciphertext[NUMBER_OF_PARTS][BLOCK_SIZE] = {};
    uint8_t counter[NUMBER_OF_PARTS][BLOCK_SIZE] = {};

#ifdef ENCRYPT_MODE
    set_multiple_line_data_from_file(plaintext, "../test_data/input.txt");
    set_multiple_line_data_from_file(counter, "../test_data/ctr.txt");
    set_data_from_file(key, BLOCK_SIZE, "../test_data/key.txt");
    do_counter_mode_AES(plaintext, counter, ciphertext, key, NUMBER_OF_PARTS);
    print(ciphertext);
#endif

#ifdef DECRYPT_MODE
    set_multiple_line_data_from_file(ciphertext, "../test_data/input.txt");
    set_multiple_line_data_from_file(counter, "../test_data/ctr.txt");
    set_data_from_file(key, BLOCK_SIZE, "../test_data/key.txt");
    do_counter_mode_AES(ciphertext, counter, plaintext, key, NUMBER_OF_PARTS);
    print(plaintext);
#endif

    return 0;
}

#undef NUMBER_OF_PARTS
#undef BLOCK_SIZE