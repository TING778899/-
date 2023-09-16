#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//�ṹ������ΪS 
typedef struct Shoppingitem{
	char name[50];
	int quantity;
	struct Shoppingitem* next;	
}S;
//һ�������Ʒ�ĺ��� 
void additem(S *q,char itemName[],int itemQuantity)
{
	S *newitem=(S *)malloc(sizeof(S));
	strcpy(newitem->name,itemName);
	newitem->quantity=itemQuantity;
	newitem->next=NULL;
	q->next=newitem;
	q=newitem;
}
//�����ӹ����嵥���Ƴ���Ʒ
void removeitem(S *h,char itemName[])
{
	S *current=h;
	S *previous=NULL;
	while(current!=NULL)
	{
		if(strcmp(current->name,itemName)==0)
		{
			if(previous!=NULL)
			{
				previous->next=current->next;
			}else{
				h=current->next;
			}
			free(current);
			break;
		}
		previous=current;
		current=current->next;
	}
}
//�����鿴�����嵥
void displayList(S *h){
	S *current=h;
	printf("�����嵥��\n");
	while(current!=NULL)
	{
		printf("%s-����:%d\n",current->name,current->quantity);
		current-current->next;
	}
} 
//�ģ��޸Ĺ����嵥����Ʒ������
void updateQuantity(S *h,char itemName[],int newitemQuantity)
{
	S *current=h;
	while(current!=NULL)
	{
		if(strcmp(current->name,itemName)==0)
		{
			current->quantity=newitemQuantity;
			break;
		}
		current=current->next; 
	}
 } 
//�壺��չ����嵥
void clearlist(S *h)
{
	while(h!=NULL)
	{
		S *t=h;
		h=h->next;
		free(t); 
	}
 } 
//�������㹺���嵥����Ʒ��������
int totalQuantity(S *h)
{
	S *current=h;
	int total=0;
	while(current!=NULL)
	{
		total=total+current->quantity;
		current=current->next;
	}
	return total;
}
//�ߣ��鿴�����嵥�е���Ʒ 
void finditem(S *h,char itemName[])
{
	S *current=h;
	printf("������Ʒ%s:\n",itemName);
	while(current!=NULL)
	{
		if(strcmp(current->name,itemName)==0)
		{
			printf("%s-����:%d\n",current->name,current->quantity);
			return;
		 } 
		 current=current->next;
	}
	printf("δ�ҵ���Ʒ%s:\n",itemName);
 } 
//�ˣ��������嵥
void sortlist(S *h)
{
	S *current=h;
	S *nextitem=NULL;
	char tempname[50];
	int tempQuantity;
	while(current!=NULL)
	{
		nextitem=current->next;
		while(nextitem!=NULL)
		{
			if(strcmp(current->name,nextitem->name)>0)
			{
				//������Ʒ��Ϣ
				 strcpy(tempname,current->name);
				 strcpy(current->name,nextitem->name);
				 strcpy(nextitem->name,current->name);
				 tempQuantity=current->quantity;
				 current->quantity=nextitem->quantity;
				 nextitem->quantity=tempQuantity;
			}
			nextitem=nextitem->next;
		}
		current=current->next;
	}
 } 
//�ţ��ϲ������嵥
void mergelists(S **h1,S **h2){
	S *current=*h1;
	//��������һ�������嵥��ĩβ
	while(current->next!=NULL)
	 	current=current->next;
	current->next=*h2;
	*h2=NULL;//��յڶ��������嵥��ͷָ�룬��ֹ���� 
} 
//ʮ��ɾ�������嵥�е���Ʒ
//ʵ��һ�����������Ը�����Ʒ����ɾ�������嵥�е���Ʒ��Ŀ
//����ж����ͬ���Ƶ���Ʒ������ѡ��ɾ�������嵥�е���Ʒ��Ŀ��
//����ж����ͬ���Ƶ���Ʒ������ѡ��һ������ȫ����
void deleteitem(S *h,char itemName[],int deleteAll)
{
	S *current=h;
	S *prev=NULL;
	while(current!=NULL)
	{
		if(strcmp(current->name,itemName)==0)
		{
			if(prev==NULL)
			{
			//���Ҫɾ�����ǵ�һ���ڵ�
			S *t=h;
			h=h->next;
			free(t);
			if(!deleteAll)break; 
			}else{
			//���Ҫɾ���Ĳ��ǵ�һ���ڵ�
			prev=current;
			free(current);
			current=prev->next;
			if(!deleteAll)break; 
			}
		}else{
			prev=current;
			current=current->next;
			}
	}
 }  
//������������������������ 
//��������Ϊnum����Ʒ�Ĺ����嵥 
int main()
{
	S *p;
	S *q=(S *)malloc(sizeof(S));//�������嵥���һ����Ʒ 
	S *h=(S *)malloc(sizeof(S));
	q->next=NULL;
	h->next=NULL;
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		//ͷ�巨���������嵥 
		p=(S *)malloc(sizeof(S));
		scanf("%s",p->name);
		scanf("%d",&p->quantity);
		if(i=0) q=p;
		p->next=h->next;
		h->next=p;
	}
	return 0;
} 
