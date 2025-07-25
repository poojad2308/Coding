/******************************************************************************
TypeCasting operator:
reinterpret_cast- basically it will convert pointer type , meaning here both the 
pointers are actually pointing to the same memery and we have used the existing
pointer only to convert it into char pointer.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int n = 97;
  
    // Store the address of number in nptr
    int* nptr = &n;

    // Reinterpreting the pointer as a char pointer
    char* charptr = reinterpret_cast<char*>(nptr);

    // Printing the memory addresses and values
     cout<<"Integer Address:"<< nptr<<endl;
     cout<<"Char Address:"<< &charptr<<endl;
    cout<<endl<<*charptr<<endl<<*nptr;

    return 0;
}
/* Output reinterpret_cast-
Integer Address:0x7fff37416cf4
Char Address:0x7fff37416cf4

a
97 .*/