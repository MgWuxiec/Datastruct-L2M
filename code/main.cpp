#include <iostream>
#include <vector>
#include "src/Node.hpp"
#include "src/LinkedList.hpp"
using namespace std;

int main() {
    Mg::LinkedList list(2);
//    list.emplace_back(2021);
//    list.emplace_back(1999);
//    list.insert(1024, 2);
    list.insert(1025, 0);
    list.emplace_back(2020);
    list.debug();
    list.debugList();
    return 0;
}
