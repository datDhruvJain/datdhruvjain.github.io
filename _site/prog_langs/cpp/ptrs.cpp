#include <iostream>
using namespace std;

int main () {
   int  var;
   int *ptr;
   int  val;

   var = 3000;

   // take the address of var
   ptr = &var;

   // take the value available at ptr
   val = *ptr;
   cout << "Value of var :" << var << endl;
   cout << "Value of ptr :" << ptr << endl;
   cout << "Value of val :" << val << endl;

   return 0;
}
