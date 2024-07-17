#include<stdio.h>
#include<stdlib.h>
int len;
struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node1{
	int data1;
	struct node1* left1;
	struct node1* right1;
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
	temp->left=NULL;
	temp->right=NULL;
	temp1->left1=NULL;
	temp1->right1=NULL;
	if(root==NULL||root1==NULL){
		root=temp;
		root1=temp1;
	}
	else{
		struct node* p=root;
		struct node1* q=root1;
		while(p->right!=NULL||q->right1!=NULL){
			p=p->right;
			q=q->right1;
		}
		p->right=temp;
		temp->left=p;
		q->right1=temp1;
		temp1->left1=q;
		
	}
}
}
void addatbegin(){
	struct node* temp=root;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&temp->data);
	temp->left=NULL;
	temp->right=NULL;
	if(root==NULL){
		root=temp;
	}
	else{
		temp->right=root;
		root->left=temp;
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
		temp->left=NULL;
		temp->right=NULL;
		while(i<loc-1){
			p=p->right;
			i++;
		}
		temp->right=p->right;
		p->right->left=temp;
		temp->left=p;
		p->right=temp;
		
		
		
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
		temp=temp->right;
	}
		
	}
	
}
int length(){
	struct node* temp=root;
	int count=0;
	while(temp!=NULL){
		temp=temp->right;
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
		root=temp->right;
		temp->right=NULL;
		free(temp);
	}
	else{
		struct node *p=root,*q;
		int i=1;
		while(i<loc-1){
			p=p->right;
			i++;
		}
		q=p->right;
		p->right=q->right;
		q->right=NULL;
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
			temp=temp->right;
		}
	}
}
void concatenation()
{
	struct node* p;
	p=root;
	while(p->right!=NULL){
		p=p->right;
	}
	p->right=root1;	
}
void reverse(){
	struct node *prevnode,*currentnode,*nextnode;
	prevnode=NULL;
	currentnode=nextnode=root;
	while(nextnode!=NULL){
		nextnode=nextnode->right;
		currentnode->right=prevnode;
		prevnode=currentnode;
		currentnode=nextnode;
	}
	root=prevnode;
}
void sorting(){
	int temp;
	struct node* p=root;
	struct node* q;
	for(p=root;p->right!=NULL;p=p->right){
		for(q=p->right;q!=NULL;q=q->right){
			if(p->data>q->data){
				temp=p->data;
				p->data=q->data;
				q->data=temp;
			}
		}
	}
}

