#include <stdio.h>

int a[50], max, min;

void findMinMax(int i, int n){

    int mid, maximum, minimum;

    if(i == n)
        max = min = a[i];
    else if(i == n - 1){

        if(a[i] >= a[n]){
            max = a[i];
            min = a[n];
        }
        else{
            min = a[i];
            max = a[n];
        }
    }
    else{
        mid = (i + n) / 2;
        findMinMax(i, mid);
        maximum = max;
        minimum = min;
        findMinMax(mid + 1, n);
        if(max < maximum)
            max = maximum;
        if(min > minimum)
            min = minimum;    
    }
}

void main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter %d elements: ", n);
    for(int i = 0; i < n; i+=1)
        scanf("%d", &a[i]);

    findMinMax(0, n - 1);

    printf("Min: %d\nMax: %d", min, max);    
}
