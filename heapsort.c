#include<stdio.h>
#include<stdlib.h>

int arr[10];

void insertHeap(int value, int size, int arr[10]){
    size = size + 1;
    arr[size] = value;
    int pos = size;
    int par = 0;
    int temp;
    while(pos > 0){
        par = (pos - 1)/2;
        if(arr[par] <= arr[pos]){
            return;
        }
        else{
            temp = arr[pos];
            arr[pos] = arr[par];
            arr[par] = temp;
            pos = par;
        }
    }
}

void displayHeap(int size, int arr[10]){
    int i; 
    for(i = 1; i <= size; i+=1)
        printf("%d ", arr[i]);
}

int main(){
    int data, i, size = 0;
    int choice;
    do{
        printf("\n1. Insert");
        printf("\n2. Display");
        printf("\n3. Exit");
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertHeap(data, size, arr);
                break;
            case 2:
                displayHeap(size, arr);
                break;
            case 3:
                return 0;    
        }
    }while(1);
}