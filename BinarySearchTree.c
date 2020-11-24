#include<stdio.h>
#include<stdlib.h>
#include "BinarySearchTree.h"

int main(){

    int choice, data;
    NODE *root = NULL;
    do{
        printf("\n1. Insert");
        printf("\n2. Display(Preorder Traversal)");
        printf("\n3. Remove");
        printf("\n4. Search");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                root = insert(root, data);
                break;
            case 2:
                root = display(root);
                break;
            case 4:
                printf("Enter data you want to search: ");
                scanf("%d", &data);
                if(search(root, data) == 0){
                    printf("%d don't exist.", data);
                }   
                else{
                    printf("%d exists.", data);
                } 
                break;
            case 5:
                return 0;
            default:
                printf("INVALID CHOICE !!");
                break;            
        }
    }while(1);
    return 0;
}