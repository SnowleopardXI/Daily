#include <iostream>
using namespace std;
using namespace std;
class Student{
	private:
		string name;
		int age;
		Student* myfriend;
	public:
		Student();
		Student(string name,int age);
		Student(string name, int age,string friend_name,int friend_age);
		
		void setFriend(string name,int age);
		Student& operator=(const Student&);
		~Student();
		Student(const Student&);
		friend ostream& operator<<(ostream& os,const Student& s);
};

ostream& operator<<(ostream& os,const Student& s);
