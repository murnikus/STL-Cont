#include "List.hpp"

int main() {
    atlas::List<int> list{1,2};
    auto it = list.before_begin();
    ++it;
    std::cout << *it << std::endl;
}