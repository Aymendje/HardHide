#ifndef BITARRAY_H_
#define BITARRAY_H_

#include "Global.h"
#include <stdint.h>
*//Reminder : this is for the RSA calcul, not for the OneTimePad
//#define SizeOfKey 2048	// Size of the otp (2kb)	// Already included from Global.h
class BitArray
{
public:
	
	BitArray();							// default constructor
	BitArray(const BitArray &copy);	// copy constructor
	~BitArray();						// delete

//	fakeBool& operator[] (const uint16_t pos  );
/*
	uint8_t operator=  (const BitArray &table);
	uint8_t operator+  (const BitArray &table);
	uint8_t operator++ (const BitArray &table);
	uint8_t operator-  (const BitArray &table);
	uint8_t operator-- (const BitArray &table);
	uint8_t operator+= (const BitArray &table);
	uint8_t operator-= (const BitArray &table);
	uint8_t operator*  (const BitArray &table);
	uint8_t operator*= (const BitArray &table);
	uint8_t operator/  (const BitArray &table);
	uint8_t operator/= (const BitArray &table);
	uint8_t operator== (const BitArray &table);
	uint8_t operator|  (const BitArray &table);
	uint8_t operator|| (const BitArray &table);
	uint8_t operator&  (const BitArray &table);
	uint8_t operator&& (const BitArray &table);
	uint8_t operator^  (const BitArray &table);
*/

private:

	uint16_t getArraySize();
	fakeBool setBit(uint16_t pos, uint8_t value);
	uint16_t getBit(uint16_t pos);

	uint8_t bitArray[SizeOfKey/ByteSize];
	uint16_t bitArraySize;
};

#endif // OTP_H_