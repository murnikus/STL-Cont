#include "List.hpp"

int main() {
    atlas::List<int> list{1,2,3};
    std::cout << std::boolalpha;
    std::cout << list.empty() << std::endl;
}