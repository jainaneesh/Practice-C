#include <stdio.h>
#include<stdlib.h>

struct Queue{
    int data;
    struct Queue* next;
};

struct Queue* front = NULL;
struct Queue* rear  = NULL;
void enqueue(int data);
struct Queue* dequeue(void);
int isEmpty(void);
void displayQueue(void);
int main(void){
    struct Queue* temp;
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    displayQueue();
    while(!isEmpty()){
        temp = dequeue();
        if( temp != NULL){
            printf("\n%d was dequeued",temp->data);
        }
    }
    displayQueue();
}


int isEmpty(void)
{
    return front == NULL;
}
void enqueue(int data)
{
    struct Queue* temp;
    temp = (struct Queue*)malloc(sizeof(struct Queue));
    if(isEmpty()){
        printf("Queue is empty");
        printf("\nAdding %d to the queue\n",data);
        temp->data = data;
        temp->next = NULL;
        front = temp;
        rear = temp;
    }else{
        printf("Adding %d to the queue\n",data);
        temp->data = data;
        temp->next = NULL;
        rear->next = temp;
        rear = temp;
    }
}

struct Queue* dequeue(void)
{
    
    if(isEmpty()){
        printf("Queue is empty");
        return NULL;
    }
    struct Queue* temp;
    temp = front;
    front = front->next;
    if(front == NULL)
        rear = NULL;
    return temp;
}

void displayQueue(void)
{
    struct Queue* temp;
    if(isEmpty()){
        printf("Queue is empty...");
        exit(1);
    }
    temp = front;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
}






















