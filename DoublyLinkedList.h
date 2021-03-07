#include<stdio.h>
#include<stdlib.h>

struct node{

    struct node *prev;
    int data;
    struct node *next;
};

typedef struct node NODE;

NODE *createList(NODE *start){

    NODE *newnode, *ptr;
    int num;
    printf("\nEnter -1 to exit creating list.");
    printf("\nEnter the element: ");
    scanf("%d", &num);
    while(num != -1){

        newnode = (NODE*)malloc(sizeof(NODE));
        newnode->data = num;
        if(start == NULL){
            newnode->prev = NULL;
            start = newnode;
            newnode->next = NULL;
        }
        else{
            ptr = start;
            while(ptr->next != NULL){
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
            newnode->next = NULL;
        }
        printf("Enter next element: ");
        scanf("%d", &num);
    }
    return start;
}

NODE *displayForward(NODE *start){

    NODE *ptr;
    ptr = start;
    while(ptr != NULL){

        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

NODE *displayBackward(NODE *start){

    NODE *ptr;
    ptr = start;
    while(ptr->next != NULL)
        ptr = ptr->next;
    
    while(ptr->prev != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }    
    printf("%d ", ptr->data);
    return start;
}

NODE *insertBeginning(NODE *start, int data){
    NODE *ptr, *newnode;
    newnode = (NODE*)malloc(sizeof(NODE));
    newnode->data = data;
    ptr = start;
    
    return start;
}