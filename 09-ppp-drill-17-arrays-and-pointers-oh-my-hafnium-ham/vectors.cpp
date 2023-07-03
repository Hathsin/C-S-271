//this code handles the first set of requirments
#include "std_lib_facilities.h"




void print_array10(ostream& os, int* a){
    for(int i = 0; i < 10; i++){
        os << *a << " \n";
        a++;
    }  
}

void print_array(ostream& os, int* a, int n){
    for(int i = 0; i < n; i++){
        os << *a << " \n";
        a++;
    }   
}

void print_vector10(ostream& os, int* a){
    for(int i = 0; i < 10; i++){
        os << *a << " \n";
        a++;
    }  
}

void print_vector(ostream& os, int* a, int n){
    for(int i = 0; i < n; i++){
        os << *a << " \n";
        a++;
    }     
}

int main(){

    int * arr = new int[10];
    print_array10(cout, arr);
    cout << " \n"; 
    delete arr;


    int * arr1 = new int[10]; 
    for(int i = 0; i < 10; i++){
        arr1[i] = (100 + i);
    }
    print_array10(cout, arr1);
    cout << " \n"; 
    delete arr1;


    int * arr2 = new int[11];
    for(int i = 0; i < 11; i++){
        arr2[i] = (100 + i);
    }
    print_array(cout, arr2, 11);
    cout << " \n"; 
    delete arr2;


    int * arr3 = new int[20];
    for(int i = 0; i < 20; i++){
        arr3[i] = (100 + i);
    }
    print_array(cout, arr3, 20);
    cout << " \n"; 
    delete arr3;



    vector<int> * vec = new vector<int> (10);
    int * tst = &vec->front();
    
    print_vector10(cout, tst);
    cout << " \n"; 
    delete vec;

    //Make all vectors now
    vector<int> * vec1 = new vector<int>; 
    for(int i = 0; i < 10; i++){
        vec1->push_back(100 + i);
    }
    int * tst1 = &vec1->front();
    print_vector10(cout, tst1);
    cout << " \n"; 
    delete vec1;


    vector<int> * vec2 = new vector<int>;
    for(int i = 0; i < 11; i++){
        vec2->push_back(100 + i);
    }
    int * tst2 = &vec2->front();
    print_vector(cout, tst2, 11);
    cout << " \n"; 
    delete vec2;


    vector<int> * vec3 = new vector<int>;
    for(int i = 0; i < 20; i++){
        vec3->push_back(100 + i);
    }
    int * tst3 = &vec3->front();
    print_vector(cout, tst3, 20);
    cout << " "; 
    delete vec3;

}


