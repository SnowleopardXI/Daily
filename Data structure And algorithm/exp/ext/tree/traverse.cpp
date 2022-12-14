#include <iostream>
using namespace std;
//按层次顺序遍历二叉树
struct tree
{
    int data;
    tree *left;
    tree *right;
};
tree *create(int a[], int n, int i)
{
    tree *p;
    if (i >= n)
        return NULL;
    p = new tree;
    p->data = a[i];
    p->left = create(a, n, 2 * i + 1);
    p->right = create(a, n, 2 * i + 2);
    return p;
}
void traverse(tree *root)
{
    tree *q[100];
    int front = 0, rear = 0;
    tree *p;
    if (root == NULL)
        return;
    q[rear++] = root;
    while (front != rear)
    {
        p = q[front++];
        cout << p->data << " ";
        if (p->left != NULL)
            q[rear++] = p->left;
        if (p->right != NULL)
            q[rear++] = p->right;
    }
}
int main()
{
    int a[] = {1,3,5,8,9,7,6,4,2};
    tree *root;
    root = create(a, 9, 0);
    traverse(root);
    return 0;
}