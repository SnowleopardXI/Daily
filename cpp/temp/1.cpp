#include <iostream>
#include <string>
using namespace std;
int main()
{
    string s1,s2,s3;
    s1="hello";
    s2='123';
    s3=s1+s2;
    cout<<s3<<endl;
    string s4=s1+"123";
    cout<<"s1+\"123\"is"<<s4<<endl;
    return 0;
}