#include<vector>
#include"util.hpp"

namespace Common {
    template<typename T>
    class MemPool final {
    public: 
        explicit MemPool(int size) 
            : vec_store(size, ObjectBlock(T(), true)){
                mem_size = size;
            }

        template<typename... Args>
        T* PoolAlloc(Args... args) noexcept {
            auto pObjectBlock = &vec_store[next_free_idx];
            T* res = &(pObjectBlock->object);
            printf("address : %p idx : %d \n", res, next_free_idx);
            res = new(res) T(args...);  
            pObjectBlock->freeyn = false;
            update_next_idx();
            return res;
        }

        auto PoolDealloc(const T *elem) noexcept {
            int index = 0;
            for (auto& cur_obj : vec_store ){
                if(!memcmp(cur_obj.object.data, elem->data, strlen(elem->data))) {
                    memset(cur_obj.object.data, 0x00, sizeof(cur_obj.object.data));
                    cur_obj.freeyn = true;
                    printf("Dealloc : %p\n", &cur_obj.object);
                    next_free_idx = index;
                    break;
                }
                index++ ;
            }
        }
    
    private:
        struct ObjectBlock {
            T object;
            bool freeyn;
            ObjectBlock(T obj, bool free) : object(obj), freeyn(free)  {}
        };
        std::vector<ObjectBlock> vec_store;
        int mem_size = 0;

        int next_free_idx = 0;
        auto update_next_idx () {
            auto cur_idx = next_free_idx;
            while(!vec_store[next_free_idx].freeyn){
                next_free_idx++;
                if (next_free_idx == vec_store.size()){
                    next_free_idx = 0; // index 끝까지 갔으면 다시 0 셋팅 
                }
                if (cur_idx == next_free_idx) {
                    ASSERT(cur_idx!= next_free_idx, "Memory Pool Out of Space"); //한바퀴 다 돌았느데도 빈 곳이 없는 경우 
                }
            }
        }
    };
}