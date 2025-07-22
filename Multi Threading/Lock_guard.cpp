/******************************************************************************
Unique lock can be is different from loack gurd as unique lock can be lock any 
part of the code and Lock guard can not behave like that .
like we can declare unique lock and lock it later in code via lock.lock()
but this is not the case with lock guard as it will imijiatly lock the code once declare.

*******************************************************************************/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
condition_variable cv;
mutex m;
void print_even(){
    int j=100;
    lock_guard<mutex> lock(m);
    for(auto i=1;i<=j;i++){
        if(i%2==0) cout<<i<<endl;
    }
}
void print_odd(){
    int j=100;
    lock_guard<mutex> lock(m);
    for(auto i=1;i<j;i++){
        if(i%2!=0) cout<<i<<endl;
    }
}
int main()
{
    thread t1(print_even);
    thread t2(print_odd);
    t1.join();
    t2.join();
    return 0;
}