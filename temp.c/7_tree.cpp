#include <iostream>
using namespace std;

// 1. Define the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;
    
    // Constructor to easily create new nodes
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// 2. Traversal Functions

void preOrder(Node* root) {
    if (root == NULL) return;     // Base Case
    
    cout << root->data << " ";    // 1. Print Root
    preOrder(root->left);         // 2. Visit Left Subtree
    preOrder(root->right);        // 3. Visit Right Subtree
}

void inOrder(Node* root) {
    if (root == NULL) return;     // Base Case
    
    inOrder(root->left);          // 1. Visit Left Subtree
    cout << root->data << " ";    // 2. Print Root
    inOrder(root->right);         // 3. Visit Right Subtree
}

void postOrder(Node* root) {
    if (root == NULL) return;     // Base Case
    
    postOrder(root->left);        // 1. Visit Left Subtree
    postOrder(root->right);       // 2. Visit Right Subtree
    cout << root->data << " ";    // 3. Print Root
}

// 3. The Main Function
int main() {
    // Build the tree
    // Level 1 (Root)
    Node* root = new Node(12);
    
    // Level 2
    root->left = new Node(6);
    root->right = new Node(18);
    
    // Level 3
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    
    root->right->left = new Node(14);
    root->right->right = new Node(16);

    // Print the traversals
    cout << "--- Binary Tree Traversals ---" << endl;
    
    cout << "Pre-Order  (Root, Left, Right) : ";
    preOrder(root);
    cout << endl;

    cout << "In-Order   (Left, Root, Right) : ";
    inOrder(root);
    cout << endl;

    cout << "Post-Order (Left, Right, Root) : ";
    postOrder(root);
    cout << endl;

    return 0;
}