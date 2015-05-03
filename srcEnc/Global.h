#ifndef GLOBAL_H_
#define GLOBAL_H_

#include <stdint.h>
// All the global includes and definitions goes here !

#define F_CPU 16000000UL // 16 MHz

#define True_8 0x01		// a bool is sometimes 8 bits, sometimes 16 and even 32 bits, so I prefer
#define False_8 0x00		// setting up uint8_t with predetermined return codes

#define ByteSize 8			// size of 1 byte
#define ByteValue 0b11111111		// value of 1 byte

#define SizeOfKey 2048	// Size of the otp (2kb)

#define GET_1_BIT(x) (x & 0x07)	// return only 0x0000000? instead of 0x????????

#if (SizeOfKey % ByteSize != False_8)	// Refuse a SizeOfKey not multiple of 8 
	#error "SizeOfKey not multiple of 8"
#endif

typedef uint8_t fakeBool;	// Just a typedef so I know what I am using

#endif // GLOBAL_H_
