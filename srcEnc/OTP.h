#ifndef OTP_H_
#define OTP_H_

#include <stdint.h>
#include "Global.h"

// #define SizeOfKey 2048	// Size of the otp (2kb)
#define SizeOfKeyAdress 11	// log(SizeOfKey, 2) = 11 bits of possible adresses
#define SizeOfPos ((SizeOfKeyAdress >> 3) + 1)	// (shoud be 2) The 3 comes from 2^3 = 8, and it jsut counts how many bytes their is in SizeOfKeyAdress
												// The +1 is sometimes redudant, buy I dont want to put a condition if ... % 8 != 0 then + 1

class OTP
{
public:
	
	OTP();
	~OTP();

	// Checks if the OTP still have some space
	uint8_t isValid();

	// Add bytes to the OTP, shoud be used only while populating the OTP at first use
	uint8_t addByte(uint8_t byteToAdd);

	// Reads 1 bytes from the OTP then "remove" it from the OTP
	// (in fact jsut add 1 to the position of the next read)
	uint8_t getByte();

	// Gives the size of the adress (well, the number of bytes inside the adress of a byte of the key)
	// TODO re-explain that shit
	uint8_t getAdresseSize();

	// Reset everything so it is ready to be reused 
	// (its just because when we use all of the OTP, we dont want to remap a new memory space, we will use the same)
	void resetOTP();

	// Put the position back to 0
	void resetPosition();

	// Check if OTP is completly filled
	uint8_t getIsFilled();
	

private:
	// Increment the position
	uint8_t incPosition();

	// A huge array containing the whole key
	// I hope it fits...
	// If you change SizeOfKey, you might need to change SizeOfKeyAdress, SizeOfPos and more important, the number of [] in the one time pad array
	// Especially if SizeOfKeyAdress is greater than 16 (that means if SizeOfKey is greather than 65536)
	// TODO: rethink this shit, it dosent make sense at all
	uint8_t oneTimePadArray[SizeOfKeyAdress-ByteSize][ByteValue]; 
	// exemple : if SizeOfKeyAdress was 18, it would be
	// uint8_t oneTimePadArray[ByteValue][ByteValue][SizeOfKeyAdress - 2*ByteValue]; 


	// Here is the problem : SizeOfKey is 2^21 long
	// but we are limited to 8 bit long unsigned numbers (or 16)
	// so we need something like 2^8 * 2^8 * 2^8 numbers, to get 2^24 bits long number
	// Its like a 3 level pointer
	// Why not use a 32 bits int ? the int class is suposed to be 32, but 
	// have some weird behaviour sometimes so I prefer not.
	uint8_t position[SizeOfPos];

	// Check if OTP is completly filled
	uint8_t isFilled;
};

#endif // OTP_H_