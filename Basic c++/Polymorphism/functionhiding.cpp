#include <iostream>
#include<cstring>
using namespace std;
class base{
    public:
    virtual void show(int x){
        cout<<"integer value x"<<x;
    }
};
class derived: public base{
    public:
    using base::show;
    void show(string ptr)  {
        cout<<"name"<<ptr;
    }
};

int main(){
    derived *ptr = new derived();
    ptr->show(5);
    ptr->show("Pooja");

    return 0;
}