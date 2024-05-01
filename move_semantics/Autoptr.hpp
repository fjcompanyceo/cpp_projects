#pragma once

#include <iostream>

template<class T>
class Autoptr{
    private:

    public:
        T *m_ptr = nullptr;
        Autoptr(T *ptr = nullptr) : m_ptr(ptr){

        }
        ~Autoptr() {
           if(m_ptr != nullptr){
            delete m_ptr;
           } 
        }
        Autoptr(Autoptr &a){
            m_ptr=a.m_ptr;
            a.m_ptr = nullptr; //소유권 이전 move semantics
        }

        Autoptr& operator = (Autoptr& a) {
            if (&a == this) {
                return *this;
            }

            delete m_ptr;
            m_ptr = a.m_ptr;
            a.m_ptr = nullptr; //소유권 이전 move semantics // semantics는 수행에 대한 의미(기능)
            // copy semantics
            // reference semantics //pointer 개념
            // move semantics
            return *this;
        }

        T& operator*() const { return *m_ptr;}
        T* operator->() const { 
            if (m_ptr == nullptr) {
                throw std::runtime_error("Null pointer dereference");
            }
            return m_ptr;
        }

        bool isNull() const { return m_ptr == nullptr;}


};


