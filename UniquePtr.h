/**
 * @file    UniquePtr.h
 *
 * @brief   Defines Unique_ptr class
 */
#ifndef UNIQUEPTR_H
#define UNIQUEPTR_H
#include "Foo.h"
#include <iostream>
  using std::cout;
#include <iostream>
#include <utility>
#include <string>



template <class T>
class UniquePtr {

public:
    UniquePtr(T* ptr);
    // or
    // UniquePtr(T* ptr) : _ptr{ptr} {}
    ~UniquePtr();
    template <typename...Args>
    UniquePtr(Args&&...args);
    // or
    /*template <typename... Args>
     UniquePtr(Args&&... args) { _ptr = new T{ args... };}*/
    T& operator* () const { return *_ptr; }
    T* operator-> () const { return  _ptr; }

private:
    T* _ptr;
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator = (const UniquePtr&) = delete;
};


template <typename T>
UniquePtr<T>::UniquePtr(T* ptr) {
    _ptr = ptr;
    return;
}


template <typename T>
UniquePtr<T>::~UniquePtr() {
    delete _ptr;
    return;
}


template <typename T> template <typename...Args>
UniquePtr<T>::UniquePtr(Args&&...args) {
    _ptr = new T{ args... };
}


// Pointer(5)

template <typename T>
class UniquePtr<T[]> {
public:
    UniquePtr(T* ptr);              //or UniquePtr(T* ptr) : _ptr{ptr} {}
    ~UniquePtr();
    UniquePtr(int size);           // or UniquePtr(int size) {_ptr = new T[size];}
    // T* operator->() const {return  _ptr;}
    T& operator* () const { return *_ptr; }
    T& operator[](int i) const;    // or T& operator[](int i) const {return _ptr[i];}

private:
    T* _ptr;
    UniquePtr(const UniquePtr<T>&) = delete;
    UniquePtr& operator= (const UniquePtr<T>&) = delete;
};


template <typename T>
UniquePtr<T[]>::UniquePtr(T* ptr) {
    _ptr = ptr;
    return;
}


template <typename T>
UniquePtr<T[]>::~UniquePtr() {
    delete[] _ptr;
    return;
}


template <typename T>
UniquePtr<T[]>::UniquePtr(int size) {
    _ptr = new T[size];
}


template <typename T>
T& UniquePtr<T[]>::operator[](int i) const {
    return _ptr[i];
}


#endif
