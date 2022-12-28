#include<stdio.h>
#include<stdlib.h>
struct node{
        int item;
        struct node* left;
        struct node* right;
};

//create a new node
struct node* createNode(int value){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->item= value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

//Inserting to the left of the node in tree
struct node* insertLeft(struct node* root, int value){
    root->left = createNode(value);
    return root->left;
}

//Inseting to the right of the node in the tree
struct node* insertRight(struct node* root, int value){
    root->right = createNode(value);
    return root->right;
}

// Inorder travseral of the tree
void inorderTraversal(struct node* root){
    if(root==NULL){
    return;
    }
    inorderTraversal(root->left);
    printf("%d ->", root->item);
    inorderTraversal(root->right);
}

// Preorder Traversal of the tree
void preorderTraversal(struct node* root){
    if(root==NULL){
        return;
    }
    printf("%d ->", root->item);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
} 

// Postorder Traversal of the tree
void postorderTraversal(struct node* root){
    if(root==NULL){
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ->", root->item);
}



int main(){
    struct node* root = createNode(1);
  insertLeft(root, 12);
  insertRight(root, 9);

  insertLeft(root->left, 5);
  insertRight(root->left, 6);

  printf("Inorder traversal \n");
  inorderTraversal(root);

  printf("\nPreorder traversal \n");
  preorderTraversal(root);

  printf("\nPostorder traversal \n");
  postorderTraversal(root);


    return 0;
}