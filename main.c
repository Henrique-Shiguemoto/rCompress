#include <stdio.h>
#include <string.h>
#include "rCompress.h"

int main(void) {
	printf("RLE - Run Length Encryption.\n");

	rc_byte* data = (rc_byte*)"wwwwwwwwwwwwwwwaaaaaaaaaaaaaaaadexxxxxx";
	rc_byte output[256] = {0};
	if(rc_compress(data, strlen((const char*) data), RC_ALGORITHM_RLE, output)){
		int size_data = (int)strlen((const char*) data);
		int size_output = (int)strlen((const char*) output);
		printf("Uncompressed data: %s - Size: %d\n", data, size_data);
		printf("Compressed  Output: %s - Size: %d\n", output, size_output);
		printf("Compression Rate: %f\n", 1.0f - ((float)size_output / (float)size_data));
	}else{
		printf("Error! Couldn't compress for some reason...\n");
	}

	rc_byte result[256] = {0};
	if(rc_decompress(output, strlen((const char*) output), RC_ALGORITHM_RLE, result)){
		int size_compressed = (int)strlen((const char*) output);
		int size_result = (int)strlen((const char*) result);
		printf("Compressed Data:   %s - Size: %d\n", output, size_compressed);
		printf("Uncompressed Data: %s - Size: %d\n", result, size_result);
	}else{
		printf("Error! Couldn't decompress for some reason...\n");
	}
	
	return 0;
}