#include<iostream>
using namespace std;
//sizeof operator simple way
#define mysizeof(x)   (char*)(&x+1)-(char*)(&x);
int main(){
    int x=0;
    char ch ='a';
    int arr[2];
    cout<<mysizeof(x);
    cout<<mysizeof(ch);
    cout<<mysizeof(arr);
}