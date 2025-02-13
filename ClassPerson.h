#include<iostream>
#include<string>

using namespace std;
#pragma once
class ClassPerson
{
private:
	std::string name;
	int age;

public:
	ClassPerson() : name("name"), age(0) {
	}
	ClassPerson(const ClassPerson& other) {
		cout << "Copy constructor running!... \n" << endl;
		name = other.name;
		age = other.age;
	}
	ClassPerson(string name, int age) :
		name(name), age(age) {
	}
	void print() const {
		cout << name << " : " << age << endl;
	}

	bool operator < (const ClassPerson& other) const {
		if (name == other.name) {
			return age < other.age;
		}
		else
		{
			return name < other.name;
		}
	}

};

