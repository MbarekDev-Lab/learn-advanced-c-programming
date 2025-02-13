#pragma once
#include <iostream>
#include<string>

using namespace std;
namespace testclasses {

	class Parent
	{
	public:
		Parent(const Parent &other ) {
			cout << " copy Parent " << endl;
		}
		virtual void print() {
			cout << " parent " << endl;
	}
		virtual ~Parent(){}

	private:
	};

	class Child : public Parent
	{
	public:
		void print() {
			cout << "child" << endl;
		}

	private:
	};


	class TESTFUNCS {
	public :
		void test() {
			cout << " hello" << endl;
		}
		bool match(string test) {
			return test.size() ==  3;
		}



	};

	template<class T, class k>
	class Testatemplet{
	private:
		T obj;
	public:
		Testatemplet(T obj) {
			this->obj = obj;
		}	
		void print() {
			cout << obj << endl;
		}
		
		template<class t, class f>
		void print(t n, f g) {
			cout << n << g<< endl;
		}

		void print(int n) {
			cout <<"Non temp Version " << n << endl;
		}

		template<class m >
		void print(m n) {
			cout << " temp Version " << n << endl;
		}	
		
		
		template<typename m >
		void show() {
			cout << " show Version wsss " << m() << endl;
		}

	};


	class Test
	{
		int id;
		string name;
	public:
		Test(int id, string name) : id(id), name(name) {}

		Test() : id(0), name("") {}

		void print() const {
			cout << id << ": " << name << endl;
		}
		bool operator<(const Test& other) const {
			return name < other.name;
		}

		// Assignment operator overloading
		const Test& operator=(const Test& other) {
			cout << "Assignment operator running" << endl;
			id = other.id;
			name = other.name;
			return *this;
		}


		// Copy constructor
		Test(const Test& other) {
			cout << "Copy constructor running" << endl;
			//id = other.id;
			//name = other.name;
			// we can also use the assignment operator
			*this = other;
		}
		
		// Destructor	
		//~Test() {
			//cout << "Object destroyed" << endl;
		//}

		friend ostream& operator<< (ostream& out, const Test& test) {
			out << test.id << ": " << test.name;
			return out;
		}
	};


	class TestSort
	{
		int id;
		string name;
	public:
		TestSort(int id, string name) : id(id), name(name) {}
		void print() {
			cout << id << ": " << name << endl;
		}
		/*
		 bool  operator <(const TestSort& other) const {
			return name < other.name;
		}
		*/
		friend 	bool comp(const TestSort& a, const TestSort& b);
	};
//	using namespace testclasses;
	bool comp(const TestSort& a, const TestSort& b) {
		//return a.name < b.name;
		return a.name < b.name;
	}




}

