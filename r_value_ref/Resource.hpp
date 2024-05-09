#pragma once
#include <iostream>

class Resource 
{
public:
    int* m_data = nullptr;
    unsigned m_length = 0;
    
    Resource()
    {
        std::cout << "Resource default constructed" << std::endl;
    }
    Resource(unsigned length)
    {
        std::cout << "Resource length constructed" << std::endl;
        m_length = length;
        m_data = new int[length];
    }
    Resource(const Resource &res) 
    {
        std::cout << "Resource copy constructed" << std::endl;
        Resource(res.m_length);
        for(int i=0;i<m_length;i++){
            m_data[i] = res.m_data[i]; //deep copy
        } 
    }
    ~Resource() 
    {
        std::cout << "Resource destroyed" << std::endl;
        if (m_data != nullptr){
            delete m_data;
        }
        m_length = 0;
    }
    Resource & operator = (Resource & res) {
        std::cout << "Resource copy assignment" << std::endl;
        if (&res == this ) {
            return *this;
        }    
        if (this->m_data != nullptr) {
            delete[] m_data;
        }
        this->m_length = res.m_length;
        this->m_data = new int[res.m_length];
        for(int i = 0; i< this->m_length; i++){
            this->m_data[i] = res.m_data[i];
        }
        return *this;
    }
    void setall(const int& val) {
        for(int i=0; i<m_length; i++){
            m_data[i] = val;
        }
    }
    void showall() {
        for(int i=0; i<m_length; i++) {
            std::cout << m_data[i] << ' ';
        }
        std::cout << std::endl;
    }
};
