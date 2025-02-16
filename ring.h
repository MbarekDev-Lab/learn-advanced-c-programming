#pragma once
#ifndef RING_H
#define RING_H

#include<iostream>
using namespace std;
template<class T>
class ring {

private:
    int m_pos;
    int m_size;
	T* m_values;

public:
	class iterator;
public:
    ring(int size) : m_pos(0), m_size(size), m_values(NULL) {
        m_values = new T[size];
    }
    ~ring() {
        delete[]m_values;//size = 0x00007ff7b31e8ba0 {learn-advanced-c-programming.exe!ring<std::string>::size(void)}
    }

    int size() {
        return m_size;
    }

    void add(T value) {
        //if [m_pos++] must be post increament :
        m_values[m_pos++] = value;
        /*// or
         m_values[m_pos] = value;
            m_pos++;
		*/
        if (m_pos == m_size) {
            m_pos = 0;
        }
    }

    T& get(int pos) {
        return m_values[pos];
    }




};

template<class T>
class ring<T>::iterator {
	public:
		void print();
};

template<class T>
void ring<T>::iterator::print() {
	cout << "Hello Mbarek from iterator ring<int> ->: "<< T() << endl;
}

template<class T>
class ring2 {
public:
    class iterator2;
    ring2(int size) : m_size(size), m_values(size), m_pos(0) {}
    void add(T value) {
        m_values[m_pos++] = value;
        if (m_pos == m_size) {
            m_pos = 0;
        }
    }
    T get(int pos) const {
        return m_values[pos];
    }

    int size() const {
        return m_size;
    }
private:
    int m_size;
    vector<T> m_values;
    int m_pos;
};

template<class T>
class ring2<T>::iterator2 {
public:
    void print();
};

template<class T>
void ring2<T>::iterator2::print() {
    cout << "Hello Mbarek from iterator2" << endl;
}

#endif //'!RING_H'



