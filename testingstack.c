#include<stdio.h>
#include<stdlib.h>
#define CAPACITY 100
int stack[CAPACITY];
int top=-1;
int ele;
int peek_ele;
void push(int );
int pop(void );
int peek(void );
void poll(void);
int isFull(void);
int isEmpty(void);
int main(){
	int ch, item;
	while(1){
		printf("stack operations\n");
		printf("1.push\n");
		printf("2.pop\n");
		printf("3.peek\n");
		printf("4.poll\n");
		printf("5.quit\n");
		printf("Enter the choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1: printf("Enter the element:");
					scanf("%d",&item);
					push(item);
					break;
			case 2: pop();
					break;
			case 3: peek_ele =peek();
					printf("%d\n",peek_ele);
					break;
			case 4: poll();
					break;
			case 5: exit(1);
			default: printf("invalid input\n");
		}
	
	}
	
}
void push(int ele){
	if(isFull()){
		printf("stack overflow\n");
	}
	else{
		top++;
		stack[top]=ele;
	}
}
int pop(){
	if(isEmpty()){
		printf("stack is empty\n");
	}
	else{
		return stack[top--];
}
}
int peek(){
	if(isEmpty()){
		printf("stack is empty\n");
		}
	else{
		return stack[top];
	}
}
void poll(){
	int i;
	if(isEmpty()){
		printf("stack is emptty\n");
	}
	else{
		for( i=0;i<=top;i++){
			printf("%d\n ",stack[i]);
		}
		
	}

}
int isEmpty(){
	if(top==-1){
		return 1;
	}
	else{
		return 0;
	}
}
 int isFull(){
	if(top ==CAPACITY-1){
		return 1;
	}
	else{
		return 0;
	}
}
