//
// Created by Magnesium on 2022/11/29.
//

#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

namespace Mg{
    /***********************************
     * 类的声明
     * */
    template<class T>
    class Node {
    private:
        T m_value;
        Node* m_next;

    public:
        explicit Node(T val = nullptr, Node* next = nullptr);
        void setValue(T val);
        T getValue();

        void setNext(Node* next);
        Node* getNext();
    };

    /***********************************
     * 成员函数实现
     * */
    template<class T>
    Node<T>::Node(T value, Node<T> *next): m_value(value), m_next(next) {}

    template<class T>
    void Node<T>::setValue(T value) {
        m_value = value;
    }

    template<class T>
    T Node<T>::getValue() {
        return m_value;
    }

    template<class T>
    void Node<T>::setNext(Node<T> *next) {
        m_next = next;
    }

    template<class T>
    Node<T>* Node<T>::getNext() {
        return m_next;
    }
}

#endif //CODE_NODE_HPP
