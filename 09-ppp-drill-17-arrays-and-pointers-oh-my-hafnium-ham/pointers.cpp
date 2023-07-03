//this is for the second part of the drill 
#include "std_lib_facilities.h"


void print_array10(ostream& os, int* a){
    for(int i = 0; i < 10; i++){
        os << *a << " ";
        a++;
    }  
    os<<'\n';
}

void print_array(ostream& os, int* a, int n){
    for(int i = 0; i < n; i++){
        os << *a << " ";
        a++;
    }   
    os<<'\n';
}

void print_vector10(ostream& os, int* a){
    for(int i = 0; i < 10; i++){
        os << *a << " ";
        a++;
    }  
    os<<'\n';
}

void print_vector(ostream& os, int* a, int n){
    for(int i = 0; i < n; i++){
        os << *a << " ";
        a++;
    }     
    os<<'\n';
}



int main(){
    int x = 7;
    int * p1 = &x;
    cout << "address val: " << &p1 << "\nval store: " << *p1 << '\n';


    int * p2 = new int[7];
    for(int i = 0; i < 7; i++){
        p2[i] = (pow(2,i));
    }
    cout << "address val: " << p2 << "\nval store: ";

    print_array(cout, p2, 7);



    int * p3 = p2;
    p1 = p2;
    p2 = p3;
    cout << "address val post moval: " << p1 << "\nval store: " << *p1 << '\n';
    cout << "address val post moval: " << p2 << "\nval store: ";

    print_array(cout, p2, 7);
    
    delete[] p2;

    
    p1 = new int[10];
    for(int i = 0; i < 10; i++){
        p1[i] = (pow(2,i));
    }
    cout << "address val step3: " << p1 << "\nval store: ";
    print_array10(cout, p1);


    p2 = new int[10];
    cout << "address val step3: " << p2 << "\nval store: ";
    print_array10(cout, p2);

    cout << "vals swapped: \n";
    print_array10(cout, p1);
    print_array10(cout, p2);

    for(int i = 0; i < 10; i++){
        p2[i] = p1[i];
    }
    
    




///*
    vector<int> * p5 = new vector<int>;
    
    for(int i = 0; i < 10; i++){
        p5->push_back(pow(2,i));
    }
    p1 = &p5->front();
    


    vector<int> * p4 = new vector<int> (10);
    p2 = &p4->front();

    cout << "VECTOR vals before swap: \n" ;
    print_vector10(cout, p1);
    print_vector10(cout, p2);

    p3 = p2;
    p2 = p1;
    p1 = p3;
    /*
    for(int i = 0; i < 10; i++){
        p4->at(i) = (*p5) [i];
    }
    */
    cout << "VECTOR vals post swap: \n";
    print_vector10(cout, p1);
    print_vector10(cout, p2);
    
//*/
}
