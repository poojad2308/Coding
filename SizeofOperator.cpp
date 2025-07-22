#include<iostream>
using namepspace std;
#define mysizeof(x)   (char*)(&x+1)-(char*)(x);
int main(){
    int x=0;
    int char ='a';
    int arr[2];
    cout<<mysizeof(x);
    cout<<mysizeof(char);
    cout<<mysizeof(arr);
}