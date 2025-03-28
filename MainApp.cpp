// learn-advanced-c-programming.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<stack>
#include<queue>
#include <array>
#include <functional>	
#include<algorithm>
#include <functional> // For std::bind

// mein includes
#include "MyExiption.h"
#include "ClassPerson.h"
#include "Test.h"
#include "Stack.h"
#include "PersonTest.h"
#include "AdvacedCPP.h"
#include "Complex.h"
#include "ring.h"
using namespace placeholders;


using namespace testclasses;
using namespace testclassesComplex;

// Custom function to count strings using a function pointer
bool static match(const string& text) {
	return text == "one";
}

void static test(int x, string y) {
	cout << " hello" << x << y << endl;
}

int static countString(vector<string> &texts , bool (*match)(const string&)) {
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
	ParentX() : one(0) {}
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
	//ChildX(){ }
	ChildX(): two(2){
	}
	void print() {
		cout << "child" << endl;
	}
};

void static testFunc(Animal& an) {
	an.run();
};
bool static check(string &test) {
	return test.size() == 3;
}
class {
public:
	bool operator()(string& text) {
		return text == "lion";
	}
}checkStr;

void static checkFun(function<bool(string&)> check) {
		string value = "lion";
		cout << check(value) << endl;
}

int main() {
	// Begin of Prog
	cout << "Prog begint here!\n \n";
	if (1) {
		cout << "Section 8 C++ 11 new features !\n";

		//shared_ptr<TestSharedPtr> pTestSharedPtr(new TestSharedPtr());
		shared_ptr<TestSharedPtr> pSharedPtr(nullptr);
		// Trying to use the shared_ptr
		if (pSharedPtr != nullptr) {
			pSharedPtr->run();  // This won't run because pSharedPtr is null
		}
		else {
			cout << "pSharedPtr is nullptr, can't run method." << endl;
		}

		//shared_ptr<TestSharedPtr> pTestSharedPtr(new TestSharedPtr());
		//shared_ptr<TestSharedPtr> pTestSharedPtr3 = pTestSharedPtr;
		
		// Using shared_ptr with make_shared
		shared_ptr<TestSharedPtr> pTestSharedPtr = make_shared<TestSharedPtr>();  // Recommended approach
		pTestSharedPtr->run();

		// Shared ownership of the object
		shared_ptr<TestSharedPtr> pTestSharedPtr2 = pTestSharedPtr;
		shared_ptr<TestSharedPtr> pTestSharedPtr3 = pTestSharedPtr2;
	
		//End of active code 
		std::cout <<"\n \n End of active code : ! "<<endl;
	}
	else {
		cout << "Section 8 C++ 11 new features !\n";

		// unique_ptr
		unique_ptr<int> pTest(new int());
		*pTest = 7;

		cout << "Finished pTest " << endl;
		cout << *pTest << endl;

		unique_ptr<int> pTestSmart = make_unique<int>(7);  // Allocate an int with value 7
		cout << "Finished pTestSmart" << endl;
		cout << *pTestSmart << endl;  // Output: 7

		unique_ptr<TestUniquePtr> ptr = make_unique<TestUniquePtr>();
		ptr->run();  // Call member function

		unique_ptr<TestUniquePtr[]> pSmartTest(new TestUniquePtr[2]);
		pSmartTest[1].run();  // Call member function
		//pSmartTest->run();  // not allowed

		//unique_ptr<TestUniquePtr> ptr = make_unique<TestUniquePtr>();
		//ptr->run();  // Call member function


		BindTest bindTest;
		//bindTest.add(1,2,3);
		//cout << bindTest.add(1, 2, 3) << endl;
		//auto calculate = bind(&BindTest::add, bindTest, 1, 2, 3);
		//auto calculate = bind(BindTest::add, _1, _2, _3);
		//cout << calculate(10,20,30) << endl;

		// bind add with fixed parameters
		//auto calculate = std::bind(&BindTest::add, bindTest, 2, 100, 1);
		//cout << "Result of add: " << calculate() << endl;  // Calls bindTest.add(2, 100, 1)

		//auto calculateDynamic = std::bind(&BindTest::add, bindTest, _1, _2, 10);
		//int result = bindTest.run(calculateDynamic);  // Calls add with (7, 3, 10)
		// 
		// Bind add with fixed parameters
		auto calculate = std::bind(&BindTest::add, std::ref(bindTest), 2, 100, 1);
		cout << "Result of add: " << calculate() << endl;  // Calls bindTest.add(2, 100, 1)

		// Bind add dynamically with placeholders
		auto calculateDynamic = std::bind(&BindTest::add, std::ref(bindTest), _1, _2, 10);
		int result = bindTest.run(calculateDynamic);  // Calls add with (7, 3, 10)

		cout << "Result of run: " << result << endl;


		TestCheckIfRvalue obj;
		call(obj); // Calls lvalue version
		call(TestCheckIfRvalue()); // Calls rvalue version 

		/*
		   check(obj);   // Calls lvalue version
			check(TestCheckIfRvalue()); // Calls rvalue version
			call(10); // Works fine for built-in types
			call(obj); // Works fine for objects

		  The&& after auto indicates that checktest is a universal reference.
			Universal references can bind to both lvalues and rvalues.
			auto&& is a universal reference, which can bind to both lvalues
			and rvalues. In this case, it binds to the rvalue TestCheck().
		*/
		//TestCheck testCheck;

	   //auto&& checktest = TestCheck();

	   //cout << "Check test: " << checktest << endl;



		cout << "reinterpret_cas !\n";
		// reinterpret_cast
		Parent2 parent2;
		Brother2 brother2;
		Sister2 sister2;

		Parent2* ppb = &brother2; //0x000000319abb8658
		//Brother2* pbb = reinterpret_cast<Brother2*>(ppb);
		Sister2* sbb = reinterpret_cast<Sister2*>(ppb);
		if (sbb == nullptr) {
			cout << "Invalid cast" << endl;
		}
		else {
			cout << "pbb  " << sbb << endl;
		}

		// dynamic casting 
	
		Brother2* pbb2 = dynamic_cast<Brother2*>(ppb); //0x00007ff664b0f751 {learn-advanced-c-programming.exe!testclasses::Brother2::`vector deleting destructor'(unsigned int)}
		if (pbb2 == nullptr) {
			cout << "Invalid cast" << endl;
		}
		else {
			cout << "pbb  " << ppb << endl;
		}

		// static casting 
		//Brother2* bp = &parent2;// not allowed
		Parent2* pp = &brother2; // allowed

		Brother2* bp = static_cast<Brother2*>(&parent2); //is not safe
		//cout << bp << endl;

		Brother2* pbb = static_cast<Brother2*>(ppb);

		cout << "pbb  " << ppb << endl;

		//Parent2&& p = Parent2();
		Parent2&& p = static_cast<Parent2&&>(parent2); //creates an rvalue reference p
		p.speak();


		//	cout << "p  " << p << endl;
		//  dynamic casting
			/*
				To safely cast a base class pointer to a derived class pointer,
				you should use dynamic_cast. dynamic_cast performs a runtime check to ensure
				the validity of the cast and returns nullptr if the cast is not valid.

			// cast to  int:
			float value = 3.23;
			// C
			cout << int(value) << endl;
			// CPP
			cout << static_cast<int>(value) << endl;*/


		cout << " Move Constructor: !\n";
		vector<ConstructorsAndMemory> constructorsAndMemoryVector;
		constructorsAndMemoryVector.push_back(ConstructorsAndMemory());

		// Move assignment operator
		ConstructorsAndMemory moveAssignment;

		moveAssignment = getConstructorsAndMemory();

		cout << " Rvalues and LValues!\n";
		ConstructorsAndMemory constructorsAndMemory = getConstructorsAndMemory();
		cout << constructorsAndMemory << endl;

		vector<ConstructorsAndMemory> lValVector;
		lValVector.push_back(ConstructorsAndMemory());

		int value1 = 7;
		int* pValue1 = &value1;
		//is not allowed
		//int* pValue2 = &7;

		ConstructorsAndMemory* pConstructorsAndMemory = &constructorsAndMemory;
		//ConstructorsAndMemory* pConstructorsAndMemory2 = &ConstructorsAndMemory();

		int* pValue3 = &++value1;
		cout << *pValue3 << endl;


		//int* pValue4 = &value1++;
		int s = 7 + value1; //rvalue

		//int *s = &(7 + value1); 
		//cout << *s << endl;

		//int* pValue5 = &(value1++);
		//cout << s << endl;

		const ConstructorsAndMemory& rConstructorsAndMemory = getConstructorsAndMemory();
		ConstructorsAndMemory cnstructorsAndMemory(ConstructorsAndMemory(1));
		cout << cnstructorsAndMemory << endl;



		cout << "Constructor and Memory !\n";
		cout << "Copy elision !\n";
		ElisionAndOptimization elisionandoptimization = getElisionAndOptimization();
		cout << elisionandoptimization << endl;
		vector<ElisionAndOptimization> vec3;
		vec3.push_back(ElisionAndOptimization());
		
		//  using mutable to allow the cats to be changed

		//Delegate Constructor
		ParentDelegate parent("Mbarek");
		ChildDelegate child;
		
		
		int  cats = 5;
		[]() {}(); // empty lambda
		[cats]()mutable { // to allow the cats to be changed
			cats = 8;
			cout << cats << endl;
			}();

		// The Standerd function Types :
		std::vector<int> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
		// Count the number of even numbers in the vector
		int countEv = std::count_if(vec.begin(), vec.end(), [](int x) {
			return x % 2 == 0;
			});
		std::cout << "Number of even numbers: " << countEv << std::endl;

		int size = 4;
		vector<string> vec2{ "one", "two", "three", "lion" };
		int count = count_if(vec2.begin(), vec2.end(), [size](string test) {
			return test.size() == size;
			});
		cout << count << endl;

		//count = count_if(vec2.begin(), vec2.end(), check);
		cout << count << endl;

		count = count_if(vec2.begin(), vec2.end(), checkStr);
		cout << count << endl;

		count = count_if(vec2.begin(), vec2.end(), checkStr);
		cout << count << endl;

		auto lambda = [size](string test) {
			return test.size() == size;
			};

		// passing a lambda to a function
		checkFun(lambda);
		// passing a functor to a function
		checkFun(checkStr);

		// passing a function to a function
		//function<bool(string&)> checkF = check;
		function<int(int, int)> add = [](int one, int two) {return one + two; };
		count = add(7, 3);
		cout << count << endl;

		Increment incrementBy2(2);
		//for_each(vec.begin(), vec.end(), incrementBy2);
		//for (int i : vec) {
		//	std::cout << i << " "; // Output: 3 4 5 6 7 8 9 10 11 12
		//}

		cout << "Capture with 'this' lambdas (cupturing this with lambdas)!\n";
		// Lambda Capture Expressions [capture](parameters) -> return_type { function_body }
		// since c++ 20 [capture]<template_parameters>(parameters) -> return_type { function_body }
		TestLamdaexpressions Capture;
		Capture.runLambda();

		cout << " Lambda  Capture Expressions  ...	[](){}(); " << endl;
		int one = 1;
		int two = 2;
		int three = 3;

		// = capture by value ||  & capture by reference
		// Capture one and two by value
		[one, two]() {  cout << one << two << endl; }();

		// Capture all local variables by value
		[=]() {cout << one << two << endl; }();

		[one]() {cout << one + 3 << one << endl; }();

		// Capture all local variables by value, but capture three by reference
		[=, &three]() {three = 7; cout << one << two << endl; }();
		cout << three << endl;

		// Capture all local variables by reference
		[&]() {three = 7; two = 8; cout << one << two << endl; }();

		// Capture all local variables by reference, but two and three by value
		[&, two, three]() {one = 100; cout << one << two << endl; }();


		cout << " Lambda expression Parameteres and return types ... " << endl;
		TestLamdaexpressions testLamdaexpressions;
		auto func = []() {cout << " Lamda expression ... " << endl; };
		[]() {cout << " Lamda expression 	[]()... " << endl; }();

		testLamdaexpressions.test1(func);
		func();
		testLamdaexpressions.test1([]() {cout << " Lamda expression again ... " << endl; });
		auto pGHreet = [](string name) {cout << " Hello " << name << endl; };

		pGHreet("Mbarek");

		testLamdaexpressions.test2([](string name) {cout << " Hello " << name << endl; });
		testLamdaexpressions.test2(pGHreet);

		auto pDivide = [](double a, double b) -> double {
			if (b == 0.0) {
				return 0.0; // throw MyException("Divide by zero"); infinit value
			}
			return a / b;
			};

		cout << pDivide(10.0, 0.0) << endl;
		testLamdaexpressions.runDivide(pDivide);

		cout << "Initialization  !\n";
		vector<int> numbers{ 1,2,3,4 };
		cout << numbers[2] << endl;

		Initialization98 init{ 1,2,3,4,5,6,7,8,9,10 };
		init.print({ "one", "two", "three", "four" });
		init.print();

		Initialization98 init2(100);
		init2.print();


		cout << "Making Classes iterable !\n";
		ring<string> makingclassiterrable(3);
		makingclassiterrable.add("One");
		makingclassiterrable.add("Two");
		makingclassiterrable.add("Three");

		for (ring <string>::iterator classIterable = makingclassiterrable.begin(); classIterable != makingclassiterrable.end(); classIterable++) {
			cout << *classIterable << endl;
		}
		cout << endl;
		for (auto value : makingclassiterrable) {
			cout << value << endl;
		}

		for (string value : makingclassiterrable) {
			cout << value << endl;
		}

		// A Ring Buffer Class!
		ring<string>textring(3);
		textring.add("one");
		textring.add("two");
		textring.add("three");
		textring.add("four"); // - "four" overwrites "one".
		textring.add("five"); // - "five" overwrites "two".
		//textring.add("six");
		for (int i = 0; i < textring.size(); ++i) {
			cout << textring.get(i) << endl;
		}
		/*
		 ring<int>::iterator it;
		it.print();
		ring2<int>::iterator2 it2;
		it2.print();
		*/

		// Nested Template Classes
		auto texts1 = { "one", "two", "three" };
		initializer_list<const char*> texts2 = { "one", "two", "three" };
		const char* texts3[] = { "one", "two", "three" };
		string texts4[] = { "one", "two", "three" };
		array<const char*, 3> texts5 = { "one", "two", "three" };
		vector<int> numbersF;
		numbersF.push_back(5);
		numbersF.push_back(6);
		numbersF.push_back(7);

		for (const auto& txt : texts1) {
			cout << txt << endl;
		}
		for (const auto& txt : texts2) {
			cout << txt << endl;
		}
		for (const auto& txt : texts3) {
			cout << txt << endl;
		}
		for (const auto& txt : texts4) {
			cout << txt << endl;
		}
		for (const auto& txt : texts5) {
			std::cout << txt << std::endl;
		}
		for (auto num : numbersF) {
			cout << num << endl;
		}
		string hey = "hello";
		for (auto s : hey) {
			cout << s << endl;
		}

		TestCPP11 cpp11;
		cout << cpp11.test(1, 2) << endl;
		cout << cpp11.testGet() << endl;
		//string value;
		auto value = "";
		decltype(value) name = "Mbarek";
		cout << "valuer type : " << typeid(value).name() << " -> " << name << endl;

		cout << "Section 7 Functors !\n";
		//MachTest pred;
		string value2 = "lionn";
		//cout << pred(value) << endl; //will be false becaus lionn != lion orOutput: 1 (true)
		//testclasses::MachTest m;
		//check(value, m);

		// Demonstrating polymorphism
		// Abstraction in cpp
		//Labrador2 labs[5];
		Labrador2 lab;
		//lab.speak();
		//lab.run();
		//lab.speak2();

		Animal* animals[5];
		animals[0] = &lab;
		animals[0]->speak();
		animals[1]->run();/*Exception thrown at 0x009D87CD in learn-advanced-c-programming.exe: 0xC0000005: Access violation reading location 0xCCCCCCCC.*/
		animals[2]->run();
		testFunc(lab);

		//ChildX c1;
		//ParentX& p1 = c1;
		//p1.print(); // Should print "child"

		//ParentX p2 = ChildX();
		//p2.print(); // Should print "parent" due to object slicing

		cout << "Section 5 Function Pointer !\n";
		// beging of function pointer
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
		void (*pTest2)(int, string);
		pTest2 = &test;

		// other way to call by func pointer 
		//void (*pTest)(int,string) = test;

		// test call the function 
		(*pTest2)(2,"mbarek");
		//cout << countString(texts, pTest) << endl;

		functionPointer.test();
		//void (*pTest)();
		//pTest = &functionPointer.test;
		//(*pTest)();

		//void (*pTestMethod)() = &functionPointer.test;
		//(*pTestMethod)();


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

		vector<double> numbersD(20);
		int capacity = numbersD.capacity();
		int  size2 = numberslist.size();

		cout << "Capacity: " << capacity << endl;
		cout << "Size    : " << size << "\n \n" << endl;

		for (int i = 0; i < 10; i++) {
			if (numbersD.capacity() != capacity) {
				capacity = numbersD.capacity();
				cout << "Capacity: " << capacity << endl;
			}
			numberslist.push_back(i);

			cout << "Capacity:  " << numbersD.capacity() << "  Size: " << numbersD.size() << endl;
		}


		// the size is the acual number of the elements in the vector
		numbersD.resize(100); // resize the vector to 100 elements
		cout << "Capacity after resize: " << numbersD.capacity() << endl;
		cout << "Size after resize: " << numberslist.size() << endl;

		// clear the vector
		numbersD.clear();
		cout << "Size after clear    : " << numbersD.size() << endl;
		cout << "Capacity after clear: " << numbersD.capacity() << endl;


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
