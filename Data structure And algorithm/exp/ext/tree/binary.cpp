#include <iostream>
using namespace std;
//二叉树
struct binary
{
    int data;
    binary *left;
    binary *right;
};
//键盘输入前序遍历序列，建立二叉树
binary *CreateTree()
{
    binary *root;
    int data;
    cin >> data;
    if (data == 0)
    {
        root = NULL;
    }
    else
    {
        root = new binary;
        root->data = data;
        root->left = CreateTree();
        root->right = CreateTree();
    }
    return root;
}
//前序遍历
void PreOrderTree(binary *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        PreOrderTree(root->left);
        PreOrderTree(root->right);
    }
}
//非递归中序遍历
void InOrderTree(binary *root)
{
    binary *stack[100];
    int top = -1;
    binary *p = root;
    while (p != NULL || top != -1)
    {
        while (p != NULL)
        {
            stack[++top] = p;
            p = p->left;
        }
        if (top != -1)
        {
            p = stack[top--];
            cout << p->data << " ";
            p = p->right;
        }
    }
}
//后序遍历
void LaOrderTree(binary *root)
{
    if (root != NULL)
    {
        LaOrderTree(root->left);
        LaOrderTree(root->right);
        cout << root->data << " ";
    }
}
int main()
{
    binary *root = CreateTree();
    cout << "前序遍历：";
    PreOrderTree(root);
    cout << endl;
    cout << "中序遍历：";
    InOrderTree(root);
    cout << endl;
    cout << "后序遍历：";
    LaOrderTree(root);
    cout << endl;
    return 0;
}