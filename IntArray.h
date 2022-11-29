#pragma once
#include <exception>
using namespace std;
#ifndef INTARRAY_H
#define INTARRAY_H

class IntArray {
private:
    int m_length;
    int* m_data;

public:
    IntArray(int length);
    ~IntArray();

    void erase();
    int& operator[](const int& index);
    void reallocate(int newLength);
    void resize(int newLength);
    void insertBefore(int value, int index);
    void remove(int index);
    void insertAtBegin(int value);
    void insertAtEnd(int value);
    void search(int value);
    int getLength() const;
    void printArray();
};

class bad_range : public exception {
public:
    virtual const char* what() const noexcept override {
        return "ERROR: Выход за пределы массива!";
    }
};

class bad_length : public exception {
public:
    virtual const char* what() const noexcept override {
        return "ERROR: Неверная длинна массива!";
    }
};
#endif

