#include<stdio.h>

void arrayInitializer(int arr[], int size); 
void quickSort(int arr[50], int l, int h);

int main(){
    //Your code here
    int arr[10];
    int i, size, l, h;

    printf("Enter the no. of elements you want to insert: ");
    scanf("%d", &size);

    printf("Now enter the elements: ");
    arrayInitializer(arr, size);

    l = 0;
    h = size - 1;
    quickSort(arr, l, h);
    printf("Sorted array: ");

    for(i = 0; i < size; i+=1){
        printf("%d ",arr[i]);
    }
    return 0;
}

void arrayInitializer(int arr[10], int size){

    int i;
    for(i = 0; i < size; i += 1){

        scanf("%d", &arr[i]);
    }
}

void quickSort(int arr[10], int l, int h){

    int temp , pivot, low, high;
    low = l;
    high = h;
    pivot = arr[(low + high)/2];

    do{

        while(pivot > arr[low]){
            low+=1;
        }
        while(pivot < arr[high]){
            high-=1;
        }
        if(low <= high){
            temp = arr[low];
            arr[low++] = arr[high];
            arr[high--] = temp;
        }
        
    }while(low <= high);
    if(l < high)
        quickSort(arr, l, high);
    if(low < h)
        quickSort(arr, low, h);
}