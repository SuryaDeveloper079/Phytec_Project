#include<stdio.h>

#define size 5 // To decleare the Fixed size in Queue

int queue[size]; // Create and inilize the Queue and sizeof the Queue

int front=-1,rear=-1; //To inilize the front and rear (-1) That means queue is empty

//Add the Data to Queue
void enqueue(int data){

	// To check that rear is size-1 (Queue is full)
	if(rear == size-1){
		printf("The Queue is full");
	}

	// otherwise to add the data into queue
	else{
		if (front == -1) front = 0;
		queue[++rear]=data;
		printf("The Data Inserted : %d\n",data);
		
	}
}

//delete the data from the Queue
void dequeue(){

	//Check Queue is empty
	if(front == -1 && front>rear){
		printf("The Queue is Empty");
	}
	//otherwise delete the data from the Queue
	else{
		printf("the Deleted Data: %d\n",queue[front++]);
	}
}

//Print the Top of the Queue
void peek(){
	if(front == -1 && front>rear){
                printf("The Queue is Empty");
    }
	//Print the front Data on the Queue 
	else{
		printf("The Top of the Queue : %d",queue[front]);
	}	
}
//Print the all from the Queue
void display(){
	//If check Queue is empty or not
	if(front == -1 && front>rear){
                printf("The Queue is Empty");
    }
	//To prin the data one by one, iterate the For loop 
	printf("Queue: ");
	for(int i=front;i<=rear;i++){
		printf("%d ",queue[i]);
	}
	printf("\n");
}

int main(){

	//to pass the data to Enque function
	enqueue(10);
	enqueue(20);
	enqueue(30);

	display(); // Display the stored Data from the Queue
	printf("\n");
	
	peek(); //Print the Top of the Queue
	printf("\n");
	dequeue(); // To delete the data Front of the Queue
	
	

	printf("\n");
	display();
}
