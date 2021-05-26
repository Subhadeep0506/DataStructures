#include<stdio.h>
#include<stdlib.h>

struct tree{
    struct tree *left;
    int data;
    struct tree *right;
    int height;
};

typedef struct tree NODE;

NODE *insertData(NODE *root, int data){

    NODE *newnode;
    if(root == NULL){
        root = (NODE*)malloc(sizeof(NODE));
        root->data = data;
        root->left = NULL;
        root->right = NULL;
    }
    else if(data < root->data){
            root->left = inserData(root->left, data);
    }
    else{
        root->right = inserData(root->right, data); 
    }
    return root;
}