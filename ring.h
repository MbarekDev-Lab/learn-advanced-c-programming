#pragma once
#ifndef RING_H
#define RING_H

#include<iostream>
using namespace std;
template<class T>
class ring {
public:
	class iterator;
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



