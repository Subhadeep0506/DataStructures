#include<stdio.h>

void arrayInitialize(int arr[], int size);
void selectionSort(int arr[50], int size);

int main(){
    //Your code here
    int arr[50];
    int i, size;

    printf("Enter the no. of elements you want to insert: ");
    scanf("%d", &size);

    printf("Now enter the elements: ");
    arrayInitialize(arr, size);

    selectionSort(arr, size);
    printf("Sorted array: ");

    for(i = 0; i < size; i+=1){
        printf("%d ",arr[i]);
    }
    return 0;
}

void arrayInitialize(int arr[50], int size){

    int i;

    for(i = 0; i < size; i += 1){

        scanf("%d", &arr[i]);
    }
}

void selectionSort(int arr[50], int size){

    int i , j , temp , min;
    for(i = 0; i < size; i += 1){

        min = i;
        for(j = i + 1; j < size; j += 1){
            if(arr[j] < arr[min]){

                min = j;
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}