#include<iostream>
#include<bits/stdc++.h>
using namespace std;
//class Animal{
//	public:
//		virtual void speak();
//}; 
//void Animal::speak()
//{
//	cout<<"�������"<<endl;
//}
//class cat:public Animal{
//	public:
//		virtual void speak();
//};
//void cat::speak()
//{
//	cout<<"è�Ľ���������"<<endl;
//}
//class dog:public Animal{
//	public:
//		virtual void speak();
//};
//void dog::speak()
//{
//	cout<<"���Ľ���������"<<endl;
//}
//int main(){
//	cat a1;
//	Animal *pa=&a1;
//	pa->speak();//�����ԣ���ȥ��virtual��Ĵ��������ͼ��ݣ�����virtual�󣬵�����������麯����������麯������˼�������ʹ�������࣬�����ǻ���ĺ��� 
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
    derived b;//����base��Ϊ�����࣬���ܶ������
    b.p();
    return 0;
}

