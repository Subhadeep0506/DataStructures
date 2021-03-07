#include<stdio.h>
#include<stdlib.h>

int getMax(int arr[]){
    int max = arr[0];
    for(int i = 1; i < 10; i+=1){
        if(arr[i] > max)
            max = arr[i];
    }
    return max;
}

int getPass(int max){
    int pass = 0;
    while(max != 0){
        max = max / 10;
        pass += 1;
    }
    return pass;
}

int getPlaceValue(int place_val, int num){
    int n;

    return n;
}

int main(){
    int arr[10], temp[10][10];
    int i, j, pass, place_val, digit;
    printf("Enter 10 elements: ");

    for(i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }

    int max = getMax(arr);
    pass = getPass(max);

    for(int k = 1; k <= pass; k+=1){
        place_val = k;
        i = 0;
        j = 0;
        for(i = 0; i < 10; i++){
            digit = getPlaceValue(place_val, arr[i]);  
            if() 
        }
    }
    return 0;
}