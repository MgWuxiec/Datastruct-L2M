//
// Created by Magnesium on 2022/11/29.
//

#ifndef CODE_LINKEDLIST_HPP
#define CODE_LINKEDLIST_HPP

#include "Node.hpp"

namespace Mg{
    template<class T>
    class LinkedList{
    private:
        Node<T> root;
        int counter{};
    public:
        LinkedList();

    };

    template<class T>
    LinkedList<T>::LinkedList():root(nullptr, nullptr), counter(0) {}


}

#endif //CODE_LINKEDLIST_HPP
