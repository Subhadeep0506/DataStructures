#include<stdio.h>
#include "CircularLinkedList.h"

void displayMenu();

int main(){

    NODE *start = NULL;
    int data, choice;

    do{
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                start = createList(start);
                break;
            case 2:
                start = displayList(start);
                break;
            case 3:
                start = addAtBeginning(start);
                break;    
            case 4:
                start = addAtEnd(start);
                break; 
            case 5:
                start = deleteAtBeginning(start);
                break;
            case 6:
                start = deleteAtEnd(start);
                break;           
            case 7:
                return 0;        
        }
    }while(1);
}

void displayMenu(){

    printf("\n1. Create list");
    printf("\n2. Display list");
    printf("\n3. Insert at Beginning");
    printf("\n4. Insert at End");
    printf("\n5. Delete at Beginning");
    printf("\n6. Delete at End");
    printf("\n7. Exit");
}