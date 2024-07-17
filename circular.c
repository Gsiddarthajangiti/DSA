#include<stdio.h>
#include<stdlib.h>
int len;
struct node{
	int data;
	struct node* link;
};
struct node* head=NULL;
struct node* tail=NULL;
void create();
void display();
void addatbegin();
void addatend();
void addatpos();
void deletion();
void deletionatend();
void length();
int main(){
	int ch;
	while(1){
		printf("linked list operations\n");
		printf("1.creation\n");
		printf("2.display\n");
		printf("3.length\n");
		printf("4.addatbegin\n");
		printf("5.addatend\n");
		printf("6.addatpos\n");
		printf("7.deletion\n");
		printf("8.deletionatend\n");
		printf("9.quit\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1 : create();
		         	 break;
			
	    	case 2 : display();
	             	 break;
	        case 3 : length();
	        		 break;
	        case 4 : addatbegin();
	        		 break;
	        case 5 : addatend();
	        		 break;
	        case 6 : addatpos();
	        		 break;
			case 7 : deletion();
	        		 break;	
			case 8 : deletionatend();
	        		 break;				 		 
	    	case 9 : exit(1);
	    	default : printf("invalid input\n");
		}	
		
	
 }
 return 0;		
}
void create(){
	struct node* temp;
	int i=0;int cha;
	printf("Enter the number of nodes");
	scanf("%d",&cha);
	while(cha>i){
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data of first linked list:");
	scanf("%d",&temp->data);
	temp->link=NULL;
	i++;
	if(head==NULL){
		head=temp;
		tail=temp;
	}
	else{
		tail->link=temp;
		tail=temp;
		tail->link=head;
		
	}
 }
}

void display(){
	struct node* temp=head;
	if(head==NULL){
		printf("list is empty");
	}
	else{
		while(temp->link!=head){
		printf("%d-->",temp->data);
		temp=temp->link;
	}
	printf("%d\n",temp->data);		
	}
	
}
void length(){
	struct node* temp=head;
	int count=0;
	while(temp->link!=head){
		count++;
		temp=temp->link;
	}
	printf("the length of circular linked list= %d\n",count+1);
}
void addatbegin(){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&temp->data);
	temp->link=head;
	tail->link=temp;
	head=temp;
	}	
void addatend(){
	struct node* temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&temp->data);
	tail->link=temp;
	temp->link=head;
		
	}
void addatpos(){
	struct node* temp;
	struct node* p=head;
	int pos,i;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
	scanf("%d",&temp->data);
	printf("Enter the position:");
	scanf("%d",&pos);
	for(i=1;i<pos-1;i++)
	p=p->link;
	temp->link=p->link;
	p->link=temp;
	

}
void deletion(){
	struct node* temp;
	int pos;
	printf("Enter the position that you want to delete:");
	scanf("%d",&pos);
	if(pos==1){
		temp=head;
		head=head->link;
		tail->link=head;
		temp->link=NULL;
		
	}
	else{
	struct node* temp=head;
	int i;
	for(i=1;i<pos-1;i++)
	temp=temp->link;
	temp->link=temp->link->link;		
		
	}
}
void deletionatend(){
	struct node* temp;
	temp=head;
	while(temp->link!=tail){
		temp=temp->link;
	}
	tail->link=NULL;
	temp->link=head;
	tail=temp;
}
