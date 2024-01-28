#include<iostream>

template <typename T>
class vector {
    T* data;
    int capacity; // 현재 data 배열에 할당된 총 크기 
    int length; //data 배열에서 다음으로 들어갈 데이터의 index

    public: 

        typedef T val_type;
        vector(int n=1) : data(new T[n]), capacity(0), length(0) {}

        void push(T input){
            if (capacity <= length){
                T* temp = new T[capacity*2];
                for(int i=0;i<length;i++){
                    temp[i] = data[i];
                }
                data = temp;
                capacity *=2;
            }
            data[length] = input;
            length++;
            
            return;
        }
        void remove(int idx) {
            
            for(int i = idx+1; i < length; i++){
                data[i-1] = data[i];
            }
            length--;
            return;
        }
        int size() { return length;}

        T operator[] (int i) { return data[i];}

        ~vector() {
            if(data){
                delete[] data;
            }
        }

};

template <>
class vector<bool> {
    unsigned int* data;
    int length;
    int capacity;

    public :
        vector(int n=1) : data(new unsigned int[n]), capacity(0), length(0) {}
        void push(bool input){
            if(capacity*32 <= length){
                unsigned int* temp = new unsigned int[capacity+1];
                for(int i=0;i<capacity;i++){
                    temp[i] = data[i];
                }
                data = temp;
                capacity++;
            }
            if(input){
                data[length/32] |= (1 << length%32);
            }
            length++; 
            return;
        }
        void remove(int idx){
            for(int i = idx+1; i< length;i++){
                int cur = i;
                int pre = i-1;
                if (data[cur/32] & (1<<cur%32)){
                    data[pre/32] |= (1<<pre%32);
                }
                else {
                    data[pre/32] &= ~(1<<pre%32); 
                }
            }
            length--;
        }
        int size() { return length;}

        bool operator[] (int idx) { 
            return (data[idx/32] & (1<<idx%32)) != 0;
        }

        ~vector() {
            if(data){
                delete[] data;
            }
        }
        
};

int main() {
    vector<bool> arr;
    arr.push(1);
    arr.push(1);
    arr.push(1);
    arr.push(1);
    arr.push(1);
    arr.push(0);
    arr.push(1);
    arr.push(1);
    arr.push(1);
    arr.push(1);
    arr.push(1);
    arr.push(1);
    arr.push(1);
    arr.push(1);
    arr.push(0);
    for(int i=0;i<arr.size();i++){
        std::cout <<  arr[i];
    }
    std::cout << std::endl;
    std::cout << "print finished" << std::endl;
    return 0;
}