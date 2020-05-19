// 2.4 무치형 (보이드, Void).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void my_function()
{

}

int main()
{
	//void my_void;

	int i = 123;
	float f = 123.456f;

	void* my_void;

	my_void = (void*)&i;
	my_void = (void*)&f;

	return 0;
}


