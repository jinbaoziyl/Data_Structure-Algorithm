#include <stdio.h>
#include <iostream>

#include "../include/Ut_YLinLib.h"
#include "../include/Exception.h"
#include "../include/ArithmeticException.h"
#include "../include/Recursive.h"
using namespace std;

int main()
{
	int n;
	unsigned int val_sum;
	int rval = SmartPointer_Test();
	rval |= Exception_Test();
	cout << "Reture Value: " << rval << endl;

	cout << "[Recursive-Sum] Please input a number: " 
	cin >> n;
	val_sum = Sum(n);
	cout << "The Sum of n is:  " << val_sum << endl;

	return 0;	
}

