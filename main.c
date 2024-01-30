#include <stdio.h>
#include <string.h>
#include "rCompress.h"

int main(int argc, char const *argv[]) {
	printf("RLE - Run Length Encryption.\n");

	char* input = "AAAAAAFDDCCCCCCCAEEEEEEEEEEEEEEEEE";
	char output[256];

	if(rc_compress(input, strlen((const char*) input), RC_ALGORITHM_RLE, output)){
		printf("Input: %s\n", input);
		printf("Output: %s\n", output);
	}else{
		printf("Error! Couldn't Compress for some reason...\n");
	}
	
	return 0;
}