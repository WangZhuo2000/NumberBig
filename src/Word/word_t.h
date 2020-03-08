/* 这个文件定义一个字节的大小，先假定字节大小是 64 使用uint64_t来表示一个字节。
*/

#pragma once

#include <stdint.h>
#include <stddef.h>

#define WORD uint64_t
typedef uint64_t* WORD_T;
#define WORDMAX UINT64_MAX
#define WORDSIZE 64
#define HALFWORDSIZE 32
#define BYTESIZE 8
