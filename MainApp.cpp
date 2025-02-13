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
#include <algorithm>

// mein includes
#include "MyExiption.h"
#include "ClassPerson.h"
#include "Test.h"
#include "Stack.h"
#include "PersonTest.h"
#include "AdvacedCPP.h"
#include "Complex.h"

using namespace std;
using namespace testclasses;
using namespace testclassesComplex;


// Custom function to count strings using a function pointer
bool match(const string& text) {
	return text == "one";
}

void test(int x, string y) {
	cout << " hello" << x << y << endl;
}

int countString(vector<string> &texts , bool (*match)(const string&)) {
	int tally=0;
	for (size_t i = 0; i < texts.size(); i++)
	{
		if (match(texts[i])) {
			tally++;
		}
	}
	return tally;
}




class ParentX
{
private:
	int one;

public:
	ParentX(const ParentX& other): one(0) {
		cout << " copy Parent " << endl;
	}
	virtual void print() {
		cout << " parent " << endl;
	}
	virtual ~ParentX() {}
};

class ChildX : public ParentX
{
private:
	int two;
public:
	ChildX(){ }
	ChildX(): two(2){

	}
	void print() {
		cout << "child" << endl;
	}
};



int main()
{
	// Begin of Prog
	cout << "Prog begint here!\n \n";
	if (1) {
		//Begin of active code
		cout << "Section 7 Function Pointer !\n";

		// Demonstrating polymorphism
		ChildX c1;
		ParentX& p1 = c1;
		p1.print(); // Should print "child"

		ParentX p2 = ChildX();
		p2.print(); // Should print "parent" due to object slicing
	
	
		//End of active code 
		std::cout <<"\n \n End of active code : ! "<<endl;
	}
	else {

		testclasses::TESTFUNCS functionPointer;
		vector<string>texts;

		texts.push_back("one");
		texts.push_back("three");
		cout << functionPointer.match("one") << "\n" << endl;

		// Using count_if with a lambda function
		auto matchP = [](const string& text) {
			return text == "one";
			};

		cout << count_if(texts.begin(), texts.end(), matchP) << endl;
		cout << countString(texts, match) << endl;


		//test(3,"");
		void (*pTest)(int, string);
		pTest = &test;

		// other way to call by func pointer 
		//void (*pTest)(int,string) = test;

		// test call the function 
		//(*pTest)(2,"mbarek");
		//cout << countString(texts, pTest) << endl;

		/*
			functionPointer.test();
			void (*pTest)();
			pTest = &functionPointer.test;
			(*pTest)();
		*/



		cout << "Section 6 Template Classes and Functions!\n";
		Testatemplet<string, int> testTempletClass("hello Mbarek");
		//testTempletClass.print<string, int>("cccc", 4);
		//testTempletClass.print(20);
		testTempletClass.print<>(20);
		testTempletClass.show<int>();


		cout << "printing overloading the Assignment Operator!\n";
		Complex c1(3, 4);
		Complex c2(2, 3);
		Complex c3 = c1 + c2;
		cout << c1 << endl;   //(3, 4) 
		cout << c1 + c2 << endl;//(5, 7)
		cout << c1 + c2 + c3 << endl;//(10, 14)

		Complex c6(1, 7);
		cout << 3.2 + c6 << endl;

		cout << 7 + c1 + c2 + 8 + 9 + c6 << endl;

		if (c1 == c2) {
			cout << " Equal " << endl;
		}
		else
		{
			cout << " Not Equal " << endl;
		}
		//Complex c2 = c1;
		//Complex c2(c1);
		//Complex c3;
		//c3 = c2;
		//cout << c2 << ":" << c3 << endl;
		cout << "end of overloading operator" << endl;
		
		
		Test testOverLaoding(10, "Mike");
		testOverLaoding.print();

		Test test2Pverloading(20, "barek");
		cout << test2Pverloading << endl;
		
		test2Pverloading = testOverLaoding;

		test2Pverloading.print();

		testclasses::Test test3;

		// methods chaining
		//test3 = test2 = test1;

		//test3 = test2;
		test3.operator=(test2Pverloading);

		cout << "print test3: \n";
		test3.print();
		cout << endl;

		Test test4 = testOverLaoding;
		test4.print();


		test3.print();
		//cout<< test3 << endl;

		cout << "End of printing overloading the Assignment Operator!\n";

		cout << "STL Complex Data Types!\n";

		map<string, vector<int> > scores;
		scores["Mike"].push_back(10);
		scores["Mike"].push_back(20);
		scores["Mike"].push_back(30);
		scores["Mike"].push_back(40);
		scores["Mike"].push_back(50);
		scores["Mike"].push_back(20);
		scores["Mbarek"].push_back(100);
		scores["Mbarek"].push_back(90);
		scores["Vicky"].push_back(15);

		for (map<string, vector<int>>::iterator it = scores.begin(); it != scores.end(); it++) {
			string name = it->first;
			vector<int> scoreList = it->second;
			cout << name << ": " << flush;

			for (size_t i = 0; i < scoreList.size(); i++) {
				cout << scoreList[i] << " " << flush;
			}
			cout << endl;
		}


		cout << "Sorting vector in cpp!\n";
		//testclasses::TestSort test1(10, "Mike");
		vector<TestSort> testsSort;
		testsSort.push_back(TestSort(10, "Mike"));
		testsSort.push_back(TestSort(30, "Raj"));
		testsSort.push_back(TestSort(20, "Vicky"));
		testsSort.push_back(TestSort(333, "Sue"));

		//	std::sort(testsSort.begin(), testsSort.end(), comp);
		std::sort(testsSort.begin(), testsSort.begin() + 3, comp);
		for (size_t i = 0; i < testsSort.size(); i++)
		{
			//testsSort[i].print();
			TestSort& test = testsSort[i];
			test.print();
		}
		//TestSort test3(333, "3AQBO");
		//TestSort test4(20, "MbaREK ");

		//cout << comp(test3, test4) << endl;

		// queue   ->  FIFO
		queue<StackQueueTest> testQueue;
		testQueue.push(StackQueueTest("Mike"));
		testQueue.push(StackQueueTest("Vicky"));
		testQueue.push(StackQueueTest("Sue"));
		testQueue.push(StackQueueTest("Bob"));

		// stack   ->  LIFO
		stack<StackQueueTest> testStack;
		testStack.push(StackQueueTest("Mike"));
		testStack.push(StackQueueTest("Vicky"));
		testStack.push(StackQueueTest("Sue"));
		testStack.push(StackQueueTest("Bob"));

		cout << " \n \n" << endl;
		/* invalid code object destroyed:
		Stack test1 = testStack.top();
		test1.pring();

		Stack& test2 = testStack.top();	// reference to the top element
		testStack.pop();
		test2.pring(); Reference refer to destroyed object
		*/

		while (!testStack.empty()) {
			StackQueueTest& test = testStack.top();
			test.pring();
			testStack.pop();
		}

		while (!testQueue.empty()) {
			StackQueueTest& testQ = testQueue.front();
			testQ.pring();
			testQueue.pop();
		}
		// End of queue and stack


		// Begin of map and set
		set<int> setNumbers;
		setNumbers.insert(50);
		setNumbers.insert(10);
		setNumbers.insert(30);
		setNumbers.insert(20);

		for (set<int>::iterator it = setNumbers.begin(); it != setNumbers.end(); it++) {
			cout << *it << endl;
		}
		set<int>::iterator itFind = setNumbers.find(30);
		if (itFind != setNumbers.end()) {
			cout << "Found: " << *itFind << endl;
		}

		if (setNumbers.count(30)) {
			cout << "Number found." << endl;
		}

		set<Test> tests;

		tests.insert(Test(10, "Mike"));
		tests.insert(Test(30, "Joe"));
		tests.insert(Test(333, "Joe"));
		tests.insert(Test(20, "Joe"));
		tests.insert(Test(20, "Joe"));
		tests.insert(Test(50, "Joe"));
		tests.insert(Test(20, "Joe"));
		tests.insert(Test(20, "Jofe"));

		for (set<Test>::iterator it = tests.begin(); it != tests.end(); it++) {
			it->print();
		}

		//multimap
		multimap<string, int> lookup;
		multimap<int, string> lookupk;

		for (multimap<string, int>::iterator it = lookup.begin(); it != lookup.end(); it++) {
			cout << it->first << ": " << it->second << endl;
		}

		lookupk.insert(make_pair(40, "Mike"));
		lookupk.insert(make_pair(20, "Viky"));
		lookupk.insert(make_pair(30, "Roj"));
		lookupk.insert(make_pair(60, "Bob"));

		for (multimap<int, string >::iterator it = lookupk.begin(); it != lookupk.end(); it++) {
			cout << it->first << ": " << it->second << endl;

		}

		auto its = lookupk.equal_range(30);
		for (multimap<int, string>::iterator it = its.first; it != its.second; it++) {
			cout << it->first << "equal_range : " << it->second << endl;
		}

		string test1 = "Mike";
		string test2 = "Bob";
		bool test = test1 < test2;

		map<ClassPerson, int> people1;

		people1[ClassPerson("Mike", 40)] = 40;
		people1[ClassPerson("Vicky", 30)] = 30;
		people1[ClassPerson("Raj", 20)] = 20;
		people1[ClassPerson("Raj", 333)] = 330;

		for (map<ClassPerson, int>::iterator it = people1.begin(); it != people1.end(); it++) {
			cout << it->second << ": " << flush;
			it->first.print();
			cout << endl;
		}

		map<int, PersonTest> people;

		people[0] = PersonTest("mbaddddrek", 40);
		people[1] = PersonTest("Viddddcky", 30);

		people[2] = PersonTest("Raj", 20);
		people[233] = PersonTest("Raj", 20);
		

		people.insert(make_pair(55, PersonTest("Benraiss", 45)));
		people.insert(make_pair(55, PersonTest("iiiii", 95)));

		for (map<int, PersonTest>::iterator it = people.begin(); it != people.end(); it++) {
			cout << it->first << ": " << flush;
			it->second.print();
		}

		map<string, int> ages;
		ages["Mike"] = 40;
		ages["Raj"] = 20;
		ages["Vicky"] = 30;
		ages["Mike"] = 70;

		cout << ages["Raj"] << endl;

		ages.insert(pair<string, int>("Peter", 100));

		ages.insert(make_pair("gsdugz", 333));

		if (ages.find("Vicky") != ages.end())
		{
			cout << "Found Viky" << endl;
		}
		else {
			cout << "Key not found" << endl;
		}

		for (map<string, int>::iterator it = ages.begin(); it != ages.end(); it++)
		{

			std::cout << it->first << ":" << it->second << endl;

			//pair<string, int> age = *it;
			//cout << age.first << ": " << age.second << endl;
		}

		// List string
		list<int> numberslist;

		numberslist.push_back(1);
		numberslist.push_back(2);
		numberslist.push_back(3);
		numberslist.push_front(0);

		//numbers.push_back(4);

		list<int>::iterator it = numberslist.begin();
		it++;

		numberslist.insert(it, 100);
		cout << "Element: " << *it << endl;

		list<int>::iterator eraseIt = numberslist.begin();
		eraseIt++;

		eraseIt = numberslist.erase(eraseIt);
		cout << "Element: " << *eraseIt << endl;

		for (list<int>::iterator it = numberslist.begin(); it != numberslist.end();) {
			if (*it == 2)
			{
				int value = std::stoi("123");
				numberslist.insert(it, value);
			}

			if (*it == 1)
			{
				it = numberslist.erase(it);
			}
			else {
				it++;
			}
		}

		for (list<int>::iterator it = numberslist.begin(); it != numberslist.end(); it++) {
			cout << *it << endl;
		}

		// End of List string

	// tow dimensional vector
	// vector<vector<int>>(3, vector<int>(3, 4)) 
	// creates a new 3x3 vector with all elements initialized to 4

		vector<vector<int>> grid;
		grid = vector<vector<int>>(3, vector<int>(3, 4));

		//to push one more element into the row 1 of the grid
		grid[1].push_back(8);

		for (size_t row = 0; row < grid.size(); row++) {
			for (size_t col = 0; col < grid[0].size(); col++)
			{
				cout << grid[row][col] << flush;
			}
			cout << endl;
		}
		cout << "§ End Vector pres \n" << endl;

		cout << "First row: ";
		for (int elem : grid[0]) {
			cout << elem << " ";
		}
		cout << endl;

		cout << "Second row: ";
		for (int elem : grid[1]) {
			cout << elem << " ";
		}
		cout << endl;

		cout << "Third row: ";
		for (int elem : grid[2]) {
			cout << elem << " ";
		}
		cout << endl;

		cout << " \nEnd vector rows " << ": ";

		grid[0] = { 4, 4, 4 }; // First row
		grid[1] = { 4, 4, 4 }; // Second row
		grid[2] = { 4, 4, 4 }; // Third row
		// end of tow dimensional vector

		vector<double> numbers(20);
		int capacity = numbers.capacity();
		int size = numberslist.size();

		cout << "Capacity: " << capacity << endl;
		cout << "Size    : " << size << "\n \n" << endl;

		for (int i = 0; i < 10; i++) {
			if (numbers.capacity() != capacity) {
				capacity = numbers.capacity();
				cout << "Capacity: " << capacity << endl;
			}
			numberslist.push_back(i);

			cout << "Capacity:  " << numbers.capacity() << "  Size: " << numbers.size() << endl;
		}


		// the size is the acual number of the elements in the vector
		numbers.resize(100); // resize the vector to 100 elements
		cout << "Capacity after resize: " << numbers.capacity() << endl;
		cout << "Size after resize: " << numberslist.size() << endl;

		// clear the vector
		numbers.clear();
		cout << "Size after clear    : " << numbers.size() << endl;
		cout << "Capacity after clear: " << numbers.capacity() << endl;


		// List string
		vector<string> strings;
		strings.push_back("one");
		strings.push_back("two");
		strings.push_back("three");

		for (size_t i = 0; i < strings.size(); i++) {
			cout << strings[i] << endl;
		}

		for (vector<string>::iterator it = strings.begin(); it != strings.end(); it++) {
			cout << *it << endl;
		}

		vector<string>::iterator itv = strings.begin();
		itv += 1; // arithmetic operation on iterator
		cout << *itv << endl;	// two


		// Write a binary file
		Person someone = { 'A',"Frodo", 220, 0.8 };
		//Person someone = { "Frodo", 220, 0.8 };
		string fileName = "test.bin";
		ofstream outputFile;
		// using binary mode fstream
		//fstream outputFile;
		//outputFile.open(fileName, ios::binary|ios::out);
		// using binary mode ofstream
		outputFile.open(fileName, ios::binary);
		if (outputFile.is_open()) {
			outputFile.write((char*)&someone, sizeof(Person));
			//new way of casting better than c style casting
			outputFile.write(reinterpret_cast<char*>(&someone), sizeof(Person));
			outputFile.close();
		}
		else {
			cout << "Could not create file: " << fileName << endl;
		}
		// Read a binary file
		Person someoneElse = {};
		ifstream inputFile;
		inputFile.open(fileName, ios::binary);
		if (inputFile.is_open())
		{
			inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Person));
			inputFile.close();
		}
		else
		{
			cout << "Could not read file: " << fileName << endl;
		}

		cout << someoneElse.name << ", " << someoneElse.age << ", " << someoneElse.weight << endl;
		cout << sizeof(Person) << endl;

		// _> Writing to a file

		//ofstream outFile;
		fstream outFile;
		string outFileName = "test.txt";

		// outFile.open(outFileName);

		 // Truncation: When a file is opened with ios::out, its existing contents are erased.
		outFile.open(outFileName, ios::out);

		if (outFile.is_open()) {
			outFile << "begging of Wittling !" << endl;
			outFile << 222.3433 << endl;
			outFile << 11111133455 << endl;
			outFile << true << endl;
			outFile << "end of writing " << endl;
			outFile.close();
		}
		else {
			cout << "Could not open file" << endl;
			return 1;
		}

		string intFileName = "test.txt";

		ifstream inFile;

		inFile.open(intFileName);

		if (inFile.is_open()) {
			string line;

			//inFile >> line; // read the first word
			//cout << line << endl;


			while (!inFile.eof()) {
				getline(inFile, line);
				cout << line << endl;
			}

			inFile.close();
		}
		else {
			cout << "Could not open file: " << intFileName << endl;
			return 1;
		}
		// End of writing to a file

		try {
			// Code that may throw an exception
			MyException* test = new MyException();
			test->goesWrong();
			delete test;
		}
		catch (const MyException& e) {
			// Handle the custom exception
			cout << "Caught MyException: " << e.what() << endl;
		}
		catch (const exception& e) {
			// Handle other exceptions
			cout << "Caught exception: " << e.what() << endl;
		}

		cout << "This is false" << endl;
	}



	/*
		cout << "Size of char: " << sizeof(char) << endl;
		cout << "Size of int: " << sizeof(int) << endl;
		cout << "Size of short int: " << sizeof(short int) << endl;
		cout << "Size of long int: " << sizeof(long int) << endl;
		cout << "Size of float: " << sizeof(float) << endl;
		cout << "Size of double: " << sizeof(double) << endl;
		cout << "Size of long double: " << sizeof(long double) << endl;
		cout << "Size of bool: " << sizeof(bool) << endl;
		cout << "Size of string: " << sizeof(string) << endl;
		cout << "Size of wchar_t: " << sizeof(wchar_t) << endl;
		cout << "Size of long long: " << sizeof(long long) << endl;
	*/

	// End of Prog
	std::cout << " Hey it's end of  Prog! \n";
	return 0;
}
