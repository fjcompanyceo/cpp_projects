#include <cstring>
#include <iostream>
#include "mempool_20241229.hpp"

class TrCode {
private:
    //char data[1024] = {0,};
public: 
    char data[1024] = {0,};
    TrCode () {
        memset(data, 0x00, sizeof(data));
    }
    TrCode (const char* input){
        memcpy(data, input, strlen(input)+1);
    }
    auto printdata() {
        //std::cout << "DATA :" << data << std::endl;
        printf("DATA: %s\n", data);
    }
};


int main () {
    Common::MemPool<TrCode> MemTrCode(50);
    TrCode* temp1 = MemTrCode.PoolAlloc("ask101");
    temp1->printdata();
    TrCode* temp2 = MemTrCode.PoolAlloc("ask102");
    temp2->printdata();
    TrCode* temp3 = MemTrCode.PoolAlloc("ask103");
    temp3->printdata();
    TrCode* temp4 = MemTrCode.PoolAlloc("ask104");
    temp4->printdata();
    printf("stack: %p\n", &MemTrCode);
    printf("heap: %p\n", temp1);
    printf("heap: %p\n", temp2);
    printf("heap: %p\n", temp3);
    printf("heap: %p\n", temp4);
    MemTrCode.PoolDealloc(temp1);
    TrCode* temp5 = MemTrCode.PoolAlloc("ask105");
    temp5->printdata();

    return 0;
}
