#pragma once
#include <iostream>
class Resource {
    private:
        int m_data[100];
    
    public:
        Resource() {
            std::cout << "Resource Constructor" << std::endl;
            memset(m_data, 0, sizeof(m_data)); 

        }
        
        ~Resource() {
            std::cout << "Resource Destructor" << std::endl;
        }
        /*
        void setData(int val) {
            for (int num : m_data) {
                num = val;    
            }
            return;   
        }
        void showData() {
            for (int dat : m_data){
                std::cout << dat;
            }
            std::cout << std::endl;
        }
        */


};
