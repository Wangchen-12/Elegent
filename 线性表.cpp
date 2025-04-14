#include<iostream>
#include<bits/stdc++.h>
#define MAXSIZE 10
using namespace std;
#define error 0
#define ok 0
//typedef struct {
//	int *elem;              //定义一个结构体 
//	int length;
//}SqList;
//
//
//void initlist(SqList &L)
//{
//	L.elem=new int[MAXSIZE];
//	if(!L.elem)              //创建一个空的线性表 
//	exit(OVERFLOW);
//	L.length=0;
//} 
//
//
//int LengthList(SqList &L)
//{
//	return L.length;         //输出线性表的长度 
// } 
// 
// 
// void shuchuList(SqList &L)
// {
// 	for(L.length=0;L.length<MAXSIZE;L.length++)  //输出线性表的数值 
// 	cout<<L.elem[L.length]<<" ";
// }
// 
// 
// void ClearList(SqList &L)
// {
// 	L.length=0;              //清空线性表 
//  } 
//  
//  
//  int GetList(SqList &L,int i,int &e)
//  {
//  	if(i<0||i>L.length) return error;
//	  e=L.elem[i-1];                     //取线性表中的第i个值 
//	  return ok; 
//  }
//  
//  
//  int  AddList(SqList &L,int i,int e)
//  {
//  	if(i<0||(i>L.length+1))return error;
//  	if(L.length==MAXSIZE)
//  	return error;
//  	for(int j=L.length-1;j>=i-1;j--)    //在第i个位置添加一个e值 
//  	L.elem[j+1]=L.elem[j];
//  	L.elem[i-1]=e;
//  	L.length++;
//  	return ok;
//   } 
// 
// 
// int EraseList(SqList &L,int i)
// {
// 	if(i<0||(i>L.length+1))return error;
// 	for(int j=i;j<=L.length-1;j++)
// 	L.elem[j-1]=L.elem[j];
// }
//int main()
//{
//	SqList L;
//	int e;
//	initlist(L);
//	for(int i=1;i<10;i++)
//	AddList(L,i,i);         //利用添加函数来初始化线性表 
//	for(int i=1;i<10;i++)
//	{
//		GetList(L,i,e);     //利用提取函数来提取线性表的值 
//		cout<<e<<" ";
//	}
// } 
typedef struct book{
	char name[20];
	char number[20];
}elemtype; 
typedef struct Lnode{
	elemtype data;
	Lnode *next;
}Lnode,*linklist;
void creatlist(linklist &L,int n)
{
	L=new Lnode;
	L->next=NULL;
	Lnode *p,*r=L;
	for(int i=0;i<n;i++)
	{
		p=new Lnode;
		cout<<"请输入第"<<i+1<<"个人的名字和电话号码"<<endl;
		cin>>p->data.name>>p->data.number;
		p->next=NULL;
		r->next=p;
		r=p;
	} 
}

void output(linklist L)
{
	Lnode *p;
	p=L->next;
	cout<<"姓名"<<"\t"<<"电话号码"<<endl;
	while(p)
	{
		cout<<p->data.name<<"\t"<<p->data.number<<endl;
		p=p->next;
	}
}

Lnode *findlist(linklist &L,char e)
{
	linklist p;
	p=L->next;
	while(p&&*p->data.name!=e)
	{
		p=p->next;
	}
	
	return p;
}

int insertlist(linklist &L,int i,char m,char n)
{
	Lnode *r=L;int j=0;
	while(r&&(j<i-1))
	{
		r=r->next;++j;
	}
	if(!r||j>i-1)return 0;
	Lnode *s=new Lnode;
	*s->data.name=m;
	*s->data.number=n;
	s->next=r->next;
	r->next=s;
	return 1;
}

int deletelist(linklist &L,int i)
{
	Lnode *p,*q;int j=0;
	while((p->next)&&(j<i-1))
	{
		p=p->next;++j;
	}
	if(!(p->next)||(j>i-1))return 0;
	q=p->next;
	p->next=q->next;
	free(q);
	return 1;
}

int getelem(linklist L,int i,char &e,char &v)
{
	Lnode *p=L->next;
	int j=1;
	while(p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)return 0;
	e=*p->data.name;
	v=*p->data.number;
	return 1;
}
void menu()
{
	printf("----通讯录(单链表)---\n");
	printf("1.创建\n");
	printf("2.取值\n");
	printf("3.查找\n");
	printf("4.插入\n");
	printf("5.删除\n");
	printf("6.输出\n");
	printf("7.逆序\n");
	printf("8.合并\n");
	printf("0.退出\n");
	printf("---------------------\n");
}
int main()
{
	linklist L;
	Lnode *p;
	char vvv,m,v;
	int a;
	int n;
	menu();
	do{
		cout<<"请选你要执行的命令"<<endl;
	cin>>a;
		switch(a){
		case 0:
				cout<<"成功退出"<<endl;
				return 0;
		case 1:
			cout<<"请输入你想创建的元素个数"<<endl;
			cin>>n;
			creatlist(L,n);
			cout<<"操作成功"<<endl;
			break;
		case 2:
			cout<<"输出你想取的位置"<<endl;
			cin>>n;
			if(getelem(L,n,m,v))
			{
				cout<<"你取的位置的信息是";
			cout<<m<<"\t"<<v<<endl;
			}
			else
			cout<<"抱歉没有找到相应的信息"<<endl;
			break;
		case 3:
			cout<<"请输入你想要找的人或电话号码"<<endl;
			char e;cin>>e;
			p=findlist(L,e);
			if(p!=NULL)
			cout<<"你要找的人的号码是"<<p->data.number<<endl;
			else
			cout<<"很遗憾，没有找到相应的人"<<endl;
			break;
		case 4:
			cout<<"请输入你想在第几个位置插入数据"<<endl;
			cout<<"请输入插入数据的名字和电话号码"<<endl;
			cin>>m;cin>>v;
			if(insertlist(L,n,m,v))
			cout<<"插入成功"<<endl;
			else
			cout<<"插入失败"<<endl; 
			break;
		case 5:
			cout<<"请输入你想删除的元素位置"<<endl;
			if(deletelist(L,n))/////////////////////////z这里有问题，不会执行下面的代码/// 
			cout<<"删除元素成功"<<endl;
			else
			cout<<"删除元素失败"<<endl;
			break;
		case 6:
		    output(L);
			break;
			
	    }	 
	}while(a);
	cout<<"你已退出界面"<<endl; 
}
























