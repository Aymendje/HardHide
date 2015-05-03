#include "BitArray.h"

// Constructor, just zeroing the array
BitArray::BitArray()
{
	bitArraySize = SizeOfKey/ByteSize;

	for (uint8_t i = 0; i < bitArraySize; i++)
	{
		bitArray[i] = False_8;
	}
}

// Copy constructor
BitArray::BitArray(const BitArray &copy)
{
	this = copy;
}


uint16_t BitArray::getArraySize()
{
	return bitArraySize;
}

fakeBool BitArray::setBit(uint16_t pos, fakeBool value)
{
	if (pos >= SizeOfKey)
		return False_8;

	uint8_t realPos = pos / 8;
	if (value == True_8)
		bitArray[realPos] |= True_8 << (pos % 8);
	else if (value == False_8)
		bitArray[realPos] &= ~(True_8 << (pos % 8));
	return True_8;
}


fakeBool BitArray::getBit(uint16_t pos)
{
	uint8_t realPos = pos / 8;
	uint8_t value = bitArray[realPos];
	uint8_t boolValue = value >> (pos % 8);
	return GET_1_BIT(boolValue);
}

// TODO Check maybe if a = a would make it crash ?
int8_t operator=  (const BitArray &table)
{
	for (uint8_t i = 0; i < bitArraySize; i++)
	{
		bitArray[i] = table[i];
	}
}