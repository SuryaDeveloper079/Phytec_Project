#include<stdio.h>

#define size 5

int queue[size];

int front=-1,rear=-1;


void enqueue(int data){
	if(rear == size-1){
		printf("The Queue is full");
	}
	else{
		if (front == -1) front = 0;
		queue[++rear]=data;
		printf("The Data Inserted : %d\n",data);
		
	}
}
void dequeue(){
	if(front == -1 && front>rear){
		printf("The Queue is Empty");
	}
	else{
		printf("the Deleted Data: %d\n",queue[front++]);
	}
}
void peek(){
	if(front == -1 && front>rear){
                printf("The Queue is Empty");
        }else{
		printf("The Top of the Queue : %d",queue[front]);
	}	
}
void display(){
	if(front == -1 && front>rear){
                printf("The Queue is Empty");
        }
	for(int i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}

int main(){

	enqueue(10);
	enqueue(20);
	enqueue(30);
	display();
	printf("\n");
	peek();
	printf("\n");
	dequeue();
	printf("\n");
	peek();
	printf("\n");
	display();
}
