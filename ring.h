#pragma once
#ifndef RING_H
#define RING_H

#include <iostream>
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
        delete[] m_values;
    }

    int size() {
        return m_size;
    }

    iterator begin() {
        return iterator(0, *this);
    }

    iterator end() {
        return iterator(m_size, *this);
    }

    void add(T value) {
        m_values[m_pos++] = value;
        if (m_pos == m_size) {
            m_pos = 0;
        }
    }

    T& get(int pos) {
        return m_values[pos];
    }

    class iterator {
    private:
        int m_pos;
        ring& m_ring;

    public:
        iterator(int pos, ring& aring) : m_pos(pos), m_ring(aring) {}

        iterator& operator++() {
            m_pos++;
            return *this;
        }

        T& operator*() {
            return m_ring.get(m_pos);
        }

        bool operator!=(const iterator& other) const {
            return m_pos != other.m_pos;
        }
    };
};

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

#endif // RING_H
