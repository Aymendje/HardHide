#include "OTP.h"

// Constructor, well, its like a reset, we call it like its new
OTP::OTP()
{
	resetOTP();
}

// Destructor, we already have a reset function to zero everyting
OTP::~OTP()
{
	resetOTP();
}

fakeBool OTP::isValid()
{
	if (position < ByteValue)
	{
		return True_8;
	}			
	else
	{
		return False_8;
	}
}

fakeBool OTP::addByte(uint8_t byteToAdd)
{
	if (isValid() && !isFilled)
	{
		oneTimePadArray[position] = byteToAdd;
		incPosition();
		if (isValid())
		{
			//Do nothing, We still need to fill
		}
		else
		{
			isFilled = True_8;
		}
		return True_8;
	}
	else
	{
		return False_8;
	}
}

uint8_t OTP::getByte()
{
	// I could do something like oneTimePadArray[position++]; but I prefer not
	uint8_t currentByte = oneTimePadArray[position];
	incPosition();
	return currentByte;
}

void OTP::resetOTP()
{
	resetPosition();

	for(uint16_t i = 0; i < SizeOfKey; i++)
	{
			oneTimePadArray[i] = 0x00;
	}

	isFilled = False_8;
}

fakeBool OTP::incPosition()
{
	if (isValid())
	{
		if (position < SizeOfKey)
		{
			position++;
			return True_8;
		}
	}
	return False_8;
}


void OTP::resetPosition()
{
	position = 0x00;
}


fakeBool OTP::getIsFilled()
{
	return isFilled;
}