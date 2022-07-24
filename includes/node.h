

#ifndef ALGORITMOS_II_NODE_H
#define ALGORITMOS_II_NODE_H

template<typename T>
struct template_node {
    template_node<typeof(T)> *next;
    T value;
};

template<typename T>
struct doubly_node {
    template_node<typeof(T)> *next;
    template_node<typeof(T)> *last;
    T value;
};

template<typename T>
struct tree_node {
    tree_node<typeof(T)> *l_child;
    tree_node<typeof(T)> *r_child;
    unsigned short int height;
    short int balance_factor;
    unsigned short int q;
    T key;
};
template<class T>
using tNode = tree_node<typeof(T)> *;

#endif //ALGORITMOS_II_NODE_H
