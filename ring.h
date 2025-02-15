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
	cout << "Hello sss from iterator ring<int> ->: "<< T() << endl;
}

#endif //'!RING_H'


#pragma once
#ifndef RING_H
#define RING_H

#include <iostream>
#include <vector>
using namespace std;

template<class T>
class ring {
public:
    class iterator;

    ring(int size) : m_size(size), m_values(size), m_pos(0) {}

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
class ring<T>::iterator {
public:
    void print();
};

template<class T>
void ring<T>::iterator::print() {
    cout << "Hello from iterator" << endl;
}

#endif // RING_H
