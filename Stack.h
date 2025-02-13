#pragma once
#include <iostream>
#include <string>
using namespace std;


class StackQueueTest
{
private:
	string name;

public:	
	StackQueueTest(string name) : name(name){
	}

	// destroy the stack
	~StackQueueTest() {
		//delete[] Stack;
		//cout << "Object destroyed" << endl;
	}


	void pring() const{
		cout << name << endl;
	}

};

