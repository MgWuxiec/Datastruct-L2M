//
// Created by Magnesium on 2022/11/29.
//

#ifndef CODE_NODE_HPP
#define CODE_NODE_HPP

namespace Mg{
    /***********************************
     * 类的声明
     * */
    class Node {
    public:
        int value;
        int next;

    public:
        explicit Node(int val = 1<<31, int next = -1);
    };


    /***********************************
     * 成员函数实现
     * */
    Node::Node(int val, int next): value(val), next(next){

    }

}

#endif //CODE_NODE_HPP
