#include <stdio.h>
#include <string.h>
#include "rCompress.h"

int main(int argc, char *argv[]) {
	if(argc < 2){
		printf("USAGE: [program_name] [string]\n");
		return 1;
	}

	printf("RLE - Run Length Encryption.\n");

	char* input = argv[1];
	char output[256] = {0};

	if(rc_compress(input, strlen((const char*) input), RC_ALGORITHM_RLE, output)){
		int size_input = (int)strlen((const char*) input);
		int size_output = (int)strlen((const char*) output);
		printf("Input: 	%s - Size: %d\n", input, size_input);
		printf("Output: %s - Size: %d\n", output, size_output);
		printf("Compression Rate: %f\n", 1.0f - ((float)size_output / (float)size_input));
	}else{
		printf("Error! Couldn't Compress for some reason...\n");
	}
	
	return 0;
}