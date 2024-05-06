#include <iostream>

template<class T>
class Autoptr {

private:
    T* m_ptr;

public:
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
    // Autoptr(Autoptr&& a) : m_ptr(a.m_ptr) {
    //     a.m_ptr = nullptr; 
    //     std::cout << "Autoptr move constructor" << std::endl;
    // }

    // Autoptr& operator = (Autoptr&& a) {
    //     std::cout << "Autoptr move assignment" << std::endl;
    //     if (&a == this) {
    //         return *this;
    //     }
    //     if (!m_ptr) delete m_ptr;
    //     a.m_ptr = nullptr;
    //     return *this;
    // }

};