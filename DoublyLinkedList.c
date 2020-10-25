#include<stdio.h>
#include "DoublyLinkedList.h"

void displayMenu();

int main(){

    NODE *start = NULL;
    int num, choice;
    do{
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){

            case 1:
                start = createList(start);
                break;
            case 2: 
                start = displayForward(start);
                break;
            case 3:
                start = displayBackward(start);
                break;
            case 4:
                return 0; 
            default:
                printf("INVALID CHOICE !");
                break;             
        }
    }while(1);
}

void displayMenu(){

    printf("\n1. Create list");
    printf("\n2. Display Forward");
    printf("\n3. Display Backward");
    printf("\n4. Exit");
}