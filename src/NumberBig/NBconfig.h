#pragma once

#include "src/Word/word_t.h"

#define MAX_number_bits 512
#define MAX_number_byte (MAX_number_bits / BYTESIZE)
#define MAX_number_word (MAX_number_bits / WORDSIZE)

/* 我把最大的数字设定成512，这里可以根据以后的实现来修改 */