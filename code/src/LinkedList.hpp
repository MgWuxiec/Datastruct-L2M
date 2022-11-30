//
// Created by Magnesium on 2022/11/29.
//

#ifndef CODE_LINKEDLIST_HPP
#define CODE_LINKEDLIST_HPP

#include "Node.hpp"
#include <iostream>

namespace Mg{
    template<class T>
    class LinkedList{
    private:
        Node<T> front;
        Node<T> rear;
        int counter{0};

    public:
        LinkedList();
        ~LinkedList();
        void emplace_back(T value);
        T get(int index);
    };

    template<class T>
    LinkedList<T>::LinkedList():front(nullptr, nullptr), counter(0) {}

    template<class T>
    LinkedList<T>::~LinkedList() {
        while(front.getNext()!=nullptr){
            Node<T>*temp = front.getNext();
            front.setNext(temp->getNext());
            delete temp;
        }
    }

    template<class T>
    void LinkedList<T>::emplace_back(T value) {
        rear.getNext()->setNext(new Node<T>(value));
        rear.setNext(rear.getNext()->getNext());
        counter++;
    }

    template<class T>
    T LinkedList<T>::get(int index) {
        Node<T>*ptr = front.getNext();
        while(ptr!=nullptr && index--)ptr = ptr->getNext();
        return ptr->getValue();
    }
}

#endif //CODE_LINKEDLIST_HPP
