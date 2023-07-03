//follow remaining steps on this cpp file 
#include "std_lib_facilities.h"

int main(){
    double x, smol, big, running;   
    bool once = true;
    string measure;
    vector<double> vals;
    while (true)
    {
        if(!(cin >> x >> measure)){
            break;
        }
        ///*

        if(measure == "cm"){
            x /= 100;
        }
        else if(measure == "m"){
            x = x;
        }
        else if(measure == "in"){
            x *= 0.0254;
        }
        else if(measure == "ft"){
            x *= 0.3048;
        }
        else{
            //cout << "invalid unit\n";
            break;
        }
        
        vals.push_back(x);
        running += x;
//*/
        cout << x << " ";
        ///*
        if(once){
                smol = x;
                big = x;
                cout << "that is the largest so far\n";
                once = false;
            }
        if (x > big){
            cout << "that is the largest so far\n";
            big = x;
            
        }
        else if (x < smol){
            cout << "that is the smallest so far\n";
            smol = x;
        }
   }
   if(!(vals.size() == 0)){
        sort(vals);
        cout << "smallest:" << smol << '\n' << "largest:" << big << '\n' << "sum:" << running << '\n';
        for(double temp: vals){
            cout << temp << '\n';
        }
   }
   else{
        cout << "smallest:\n" << "largest:\n" << "sum:\n";
   }
   //*/
}