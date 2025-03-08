#pragma once
#include <iostream>
#include<string>
#include<initializer_list>

using namespace std;
namespace testclasses {


	class ConstructorsAndMemory {
	private:
		static const int SIZE = 100;
		int *m_pBuffer;

	public:
		ConstructorsAndMemory()  {
			cout << "No parameter constructor, Default Constructor" << endl;
			m_pBuffer = new int[SIZE] {};
			//memset(_pBuffer, 0, sizeof(int) * SIZE);
		}

		ConstructorsAndMemory(int data)  {
			cout << "parameter constructor" << endl;

			m_pBuffer = new int[SIZE] {};
			for (int i = 0; i < SIZE; i++) {
				m_pBuffer[i] = 7*data;
			}

		}
		//copy constructor
		ConstructorsAndMemory(const ConstructorsAndMemory& other){
			cout << "copy constructor" << endl;
			m_pBuffer = new int[SIZE] {};
			memcpy(m_pBuffer, other.m_pBuffer, SIZE * sizeof(int));

		}

		ConstructorsAndMemory& operator=(const ConstructorsAndMemory& other) {
			cout << "assignment" << endl;
			m_pBuffer = new int[SIZE] {};
			memcpy(m_pBuffer, other.m_pBuffer, SIZE * sizeof(int));
			return *this;
		}

		~ConstructorsAndMemory() {
			cout << "destructor" << endl;
			delete[] m_pBuffer;
		}

		friend ostream& operator<<(ostream& out, const ConstructorsAndMemory& test);
	};

	//ostream& operator<<(ostream& out, const ConstructorsAndMemory& test) {
	//	out << "Hello from test";
	//	return out;
	//}

	ostream& operator<<(ostream& out, const ConstructorsAndMemory& test) {
		out << "Buffer contents: ";
		for (int i = 0; i < ConstructorsAndMemory::SIZE; ++i) {
			out << test.m_pBuffer[i] << " ";
		}
		return out;
	}

	ConstructorsAndMemory getConstructorsAndMemory() {
		return ConstructorsAndMemory();
	}


	class ElisionAndOptimization { 
	public:
		ElisionAndOptimization() {
			cout << "constructor" << endl;
		}

		ElisionAndOptimization(int i) {
			cout << "parameterized constructor" << endl;
		}

		ElisionAndOptimization(const ElisionAndOptimization& other) {
			cout << "copy constructor" << endl;
		}

		ElisionAndOptimization& operator=(const ElisionAndOptimization& other) {
			cout << "assignment" << endl;
			return *this;
		}

		~ElisionAndOptimization() {
			cout << "destructor" << endl;
		}

		friend ostream& operator<<(ostream& out, const ElisionAndOptimization& test);
	};

	ostream& operator<<(ostream& out, const ElisionAndOptimization& test) {
		out << "Hello from test";
		return out;
	}
	ElisionAndOptimization getElisionAndOptimization() {
		return ElisionAndOptimization();
	}




	class ParentDelegate {
		int dogs{5};
		string text{"hello"};
	public:
		ParentDelegate() : ParentDelegate("ParentDelegate") {
			dogs = 5;
			cout << "no parameter parent constructor" << endl;
		}

		ParentDelegate(string text) {
			dogs = 5;
			this->text = text;
			cout << "string parent constructor" << endl;
		}
	};


	class ChildDelegate : public ParentDelegate {
	int cats;
	public:
		ChildDelegate() = default;
	 

	};

	class Increment {
	public:
		Increment(int n) : num(n) {}

		// Overload the function call operator
		void operator()(int& element) const {
			element += num;
		}

	private:
		int num;
	};
	
	class TestLamdaexpressions {

	private:
		int one{1};
		int two{2};

	public:
		TestLamdaexpressions() {
			cout << "TestLamdaexpressions constructor" << endl;
		}

		void runLambda() { // cupturing this with lambdas
			int three = 3;
			int four = 4;
			//auto pLambda = [this, three , four] {
			//auto pLambda = [=, this, three, four] { // we cannot do this->one = 111; because this is read only
			auto pLambda = [&, this](int six) { // passing the values by reference
				//one = 111;
				cout << "one "<<one << endl;
				cout << "two "<<two << endl;
				cout << "three "<<three << endl;
				cout << "four " <<four << endl;
					//cout << six << endl;
				}; // we can also use [=] to capture all the variables by value
			pLambda(6); // we can pass the value to the lambda function (6)
		}

		void test1(void(*pFunc)()) {
			
			pFunc();
		
			/*
				int one = 1;
				int two = 2;
				int three = 3;
				// Capture one and two by value
				[one, two]() {
				cout << one << ", " << two << endl; }();
				// Capture all local variables by value
				[=]() {cout << one << ", " << two << endl; }();
				// Capture all local variables by value, but capture three by reference
				[=, &three]() {three = 7; cout << one << ", " << two << endl; }();
				// Capture all local variables by reference
				[&]() {three = 7; two = 8; cout << one << ", " << two << endl; }();
				// Capture all local variables by reference, but two and three by value
				[&, two, three]() {one = 100; cout << one << ", " << two << endl; }();
				// Capture all local variables by reference, but two and three by value
				[&, two, three]() {one = 100; cout << one << ", " << two << endl; }();
				// Capture all local variables by reference, but two and three by value
				[=, &two, &three]() {one = 100; cout << one << ", " << two << endl; }();
			*/
		}
		
		void test2(void(*greater)( string text)) {
			greater("benraiss");
			//cout << "value: " << value << ", text: " << text << endl;
		}
		
		void runDivide(double(*divide)(double a, double b)) {
			auto r = divide(9, 3);
			cout << r << endl;
		}
	};

	class Initialization98
	{
		int id{ 3 };
		string text{ "hello" };
	public:

		/*
			 // Default constructor
			Initialization98() = default;

			// Copy constructor
			Initialization98(const Initialization98& other) = default;

			// Copy assignment operator
			Initialization98& operator=(const Initialization98& other) = default;

			// Parameterized constructor
			Initialization98(int id, std::string text) : id(id), text(text) {}
		*/

		Initialization98() = default;
		//Initialization98(const Initialization98& other) = default;
		Initialization98(const Initialization98& other) = delete;
		//Initialization98& operator=(const Initialization98& other) = default;
		//Initialization98& operator=(const Initialization98& other) = delete;

		Initialization98& operator=(const Initialization98& other) {
			if (this != &other) { // Check for self-assignment
				this->id = other.id;
				this->text = other.text;
			}
			return *this;
		}

		Initialization98(initializer_list<int> text) {
			for (auto val : text) {
			cout << val << endl;
			}
		}

		Initialization98(int id) : id(id){
		}

		void print(initializer_list<string> anytext) {
			for (auto val : anytext) {
				cout << val << endl;
			}
		}

		void print() {
			cout << id << ": " << text << endl;
		}
	};

	class TestCPP11
	{
	public:
		TestCPP11();
		~TestCPP11();
	
		// allowing the return type with the arrow
		template<class T, class S>
		auto test(T value1 , S value2) -> decltype(value1, value2) {
			return value1 + value2;
		}

		int get() {
			return 999;
		}

		auto testGet() -> decltype(get()){
			return get();
		}


	private:

	};

	TestCPP11::TestCPP11()
	{
	}

	TestCPP11::~TestCPP11()
	{
	}

	class TestFunctors {
		virtual bool operator()(string& text) = 0;
		virtual ~TestFunctors() {}
	};

	// Functor Implimentation 
	/*
	struct MachTest : TestFunctors {
		virtual bool operator()(string& text) {
			return text == "lion";
		}
	};
	 void check(string text, TestFunctors& testFunctors) {
		if (testFunctors(text)) {
			cout << "No mach ." << endl;

		}
		else {
			cout << " mach." << endl;
		}
	}
	*/

	class Animal {
	public:
		virtual void run() = 0;
		virtual void speak() = 0;
		virtual void speak2() = 0;
	};

	class Dog : public Animal {
	public:
		virtual void speak() {
			cout << " Woof !" << endl;
		}

		virtual void run() {
			cout << "Dog is running " << endl;
		}
	};

	class Labrador : public Dog {
	public:
		virtual void run() {
			cout << "Labrador is running " << endl;
		}
	};

	class Labrador2 : public Labrador {
	public:
		Labrador2() {
			cout << "new Labrador2 " << endl;
		}
		virtual void speak2() {
			cout << "Labradord is running " << endl;
		}
		virtual void run() {
			cout << "Labrador2 is running " << endl;
		}
	};



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

