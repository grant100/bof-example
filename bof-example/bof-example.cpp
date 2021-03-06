// bof-example.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>

// need to disable _RTC_CheckStackVars if using visual studio....

// call - pushes EIP, EBP and allocates memory for local variables. 
// ret - pops the LAST value in the stack (esp) which supposed to be the returning address, and assign it to IP register.

// buffer overflows and overwrites ebp and eip values originally stored in the stack. 
// after work has concluded (function end), the esp gets set to ebp, then ebp gets popped, this moves the stack pointer to the original eip address. 
// ret then executes the instruction at that address.
void vulnerable() {
	char buffer[8];
	for (int i = 0; i < 1000; i++) {
		buffer[i] = 'A';
	}
	return;
}


int main()
{
	vulnerable();
    return 0;
}

