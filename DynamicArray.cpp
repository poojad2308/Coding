/******************************************************************************

Dynamic Array implementaion

*******************************************************************************/
#include <iostream>
#include <stdexcept>
using namespace std;
class myvector{
    private:
    int *data;
    size_t size; //size of the vector
    size_t capacity; // capacity of the array  
    public:
    myvector():data(new int[1]),size(0),capacity(1){}
    void resize(int new_capacity){
        int *new_data= new int[new_capacity];
        for(int i=0;i<size;i++){
            new_data[i]=data[i];
        }
        delete[] data;
        capacity=new_capacity;
        data= new_data;
    }
    // function for push_back
    void push_back(int val){
        if(size==capacity) resize(2*capacity);
        data[size++]=val;
    }
    //function of pop_back
    void pop_back(){
        if(size==0) throw out_of_range("Index outof range");
        size=size-1;    
    }
    int getsize() const{
        return size;
    }
    int getcapacity(){
        return capacity;
    }
    int at(int index){
        if(index>=size){
            throw out_of_range("index of outof range");
        }
        return data[index];
    }
    ~myvector(){
        delete[] data;
    }
};
int main()
{
    myvector vec;
    for(int i=0;i<10;i++){
        vec.push_back(i);
    }
    for(int i=0;i<vec.getsize();i++){
        cout<<vec.at(i);
    }
    cout<<vec.getsize();
    

    return 0;
}