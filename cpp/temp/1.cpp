//数字中缀表达式转前缀
#include <iostream>
#include <string>
#include <stack>
using namespace std;
string InfixToPrefix(string infix)
{
    stack<char> s;
    string prefix;
    for (int i = infix.size() - 1; i >= 0; i--)
    {
        if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            while (!s.empty() && s.top() != '(' && s.top() != ')')
            {
                prefix += s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == '(')
        {
            while (!s.empty() && s.top() != ')')
            {
                prefix += s.top();
                s.pop();
            }
            s.pop();
        }
        else
        {
            prefix += infix[i];
        }
    }
    while (!s.empty())
    {
        prefix += s.top();
        s.pop();
    }
    return prefix;
}
int main()
{
    string infix = "10+4+(8-(12-(6+4/5)))/3*(6-2)(12-7)";
    string prefix = InfixToPrefix(infix);
    cout << prefix << endl;
    return 0;
}
