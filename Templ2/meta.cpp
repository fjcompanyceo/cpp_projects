#include<iostream>
template <int N>
class Factorial {
    public:
        static const int result = N * Factorial<N-1>::result;//변수 연산이 compile time에 이뤄진다. 
        static int show_res() {
            return result;
        }
};

template <>
class Factorial<1> {
    public:
        static const int result = 1;
        static int show_res() {
            return result;
        }
};

int main () {

    std::cout << Factorial<6>::show_res() << std::endl;
    std::cout << Factorial<5>::show_res() << std::endl;
    std::cout << Factorial<4>::show_res() << std::endl;
    std::cout << Factorial<3>::show_res() << std::endl;
    std::cout << Factorial<2>::show_res() << std::endl;
    std::cout << Factorial<1>::show_res() << std::endl;

    return 0;

}