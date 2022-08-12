#ifndef COUNTER_MODE_H
#define COUNTER_MODE_H

#include <stdint.h>
#define BLOCK_SIZE 16

void do_counter_mode_AES(
    const uint8_t (*input_text)[BLOCK_SIZE], 
    const uint8_t (*counter)[BLOCK_SIZE], 
    uint8_t (*output_text)[BLOCK_SIZE], 
    const uint8_t *key, 
    int number_of_parts);

#endif