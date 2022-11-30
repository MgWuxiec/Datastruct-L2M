//
// Created by Magnesium on 2022/11/29.
//

#ifndef CODE_LINKEDLIST_HPP
#define CODE_LINKEDLIST_HPP

#include "Node.hpp"
#include <iostream>

namespace Mg{
    /***********************************
    * �������
    * - mptr: ��ָ��Ҫ��֤�ǵ�һ����δ�����ڵ�
    * - rear: ��ָ��Ҫ��֤����������һ��Ԫ��
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
     * ��Ա����ʵ��
     ***********************************/
    LinkedList::LinkedList(int max): max(max) {
        array = new Node[max+1];
    }

    LinkedList::~LinkedList() {
        delete array;
    }

    /* ��β�巨�У����ν�����������ָ��ı仯
     * 1��next
     * 2��rear
     * 3��mptr
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
            std::cout << "LinkedList::emplace_back(int): �����ڽڵ�����ﵽ���" << std::endl;
        }
    }

    /* ��ͷ�巨�У����ν�����������ָ��ı仯
     * 1���½ڵ��next
     * 2����ڵ��next
     * 3��mptr
     * */
    void LinkedList::emplace_front(int value) {
        if (counter<max){
            // step 1: �½ڵ��next
            array[mptr].value = value;
            array[mptr].next = array[0].next;
            counter++;

            // step 2: ��ڵ��next
            array[0].next = mptr;

            // step 3: mptr
            while(mptr<=max && array[++mptr].next!=-1);
        }else{
            std::cout << "LinkedList::emplace_front(int): �����ڽڵ�����ﵽ���" << std::endl;
        }
    }

    int LinkedList::get(int index) {
        int ptr = array->next;

        while(array[index].next!=-1 && index--) ptr=array[ptr].next;

        if (index==-1){
            return array[ptr].value;
        }else{
            std::cout << "LinkedList::get(int): ��������Խ�磡" << std::endl;
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

    /* ����Ԫ��Ҫ���������ĸ�ָ����ƶ���
     * 1���½ڵ��next
     * 2��Ŀ��λ��ǰ���ڵ��next
     * 3������ǲ��뵽�����ĩβ����Ҫ�ƶ�rear
     * 4��mptr
     * */
    void LinkedList::insert(int value, int index) {
        if (counter<max){
            int ptr = 0;
            while(array[ptr].next!=-1 && index--) ptr = array[ptr].next;

            // step 1: �½ڵ��next
            array[mptr].next = array[ptr].next;
            array[mptr].value = value;
            counter++;

            // step 2: Ŀ��λ��ǰ���ڵ��next
            array[ptr].next = mptr;

            // step 3: rear
            if (mptr!=rear){
                rear = mptr;
            }

            // step 4: mptr
            while(mptr<=max && array[++mptr].next!=-1);


        }else{
            std::cout << "LinkedList::insert(int,int): �����ڽڵ�����ﵽ���" << std::endl;
        }
    }

    void LinkedList::remove(int index) {

    }
}

#endif //CODE_LINKEDLIST_HPP
