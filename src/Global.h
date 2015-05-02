#ifndef GLOBAL_H_
#define GLOBAL_H_
// All the global includes and definitions goes here !

#define True_8 0x01		// a bool is sometimes 8 bits, sometimes 16 and even 32 bits, so I prefer
#define False_8 0x00		// setting up uint8_t with predetermined return codes

#define ByteSize 8			// size of 1 byte
#define ByteValue (1<<ByteSize)		// Value of a byte, shoud be 256, everytime

#endif // GLOBAL_H_