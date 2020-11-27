#include<stdio.h>
#include<stdlib.h>

struct BstTree{
    int data;
    struct BstTree *left;
    struct BstTree *right;
};

typedef struct BstTree NODE;

NODE *insert(NODE *root, int data){
    NODE *newnode;
    if(root == NULL){
        root = (NODE*)malloc(sizeof(NODE));
        root->left = NULL;
        root->right = NULL;
        root->data = data;
    }
    else if(data <= root->data){
            root->left = insert(root->left, data);
    }
    else{
        root->right = insert(root->right, data);
    }
    return root;
}

NODE *display(NODE *root){
    if(root != NULL){
        printf("%d ", root->data);
        display(root->left);
        display(root->right);
    }
    return root;
}

int search(NODE *root, int data){
    int flag = 0;
    if(root == NULL){
        flag = 0;
    }
    else{
        if(root->data == data){
            flag = 1;
        }
        else if(data < root->data){
                flag = search(root->left, data);
        }
        else{
            flag = search(root->right, data);
        }
    }
    return flag;
}

NODE *findMin(NODE *root){
    if(root == NULL || root->left == NULL)
        return root;
    else 
        return findMin(root->left);    
}

NODE *Remove(NODE *root, int val){
    NODE *ptr;
    if(root == NULL){
        printf("Tree is empty. Nothing to delete.");
    }
    else if(val < root->data){
        root->left = Remove(root->left, val);
    }
    else if(val > root->data){
        root->right = Remove(root->right, val);
    }
    else if(val == root->data){
        if(root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }
        //one child: on right
        else if(root->left == NULL){
                NODE *ptr = root;
                root = root->right;
                free(ptr);
        }
        //one child: on left
        else if(root->right == NULL){
            NODE *ptr = root;
            root = root->left;
            free(ptr);
        }
        //two children
        else {
            NODE *ptr = findMin(root->right);
            root->data = ptr->data;
            root->right = Remove(root->right, ptr->data);
        }
    }
    return root;
}