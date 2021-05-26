#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void displayMenu();

int main()
{

    NODE *start = NULL;
    int choice, data;
    do
    {
        displayMenu();
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            start = createList(start);
            break;

        case 2:
            start = displayList(start);
            break;

        // case 3:
        //     printf("Enter data to be added at end of list: ");
        //     scanf("%d", &data);
        //     start = addAtEnd(start, data);
        //     break;

        // case 4:
        //     printf("Enter data to be added at beginning of list: ");
        //     scanf("%d", &data);
        //     start = addAtBeginning(start, data);
        //     break;

        case 5:
            start = deleteAtEnd(start);
            break;

        case 3:
            start = deleteAtBeginning(start);
            break;

        case 7:
            start = insertBefore(start);
            break;

        case 8:
            start = insertAfter(start);
            break;

        case 9:
            start = searchElem(start);
            break;    

        case 10:
            start = sortList(start);
            break;
            
        case 11:
            start = reverseList(start);
            printf("List reversed.\n");
            break;

        case 4:
            return 0;
            
        default:
            printf("INVALID CHOICE !!");
            break;
        }

    } while (1);
}

void displayMenu(){

    printf("\n1. Create List");
    printf("\n2. Display List");
    printf("\n3. Delete at beginning");
    printf("\n4. Exit");
    // printf("\n3. Add data at end");
    // printf("\n4. Add data at beginning");
    // printf("\n5. Delete at end");
    
    // printf("\n7. Insert node before a existing node");
    // printf("\n8. Insert node after a existing node");
    // printf("\n9. Search for an element.");
    // printf("\n10. Sorting the elements.");
    // printf("\n11. Reversing the elements.");
    
}