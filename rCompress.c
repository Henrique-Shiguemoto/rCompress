#include "rCompress.h"

// COMPRESSION
static int _rc_compress_rle(rc_byte* bytes, unsigned long data_size, rc_byte* destination){
	return RC_FAILURE;
}

static int _rc_compress_huffman(rc_byte* bytes, unsigned long data_size, rc_byte* destination){
	return RC_FAILURE;
}

int rc_compress(rc_byte* bytes, unsigned long data_size, rc_algorithm algorithm, rc_byte* destination){
	switch(algorithm){
		case RC_ALGORITHM_RLE: 		return _rc_compress_rle(bytes, data_size, destination);
		case RC_ALGORITHM_HUFFMAN: 	return _rc_compress_huffman(bytes, data_size, destination);
		default: break;
	}
	return RC_FAILURE;
}

int rc_compress_from_file(const char* filename, rc_algorithm algorithm, rc_byte* destination){
	return RC_FAILURE;
}

// DECOMPRESSION
static int _rc_decompress_rle(rc_byte* bytes, unsigned long data_size, rc_byte* destination){
	return RC_FAILURE;
}

static int _rc_decompress_huffman(rc_byte* bytes, unsigned long data_size, rc_byte* destination){
	return RC_FAILURE;
}

int rc_decompress(rc_byte* bytes, unsigned long data_size, rc_algorithm algorithm, rc_byte* destination){
	switch(algorithm){
		case RC_ALGORITHM_RLE: 		return _rc_decompress_rle(bytes, data_size, destination);
		case RC_ALGORITHM_HUFFMAN: 	return _rc_decompress_huffman(bytes, data_size, destination);
		default: break;
	}
	return RC_FAILURE;
}

int rc_decompress_from_file(const char* filename, rc_algorithm algorithm, rc_byte* destination){
	return RC_FAILURE;
}
