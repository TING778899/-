#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//结构体命名为S 
typedef struct Shoppingitem{
	char name[50];
	int quantity;
	struct Shoppingitem* next;	
}S;
//一：添加商品的函数 
void additem(S *q,char itemName[],int itemQuantity)
{
	S *newitem=(S *)malloc(sizeof(S));
	strcpy(newitem->name,itemName);
	newitem->quantity=itemQuantity;
	newitem->next=NULL;
	q->next=newitem;
	q=newitem;
}
//二：从购物清单中移除商品
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
//三：查看购物清单
void displayList(S *h){
	S *current=h;
	printf("购物清单：\n");
	while(current!=NULL)
	{
		printf("%s-数量:%d\n",current->name,current->quantity);
		current-current->next;
	}
} 
//四：修改购物清单中商品的数量
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
//五：清空购物清单
void clearlist(S *h)
{
	while(h!=NULL)
	{
		S *t=h;
		h=h->next;
		free(t); 
	}
 } 
//六：计算购物清单中商品的总数量
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
//七：查看购物清单中的商品 
void finditem(S *h,char itemName[])
{
	S *current=h;
	printf("查找商品%s:\n",itemName);
	while(current!=NULL)
	{
		if(strcmp(current->name,itemName)==0)
		{
			printf("%s-数量:%d\n",current->name,current->quantity);
			return;
		 } 
		 current=current->next;
	}
	printf("未找到商品%s:\n",itemName);
 } 
//八：排序购物清单
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
				//交换商品信息
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
//九：合并购物清单
void mergelists(S **h1,S **h2){
	S *current=*h1;
	//遍历到第一个购物清单的末尾
	while(current->next!=NULL)
	 	current=current->next;
	current->next=*h2;
	*h2=NULL;//清空第二个购物清单的头指针，防止误用 
} 
//十：删除购物清单中的商品
//实现一个函数，可以根据商品名称删除购物清单中的商品项目
//如果有多个相同名称的商品，可以选择删除购物清单中的商品项目。
//如果有多个相同名称的商品，可以选择一个或者全部。
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
			//如果要删除的是第一个节点
			S *t=h;
			h=h->next;
			free(t);
			if(!deleteAll)break; 
			}else{
			//如果要删除的不是第一个节点
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
//主函数主函数主函数！！！ 
//创建总数为num个物品的购物清单 
int main()
{
	S *p;
	S *q=(S *)malloc(sizeof(S));//代表购物清单最后一个商品 
	S *h=(S *)malloc(sizeof(S));
	q->next=NULL;
	h->next=NULL;
	int num;
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		//头插法创建购物清单 
		p=(S *)malloc(sizeof(S));
		scanf("%s",p->name);
		scanf("%d",&p->quantity);
		if(i=0) q=p;
		p->next=h->next;
		h->next=p;
	}
	return 0;
} 
