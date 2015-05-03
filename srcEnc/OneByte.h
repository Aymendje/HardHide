#ifndef ONEBYTE_H_
#define ONEBYTE_H_

#include "Global.h"
#include <stdint.h>
//Reminder : this is for the RSA calcul, not for the OneTimePad
//#define SizeOfKey 2048	// Size of the otp (2kb)	// Already included from Global.h

typedef struct {
    uint8_t bit0:1;
    uint8_t bit1:1;
    uint8_t bit2:1;
    uint8_t bit3:1;
    uint8_t bit4:1;
    uint8_t bit5:1;
    uint8_t bit6:1;
    uint8_t bit7:1;
} BitByte;

typedef union {
    BitByte asBits;
    uint8_t asByte;
} BitField;



class OneByte
{
public:
	
	OneByte();							// default constructor
	~OneByte();						// delete

	// Assignment operator
	uint8_t& operator[] (const uint8_t pos  );
	uint8_t  operator[] (const uint8_t pos  ) const;
	uint8_t& asByte  ();
	uint8_t  getByte ()  const;

private:
	BitField oneByte;
};

#endif // ONEBYTE_H_	