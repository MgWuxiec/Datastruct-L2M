#include <iostream>
#include <vector>
#include "src/Node.hpp"

int main() {
    Mg::Node<int> node(1);
    std::cout << node.getValue() << std::endl;
    return 0;
}
