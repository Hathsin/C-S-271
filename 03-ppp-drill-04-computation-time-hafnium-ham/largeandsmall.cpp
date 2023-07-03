//follow steps 1-5 on this cpp file 
#include "std_lib_facilities.h"

int main(){
   double x, y;     
   while (true)
   {
      if (!(cin >> x >> y)){
         break;
      }
     ///**
      if (x > y){
         cout << "the smaller value is:"<< y << '\n';
         cout << "the larger value is:"<< x << '\n';
         if (y + .01 >= x){
            cout << "the numbers are almost equal\n";
         }
      }
      else if (y > x){
         cout << "the smaller value is:"<< x << '\n';
         cout << "the larger value is:"<< y << '\n';
         if (x + .01 >= y){
            cout << "the numbers are almost equal\n";
         }
      }
      else if (x == y){
         cout << "the numbers are equal" << '\n';
      }
      else{
         break;
      }
      //*/
   }
   return 0;
}