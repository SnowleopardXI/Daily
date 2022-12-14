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
//非递归后序遍历二叉树，求从根结点到P所指结点之间的路径
void PostOrderTree(binary *root, binary *p)
{
    binary *stack[100];
    int top = -1;
    binary *pre = NULL;
    binary *cur = root;
    while (cur != NULL || top != -1)
    {
        while (cur != NULL)
        {
            stack[++top] = cur;
            cur = cur->left;
        }
        if (top != -1)
        {
            cur = stack[top];
            if (cur->right == NULL || cur->right == pre)
            {
                cout << cur->data << " ";
                top--;
                pre = cur;
                cur = NULL;
            }
            else
            {
                cur = cur->right;
            }
        }
    }
}
int main()
{
    binary *root = CreateTree();
    binary *p = root->left->right;
    PostOrderTree(root, p);
    return 0;
}
