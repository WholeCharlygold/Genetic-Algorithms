#include "main.h"

int convertBinaryToDecimal(int *  n)
{
	int decimalNumber = 0, i = 0, remainder;
	
		for (int y = 0; y < NUMA; y++) {
			decimalNumber += n[y]*pow(2,NUMA-(y+1));
		
	}
	
	return decimalNumber;
}
long long convertDecimalToBinary(int n)
{
	long long binaryNumber = 0;
	int remainder, i = 1, step = 1;

	while (n != 0)
	{
		remainder = n % 2;
		n /= 2;
		binaryNumber += remainder * i;
		i *= 10;
	}
	return binaryNumber;
}