#include "B1.h"

class D1 : public B1{
    public:
    void vf() { cout << "D1::vf()\n"; }//step 2x
    void f() { cout << "D1::f()\n";} //step 4

    //~D1(){cout << "tst";}
};