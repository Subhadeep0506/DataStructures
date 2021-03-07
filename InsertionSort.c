#include<stdio.h>

void insertionSort(int arr[], int size){

    int i , j , key;
    for(i = 1; i < size ; i+=1){
        
        key = arr[i];
        j = i - 1;
        while((key < arr[j]) && (j >= 0)){

            arr[j + 1] = arr[j];
            j-=1;
        }
        arr[j + 1] = key;
    }
}

int main(){

    int arr[50];
    int size,i,j,key;

    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &size);
    printf("Enter the elements: ");
    
    for(i = 0; i < size; i+=1){

        scanf("%d", &arr[i]);
    }
    
    insertionSort(arr , size);

    printf("Sorted array: ");

    for(i = 0; i < size ; i+=1){
        printf("%d " , arr[i]);
    }
    return 0;
}

