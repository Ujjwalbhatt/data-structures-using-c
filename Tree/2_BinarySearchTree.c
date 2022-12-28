#include<stdio.h>
#include<stdlib.h>
struct node{
        int key;
        struct node* left;
        struct node* right;
};

struct node *newnode(int item){
    struct node *temp= (struct node*) malloc(sizeof(struct node));
    temp->key = item;
    temp->left=temp->right=NULL;
    return temp;
}

//Inorder Traversal
void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ->",root->key);
        inorder(root->right);
    }
}

//Insert a node
struct node* insert (struct node *temp, int key){
    //Return a new node if the tree is empty 
    if(temp == NULL){
    return newnode(key);
    }

    if(key < temp->key){
        temp->left = insert(temp->left, key);
    }
    else
    {
        temp->right= insert(temp->right, key);
    }
    return temp;
}

struct node*minValueNode(struct node* temp){
    struct node*current = temp;
    //find the left most leaf
    while(current && current->left!=NULL){
        current = current->left;
    }
    return current;
}

// Deleting a node
struct node *deleteNode(struct node *root, int key){
    //Return if the tree is empty
    if(root == NULL){
        return root;
    }

    // Find the node to be deleted
    if(key < root->key){
       root->left = deleteNode(root->left, key);
    }
    else if(key > root->key){
        root->right= deleteNode(root->right, key);
    }   
    else{
        if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
    // If the node has two children
    struct node *temp = minValueNode(root->right);

    //Place the inorder successor in the posititon of the node to be deleted 
    root->key = temp->key;

    //Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int main(){

    struct node *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);
    
    printf("Inorder traversal: ");
    inorder(root);

    printf("\nAfter deleting 10\n");
    root = deleteNode(root, 10);
    printf("inorder travseral: "); 
    inorder(root);

    return 0;
}



    





