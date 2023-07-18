#include "PreferredNumber_8032.h"
#include <iostream>
#include <string>

int main(int argc, char* argv)
{
	PreferredNumber_8032::GetInstance().PrintArray(ERa::Ra20);

	int n = 7;
	float number = PreferredNumber_8032::GetInstance().GetNumber(ERa::Ra20, n);
	cout << number;

}