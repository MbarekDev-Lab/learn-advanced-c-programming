#pragma once

#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception {
public:
    // Default constructor
    MyException() : msg_("Default exception message") {}

    // Constructor
    MyException(const char* message) : msg_(message) {}

    // Override the what() method from std::exception
    virtual const char* what() const noexcept override {
        return msg_;
    }

    void goesWrong()throw (){
        throw MyException("Something went wrong!");
    }

private:
    const char* msg_;
};
