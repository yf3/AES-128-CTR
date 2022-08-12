#include "counter_mode.h"
#include "aes.h"

void do_counter_mode_AES(
    const uint8_t (*input_text)[BLOCK_SIZE], 
    const uint8_t (*counter)[BLOCK_SIZE], 
    uint8_t (*output_text)[BLOCK_SIZE], 
    const uint8_t *key, 
    int number_of_parts)
{
    for (int i = 0; i < number_of_parts; ++i)
    {
        encrypt_by_AES(counter[i], key, output_text[i]);
        for (int j = 0; j < BLOCK_SIZE; ++j)
        {
            output_text[i][j] ^= input_text[i][j];
        }
    }
}