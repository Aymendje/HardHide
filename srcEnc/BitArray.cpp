#include "BitArray.h"

// Constructor, just zeroing the array
BitArray::BitArray()
{
	bitArraySize = SizeOfKey/ByteSize;	// shoud be 2048/8 so 256

	for (uint8_t i = 0; i < bitArraySize; i++)
	{
		bitArray[i].asByte() = False_8;
	}
}

// Copy constructor
BitArray::BitArray(const BitArray &copy)
{
	// Assigning the copyed BitArray to this one
	*this = copy;
}

// Destructor, empty
BitArray::~BitArray()
{
}


// Returns  the real array size (256)
uint16_t BitArray::getArraySize() const
{
	return bitArraySize;
}


fakeBool BitArray::getByte(uint16_t pos) const
{
	// If we request a position greater than the maximum size of the array, we return an error
	if (pos >= bitArraySize)
	{
		return ERROR;
	}
	return bitArray[pos].getByte();
}

verBool BitArray::setBit(uint16_t pos, fakeBool value)
{
	// Check if we are in range
	if (pos >= SizeOfKey)
	{
		return ERROR;
	}

	// Calculate the byte position of the bit we are lookign for
	uint8_t realPos = BYTE_DIV(pos);
	(bitArray[realPos])[BYTE_MOD(pos)] = value;
	return OK;
}

fakeBool BitArray::getBit(uint16_t pos) const
{
	// Check if we are in range
	if (pos >= SizeOfKey)
	{
		return ERROR;
	}
	// Calculate the byte position of the bit we are lookign for
	uint8_t realPos = BYTE_DIV(pos);
	//Get the bit itself from the byte
	fakeBool bitValue = (bitArray[realPos])[BYTE_MOD(pos)];
	return bitValue;
}

void BitArray::operator= (const BitArray &table)
{
	// Check if we are in range
	if (table.getArraySize() != this->getArraySize())
	{
		return;
	}/*
	else if (table == this)
	{
		return;
	}*/
	for (uint16_t i = 0; i < bitArraySize; i++)
	{
		bitArray[i].asByte() = table.getBit(i);
	}
}

// it is exactly like getByte, but we return the reference of the element so it can be modified
fakeBool& BitArray::operator[] (const uint16_t pos)
{
	if (pos < bitArraySize)
	{
		uint8_t realPos = BYTE_DIV(pos);
		uint8_t posInByte = BYTE_MOD(pos);
		return (bitArray[realPos])[posInByte];
	}

	// TODO implement an error handler maybe ?
	// throw ("Provided index is out of range");
	// but avr-gcc cant throw...
}