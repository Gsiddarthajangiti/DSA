#include<stdio.h>
#include<stdlib.h>
int len;
struct node{
	int data;
	struct node* link;
};
struct node1{
	int data1;
	struct node1* link1;
};
struct node* root=NULL;
struct node1* root1=NULL;
void append();
void addatbegin();
void insert();
int length();
void display();
void delete();
void search();
void concatenation();
void reverse();
void sorting();
int main(){
	int ch;
	while(1){
		printf("linked list operations\n");
		printf("1.append\n");
		printf("2.addatbegin\n");
		printf("3.insert\n");
		printf("4.length\n");
		printf("5.display\n");
		printf("6.delete\n");
		printf("7.search\n");
		printf("8.concatination\n");
		printf("9.reverse\n");
		printf("10.sorting\n");
		printf("11.quit\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1 : append();
		         	 break;
			case 2 : addatbegin();
		         	 break;
			case 3 : insert();
		         	 break;
			case 4 : len=length();
					 printf("the length of linked list=%d\n",len);
		         	 break;
	    	case 5 : display();
	             	 break;
	    	case 6 : delete();
	             	 break;
	        case 7 : search();
	        		 break;
	        case 8 : concatenation();
	                 break;
	        case 9 : reverse();
	                 break;
	        case 10 : sorting();	
	        		 break;
	    	case 11 : exit(1);
	    	default : printf("invalid input\n");
		}	
		
	
 }
 return 0;		
}
void append(){
	int i,n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
	struct node* temp;
	struct node1* temp1;
	temp=(struct node*)malloc(sizeof(struct node));
	temp1=(struct node1*)malloc(sizeof(struct node1));
	printf("Enter the data of first linked list:");
	scanf("%d",&temp->data);
	printf("Enter the data of second linked list:");
	scanf("%d",&temp1->data1);
	temp->link=NULL;
	temp1->link1=NULL;
	if(root==NULL||root1==NULL){
		root=temp;
		root1=temp1;
	}
	else{
		struct node* p=root;
		struct node1* q=root1;
		while(p->link!=NULL||q->link1!=NULL){
			p=p->link;
			q=q->link1;
		}
		p->link=temp;
		q->link1=temp1;
		
	}
}
}
void addatbegin(){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	if(root==NULL){
		root=temp;
	}
	else{
		temp->link=root;
		root=temp;
	}
}
void insert(){
	struct node*temp;
	int loc,i=1;
	printf("Enter the location:");
	scanf("%d",&loc);
	if(loc>length()){
		printf("invalid input");
	}
	else{
		struct node* temp,*p=root;
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data:");
		scanf("%d",&temp->data);
		temp->link=NULL;
		while(i<loc-1){
			p=p->link;
			i++;
		}
		temp->link=p->link;
		p->link=temp;
		
		
		
	}
	
}
void display(){
	struct node* temp=root;
	if(root==NULL){
		printf("list is empty");
	}
	else{
		while(temp!=NULL){
		printf("%d-->",temp->data);
		temp=temp->link;
	}
		
	}
	
}
int length(){
	struct node* temp=root;
	int count=0;
	while(temp!=NULL){
		temp=temp->link;
		count++;
	}
	return count;
}
void delete(){
	struct node* temp;
	int loc;
	printf("Enter the location\n");
	scanf("%d",&loc);
	if(loc>length()){
		printf("invalid input");
	}
	else if(loc==1){
		temp=root;
		root=temp->link;
		temp->link=NULL;
		free(temp);
	}
	else{
		struct node *p=root,*q;
		int i=1;
		while(i<loc-1){
			p=p->link;
			i++;
		}
		q=p->link;
		p->link=q->link;
		q->link=NULL;
		free(q);
	}
}
void search(){
	struct node* temp=root;
	int search;
	int pos=0;
	printf("Enter the number that you want to search:");
	scanf("%d",&search);
	if(root==NULL){
		printf("list is empty");
	}
	else{
		while(temp!=NULL){
			pos++;
			if(search==temp->data){
				printf("element found=%d, loc=%d\n",temp->data,pos);
			}
			temp=temp->link;
		}
	}
}
void concatenation()
{
	struct node* p;
	p=root;
	
	while(p->link!=NULL){
		p=p->link;
	}
	p->link=root1;	
}
void reverse(){
	struct node *prevnode,*currentnode,*nextnode;
	prevnode=NULL;
	currentnode=nextnode=root;
	while(nextnode!=NULL){
		nextnode=nextnode->link;
		currentnode->link=prevnode;
		prevnode=currentnode;
		currentnode=nextnode;
	}
	root=prevnode;
}
void sorting(){
	int temp;
	struct node* p=root;
	struct node* q;
	for(p=root;p->link!=NULL;p=p->link){
		for(q=p->link;q!=NULL;q=q->link){
			if(p->data>q->data){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}

