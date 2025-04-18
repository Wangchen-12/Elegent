#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//class Animal{
//	public:
//		virtual void speak();
//}; 
//void Animal::speak()
//{
//	cout<<"动物叫声"<<endl;
//}
//class cat:public Animal{
//	public:
//		virtual void speak();
//};
//void cat::speak()
//{
//	cout<<"猫的叫声：喵喵"<<endl;
//}
//class dog:public Animal{
//	public:
//		virtual void speak();
//};
//void dog::speak()
//{
//	cout<<"狗的叫声：汪汪"<<endl;
//}
//int main(){
//	cat a1;
//	Animal *pa=&a1;
//	pa->speak();//很明显，在去掉virtual后的代码是类型兼容，但是virtual后，调用派生类的虚函数代替基类虚函数，意思就是你会使用派生类，而不是基类的函数 
//	dog a2;
//	Animal *pb=&a2;
//	pb->speak();
//}
class base {
public:
    base() {}
    /*virtual void print() {
        cout << "base print" << endl;
    }*/
    virtual void print() = 0;
    void p() {
        cout << "base p" << endl;
    }
    virtual ~base() {}    
};

class derived :public base{
public:
    derived(){}
    virtual void print() {
        cout << "derived function" << endl;
    }
    ~derived(){}
};
int main()
{
    derived b;//错误，base作为抽象类，不能定义对象
    b.p();
    return 0;
}

