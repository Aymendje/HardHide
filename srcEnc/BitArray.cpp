#include "BitArray.h"

// Constructor, just zeroing the array
BitArray::BitArray()
{
	bitArraySize = SizeOfKey/ByteSize;	// shoud be 2048/8 so 256

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

// Returns 
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
	return bitArray[pos];
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
	if (value == True_8)
	{
		// we OR the True value at the good position in the byte
		bitArray[realPos] |= True_8 << BYTE_MOD(pos);
	}
	else if (value == False_8)
	{
		// we AND the False value at the good position in the byte, with ex: 11101111
		bitArray[realPos] &= ~(True_8 << BYTE_MOD(pos));
	}
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
	uint8_t value = bitArray[realPos];
	//Get the bit itself from the byte
	uint8_t boolValue = value >> BYTE_MOD(pos);
	return GET_1_BIT(boolValue);
}

/*
// TODO Check maybe if a = a would make it crash ?
verBool BitArray::operator= (const BitArray &table)
{
	// Check if we are in range
	if (table.getArraySize() != this->getArraySize())
	{
		return ERROR;
	}
	else if (table != this)
	{
		return ERROR;
	}
	for (uint16_t i = 0; i < bitArraySize; i++)
	{
		bitArray[i] = table.getBit(i);
	}
	return OK;
}



STUFF HERE
*/