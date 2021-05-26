#include<stdio.h>

void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);

int main(){
    int arr[50];
    int size, i;

    printf("Enter the no. of elements you want to enter: ");
    scanf("%d", &size);
    printf("Now enter the elements: ");

    for(i = 0; i < size; i+=1){
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, size-1);
    printf("Sorted array: ");

    for(i = 0; i < size; i+=1){
        printf("%d " , arr[i]);
    }
    return 0;
}

void mergeSort(int arr[], int start, int end){
    
    int mid;
    if(start < end){

        mid = (start+end)/2;
        mergeSort(arr, start , mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

void merge(int arr[], int start, int mid, int end){

    int temp[50], i = start, j = mid + 1, tempIndex = start;
    while((i <= mid) && (j <= end)){
        temp[tempIndex++] = (arr[i] <= arr[j] ? arr[i++] : arr[j++]);
    }

    while(i <= mid){
        temp[tempIndex++] = arr[i++];
    }

    while(j <= end){
        temp[tempIndex++] = arr[j++];
    }
    for(tempIndex = start; tempIndex <= end; tempIndex+=1){
        arr[tempIndex] = temp[tempIndex];
    }
}