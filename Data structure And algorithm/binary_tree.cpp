#include <iostream>
using namespace std;
// A binary tree node has data, pointer to left child and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
// Function to create a binary tree
struct Node* createNode(int data)
{
    struct Node* node = new Node;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
// Function to print the nodes of a binary tree
void printTree(struct Node* node)
{
    if (node == NULL)
        return;
    cout << node->data << " ";
    printTree(node->left);
    printTree(node->right);
}
// Function to print all the nodes of a binary tree in a pre-order fashion
void printPreorder(struct Node* node)
{
    if (node == NULL)
        return;
    // First print data of node
    cout << node->data << " ";
    // Then recur on left subtree
    printPreorder(node->left);
    // Now recur on right subtree
    printPreorder(node->right);
}
// Function to print all the nodes of a binary tree in an in-order fashion
void printInorder(struct Node* node)
{
    if (node == NULL)
        return;
    // First recur on left child
    printInorder(node->left);
    // Then print the data of node
    cout << node->data << " ";
    // Now recur on right child
    printInorder(node->right);
}
// Function to print all the nodes of a binary tree in a post-order fashion
void printPostorder(struct Node* node)
{
    if (node == NULL)
        return;
    // First recur on left subtree
    printPostorder(node->left);
    // Then recur on right subtree
    printPostorder(node->right);
    // Now deal with the node
    cout << node->data << " ";
}
// Print as a tree
void printAsTree(struct Node* node, int level)
{
    if (node == NULL)
        return;
    printAsTree(node->right, level + 1);
    for (int i = 0; i < level; i++)
        cout << "    ";
    cout << node->data << endl;
    printAsTree(node->left, level + 1);
}
// Print in brackets
void printInBrackets(struct Node* node)
{
    if (node == NULL)
        return;
    cout << "(";
    cout << node->data;
    printInBrackets(node->left);
    printInBrackets(node->right);
    cout << ")";
}
int main()
{
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    cout << "Tree: ";
    printTree(root);
    cout << endl;
    cout << "Print as a tree: "<< endl;
    printAsTree(root, 0);
    cout << endl;
    cout << "Print in brackets: ";
    printInBrackets(root);
    cout << endl;
    cout << "Preorder: ";
    printPreorder(root);
    cout << endl;
    cout << "Inorder: ";
    printInorder(root);
    cout << endl;
    cout << "Postorder: ";
    printPostorder(root);
    cout << endl;
    return 0;
}