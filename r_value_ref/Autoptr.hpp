#include <iostream>

template<class T>
class Autoptr {

private:

public:

    T* m_ptr;
    Autoptr(T* ptr = nullptr) : m_ptr(ptr){
        std::cout << "Autoptr default constructor" << std::endl;
    }
    ~Autoptr() {
        std::cout << "Autoptr destructor" << std::endl;
        delete m_ptr;
    }
    Autoptr(const Autoptr& a) {
        std::cout << "Autoptr copy constructor" << std::endl;
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }
    
    Autoptr& operator = (const Autoptr& a) {
        std::cout << "Autoptr copy assignment" << std::endl;
        m_ptr = new T; 
        *m_ptr = *a.m_ptr;
        return *this;
    } 
    Autoptr(Autoptr&& a) : m_ptr(a.m_ptr) {
        a.m_ptr = nullptr; 
        std::cout << "Autoptr move constructor" << std::endl;
    }
    Autoptr& operator = (Autoptr&& a) {
        std::cout << "Autoptr move assignment" << std::endl;
        if (&a == this) {
            return *this;
        }
        if (m_ptr != nullptr) delete m_ptr;
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;
        return *this;
    }
    T* operator ->() {
        return m_ptr;
    }
    //Autoptr(const Autoptr& a) = delete;
    //Autoptr& operator=(const AutoPtr& a) = delete;
};