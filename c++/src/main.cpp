#include <stdio.h>
#include <iostream>

#include "../include/Ut_YLinLib.h"
#include "../include/Exception.h"
#include "../include/ArithmeticException.h"
using namespace std;

int main()
{
	int rval = SmartPointer_Test();
	rval |= Exception_Test();
	cout << "Reture Value: " << rval << endl;
	return 0;	
}

