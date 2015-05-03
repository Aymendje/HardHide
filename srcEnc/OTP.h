#ifndef OTP_H_
#define OTP_H_

#include "Global.h"
#include <stdint.h>

class OTP
{
public:
	
	OTP();
	~OTP();

	// Checks if the OTP still have some space
	fakeBool isValid();

	// Add bytes to the OTP, shoud be used only while populating the OTP at first use
	fakeBool addByte(uint8_t byteToAdd);

	// Reads 1 bytes from the OTP then "remove" it from the OTP
	// (in fact jsut add 1 to the position of the next read)
	uint8_t getByte();

	// Reset everything so it is ready to be reused 
	// (its just because when we use all of the OTP, we dont want to remap a new memory space, we will use the same)
	void resetOTP();

	// Put the position back to 0
	void resetPosition();

	// Check if OTP is completly filled
	fakeBool getIsFilled();
	

private:
	// Increment the position
	fakeBool incPosition();

	// A huge array containing the whole key
	// I hope it fits...
	uint8_t oneTimePadArray[SizeOfKey]; 

	// Current position inside 
	// If you need a huge OTP, like more than 65536 elements, we will use uint32_t I guess
	uint16_t position;

	// Check if OTP is completly filled
	fakeBool isFilled;
};

#endif // OTP_H_