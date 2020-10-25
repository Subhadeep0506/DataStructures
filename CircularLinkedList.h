#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *createList(NODE *start){

    NODE *newnode, *ptr;
    int n;
    printf("\nEnter -1 to exit creating list.");
    printf("\nEnter the element: ");
    scanf("%d", &n);
    while(n != -1){

        newnode = (NODE*)malloc(sizeof(NODE));
        newnode->data = n;
        if(start == NULL){
            start = newnode;
            newnode->next = newnode;
        }
        else{
            ptr = start;
            while(ptr->next != start)
                ptr = ptr->next;
            ptr->next = newnode;
            newnode->next = start;    
        }
        printf("Enter next element: ");
        scanf("%d", &n);
    }
    return start;
}

NODE *displayList(NODE *start){

    NODE *ptr;
    ptr = start;
    while(ptr->next != start){

        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ", ptr->data);
    return start;
}

NODE *addAtBeginning(NODE *start){

    NODE *newnode, *ptr;
    int num;
    printf("Enter the element: ");
    scanf("%d", &num);
    ptr = start;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = num;
    while(ptr->next != start)
        ptr = ptr->next;
    ptr->next = newnode;
    newnode->next = start;
    start = newnode;
    return start;
}

NODE *addAtEnd(NODE *start){

    NODE *newnode, *ptr;
    int num;
    printf("Enter the element: ");
    scanf("%d", &num);
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = num;
    ptr = start;
    while(ptr->next != start)
        ptr = ptr->next;
    ptr->next = newnode;
    newnode->next = start;
    return start;    
}

NODE *deleteAtBeginning(NODE *start){
    
    NODE *ptr;
    ptr = start;
    while(ptr->next != start)
        ptr = ptr->next;
    ptr->next = start->next;
    free(start);
    start = ptr->next;
    return start;
}

NODE *deleteAtEnd(NODE *start){

    NODE *ptr, *preptr;
    ptr = start;
    while(ptr->next != start){

        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = ptr->next;
    free(ptr);
    return start;
}