#ifndef RCOMPRESS_H
#define RCOMPRESS_H

#include "stdio.h" // for opening files and stuff

#define RC_FAILURE  					0
#define RC_SUCCESS 						1
#define RC_RLE_REPETITION_INDICATOR 	'*'

typedef enum rc_algorithm {
	RC_ALGORITHM_RLE = 0,
	RC_ALGORITHM_HUFFMAN,
} rc_algorithm;

typedef char rc_byte;

int rc_compress(rc_byte* bytes, unsigned long data_size, rc_algorithm algorithm, rc_byte* destination);
int rc_compress_from_file(const char* filename, rc_algorithm algorithm, rc_byte* destination);

int rc_decompress(rc_byte* bytes, unsigned long data_size, rc_algorithm algorithm, rc_byte* destination);
int rc_decompress_from_file(const char* filename, rc_algorithm algorithm, rc_byte* destination);

#endif // RCOMPRESS_H