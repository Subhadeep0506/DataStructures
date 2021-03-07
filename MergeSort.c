#include<stdio.h>

void mergeSort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);

int main(){
    //Your code here
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

void mergeSort(int arr[], int p, int r){
    
    int q;
    if(p < r){

        q = (p+r)/2;
        mergeSort(arr, p , q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }

}

void merge(int arr[], int p, int q, int r){

    int temp[50], l1 = p, r1 = q + 1, i = p;
    while((l1 <= q) && (r1 <= r)){

        if(arr[l1] < arr[r1]){

            temp[i] = arr[l1];
            l1 += 1;
            i += 1;
        }

        else{

            temp[i] = arr[r1];
            r1 += 1;
            i +=1;
        }
    }

    while(l1 <= q){

            temp[i] = arr[l1];
            l1 += 1;
            i += 1;
        }

        while(r1 <= r){

            temp[i] = arr[r1];
            r1 += 1;
            i += 1;
        }
    for(i = p; i <= r; i+=1){
        arr[i] = temp[i];
    }
}