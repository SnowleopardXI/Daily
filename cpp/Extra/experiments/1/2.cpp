#include <iostream>
using namespace std;
class Date{
public:
	void printDate();	//显示日期
	void setDay(int);	//设置日的值
	void setMonth(int); //设置月的值
	void setYear(int);  //设置年的值
private:
	int day, month, year;
};
void Date::printDate(){
    cout << "日期：" << year << "年" << month << "月" << day << "日" << endl;
}
void Date::setDay(int d){
    day = d;
}
void Date::setMonth(int m){
    month = m;
}
void Date::setYear(int y){
    year = y;
}
int main(){
	Date testDay;
	testDay.setDay(5);
	testDay.setMonth(10);
	testDay.setYear(2010);
	testDay.printDate();
	
	return 0;
};
