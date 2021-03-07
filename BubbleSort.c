#include<stdio.h>
int main(){

	int a[10]={3,5,1,2,5,6,8,5,9,12},n,i,j;
	printf("Enter array elements (max 10): ");
	
	for(i = 0;i<10;i++)
		scanf("%d",&a[i]);
	
	printf("Elements before sorting: ");
	for(i = 0;i<10;i+=1)
		printf("%d\t",a[i]);
	
	for(i = 0;i<10;i++){
		
		for(j=i+1;j<10;j++){
			
			if(a[i]>a[j]){
				n = a[j];
				a[j] = a[i];
				a[i] = n;
 			}
			 
		}
	}
	printf("\nElements after sorting: ");
	for(i = 0;i<10;i+=1)
		printf("%d\t",a[i]);
}
