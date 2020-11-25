#define MAXSTACK 10
#include <stdio.h>

typedef struct{

    int top;
    int item[MAXSTACK];
}Stack;

int isFull(Stack *st){

    if(st->top == MAXSTACK - 1)
        return 1;
    else 
        return 0;    
}

int isEmpty(Stack *st){

    if(st->top == -1)
        return 1;
    else 
        return 0;    
}

void push(Stack *st, int n){

    if(isFull(st)){
        printf("Stack is full. Cannot insert any element !");
    }
    else
    {
        st->top+=1;
        st->item[st->top] = n;
        printf("Element pushed successfully !");
    }
    
}

void pop(Stack *st){

    if(isEmpty(st)){

        printf("Stack is empty. Nothing to delete !");
    }
    else
    {
        printf("%d was popped.", st->item[st->top--]);
    }
}

void peep(Stack *st, int n){

    if(isEmpty(st)){

        printf("Stack is empty. Cannot display element !");
    }
    else if(n > st->top){

            printf("Index is empty !");
        }
        else
        {
            printf("Element at %d: %d", n, st->item[n-1]);
        }
    
}

void display(Stack *st){

    if(isEmpty(st)){
        printf("Stack is empty. Nothing to display !");
    }
    else
    {
        printf("Displaying elemeents:\n");
        for(int i = st->top; i >= 0; i-=1){

            printf("%d\n", st->item[i]);
        }
    }
    
}