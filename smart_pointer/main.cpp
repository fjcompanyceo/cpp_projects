#include<iostream>
#include<memory>

class A {
    int * data;
    
    public : 
    A() {
        std::cout << "자원을 획득함" << std::endl;
        data = new int[100];
    }
    ~A() {
        std::cout << "자원을 해제함" << std::endl;
        delete[] data;
    }

    void some() {
        std::cout << "일반포인터와 동일하게 사용가능" << std::endl;
    }
    void anot() {
        std::cout << "ptr로 받아서 출력" << std::endl;
    }

};

void do_something() {
    std::unique_ptr<A> pa(new A());
    pa->some();    
    A* temp = new(A);
    //pb에 소유권 이전
    std::unique_ptr<A> pb = std::move(pa);
    std::cout << "pb: ";
    pb->some();

    std::cout << "pa: ";
    pa->some();
    std::cout << "pa:" << pa << " " << "pb:" << pb << std::endl;
    delete temp;
}

void do_with_ptr(A * in_ptr) {
    in_ptr->anot();
    return;
}

int main () {
    do_something();
    std::unique_ptr<A> pn(new A());
    //unique_ptr 사용할 때 .get() 으로 주소값을 넘겨야 한다. 
    do_with_ptr(pn.get());
    return 0;
}

