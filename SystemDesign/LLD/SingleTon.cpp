/******************************************************************************
SingleTon Design pattern -> used for getting one instance through
*******************************************************************************/
#include <iostream>
using namespace std;
class single{
    static single* instance;
    
    public:
    single(){}
    static single* createinstance(){
         if(instance==nullptr)  instance= new single();
        return instance;
    }
};
single* single::instance=nullptr;
int main()
{
    single *ptr1= single::createinstance();
    single *ptr2= single::createinstance();
    if(ptr1==ptr2) cout<<"same";
    else cout<<"not same";
    
    return 0;
}