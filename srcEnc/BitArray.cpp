#include "BitArray.h"

// Constructor, just zeroing the array
BitArray::BitArray()
{
	bitArraySize = SizeOfKey/ByteSize;	// shoud be 2048/8 so 256
	assignationPos = 0;
	for (uint8_t i = 0; i < bitArraySize; i++)
	{
		bitArray[i] = False_8;
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


fakeBool BitArray::getByte(const uint16_t pos) const
{
	// If we request a position greater than the maximum size of the array, we return an error
	if (pos >= bitArraySize)
	{
		return ERROR;
	}
	return bitArray[pos];
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
		this[i] = table.getByte(i);
	}
}

void BitArray::operator= (const fakeBool  value  )	// If I am not wrong, value SHOULD be between 0 and 2047
{
	if (assignationPos >= SizeOfKey)
	{
		// TODO implement an error handler maybe ?
		// throw ("Provided index is out of range");
		// but avr-gcc cant throw...
		return;
	}
	uint16_t realPos = BYTE_DIV(assignationPos);
	uint8_t posInByte = BYTE_MOD(assignationPos);
	if ( value == False_8)
	{
		bitArray[realPos]  &= ~(1 << posInByte);
	}
	else if ( value == True_8)
	{
		bitArray[realPos] |= (1 << posInByte);
	}
}

// it is exactly like getByte, but we return the reference of the element so it can be modified
BitArray& BitArray::operator[] (const uint16_t pos)
{
	assignationPos = pos;

	if (pos >= bitArraySize)
	{
		// TODO implement an error handler maybe ?
		// throw ("Provided index is out of range");
		// but avr-gcc cant throw...
		assignationPos = -1;
	}

	return *this;
}

// it is exactly like getByte, but we return the reference of the element so it can be modified
fakeBool BitArray::operator[] (const uint32_t pos) const
{
	if (pos >= bitArraySize)
	{
		// TODO implement an error handler maybe ?
		// throw ("Provided index is out of range");
		// but avr-gcc cant throw...
		return ERROR;
	}
    uint16_t realPos = BYTE_DIV(pos);
    uint8_t posInByte = BYTE_MOD(pos);
    uint8_t boolValue = bitArray[realPos] >> posInByte;
    return (GET_1_BIT(boolValue));
}