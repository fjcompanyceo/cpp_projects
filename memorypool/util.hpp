#include <iostream>

inline auto ASSERT(bool cond, const std::string& msg) noexcept {
    if(!cond){
        std::cerr << "ASSERT:" << msg << std::endl;
    }
    exit(EXIT_FAILURE);
}