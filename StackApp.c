#include<stdio.h>
#define MAXINDEX 10

typedef struct{
    int top;
    int item[MAXINDEX];
}Stack;

void push(Stack *st);
int isFull(Stack *st);
int isEmpty(Stack *st);
void pop(Stack *st);
void display(Stack *st);
void peep(Stack *st);

int main(){
    //Your code here
    int choice;
    Stack st1;
    st1.top = -1;
    st1.item[MAXINDEX];
    do{

        printf("\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            push(&st1);
            break;
        case 2:
            pop(&st1);
            break;
        case 3:
            peep(&st1);
            break;
        case 4:
            display(&st1);
            break;
        case 5:
            return 0;       
        default:
            printf("INVALID CHOICE\n");
            break;
        }

    }while(1);
    return 0;
}

void push(Stack *st){
    int n;
    printf("Enter the element: ");
    scanf("%d", &n);

    if(isFull(st))
        printf("Cannot perform operation. Stack full.\n");
    else{

        st-> top++;
        st->item[st->top] = n;
        printf("Element adding successful!\n");
    }    
}

int isFull(Stack *st){

    if(st->top == MAXINDEX)
        return 1;
    else
    {
        return 0;
    }
        
}

int isEmpty(Stack *st){

    if(st->top == -1)
        return 1;
    else
    {
        return 0;
    }
        
}

void pop(Stack *st){

    int n;
    if(isEmpty(st))
        printf("Cannot perform operation. Stack is empty!\n");
    else
    {
        n = st->item[st->top];
        st->top--;
        printf("%d was popped.\n", n);
    }
        
}

void peep(Stack *st){

    int n;
    printf("Enter the index to view it's content: ");
    scanf("%d", &n);
    if(isEmpty(st))
        printf("Cannot perform operation. Stack is empty!\n");
    else if(n > st->top)
            printf("Invalid Index!");
        else
        printf("%d is the element at %d.\n", st->item[n], n);   
}

void display(Stack *st){
    if(isEmpty(st)){
        printf("Empty stack. Nothing to display.");
    }
    else{
        printf("Displaying current stack: ");
        for(int i = st->top; i >= 0 ; i-=1){
            printf("%d ", st->item[i]);
        }
    }
}