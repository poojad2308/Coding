/******************************************************************************
smart pointers question
line no. 19 -now with count also increase and also we can only use weak pointer 
when it is locked.
*******************************************************************************/
#include <iostream>
#include<memory>
using namespace std;
int main()
{
    unique_ptr<int>ptr= make_unique<int>(5);
    cout<<"ptr="<<*ptr<<endl;
    shared_ptr<int>ptr1= make_shared<int>(6);
    cout<<"ptr1="<<*ptr1;
    shared_ptr<int>ptr2= ptr1;
    cout<<"ptr2="<<*ptr2;
    weak_ptr<int>ptr3=ptr2;
    cout<<ptr3.use_count();
    if(auto weak_pt=ptr3.lock()){
        cout<<"weak_pt"<<*weak_pt<<"count"<<weak_pt.use_count();
    }
    return 0;
}