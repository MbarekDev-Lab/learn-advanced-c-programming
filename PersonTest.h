#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class PersonTest
{
private:
	string name;
	int age;

public:
	PersonTest() : name("name"), age(0) {
		cout << "No args constructor running!" << endl;
	}

	PersonTest(const PersonTest& other) {
		cout << "Copy constructor running!" << endl;
		name = other.name;
		age = other.age;
	}

	PersonTest(string name, int age) :
		name(name), age(age) {
	}

	void print() const {
		cout << name << " : " << age << endl;
	}


};
