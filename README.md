 HardHide
==========

Project I am working on for this summer / this year
Its a hardware (arduino based) solution for encrypting wireless data.
More especially, my goal would be to have an encrypting device for wireless keyboards so all data between the keyboard (or mouse ?) and the computer would be totally secure and encrypted.

At first, I was thinking about simply generating an RSA key and encrypting every keystroke and send it (with someting like RSA2048) but it is too much CPU intensive on the Arduino so youll get heavy lag and latency.

Now I am thinking about generating a one time pad (like 2048 bytes), send it over RSA, and then, while idle, generating and sending the next OTP via RSA. Using a one time pad is super secure and really easy on the CPU (it is just a XOR).

So, to wrap up, instead of sending RSA encrypted keystrokes every time, I send 1 RSA encrypted big key, then send each keystroke with a really simple (but highly secure) encryption.

I am also working on a hardware true random number generator to go with the kit, based on https://github.com/waywardgeek/infnoise work.