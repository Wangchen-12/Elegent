#include<iostream>
#include<bits/stdc++.h>
#define MAXSIZE 10
using namespace std;
#define error 0
#define ok 0
//typedef struct {
//	int *elem;              //����һ���ṹ�� 
//	int length;
//}SqList;
//
//
//void initlist(SqList &L)
//{
//	L.elem=new int[MAXSIZE];
//	if(!L.elem)              //����һ���յ����Ա� 
//	exit(OVERFLOW);
//	L.length=0;
//} 
//
//
//int LengthList(SqList &L)
//{
//	return L.length;         //������Ա�ĳ��� 
// } 
// 
// 
// void shuchuList(SqList &L)
// {
// 	for(L.length=0;L.length<MAXSIZE;L.length++)  //������Ա����ֵ 
// 	cout<<L.elem[L.length]<<" ";
// }
// 
// 
// void ClearList(SqList &L)
// {
// 	L.length=0;              //������Ա� 
//  } 
//  
//  
//  int GetList(SqList &L,int i,int &e)
//  {
//  	if(i<0||i>L.length) return error;
//	  e=L.elem[i-1];                     //ȡ���Ա��еĵ�i��ֵ 
//	  return ok; 
//  }
//  
//  
//  int  AddList(SqList &L,int i,int e)
//  {
//  	if(i<0||(i>L.length+1))return error;
//  	if(L.length==MAXSIZE)
//  	return error;
//  	for(int j=L.length-1;j>=i-1;j--)    //�ڵ�i��λ�����һ��eֵ 
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
//	AddList(L,i,i);         //������Ӻ�������ʼ�����Ա� 
//	for(int i=1;i<10;i++)
//	{
//		GetList(L,i,e);     //������ȡ��������ȡ���Ա��ֵ 
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
		cout<<"�������"<<i+1<<"���˵����ֺ͵绰����"<<endl;
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
	cout<<"����"<<"\t"<<"�绰����"<<endl;
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
	printf("----ͨѶ¼(������)---\n");
	printf("1.����\n");
	printf("2.ȡֵ\n");
	printf("3.����\n");
	printf("4.����\n");
	printf("5.ɾ��\n");
	printf("6.���\n");
	printf("7.����\n");
	printf("8.�ϲ�\n");
	printf("0.�˳�\n");
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
		cout<<"��ѡ��Ҫִ�е�����"<<endl;
	cin>>a;
		switch(a){
		case 0:
				cout<<"�ɹ��˳�"<<endl;
				return 0;
		case 1:
			cout<<"���������봴����Ԫ�ظ���"<<endl;
			cin>>n;
			creatlist(L,n);
			cout<<"�����ɹ�"<<endl;
			break;
		case 2:
			cout<<"�������ȡ��λ��"<<endl;
			cin>>n;
			if(getelem(L,n,m,v))
			{
				cout<<"��ȡ��λ�õ���Ϣ��";
			cout<<m<<"\t"<<v<<endl;
			}
			else
			cout<<"��Ǹû���ҵ���Ӧ����Ϣ"<<endl;
			break;
		case 3:
			cout<<"����������Ҫ�ҵ��˻�绰����"<<endl;
			char e;cin>>e;
			p=findlist(L,e);
			if(p!=NULL)
			cout<<"��Ҫ�ҵ��˵ĺ�����"<<p->data.number<<endl;
			else
			cout<<"���ź���û���ҵ���Ӧ����"<<endl;
			break;
		case 4:
			cout<<"�����������ڵڼ���λ�ò�������"<<endl;
			cout<<"������������ݵ����ֺ͵绰����"<<endl;
			cin>>m;cin>>v;
			if(insertlist(L,n,m,v))
			cout<<"����ɹ�"<<endl;
			else
			cout<<"����ʧ��"<<endl; 
			break;
		case 5:
			cout<<"����������ɾ����Ԫ��λ��"<<endl;
			if(deletelist(L,n))/////////////////////////z���������⣬����ִ������Ĵ���/// 
			cout<<"ɾ��Ԫ�سɹ�"<<endl;
			else
			cout<<"ɾ��Ԫ��ʧ��"<<endl;
			break;
		case 6:
		    output(L);
			break;
			
	    }	 
	}while(a);
	cout<<"�����˳�����"<<endl; 
}
























