#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node *left,*right;
	int ht;
}node;
 
node *insert(node *,int);
node *Delete(node *,int);
void preorder(node *);
void inorder(node *);
int height( node *);
node *rotateRight(node *);
node *rotateLeft(node *);
node *RR(node *);
node *LL(node *);
node *LR(node *);
node *RL(node *);
int balanceFactor(node *);
 
int main()
{
	node *root=NULL;
	int x,n,i,op;
	
	do
	{
		printf("\n AVL TREE ");
		printf("\n1)Create:");
		printf("\n2)Insert:");
		printf("\n3)Delete:");
		printf("\n4)Print:");
		printf("\n5)Quit:");
		printf("\n\nEnter Your Choice:");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1: printf("\nEnter no. of elements:");
					scanf("%d",&n);
					printf("\nEnter tree data:");
					root=NULL;
					for(i=0;i<n;i++)
					{
						scanf("%d",&x);
						root=insert(root,x);
					}
					break;
				
			case 2: printf("\nEnter a data:");
					scanf("%d",&x);
					root=insert(root,x);
					break;
					
			case 3: printf("\nEnter a data:");
					scanf("%d",&x);
					root=Delete(root,x);
					break;
			
			case 4: printf("\nPreorder sequence:\n");
					preorder(root);
					printf("\n\nInorder sequence:\n");
					inorder(root);
					printf("\n");
					break;			
		}
	}while(op!=5);
	
	return 0;
}
 
node * insert(node *root,int x)
{
	if(root==NULL)
	{
		root=(node*)malloc(sizeof(node));
		root->data=x;
		root->left=NULL;
		root->right=NULL;
	}
	else
		if(x > root->data)		// insert in right subtree
		{
			root->right=insert(root->right,x);
			if(balanceFactor(root)==-2)
				if(x>root->right->data)
					root=RR(root);
				else
					root=RL(root);
		}
		else
			if(x<root->data)
			{
				root->left=insert(root->left,x);
				if(balanceFactor(root)==2)
					if(x < root->left->data)
						root=LL(root);
					else
						root=LR(root);
			}
		
		root->ht=height(root);
		
		return(root);
}
 
node * Delete(node *root,int x)
{
	node *p;
	
	if(root==NULL)
	{
		return NULL;
	}
	else
		if(x > root->data)		// insert in right subtree
		{
			root->right=Delete(root->right,x);
			if(balanceFactor(root)==2)
				if(balanceFactor(root->left)>=0)
					root=LL(root);
				else
					root=LR(root);
		}
		else
			if(x<root->data)
			{
				root->left=Delete(root->left,x);
				if(balanceFactor(root)==-2)	//Rebalance during windup
					if(balanceFactor(root->right)<=0)
						root=RR(root);
					else
						root=RL(root);
			}
			else
			{
				//data to be deleted is found
				if(root->right!=NULL)
				{	//delete its inorder succesor
					p=root->right;
					
					while(p->left!= NULL)
						p=p->left;
					
					root->data=p->data;
					root->right=Delete(root->right,p->data);
					
					if(balanceFactor(root)==2)//Rebalance during windup
						if(balanceFactor(root->left)>=0)
							root=LL(root);
						else
							root=LR(root);\
				}
				else
					return(root->left);
			}
	root->ht=height(root);
	return(root);
}
 
int height(node *root)
{
	int lh,rh;
	if(root==NULL)
		return(0);
	
	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->ht;
		
	if(root->right==NULL)
		rh=0;
	else
		rh=1+root->right->ht;
	
	if(lh>rh)
		return(lh);
	
	return(rh);
}
 
node * rotateRight(node *x)
{
	node *y;
	y=x->left;
	x->left=y->right;
	y->right=x;
	x->ht=height(x);
	y->ht=height(y);
	return(y);
}
 
node * rotateLeft(node *x)
{
	node *y;
	y=x->right;
	x->right=y->left;
	y->left=x;
	x->ht=height(x);
	y->ht=height(y);
	
	return(y);
}
 
node * RR(node *root)
{
	root=rotateLeft(root);
	return(root);
}
 
node * LL(node *root)
{
	root=rotateRight(root);
	return(root);
}
 
node * LR(node *root)
{
	root->left=rotateLeft(root->left);
	root=rotateRight(root);
	
	return(root);
}
 
node * RL(node *root)
{
	root->right=rotateRight(root->right);
	root=rotateLeft(root);
	return(root);
}
 
int balanceFactor(node *root)
{
	int lh,rh;
	if(root==NULL)
		return(0);
 
	if(root->left==NULL)
		lh=0;
	else
		lh=1+root->left->ht;
 
	if(root->right==NULL)
		rh=0;
	else
		rh=1+root->right->ht;
 
	return(lh-rh);
}
 
void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d(Bf=%d)",root->data,balanceFactor(root));
		preorder(root->left);
		preorder(root->right);
	}
}
 
void inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d(Bf=%d)",root->data,balanceFactor(root));
		inorder(root->right);
	}
}
