//move semantics 항상 사용할  수 없고, 사용할지 말지를 판단
// int x= 5 -> x is l-value which has address, 5 is r-value which will disappear when current sentence is executed
//r-value : 메모리에 지속적으로 저장되지 않는애 (잠깐 있다가 사라질 애) r-value는 다른 곳에 쓰일 일이 없으니 move semantics해도 상관x
//&& r-value refence가 있는 이유: 가만히 있으면 사라질 애들을 저장하기 위함 //다른 곳에서 재사용될 가능성 있는 애들은 r-value에 저장하지 않는다. 
// 나만 접근하고 사용하려는 변수를 r-value reference 로 둔다. 
#include "Autoptr.hpp"
#include "Resource.hpp"
#include "chrono"

Autoptr<Resource> generateResource(){ 
    Autoptr<Resource> res(new Resource(10000000));
    return res;
}



int main () {
    auto start = std::chrono::high_resolution_clock::now();

    Autoptr<Resource> main_res;
    main_res = generateResource();

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = end - start;
    std::cout << "Function took " << duration.count() << " seconds." << std::endl;
}
