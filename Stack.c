#include <stdio.h>
#include "Stack.h"

int main(){

    int choice, n;
    Stack st;
    st.top = -1;
    do{

        printf("\n1. Push\n2. Pop\n3. Peep\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to push: ");
            scanf("%d" , &n);
            push(&st, n);
            break;
        
        case 2:
            pop(&st);
            break;

        case 3:
            printf("Enter the index(0-9): ");
            scanf("%d" , &n);
            peep(&st, n);
            break;

        case 4:
            display(&st); 
            break;

        case 5:
            return 0;

        default:
            printf("INVALID CHOICE !");
            break;
        }
    }while(1);
}