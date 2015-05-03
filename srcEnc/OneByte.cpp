#include "OneByte.h"

// Constructor, empty
OneByte::OneByte()
{
}

// Destructor, empty
OneByte::~OneByte()
{
}

// I know a swich case is horrible, but dont want to think too much
// TODO find something else maybe ?
uint8_t& OneByte::operator[] (const uint8_t pos  )	// pos shoud always be between 0 and 7
{
	if (pos < ByteSize)
	{
		switch (pos)
		{
			case 0:
				return oneByte.asBits.bit0;
				break;
			case 1:
				return oneByte.asBits.bit1;
				break;
			case 2:
				return oneByte.asBits.bit2;
				break;
			case 3:
				return oneByte.asBits.bit3;
				break;
			case 4:
				return oneByte.asBits.bit4;
				break;
			case 5:
				return oneByte.asBits.bit5;
				break;
			case 6:
				return oneByte.asBits.bit6;
				break;
			case 7:
				return oneByte.asBits.bit7;
				break;
		}
	}
	else
	{
		throw("Error, position out of range");
	}
}

uint8_t OneByte::operator[] (const uint8_t pos  ) const
{
	if (pos < ByteSize)
	{
		switch (pos)
		{
			case 0:
				return oneByte.asBits.bit0;
				break;
			case 1:
				return oneByte.asBits.bit1;
				break;
			case 2:
				return oneByte.asBits.bit2;
				break;
			case 3:
				return oneByte.asBits.bit3;
				break;
			case 4:
				return oneByte.asBits.bit4;
				break;
			case 5:
				return oneByte.asBits.bit5;
				break;
			case 6:
				return oneByte.asBits.bit6;
				break;
			case 7:
				return oneByte.asBits.bit7;
				break;
		}
	}
	return ERROR; // Dosent mean anything really
}

uint8_t& OneByte::asByte()
{
	return oneByte.asByte;
}

uint8_t OneByte::getByte() const
{
	return oneByte.asByte;
}
/*
void operator= (const uint8_t &value)
{
	oneByte.asByte = value;
}
*/