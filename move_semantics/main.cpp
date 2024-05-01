#include "Resource.hpp"
#include "Autoptr.hpp"


void doSomething() {
    //Resource *res = new Resource;
    //Resource *res(new Resource);
    Autoptr<Resource> res1(new Resource);
    std::cout << "show address res1 :" << res1.m_ptr << std::endl;
    Autoptr<Resource> res2;
    std::cout << "show address res2 :" << res2.m_ptr << std::endl;

    /* move semantics */
    res2 = res1;

    std::cout << "show address res1 :" << res1.m_ptr << std::endl;
    
    std::cout << "show address res2 :" << res2.m_ptr << std::endl;


    return;
}

int main() {
    doSomething();
    
    return 0;
}

