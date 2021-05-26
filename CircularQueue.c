#include<stdio.h>
#include "CircularQueue.h"
int main(){

    int n, choice;
    CirQueue q1;
    q1.front = -1;
    q1.rear = -1;

    do{
        printf("\n1. Insert\n2. Remove\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){

            case 1:
                printf("Enter the element you want to inert: ");
                scanf("%d", &n);
                insert(&q1,n);
                break;
            case 2:
                removeElem(&q1);
                break;
            case 3:
                display(&q1);
                break;
            case 4:
                return 0;
            default: 
                printf("INVALID CHOICE !");
                break;            
        }
    }while(1);
}
