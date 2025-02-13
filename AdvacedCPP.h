#pragma once

// learn-advanced-c-programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<queue>

// mein includes
#include "MyExiption.h"
#include "ClassPerson.h"
#include "Test.h"
#include "Stack.h"




using namespace std;

//#pragma pack(pop)
#pragma pack(push, 1)

struct Person
{
	//string name;
	char  c;
	char name[50];
	//char dumm1;
	int age;
	//  int dummy2;
	double weight;

};

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void swap(int* a, int* b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

struct MyStruct
{
	int a = 1;
	int b = 2;
};

void myFunc(const struct MyStruct* a) {
	cout << a->a << endl;
	cout << a->b << endl;

}

void swap(MyStruct* a, MyStruct* b) {
	MyStruct temp = *a;
	*a = *b;
	*b = temp;
}

void swap(MyStruct& a, MyStruct& b) {
	MyStruct temp = a;
	a = b;
	b = temp;
}



