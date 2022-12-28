/*Q7. Write a C program to create a binary search tree and perform following operations:
1) Search a particular key.
2) Delete a node from the tree.
3) Find total number of leaf nodes
4) Find height of a binary search tree
5) Count total numbers of nodes from right hand side of root node
*/

// SOURCE CODE:
#include<stdio.h>
#include <stdlib.h>

typedef struct tree {
    int info;
    struct tree * left;
    struct tree * right;
}
tree_type;
tree_type * create(int n) {
    tree_type * p;
    p = (tree_type * ) malloc(sizeof(tree_type));
    p -> info = n;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}
void insert(tree_type ** rt, tree_type * temp) {
    if ( * rt == NULL) {
        * rt = temp;
    } else {
        if ((temp -> info) < (( * rt) -> info)) {
            insert( & (( * rt) -> left), temp);
        } else if ((temp -> info) > (( * rt) -> info)) {
            insert( & (( * rt) -> right), temp);
        }
    }
}

void findNode(tree_type * root, int value) {
    if (root != NULL) {
        findNode(root -> left, value);
        if (root -> info == value) {
            printf("%d found", value);
            return;
        }
        findNode(root -> right, value);
    }
}

tree_type * minValueNode(tree_type * node) {
    tree_type * current = node;
    while (current && current -> left)
        current = current -> left;
    return current;
}

tree_type * deleteNode(tree_type * root, int key) {
    if (root == NULL)
        return root;

    if (key > root -> info)
        root -> right = deleteNode(root -> right, key);

    else if (key < root -> info)
        root -> left = deleteNode(root -> left, key);

    else {
        if (root -> right == NULL) {
            tree_type * temp = root -> left;
            free(root);
            return temp;
        } else if (root -> left == NULL) {
            tree_type * temp = root -> right;
            free(root);
            return temp;
        }

        tree_type * temp = minValueNode(root -> right);
        root -> info = temp -> info;

        root -> right = deleteNode(root -> right, temp -> info);
    }
    return root;
}

int countLeafNodes(tree_type * root) {
    if (root == NULL) {
        return 0;
    }
    if (root -> left == NULL && root -> right == NULL) {
        return 1;
    } else {
        return countLeafNodes(root -> left) + countLeafNodes(root -> right);
    }
}

int Height(tree_type * head) {
    if (head == NULL) {
        return 0;
    } else {
        int lDepth = Height(head -> left);
        int rDepth = Height(head -> right);
        if (lDepth > rDepth) {
            return (lDepth + 1);
        } else {
            return (rDepth + 1);
        }
    }
}

int countRight(tree_type * root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countRight(root -> left) + countRight(root -> right);
}

int main() {
    int num;
    tree_type * root = NULL, * temp;
    int opt = 0;
    int count = 0;
    do {
        printf("\n1 for insert\n2 for find\n3 for delete\n4 for number of leaf nodes\n5 height of tree\n6 count nodes right to root node\n7 exit\n\n");
        printf("\nEnter the option : ");
        scanf("%d", & opt);
        switch (opt) {
        case 1:
            printf("\nEnter the element:");
            scanf("%d", & num);
            temp = create(num);
            insert( & root, temp);
            break;
        case 2:
            printf("\nInput number to find:");
            scanf("%d", & count);
            findNode(root, count);
            break;
        case 3:
            printf("\nEnter the value to be deleted:");
            scanf("%d", & count);
            root = deleteNode(root, count);
            break;
        case 4:
            count = countLeafNodes(root);
            printf("\nNumber of leaf nodes:%d", count);
            break;

        case 5:
            count = Height(root);
            printf("\nHeight is:%d", count);
            break;
        case 6:
            count = countRight(root -> right);
            printf("Number of nodes to right : %d", count);
            break;
        case 7:
            printf("\nexit!");
            exit(0);
            break;
        default:
            printf("\nwrong input!");
            break;
        }
    } while (1);
}
