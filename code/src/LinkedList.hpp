//
// Created by Magnesium on 2022/11/29.
//

#ifndef CODE_LINKEDLIST_HPP
#define CODE_LINKEDLIST_HPP

#include "Node.hpp"
#include <iostream>

namespace Mg{
    /***********************************
    * 类的声明
    * - mptr: 该指针要保证是第一个人未开发节点
    * - rear: 该指针要保证是链表的最后一个元素
    ***********************************/
    class LinkedList{
    private:
        Node* array;
        int max{};

        int rear{0};
        int mptr{1};
        int counter{0};
    public:
        explicit LinkedList(int max=16);
        ~LinkedList();

        void emplace_back(int value);
        void emplace_front(int value);
        void insert(int value, int index);

        void remove(int index);

        int get(int index);
        int size() const;

        void debug();
        void debugList();
    };


    /***********************************
     * 成员函数实现
     ***********************************/
    LinkedList::LinkedList(int max): max(max) {
        array = new Node[max+1];
    }

    LinkedList::~LinkedList() {
        delete array;
    }

    /* 在尾插法中，依次进行下面三个指针的变化
     * 1、next
     * 2、rear
     * 3、mptr
     * */
    void LinkedList::emplace_back(int value) {
        if (counter<max){
            // step 1: next
            array[rear].next = mptr;
            array[mptr].value = value;
            counter++;

            // step 2: rear
            rear = mptr;

            // step 3: mptr
            while(mptr<=max && array[++mptr].next!=-1);
        }else{
            std::cout << "LinkedList::emplace_back(int): 链表内节点个数达到最大！" << std::endl;
        }
    }

    /* 在头插法中，依次进行下面三个指针的变化
     * 1、新节点的next
     * 2、虚节点的next
     * 3、mptr
     * */
    void LinkedList::emplace_front(int value) {
        if (counter<max){
            // step 1: 新节点的next
            array[mptr].value = value;
            array[mptr].next = array[0].next;
            counter++;

            // step 2: 虚节点的next
            array[0].next = mptr;

            // step 3: mptr
            while(mptr<=max && array[++mptr].next!=-1);
        }else{
            std::cout << "LinkedList::emplace_front(int): 链表内节点个数达到最大！" << std::endl;
        }
    }

    int LinkedList::get(int index) {
        int ptr = array->next;

        while(array[index].next!=-1 && index--) ptr=array[ptr].next;

        if (index==-1){
            return array[ptr].value;
        }else{
            std::cout << "LinkedList::get(int): 链表索引越界！" << std::endl;
            return 1<<31;
        }
    }

    int LinkedList::size() const {
        return counter;
    }

    void LinkedList::debug() {
        int ptr = array[0].next;
        while(ptr != -1){
            std::cout << array[ptr].value << ' ' << std::endl;
            ptr = array[ptr].next;
        }
    }

    void LinkedList::debugList() {
        std::cout << "value\tnext" << std::endl;
        for (int i=0; i<=max; i++){
            std::cout << array[i].value << "\t" << array[i].next << std::endl;
        }
    }

    /* 插入元素要考虑下面四个指针的移动：
     * 1、新节点的next
     * 2、目标位置前驱节点的next
     * 3、如果是插入到链表的末尾，则还要移动rear
     * 4、mptr
     * */
    void LinkedList::insert(int value, int index) {
        if (counter<max){
            int ptr = 0;
            while(array[ptr].next!=-1 && index--) ptr = array[ptr].next;

            // step 1: 新节点的next
            array[mptr].next = array[ptr].next;
            array[mptr].value = value;
            counter++;

            // step 2: 目标位置前驱节点的next
            array[ptr].next = mptr;

            // step 3: rear
            if (mptr!=rear){
                rear = mptr;
            }

            // step 4: mptr
            while(mptr<=max && array[++mptr].next!=-1);


        }else{
            std::cout << "LinkedList::insert(int,int): 链表内节点个数达到最大！" << std::endl;
        }
    }

    void LinkedList::remove(int index) {

    }
}

#endif //CODE_LINKEDLIST_HPP
