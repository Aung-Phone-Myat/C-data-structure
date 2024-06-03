#include "stdio.h"
#include "stdlib.h"

struct AVL_Node {
    int key;
    struct AVL_Node *left;
    struct AVL_Node *right;
    int height;
};

struct AVL_Node *AVL_newNode (int key) {
    struct AVL_Node* newNode = (struct AVL_Node*)malloc(sizeof(struct AVL_Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int AVL_height(struct AVL_Node* Node) {
    if (Node == NULL) {
        return 0;
    }
    return Node->height;
}

int max(int a, int b) {
    return (a > b)?a: b;
}

int AVL_getbalance(struct AVL_Node *node) {
    if (node == NULL) {
        return 0;
    }
    return AVL_height(node->left) - AVL_height(node->right);
}

struct AVL_Node* AVL_rightRotate (struct AVL_Node* y) {
    struct AVL_Node* x = y->left;
    struct AVL_Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(AVL_height(y->left), AVL_height(y->right)) + 1;
    x->height = max(AVL_height(x->left), AVL_height(x->right)) + 1;
    return x;
}

struct AVL_Node* AVL_leftRotate (struct AVL_Node* x) {
    struct AVL_Node *y = x->right;
    struct AVL_Node *T2 = y->left;

    y->left = x;
    x->right = T2;
    
    x->height = max(AVL_height(x->left), AVL_height(x->right)) + 1;
    y->height = max(AVL_height(y->left), AVL_height(y->right)) + 1;
    return y;
}

struct AVL_Node* AVL_insert (struct AVL_Node* node, int key) {
    if (node == NULL) {
        return AVL_newNode(key);
    }
    if (key < node->key) {
        node->left = AVL_insert(node->left, key);
    } else if (key > node->key) {
        node->right = AVL_insert(node->right, key);
    } else {
        printf("Error key cannot be same\n");
        return node;
    }
     
    node->height = max(AVL_height(node->left), AVL_height(node->right)) + 1;
    int balance = AVL_getbalance(node);

    if (balance > 1 && key < node->left->key) {
        return AVL_rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        return AVL_leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = AVL_leftRotate(node->left);
        return AVL_rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = AVL_rightRotate(node->right);
        return AVL_leftRotate(node);
    }
        return node;
}

struct AVL_Node* findMin(struct AVL_Node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct AVL_Node* AVL_delete (struct AVL_Node* node, int key) {
    if (node == NULL) {
        return node;
    }
    if (key < node->key) {
        node->left = AVL_delete(node->left, key);
    } else if (key > node->key) {
        node->right = AVL_delete(node->right, key);
    } else {
        if (node->left == NULL) {
            struct AVL_Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            struct AVL_Node *temp = node->left;
            free(node);
            return temp;
        }
        struct AVL_Node *temp = findMin(node->left);
        node->key = temp->key;
        node->right = AVL_delete(node->right, temp->key);
    }
    if (node == NULL) {
        return node;
    }
    node->height = max(AVL_height(node->left), AVL_height(node->right)) + 1;
    int balance = AVL_getbalance(node);

    if (balance > 1 && key < node->left->key) {
        return AVL_rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        return AVL_leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = AVL_leftRotate(node->left);
        return AVL_rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = AVL_rightRotate(node->right);
        return AVL_leftRotate(node);
    }
        return node;

}

void preOrder(struct AVL_Node *node) {
    if (node != NULL) {
        printf("%d ", node->key);
        preOrder(node->left);
        preOrder(node->right);
    }
}

int main () {
    struct AVL_Node *root = NULL;
    root = AVL_insert(root, 15);
    root = AVL_insert(root, 10);
    root = AVL_insert(root, 12);
    root = AVL_insert(root, 11);
    root = AVL_insert(root, 13);

    printf("Preorder traversal of the constructed AVL tree is: ");
    preOrder(root);

    root = AVL_delete(root, 10);
    printf("\nPreorder traversal after deletion of 10: ");
    preOrder(root);

    return 0;
}
