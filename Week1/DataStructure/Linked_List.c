#include <stdio.h>
#include <stdlib.h>

// Define a node
struct Node {
    int data;           // Integer data stored in the node
    struct Node* next;  // Pointer to the next nod
};

// Head pointer to the list
struct Node* head = NULL;

// Insert at end
void insertAtEnd(int value) {

    //To allocate the Memory dynamically for new node 
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;  //To assign the value of the data filed of new node
    newNode->next = NULL;   //to set the next will be NULL because it will be the last node

    // If the list is empty, set head to the new node.
    if (head == NULL) {
        head = newNode;
    }
    // Otherwise, traverse to the last node and link it to the new node.
    else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Inserted: %d\n", value); //Print the confermation that the node will be inserted
}

// Delete from front
void deleteFromFront() {

    // if the list is empty, print a message and return.
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;               //Store the current head in a temporary pointer.
    head = head->next;                      //Move head to the next node
    printf("Deleted: %d\n", temp->data);    //Print the value being deleted.
    free(temp);         //Free the memory of the deleted node to avoid memory leaks.
}

// Display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;           //Store the current head in a temporary pointer.
    printf("List: ");

    //To check that wile condidtion
    while (temp != NULL) {  
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    //  Insert 10 at the end of the list → list becomes: 10 -> NULL
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    display(); //Print the current list

    deleteFromFront();  //delete the first node
    display();

    return 0;
}

