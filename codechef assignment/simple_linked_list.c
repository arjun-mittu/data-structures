#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

//head->next = NULL;
node *l_l_1(int n){
	node *head = NULL;
	node *p = NULL;
	node *temp = NULL;
	int i=0;
	
	for(;i<n;i++){
	temp = (node*)malloc(sizeof(node));
		scanf("%d",&(temp->data));
		temp->next = NULL;
		
	if(head == NULL){
		head = temp;
	}
	else{
		
		p=head;
	while(p->next!=NULL){
			p= p->next;
		}
		p->next = temp;
	} 
	
	}
	 
	 return head;
		
}
main(){
	node *head;
	int n;
	scanf("%d",&n);
	head=l_l_1( n );
	node *p;
	p=head;
	while(p!=NULL){
		printf("\n %d",p->data);
		p=p->next;
	}
	
}




