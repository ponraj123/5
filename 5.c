#include <stdio.h>
struct node
{
	int data;
    struct node* left;
    struct node* right;
}*root=NULL;
struct node* lca(struct node* r,int n1,int n2)
{
	if(r==NULL)
	return 0;
	if(r->data>n1&&r->data>n2)
	lca(r->left,n1,n2);
	if(r->data<n1&&r->data<n2)
	 lca(r->right,n1,n2);
	 return r;
}
struct node* newnode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data  = data;
    node->left  = node->right = NULL;
    return(node);
}
int main(void) {
	int m,d,p;
struct node* root=newnode(19);
root->left=newnode(9);
root->right=newnode(20);
root->left->left=newnode(6);
root->left->right=newnode(10);
root->right->left=newnode(18);
root->right->right=newnode(22);
	scanf("%d%d",&m,&p);
    struct node *t = lca(root, m,p);
    printf("LCA of %d and %d is %d \n", m , p,  t->data);	
	// your code goes here
	return 0;
}
