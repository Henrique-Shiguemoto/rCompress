#ifndef RCOMPRESS_H
#define RCOMPRESS_H

#define RC_NULL (void*)0

typedef unsigned char rc_byte;

rc_byte* rc_compress(rc_byte* bytes, unsigned long data_size);
rc_byte* rc_decompress(rc_byte* bytes, unsigned long data_size);

#endif // RCOMPRESS_H