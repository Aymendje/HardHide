#include "OTP.h"

// Constructor, well, its like a reset, we call it like its new
OTP::OTP()
{
	resetOTP();
}

// Destructor, empty
OTP::~OTP()
{
}


verBool OTP::isValid()
{
	if (position < ByteValue)
	{
		return ERROR;
	}			
	return OK;
}

verBool OTP::addByte(uint8_t byteToAdd)
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
		return OK;
	}
	return ERROR;
}

uint8_t OTP::getByte()
{
	// I could do something like oneTimePadArray[position++]; but I prefer not
	uint8_t currentByte = oneTimePadArray[position];
	incPosition();
	return currentByte;
}

verBool OTP::resetOTP()
{
	resetPosition();

	for(uint16_t i = 0; i < SizeOfKey; i++)
	{
			oneTimePadArray[i] = 0x00;
	}

	isFilled = False_8;
	return OK;
}

verBool OTP::incPosition()
{
	if (isValid() && (position < SizeOfKey))
	{
		position++;
		return OK;
	}
	return ERROR;
}


verBool OTP::resetPosition()
{
	position = 0x00;
	return OK;
}


fakeBool OTP::getIsFilled()
{
	return isFilled;
}