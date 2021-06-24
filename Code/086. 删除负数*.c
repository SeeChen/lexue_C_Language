/*
一个带有表头节点的链表中，链表的每个节点保存了非零的整型数据。现请编写函数删除已有的链表中所有数值小于0的节点。
说明：（1）用带表头的单向链表的方式保存数据，每一个节点的数值域保存一个非零整型数。
（2）预设代码包括主函数、建立链表函数、输出链表函数，请编写删除链表中所有数值小于0的节点的函数。
结构的定义：
struct node{
  int data;  struct node *next;
};
typedef struct node NODE;
typedef struct node * PNODE;
删除所有无效数值结点的函数原型：void deleteneg(PNODE head)，
其中：参数head是带有头结点的单向链表的头指针。
程序输入：在建立链表时，每次插入到头结点后的结点数据，以0为结束。
*/
#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node NODE;
typedef struct node *PNODE;
PNODE constructlist(PNODE head,int num);
void outlist(PNODE head);
void deleteneg(PNODE head);
int main(){
	int num=1;
	PNODE head;
	head=(PNODE)malloc(sizeof(NODE));
	head->next=NULL;
	head->data=-1;
	while(num!=0){
		scanf("%d",&num);
		if(num!=0)
		constructlist(head,num);
	}
	deleteneg(head);
	outlist(head);
	return 0;
}
PNODE constructlist(PNODE head,int num){
	PNODE p;
	p=(PNODE)malloc(sizeof(NODE));
	p->data=num;
	p->next=head->next;
	head->next=p;
	return head;
}
void outlist(PNODE head){
	PNODE p;
	p=head->next;
	while(p!=NULL){
		printf("%d\n",p->data);
		p=p->next;
	}
}
void deleteneg(PNODE head){
	PNODE p=head->next,prev=NULL;
	while(p!=NULL){
		if(p->data<0){
			if(prev==NULL){
				head->next=p->next;
				free(p);
				p=head->next;
			}else{
				prev->next=p->next;
				free(p);
				p=prev;
				p=p->next;
			}
		}else{
			prev=p;
			p=p->next;
		}
	}
}
