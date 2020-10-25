#include<stdio.h>
#define MAXQUEUE 10

typedef struct{

    int front;
    int rear;
    int item[MAXQUEUE];
}Queue;

int isFull(Queue *q1){

    if(q1->rear == MAXQUEUE - 1)
        return 1;
    else
        return 0;    
}

int isEmpty(Queue *q1){

    if(q1->rear < q1->front)
        return 1;
    else 
        return 0;   
}

void insert(Queue *q1, int n){

    if(isFull(q1))
        printf("Queue is full. Element cannot be inserted !\n");
    else{

        q1->rear++;
        q1->item[q1->rear] = n;
        printf("Element inserted successfully !");
    } 

}

void removeElem(Queue *q1){

    int n;
    if(isEmpty(q1))
        printf("Queue is empty. Noting to delete !\n");
    else{

        n = q1->item[q1->front];
        q1->front++;
        printf("%d deleted successfully !", n);
    } 

}

void display(Queue *q1){

    if(isEmpty(q1))
        printf("Queue is empty. Nothing to display !");
    else{

        for(int i = q1->front; i <= q1->rear; i++){

            printf("%d ", q1->item[i]);
        }
    }    
}

