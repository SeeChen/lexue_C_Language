/*
编写一个函数，给定的带有头结点的单向链表 head，给定某结点的数据域值 m，将该结点移到链首。
结构的定义：
typedef struct node{
  int num;
  struct node *next;
} SNODE;
函数的原型：SNODE *movenode(SNODE *head, int m);
其中：参数 head 是单向链表的头指针；参数 m 是某结点的num成员的值。
例如输入结点数 n=7，则将结点数值域值 m=5 的结点移动到链首。函数运行前后链表的情况如下图所示。
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct sdata{
	int num;
	struct sdata*next;
}SNODE;
void movenode(SNODE *head,int n){
	SNODE *x1,*x2;
	x1=x2=head;
	while((x2=x1->next)!=NULL){
		if(x2->num==n){
			x1->next=x2->next;
			x2->next=head->next;
			head->next=x2;
			break;
		}
		x1=x1->next;
	}
}
void setlink(SNODE *head,int n){
	SNODE *p;
	while(n>0){
		p=(SNODE*)malloc(sizeof(SNODE));
		p->num=n;
		p->next=head->next;
		head->next=p;
		n--;
	}
}
void outlink(SNODE *head){
	while(head->next!=NULL){
		head=head->next;
		printf("%d,",head->num);
	}
	return;
}
int main(){
	int n,m;
	SNODE *head=NULL;
	scanf("%d%d",&n,&m);
	head=(SNODE*)malloc(sizeof(SNODE));
	head->num=-1;
	head->next=NULL;
	setlink(head,n);
	movenode(head,m);
	outlink(head);
	printf("\n");
}
