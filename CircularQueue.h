#include <stdio.h>
#define MAXQUEUE 10

typedef struct{
    int front;
    int rear;
    int item[MAXQUEUE];
}CirQueue;

int isFull(CirQueue *q1){
    if(q1->front == (q1->rear+1)%MAXQUEUE)
        return 1;
    else 
        return 0;    
}

int isEmpty(CirQueue *q1){
    if(q1->front == -1)
        return 1;
    else 
        return 0;    
}

void insert(CirQueue *q1, int n){
    if(isFull(q1)){
        printf("Queue is full. Cannot insert more elements !");
    }
    else{
        if(q1->front==-1){
            q1->rear = 0;
            q1->front= 0;
        }
        else{

            q1->rear = (q1->rear+1) % MAXQUEUE;
        }
        q1->item[q1->rear] = n;
        printf("Element inserted !");
    }
}

void removeElem(CirQueue *q1){
    if(isEmpty(q1)){
        printf("Queue is empty. Nothing to delete !");
    }
    else{
        if(q1->front == q1->rear){
            q1->front = -1;
            q1->rear = -1;
        }
        else{
            q1->front = (q1->front+1)%MAXQUEUE;
            printf("Item deleted !");
        }
    }
}

void display(CirQueue *q1){

    int i;
    if(isEmpty(q1)){
        printf("Queue is empty. Nothing to display !");
    }
    else{
        if(q1->front <= q1->rear){

            for(i = q1->front; i <= q1->rear; i++){
                printf("%d ", q1->item[i]);
            }
        } 
        else
        {
            for(i = q1->front; i <= MAXQUEUE-1; i++)
                printf("%d ", q1->item[i]);
            for(i = 0; i <= q1->rear; i++)
                printf("%d ", q1->item[i]);
        }
    }     
}