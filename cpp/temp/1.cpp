#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1="Hello";
    string month= "March";
    string s2(8,'x');
    cout<<s1<<endl;
    cout<<s1.at(3)<<endl;
    cout<<month<<endl;
    cout<<s2<<endl;
    s1+=s2;
    cout<<s1<<endl;
    cout<<(month<s1)<<endl;
    cout<<(s1.length()>month.length())<<endl;
    return 0;
}