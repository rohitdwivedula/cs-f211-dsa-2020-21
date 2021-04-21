#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* treenode = (Node*) malloc(sizeof(Node));
    treenode->data = data;
    treenode->left = treenode->right = NULL;
    return treenode;
}

void preOrder(Node* node) {
    if(node->left == NULL && node->right == NULL) printf("%d ", node->data);
    if(node->left != NULL) preOrder(node->left);
    if(node->right != NULL) preOrder(node->right);
}

Node* createTree(int postorder[], int inorder[], int ptrIndex, int l, int r) {
    // step1 : get the last element from postorder array
    // step2 : find the position in inorder array
    // step3 : create node
    // step4 : divide and conquer

    if(l > r) return NULL;

    int currentElement = postorder[ptrIndex];

    int i;
    for(i = l; i <= r; i++) {
        if(inorder[i] == currentElement) {
            break;
        }
    }

    Node* treeNode = createNode(currentElement);

    // decrement because postorder computed from right to left.
    ptrIndex--;

    // l to i-1 & i + 1 to r => divide and conquer
    treeNode->left = createTree(postorder, inorder, ptrIndex, l, i - 1);
    treeNode->right = createTree(postorder, inorder, ptrIndex, i + 1, r);
    return treeNode;
}

int main() {
    int n;
    scanf("%d", &n);
    int postorder[n];
    int inorder[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &postorder[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &inorder[i]);
    }

    int ptrIndex = n - 1;

    // create tree from traversal
    Node* root = createTree(postorder, inorder, ptrIndex, 0, n - 1);

    // step2: preorder traversal, print leaves only
    preOrder(root);

    return 0;
}