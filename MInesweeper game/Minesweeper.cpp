#include "Minefield.h"
#include <iostream>
using namespace std;

int main() {
    int w,h;
    cout<<"Enter board width and height: ";
    cin>>w>>h;

    Minefield field(w,h);

    // Example bombs (you can extend to random placement)
    field.setBomb(0,0);
    field.setBomb(0,1);
    field.setBomb(1,1);
    if (h>4) field.setBomb(1,4);
    if (w>4 && h>2) field.setBomb(4,2);

    field.print();

    while(true) {
        int x,y;
        cout<<"Enter x y: ";
        if(!(cin>>x>>y)) break;

        if(!field.reveal(x,y)) {
            field.print(true);
            cout<<"BOOM! Game Over.\n";
            break;
        }

        field.print();

        if(field.allSafeRevealed()) {
            cout<<"Congratulations, you win!\n";
            break;
        }
    }
    return 0;
}
