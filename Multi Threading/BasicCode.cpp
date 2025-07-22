/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
mutex m;
void print_even(){
    int j=100;
    m.lock();
    for(auto i=1;i<=j;i++){
        if(i%2==0) cout<<i<<endl;
    }
    m.unlock();
}
void print_odd(){
    int j=100;
     m.lock();
    for(auto i=1;i<j;i++){
        if(i%2!=0) cout<<i<<endl;
    }
     m.unlock();
}
int main()
{
    thread t1(print_even);
    thread t2(print_odd);
    t1.join();
    t2.join();
    return 0;
}