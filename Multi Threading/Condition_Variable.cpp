/******************************************************************************
In this thread problem i am printing odd first untill i reached 61 and then 
after I am printing all the even number.

*******************************************************************************/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;
condition_variable cv;
mutex m;
int oddturn;
void print_even(){
    int j=100;
    unique_lock<mutex> lock(m);
    cv.wait(lock, [] { return oddturn==1; });
    for(auto i=1;i<=j;i++){
        if(i%2==0) cout<<"T1-"<<i<<endl;
    }
}
void print_odd(){
    int j=100;
    unique_lock<mutex> lock(m);
    for(auto i=1;i<j;i++){
        if(i%2!=0) cout<<"T2-"<<i<<endl;
        if(i==61){ oddturn=1;
        cv.notify_all();
        break;
        }
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