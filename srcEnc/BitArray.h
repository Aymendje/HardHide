#ifndef BITARRAY_H_
#define BITARRAY_H_

#include "Global.h"
#include "OneByte.cpp"
#include <stdint.h>
//Reminder : this is for the RSA calcul, not for the OneTimePad
//#define SizeOfKey 2048	// Size of the otp (2kb)	// Already included from Global.h

class BitArray
{
public:
	
	BitArray();							// default constructor
	BitArray(const BitArray &copy);	// copy constructor
	~BitArray();						// delete

	// Assignment operator
	void 	 operator=  (const BitArray &table);
	uint8_t& operator[] (const uint16_t pos  );

	// Comparison operators
	fakeBool operator== (const BitArray &table) const;
	fakeBool operator!= (const BitArray &table) const;
	fakeBool operator<  (const BitArray &table) const;
	fakeBool operator<= (const BitArray &table) const;
	fakeBool operator>  (const BitArray &table) const;
	fakeBool operator>= (const BitArray &table) const;

	BitArray operator+  (const BitArray &table) const;
	BitArray operator-  (const BitArray &table) const;
	BitArray operator*  (const BitArray &table) const;
	BitArray operator/  (const BitArray &table) const;
	BitArray operator%  (const BitArray &table) const;
	BitArray operator-  (					  ) const;

	void 	 operator+= (const BitArray &table);
	void  	 operator-= (const BitArray &table);
	void 	 operator*= (const BitArray &table);
	void  	 operator/= (const BitArray &table);
	void  	 operator%= (const BitArray &table);
	
	// Increment operators
	void 	 operator++ (					  );
	void 	 operator++ (int				  );	// No difference between ++x and x++
	void  	 operator-- (					  );
	void  	 operator-- (int				  );	// No difference between ++x and x++

	// operators
	BitArray operator|  (const BitArray &table);
	void  	 operator|= (const BitArray &table);
	fakeBool operator|| (const BitArray &table);
	BitArray operator&  (const BitArray &table);
	void  	 operator&= (const BitArray &table);
	fakeBool operator&& (const BitArray &table);
	BitArray operator^  (const BitArray &table);
	void  	 operator^= (const BitArray &table);


private:

	uint16_t getArraySize() const;		// get the true size of the array (shoud be about 256)
	fakeBool getByte(uint16_t pos) const;	// get the whole byte in the array, takes the real position (so up to 255)
	verBool setBit(uint16_t pos, fakeBool value);	// set a bit balue, takes the fake position (up to 2047) and the binary value
	fakeBool getBit(uint16_t pos) const;	// get the value of the bit, takes the fake positon (up to 2047)

	OneByte bitArray[BYTE_DIV(SizeOfKey)];	// The bit array it self, because we need 2048 bits, so we shoud put 256 items in it (2048/8 = 256)
	uint16_t bitArraySize;	// The size of the array (256)
};

#endif // OTP_H_