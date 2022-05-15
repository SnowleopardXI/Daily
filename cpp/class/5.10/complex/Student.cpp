#include <iostream>
#include "Student.h"
using namespace std;
ostream& operator<<(ostream& os,const Student& s){
	os<<"名字:"<<s.name<<",年龄："<<s.age<<".";
	if(s.myfriend) {
		os<<"朋友名字:"<<s.myfriend->name<<",年龄："<<s.myfriend->age<<"."; 
	}
	else
		os<<"没有朋友.";
	return os;
}
Student::Student(){
	name="";
	age=0;
	myfriend=NULL;
}
Student::Student(string name,int age):name(name),age(age){
	myfriend=NULL;
}

Student::Student(string name, int age,string friend_name,int friend_age){
	this->name=name;
	this->age=age;
	this->myfriend=new Student(friend_name,friend_age); 
}
void Student::setFriend(string name,int age){
	myfriend->name=name;
	myfriend->age=age;
}
Student& Student::operator=(const Student& a){
	if(this==&a)
		return *this;
	
	name=a.name;
	age=a.age;
	if(myfriend){
		delete myfriend;
		myfriend=NULL;
	}
		
	if(a.myfriend)
		myfriend=new Student(a.myfriend->name,a.myfriend->age);
	return *this;
}
Student::~Student(){
	if(myfriend)
		delete myfriend;
}
Student::Student(const Student& a){
	this->name=a.name;
	this->age=a.age;
	if(a.myfriend){
		this->myfriend=new Student(a.myfriend->name,a.myfriend->age);
	}
	else
		this->myfriend=NULL;
}
