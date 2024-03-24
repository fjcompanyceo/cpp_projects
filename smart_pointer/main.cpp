#include<iostream>
#include<memory>
#include<vector>

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
    void set_value(int in1) {
        for(int i=0;i<=99;i++){
            data[i] = in1;
        }
    }
    void show_value() {
        for(int i=0;i<=99;i++){
            std::cout << data[i];
        }
        std::cout << std::endl;
    }
    

};

class Foo {
    int a, b;

    public:
    Foo(int in1, int in2) : a(in1), b(in2) { std::cout << "Foo 클래스 생성자 호출" << std::endl;}
    ~Foo() { std::cout << "소멸자 호출!" << std::endl;}

    void print_val() {
        std::cout << "a: " << a <<", b: " << b << std::endl;
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

    auto Foo_ptr = std::make_unique<Foo> (3,5);
    Foo_ptr->print_val();

    std::vector<std::unique_ptr<A>> vec;
    vec.emplace_back(new A());
    vec.emplace_back(new A());
    vec.emplace_back(new A());
    vec[0]->set_value(0);
    vec[1]->set_value(1);
    vec[2]->set_value(2);
    vec[0]->show_value();
    vec[1]->show_value();
    vec[2]->show_value();
    //unique_ptr 로 이루어진 vector에 새로운 unique_ptr을 add 할 때 push back을 사용하고 싶다면?
    std::unique_ptr<A> addA(new A());
    vec.push_back(std::move(addA)); 
    vec[3]->set_value(3);
    vec[3]->show_value();

    return 0;
}

