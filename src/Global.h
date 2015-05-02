#ifndef GLOBAL_H_
#define GLOBAL_H_
// All the global includes and definitions goes here !

#define F_CPU 16000000UL // 16 MHz

#define True_8 0x01		// a bool is sometimes 8 bits, sometimes 16 and even 32 bits, so I prefer
#define False_8 0x00		// setting up uint8_t with predetermined return codes

#define ByteSize 8			// size of 1 byte
#define ByteValue 0b11111111		// value of 

#endif // GLOBAL_H_