#include "../../include/SmartPointer.h"
#include "../../include/Exception.h"
#include "../../include/ArithmeticException.h"
#include <iostream>

using namespace std;
using namespace YLinLib;

class Test
{
public:
    Test()
    {
        cout << "Test()" << endl;
    }

    ~Test()
    {
        cout << "~Test()" << endl;
    }
};

int SmartPointer_Test(void)
{
    SmartPointer<Test> sp = new Test();
    SmartPointer<Test> nsp;

    nsp = sp;

    cout << sp.isNull() << endl;
    cout << nsp.isNull() << endl;
    
    return 0;
}

int Exception_Test(void)
{    
    try
    {
	THROW_EXCEPTION(ArithmeticException, "Test");
    }
    catch(ArithmeticException& e)
    {
	cout << "ArithmeticException" << endl;
	cout << e.message() << endl;
        cout << e.location() << endl; 
    }
    catch(Exception& e)
    {
        cout << "Exception" << endl;
        cout << e.message() << endl;
        cout << e.location() << endl;
    }
    return 0;
}

