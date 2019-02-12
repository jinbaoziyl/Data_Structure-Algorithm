#include "../../include/SmartPointer.h"
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



