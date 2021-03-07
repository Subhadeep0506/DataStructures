#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *createList(NODE *start)
{ //###Pointer function###
    NODE *newnode, *ptr;
    int num;
    printf("\nEnter -1 to exit list creation.");
    printf("\nEnter the element: ");
    scanf("%d", &num);
    while (num != -1)
    {

        newnode = (NODE *)malloc(sizeof(NODE));
        newnode->data = num;
        if (start == NULL)
        {
            newnode->next = NULL;
            start = newnode;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf("\nEnter next element: ");
        scanf("%d", &num);
    }
    return start;
}

NODE *displayList(NODE *start){

    NODE *ptr;
    if(start == NULL)
        printf("List is empty. Nothing to display !");
    else{ 

        ptr = start;
        while(ptr != NULL){

            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
    }
    return start;
}

NODE *addAtEnd(NODE *start, int data){

    NODE *newnode, *ptr;
    ptr = start;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    newnode->next = NULL;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = newnode;
    return start;
}

NODE *addAtBeginning(NODE *start, int data){

    NODE *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->next = start;
    start = newnode;
    newnode->data = data;
    return start;
}

NODE *deleteAtBeginning(NODE *start){

    NODE *ptr;
    ptr = start;
    start = start->next;
    free(ptr);
    return start;
}

NODE *deleteAtEnd(NODE *start){

    NODE *ptr, *preptr;
    ptr = start;
    while(ptr->next != NULL){

        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = NULL;
    free(ptr);
    return start;
}

NODE *insertBefore(NODE *start){

    NODE *newnode, *ptr,*preptr;
    int n, num;
    printf("Enter the no. before which you want to insert: ");
    scanf("%d", &n);
    ptr = start;

    do{
        preptr = ptr;
        ptr = ptr->next;
    }while(ptr->data != n);

    newnode = (NODE*)malloc(sizeof(NODE));
    preptr->next = newnode;
    newnode->next = ptr;
    printf("Newnode has been created successfuly !");
    printf("\nNow enter data: ");
    scanf("%d", &num);
    newnode->data = num;

    return start;
}

NODE *insertAfter(NODE *start){

    NODE *newnode, *ptr, *postptr;
    int n, num;
    printf("Enter the no. after which you want to insert: ");
    scanf("%d", &n);
    postptr = start;
    do{
        ptr = postptr;
        postptr = postptr->next;
    }while(ptr->data != n);
    newnode = (NODE*)malloc(sizeof(NODE));
    ptr->next = newnode;
    newnode->next = postptr;
    printf("Newnode has been created successfuly !");
    printf("\nNow enter data: ");
    scanf("%d", &num);
    newnode->data = num;

    return start;
}

NODE *searchElem(NODE *start){

    NODE *ptr;
    int num, flag = 0;
    printf("Enter the search element: ");
    scanf("%d", &num);
    ptr = start;
    do{
        ptr = ptr->next;
        if(ptr->data == num){
            flag = 1;
            break;
        }
    }while(ptr->next != NULL);
    if(flag == 1)
        printf("Element found !");
    else 
        printf("Element doesn't exist !");
    return start;       
}

NODE *sortList(NODE * start){
    
    return start;
}

NODE *reverseList(NODE *start){

    NODE *current = start, *next = NULL, *prev = NULL;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    start = prev;
    return start;
}