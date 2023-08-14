//
// Created by Lenovo on 2023/7/18.
//

#ifndef MYVECTOR_SHAREDPTR_MYVECTOR_H
#define MYVECTOR_SHAREDPTR_MYVECTOR_H

#include <iostream>

#define iterator T*
#define capacity size
#define Size unsigned int

template <typename T>
class myVector {
public:
    myVector()=default;
    ~myVector();
    myVector(const myVector& v);
    T&   operator[](int index) const;
    myVector&   operator=(const myVector<T>& v);
    bool operator==(const myVector& v) const;
    Size size();
    void push_back(const T& data);
    void pop_back();
    void insert(const T& data, int index);
    void erase(int index);
    int  find(const T& data);
    T    front() const;
    T    back() const;
    iterator begin();
    iterator end();
    bool empty();



private:
    T* space = nullptr;
    Size m_size;
};

template <typename T>
myVector<T>::~myVector()
{
    delete space;
}

template <typename T>
bool myVector<T>::operator==(const myVector<T>& v) const
{
    if (v.m_size != m_size)
        return false;
    for (int i; i < m_size;i++)
    {
        if(v.space[i] != space[i])
            return false;
    }
    return true;
}
template <typename T>
Size myVector<T>::size() {
    return m_size;
}
template <typename T>
void myVector<T>::push_back(const T& data) {
    T* newspace = new T[m_size+1];
    for(int i = 0; i < m_size; i++)
    {
        newspace[i]=space[i];
    }
    newspace[m_size] = data;
    m_size++;
    delete space;
    space = newspace;
}
template <typename T>
void myVector<T>::pop_back() {
    m_size--;
}
template <typename T>
void myVector<T>::insert(const T& data, int index) {
    if(index>m_size)
        std::terminate();
    T* newspace = new T[m_size+1];
    for(int i = 0;i < index;i++)
    {
        newspace[i] = space[i];
    }
    newspace[index] = data;
    for(int i = index + 1;i < m_size;i++)
    {
        newspace[i] = space[i-1];
    }
    delete space;
    space = newspace;
    m_size++;
}
template <typename T>
int myVector<T>::find(const T& data) {
    for(int i = 0;i < m_size;i++)
    {
        if(space[i]==data)
            return i;
    }
    return -1;
}

template <typename T>
void myVector<T>::erase(int index) {
    if(index>m_size-1)
        std::terminate();
    T* newspace = new T[m_size-1];
    for(int i = 0;i < index;i++)
    {
        newspace[i] = space[i];
    }
    for(int i = index;i < m_size-1;i++)
    {
        newspace[i] = space[i+1];
    }
    delete space;
    space = newspace;
    m_size--;
}

template <typename T>
T&   myVector<T>::operator[](int index) const
{
    return space[index];
}

template <typename T>
myVector<T>& myVector<T>::operator=(const myVector<T>& v)
{
    m_size = v.m_size;
    space = new T[m_size];
    for(int i = 0;i < m_size;i++)
    {
        space[i] = v.space[i];
    }
    return *this;
}

template <typename T>
myVector<T>::myVector(const myVector<T>& v)
{
    m_size = v.m_size;
    space = new T[m_size];
    for(int i = 0;i < m_size;i++)
    {
        space[i] = v.space[i];
    }
}

template <typename T>
T myVector<T>::front() const {
    return space[0];
}
template <typename T>
T myVector<T>::back() const {
    return space[m_size - 1];
}
template <typename T>
iterator myVector<T>::begin()
{
    return &space[0];
}
template <typename T>
iterator myVector<T>::end()
{
    return &space[m_size - 1];
}
template <typename T>
bool myVector<T>::empty()
{
    return !m_size;
}

#endif //MYVECTOR_SHAREDPTR_MYVECTOR_H
