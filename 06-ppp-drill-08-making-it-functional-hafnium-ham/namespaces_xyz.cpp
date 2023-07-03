#include "std_lib_facilities.h"

namespace X{
    int var = 0;
    extern int var;
    void print(){
        cout << var << '\n';
    }
}

namespace Y{
    int var = 0;
    extern int var;
    void print(){
        cout << var << '\n';
    }
}

namespace Z{
    int var = 0;
    extern int var;
    void print(){
        cout << var << '\n';
    }
}