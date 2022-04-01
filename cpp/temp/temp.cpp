#include <iostream>
using namespace std;
class RationalNumber
{
private:
    int a, b; // a为分子，b为分母
    public:
    // construtors
    RationalNumber(); //用初始化成员列表设置默认值分子为0，分母为1
    RationalNumber(int, int); //分子用普通赋值方法初始化，分母调用set函数初始化
    // getters
    int getNumerator(); //分子
    int getDenominator(); //分母
    // setters
    void setNumerator(int); //分子
    void setDenominator(int); //分母,如果分母为0，设置为1
    //其他成员函数
    void print(); //输出a/b的格式
    //函数myAdd(),mySubtract()，分别实现两个有理数相加和相减功能。注意传递参数是RationalNumber类型
    RationalNumber myAdd(RationalNumber);
    RationalNumber mySubtract(RationalNumber &r);
    friend RationalNumber myMultiply(RationalNumber, RationalNumber); //定义myMultiply()为友元函数
};
// 定义普通函数myDivide
/*以下为一个有理数类的部分声明，实现如下要求：
1、实现类中声明函数。
2、在类中声明并实现函数myAdd(),mySubtract()，分别实现两个有理数相加和相减功能。注意传递参数是RationalNumber类型，返回值也是RationalNumber类型。
3、定义一个普通函数myDivide()，用来实现两个有理数相除。注意传递参数是RationalNumber类型，返回值也是RationalNumber类型。
4、声明并实现一个友元函数myMutiply(),用来实现两个有理数相除。注意传递参数是RationalNumber类型，返回值也是RationalNumber类型。
5、补充main()函数，使得程序输出正确运算结果。
*/
