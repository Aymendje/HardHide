#include "OTP.h"
#include "Global.h"


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

uint8_t OTP::isValid()
{
	for(uint8_t i = 0; i < SizeOfPos; i++)
	{
		if (position[i] == ByteValue)
		{
			;	// Do nothing
		}
			
		else
		{
			return False_8;
		}
	}
	return True_8;
}

uint8_t OTP::addByte(uint8_t byteToAdd)
{
	// TODO Change this please
	// Well fuck, ill need to thing of a better thing than this
	// I am assuming here that position is an array of 2 elements, but it isnt true if we change SizeOfKeyAdress...
	if (isValid() && !isFilled)
	{
		oneTimePadArray[position[0]][position[1]] = byteToAdd;
		incPosition();
		if (isValid())
		{
			//We still need to fill
		}
		else
		{
			isFilled = True_8;
		}
		return True_8;
	}
	else
		return False_8;
}

uint8_t OTP::getByte()
{
	uint8_t currentByte = oneTimePadArray[position[0]][position[1]];
	incPosition();
	return currentByte;
}


uint8_t OTP::getAdresseSize()
{
	return SizeOfKeyAdress;
}

void OTP::resetOTP()
{
	for(uint8_t i = 0; i < SizeOfPos; i++)
	{
		position[i] = 0x00;
	}

	// TODO Change this please
	// Well fuck, ill need to thing of a better thing than this
	// I am assuming here that position is an array of 2 elements, but it isnt true if we change SizeOfKeyAdress...
	uint8_t maxJ = 1 << (SizeOfKeyAdress - ByteSize))
	for(uint8_t i = 0; i < SizeOfPos; i++)
	{
		for(uint8_t j = 0; i < maxJ; j++)
		{
			oneTimePadArray[i][j] = 0x00;
		}
	}
	isFilled = False_8;
}

uint8_t OTP::incPosition()
{
	if (isValid())
	{
		for(uint8_t i = 0; i < SizeOfPos; i++)
		{
			if (position[i] == ByteValue)
			{
				;
			}
			else
			{
				position[i]++;
				return True_8;
			}
		}
	}
	else
		return False_8;
}


void OTP::resetPosition()
{
	for(uint8_t i = 0; i < SizeOfPos; i++)
	{
		position[i] = 0x00;
	}
}


uint8_t OTP::isFilled()
{
	return isFilled;
}