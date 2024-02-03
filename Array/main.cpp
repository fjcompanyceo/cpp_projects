#include<iostream>

template <typename tp, int n>
class array {
    tp data[n];
    public:

    array(tp (&in_arr)[n]){
        //생성자
        for(int i=0;i<n;i++){
            data[i] = in_arr[i];
        }
    }

    tp* getarray() {
        return data;
    }

    unsigned int size() {
        return n;
    }

    void print_arr() {
        for(int i=0;i<n;i++){
            std::cout << data[i] << std::endl;
        }
    }

};

int main () {
    int arr[6] = {1,2,3,4,5,6};
    array<int,6> arr_6(arr);
    arr_6.print_arr();

    return 0;
}