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

template <int N>
class INT {
public:
    static const int num = N;
};

template <>
class INT<1> {
public:
    static const int num = 1;
};

template <>
class INT<2> {
public:
    static const int num = 2;
};

template <>
class INT<3> {
public:
    static const int num = 3;
};

template <typename in1, typename in2> 
class add {
public:
    typedef INT<in1::num + in2::num> result;
};

template <typename in1, typename in2>
class divide {
public:
    typedef INT<in1::num / in2::num> result;
};

template <typename N, typename d>
class check_divide {
public:
    static const bool result = (N::num % d::num == 0) || check_divide<N, typename add<d,INT<1>>::result>::result;
};

template <typename N>
class check_divide<N, typename divide<N,INT<2>>::result> {
public:
    static const bool result = (N::num % (N::num/2) == 0);
};

template <typename N>
class _is_prime {
public:
    static const bool result = check_divide<N,INT<2>>::result; 
};

template <>
class _is_prime<INT<2>> {
public:
    static const bool result = 1; 
};

template <>
class _is_prime<INT<3>> {
public:
    static const bool result = 1; 
};

template <int N>
class is_prime {
public:
    static const bool result = _is_prime<INT<N>>::result;
};


int main () {

    std::cout << Factorial<6>::show_res() << std::endl;
    std::cout << Factorial<5>::show_res() << std::endl;
    std::cout << Factorial<4>::show_res() << std::endl;
    std::cout << Factorial<3>::show_res() << std::endl;
    std::cout << Factorial<2>::show_res() << std::endl;
    std::cout << Factorial<1>::show_res() << std::endl;
    std::cout << std::endl;

    std::cout << is_prime<32>::result << std::endl;
    std::cout << is_prime<5>::result << std::endl;

    return 0;

}