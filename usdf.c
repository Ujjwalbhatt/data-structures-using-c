#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct btree
{
int data;
struct btree *left;
struct btree *right;
}btree;
btree *root;
btree *create(int p)
{
btree *node=(btree*)malloc(sizeof(btree));
node->data=p;
node->left=NULL;
node->right=NULL;
return node;
}
btree *insert(btree *p, int x)
{
btree *tmp, *pp;  
if(pp==NULL){
tmp=(btree*)malloc(sizeof(btree));
tmp->data=x;
tmp->left=NULL;
tmp->right=NULL;
p=tmp;
return p;
}
if(pp->data>x)
pp->left=insert(pp->left,x);
if(x>pp->data) pp->right=insert(pp->right,x);
return p;
}
void pre(btree *node)
{
btree *tmp;
tmp=node;
if(tmp!=NULL)
{
printf("%d\n", tmp->data);
pre(tmp->left);
pre(tmp->right);
}}
//btree *insert(btree *p, int x);
void in(btree *node)
{
btree *tmp;
tmp=node;
if(tmp!=NULL)
{
in(tmp->left);
printf("%d\n", tmp->data);
in(tmp->right);
}}

void main()
{
int n, a, i;
root=create(45);
printf("\nEnter the number of elements to insert in BST");
scanf("%d", &n);
for(i=1;i<=n;i++)
{
scanf("%d", &a);
root=insert(root,a);
}
pre(root);
printf("\n\n");
in(root);
}
