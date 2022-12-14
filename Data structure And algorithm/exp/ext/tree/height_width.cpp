#include <iostream>
using namespace std;
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
// 求二叉树的高度
int height(tree *root)
{
    int l, r;
    if (root == NULL)
        return 0;
    l = height(root->left);
    r = height(root->right);
    return l > r ? l + 1 : r + 1;
}
// 求二叉树的宽度
int width(tree *root)
{
    int l, r;
    if (root == NULL)
        return 0;
    l = width(root->left);
    r = width(root->right);
    return l > r ? l + 1 : r + 1;
}
int main()
{
    int a[] = {1, 3, 5, 8, 9, 7, 6, 4, 2};
    tree *root;
    root = create(a, 9, 0);
    cout << "height:" << height(root) << endl;
    cout << "width:" << width(root) << endl;
    return 0;
}
