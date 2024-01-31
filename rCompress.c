#include "rCompress.h"

// COMPRESSION
static int _rc_compress_rle(rc_byte* bytes, unsigned int data_size, rc_byte* destination){
	if(!bytes || !destination || data_size <= 0) return RC_FAILURE;

	rc_byte prev_byte = bytes[0];

	unsigned int i = 1;
	unsigned int dest_i = 0;
	unsigned char times_byte_repeated = 0;
	
	do {
		rc_byte byte = bytes[i];

		if(prev_byte == byte){
			++times_byte_repeated;
			if(times_byte_repeated >= RC_RLE_REPETITION_MAX_COUNT){
				destination[dest_i++] = RC_RLE_REPETITION_INDICATOR;
				destination[dest_i++] = prev_byte;
				destination[dest_i++] = times_byte_repeated;
				prev_byte = byte;
				times_byte_repeated = 0;
			}
		}else{
			destination[dest_i++] = RC_RLE_REPETITION_INDICATOR;
			destination[dest_i++] = prev_byte;
			destination[dest_i++] = times_byte_repeated + 1;
			prev_byte = byte;
			times_byte_repeated = 0;
		}
		
		++i;
	} while(i <= data_size);
	
	return RC_SUCCESS;
}

static int _rc_compress_huffman(rc_byte* bytes, unsigned int data_size, rc_byte* destination){
	return RC_FAILURE;
}

int rc_compress(rc_byte* bytes, unsigned int data_size, rc_algorithm algorithm, rc_byte* destination){
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
static int _rc_decompress_rle(rc_byte* bytes, unsigned int data_size, rc_byte* destination){
	return RC_FAILURE;
}

static int _rc_decompress_huffman(rc_byte* bytes, unsigned int data_size, rc_byte* destination){
	return RC_FAILURE;
}

int rc_decompress(rc_byte* bytes, unsigned int data_size, rc_algorithm algorithm, rc_byte* destination){
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
