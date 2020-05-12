#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;
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
node *l_l_2(node *head_1,int n){
	node *head = NULL;
	node *p = NULL;
	node *temp = NULL;
	node *ll1;
	ll1=head_1;
	int i=0;
	int k=0;
	while(ll1!=NULL && k<n){
		if(i%2==0){
			temp = (node*)malloc(sizeof(node));
			int s;
			s=ll1->data+(ll1->next->next->data);
			temp->data=s;
			temp->next = NULL;
			i=i+2;
			k=k+1;
			ll1=ll1->next->next;
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
		else{
		i=i+1;
		ll1=ll1->next;
		}
		}
	
	 return head;
	
}
node *l_l_3(node *head_1,int n){
	node *head = NULL;
	node *p = NULL;
	node *temp = NULL;
	node *ll1;
	ll1=head_1;
	int i=1;
	int k=0;
	while(ll1!=NULL && k<n){
		if(i%2==0){
			temp = (node*)malloc(sizeof(node));
			int s;
			s=ll1->data+(ll1->next->next->data);
			temp->data=s;
			temp->next = NULL;
			i=i+2;
			k=k+1;
			ll1=ll1->next->next;
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
		else{
		i=i+1;
		ll1=ll1->next;
		}
		}
	
	 return head;
	
}
int mid_ll(node *head){
	int s=0;
	node *p;
	p=head;
	s=s+p->data;
	while(p->next!=NULL){
		p=p->next;
	}
	s=s+p->data;
	return s;
}
node *update_1(node *ll1,node *ll2,node *ll3,int mid,int n,int m){
	node *head = NULL;
	node *p = NULL;
	node *temp = NULL;
	node *p1=ll1;
	node *p2=ll2;
	node *p3=ll3;
	int i=1;
	
	for(;i<=m;i++){
	temp = (node*)malloc(sizeof(node));
		if(i%2!=0){
			temp->data=p1->data;
			p1=p1->next;
		}
		else{
			if(i<(m/2)+1){
				temp->data=p2->data;
				p2=p2->next;
			}
			if(i==(m/2)+1){
				temp->data=mid;
			}
			if(i>(m/2)+1){
				temp->data=p3->data;
				p3=p3->next;
			}
		}
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
void display_ll(node *head){
	node *p;
	p=head;
	while(p!=NULL){
		printf("%d ",p->data);
		p=p->next;
	}
}
main(){
	node *head_1;
	node *head_2;
	node *head_3;
	node *head_4;
	int n,m,mid;
	scanf("%d",&n);m=(4*n)-1;
	head_1=l_l_1(2*n);
	head_2=l_l_2(head_1,n-1);
	head_3=l_l_3(head_1,n-1);
	display_ll(head_2);
	printf("\n");
	display_ll(head_3);
	mid=mid_ll(head_1);
	printf("\n%d\n",mid);
	head_4=update_1(head_1,head_2,head_3,mid,n,m);
	display_ll(head_4);
	printf("\n%d",m);
	
}




