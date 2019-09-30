#include <iostream>
using namespace std;

int main() {
   [](){
       cout << "Hello lambda World!\n"; 
   }();

   auto lambda  = [](double x)
   {
       return x*x;
   };

   cout << lambda(3.0) << "\n";


   return 0;
}