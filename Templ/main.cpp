#include<iostream>

template <typename T>
class vector {
    T* data;
    int capacity; // 현재 data 배열에 할당된 총 크기 
    int length; //data 배열에서 다음으로 들어갈 데이터의 index

    public: 

        typedef T val_type;
        vector(int n=1) : data(new T[n]), capacity(1), length(0) {}

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

        void swap(int idx1, int idx2) {
            T temp;
            temp = data[idx2];
            data[idx2] = data[idx1];
            data[idx1] = temp;
        }
        int* showdata() {
            return data;
        }

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
template<typename M>
int partition(M& inarr, int lidx, int hidx){

    int swidx = lidx-1;
    for(int i=lidx; i<hidx; i++){
        if(inarr[i] < inarr[hidx]){
            swidx++;
            inarr.swap(swidx,i);
        }
        else {
            continue;
        }
    }
    swidx++;
    inarr.swap(swidx,hidx);
    return swidx;
}

template<typename M>
void quicksort(M& input_arr, int lidx, int hidx){
    if(lidx < 0 || hidx >= input_arr.size() || hidx <= lidx){
        return;
    }
    
    if(lidx >= input_arr.size()-1){
        return;
    }
    int sp = partition(input_arr, lidx, hidx);
    
    quicksort(input_arr, lidx, sp-1);
    quicksort(input_arr,sp+1, hidx);

}


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

    vector<int> arr2;
    arr2.push(10);
    arr2.push(20);
    arr2.push(80);
    arr2.push(90);
    arr2.push(30);
    arr2.push(40);
    arr2.push(40);
    arr2.push(85);
    arr2.push(50);
    //quicksort(arr2, 0, arr2.size() - 1);
    quicksort(arr2, 0, arr2.size()-1);
    for(int i=0;i<arr2.size();i++){
        std::cout << arr2[i] << std::endl;
    }

    return 0;
}