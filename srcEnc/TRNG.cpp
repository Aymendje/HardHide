#include "OTP.h"  

#include <avr/io.h>
#include <util/delay.h>
#include <util/delay_basic.h>

#define TRNG_pin PIND
#define TRNG_adresse 0x01
#define TRNG_delay_us  1 // 0.95 but we round to 1

#define ByteSize 8

// Global variables containing the 2 one time pad keys
OTP otp_1;
OTP otp_2;

uint8_t readRN();
void initialise();
void fillOTP(OTP theOTP);

/* Function initalizing the board, all pins etc. */
void initialise()
{
  // Resetting all OTP
  otp_1.resetOTP();
  otp_2.resetOTP();

  // Initialisng everything at output mode
  DDRA = 0x00;
  DDRB = 0x00;
  DDRC = 0x00;
  DDRD = 0x00;

  // Activate TRNG_adresse in "reading" mode at the correct offset
  TRNG_pin |= TRNG_adresse;
}

/* Function to read from the TRNG */
uint8_t readRN()
{
  // Creating reading variable
  uint8_t byteRead = 0x00;

  // Looping over the variable to create an 8 bit (1 byte) random number
  for (uint8_t  i = 0; i < ByteSize; i++)
  {
    // Delay to me sure we are reading a correct value
    _delay_ms(TRNG_delay_us);

    // We write the value at the correct offset
    if(TRNG_pin && TRNG_adresse)
    {
      // We bit shift 1 at the correct position then we write it
      byteRead |= (1 << i);
    }
    else
    {
      // We out 1 at the place of the 0 then inverse every bit (ex: 00100000 becomes 11011111)
      // The we AND it with the variable to be sure it is zeroed
      byteRead &= ~(1 << i);
    }
  }
  return byteRead;
}

void fillOTP (OTP theOTP)  
{
  theOTP.resetOTP();
  while(theOTP.getIsFilled() == false)
  {
    theOTP.addByte(readRN());
  }  
  theOTP.resetPosition();
}     

int main()
{
  initialise();
  fillOTP(otp_1);
  // Do STUFF
  return 0; 
}
