
#include "D1.h"

int main()
{
    B1 obj;  //step 1
    obj.f();
    obj.vf();

    D1 obj2;  //step 2
    obj2.vf();

    B1& ref = obj2;   //step 3
    ref.vf();
    ref.f();

    //.f() now defined in D1 -4
}