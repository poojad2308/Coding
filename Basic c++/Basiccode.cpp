/****************************************************************************** 
Welcome to GDB Online. 
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,  

  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS 

  Code, Compile, Run and Debug online from anywhere in world. 
*******************************************************************************/ 

#include <iostream> 
# include<cstring> 
using namespace std; 

class base{ 
    char *str; 
    public: 
    base(char *ptr){ 
        str= new char[strlen(ptr)+1]; 
        strcpy(str,ptr); 
        cout<<"constructor"<<endl; 
    } 
    base(const base &source){ 
        str= new char[strlen(source.str)+1]; 
        strcpy(str,source.str); 
        cout<<"copy constructor"<<endl; 
    } 
    base(base &&source){ 
        str=source.str; 
        source.str; 
        cout<<"move constructor"<<endl; 
    } 
    base& operator =(const base &source){ 
        if(this!=&source){ 
            str= new char[strlen(source.str)+1]; 
            strcpy(str,source.str); 
        } 
        cout<<"assignment "<<endl; 
        return *this; 
    } 
    base& operator =(base &&source){ 
        if(this!=&source){ 
            str=source.str; 
            source.str; 
        } 
        cout<<"move assignment "<<endl; 
        return *this; 
    } 
    friend istream& operator >>(istream &in,base &source){ 
        char buffer[100]; 
        in>>buffer; 
        source.str= new char[strlen(buffer)+1]; 
        strcpy(source.str,buffer); 
        cout<<"istream "<<endl; 
        return in ; 
    } 
    friend ostream& operator <<(ostream &out,base &source){ 
        out<<source.str; 
        cout<<"oustream "<<endl; 
        return out ; 
    } 
}; 

int main() 
{ 
    base obj("pooja"); 
    base obj1(obj); 
    base obj2(move(obj)); 
    obj1=obj2; 
    obj1=move(obj2); 
    cin>>obj2; 
    cout<<obj2; 
    cout<<"------------------------------------------"; 
    cout<<"pointer way of declaring all these"; 
    cout<<"------------------------------------------"<<endl; 
    base *ptr1=new base("anju"); 
    base *ptr2 = new base(*ptr1); 
    base *ptr3= new base(move(*ptr2)); 
    *ptr3=*ptr2; 
    *ptr3=move(*ptr2); 
    cin>>*ptr3; 
    cout<<*ptr3; 
    return 0; 
} 