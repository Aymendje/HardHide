#ifndef BITARRAY_H_
#define BITARRAY_H_

#include "Global.h"
#include <stdint.h>
//Reminder : this is for the RSA calcul, not for the OneTimePad
//#define SizeOfKey 2048	// Size of the otp (2kb)	// Already included from Global.h

class BitArray
{
public:
	
	BitArray();							// default constructor			monBit = 11111111
	BitArray(const BitArray &copy);		// copy constructor				monBit[4] = 0
	~BitArray();						// delete						monBit = 11101111

	// Assignment operator
	void 	 operator=  (const BitArray &table);
	void 	 operator=  (const uint8_t  fakeBool  );

	BitArray& operator[] (const uint16_t pos  );
	fakeBool  operator[] (const uint32_t pos  ) const;	// TODO fuck this uint32_t

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
	void 	 operator++ (		int			  ) = delete;	// No ++x
	void  	 operator-- (					  );
	void  	 operator-- (		int			  ) = delete;	// No --x

	// operators
	BitArray operator|  (const BitArray &table) const;
	void  	 operator|= (const BitArray &table);
	fakeBool operator|| (const BitArray &table) const;
	BitArray operator&  (const BitArray &table) const;
	void  	 operator&= (const BitArray &table);
	fakeBool operator&& (const BitArray &table) const;
	BitArray operator^  (const BitArray &table) const;
	void  	 operator^= (const BitArray &table);


private:

	uint16_t getArraySize() const;		// get the true size of the array (shoud be about 256)
	fakeBool getByte(const uint16_t pos) const;	// get the whole byte in the array, takes the real position (so up to 255)

	uint8_t bitArray[BYTE_DIV(SizeOfKey)];	// The bit array it self, because we need 2048 bits, so we shoud put 256 items in it (2048/8 = 256)
	uint16_t bitArraySize;	// The size of the array (256)
	uint16_t assignationPos;
};

#endif // OTP_H_