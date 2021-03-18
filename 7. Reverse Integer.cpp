#include<iostream>


int reverse(int x) 
{
	int rever = 0, copy = x;
	while (copy != 0)
	{
		int temp = copy % 10;
		copy /= 10;
		rever = rever * 10 + temp;
		if (rever > INT_MAX) {
			return 0;
		}
	}
	return x > 0 ? copy : -copy;
}