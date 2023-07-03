#include <iostream>
#include <string>

using namespace std;

class B1{
    public:
    virtual void vf() { cout << "B1::vf()\n"; } //all step 1
    void f() { cout << "B1::f()\n";}

    virtual void pvf() =0; //step 5
    
    //virtual ~ B1() = 0;
};
