//
// Created by alex1 on 08/07/2022.
//

#include "iostream"
#include "string"
#include "node.h"
#include "utilities.h"

#ifndef ALGORITMOS_II_DATA_STRUCTURES_H
#define ALGORITMOS_II_DATA_STRUCTURES_H

template<typename T>
class LinkedList {
private:
    int c_items;
    template_node<typeof(T)> *head;
    template_node<typeof(T)> *end;
    template_node<typeof(T)> *temp;
public:
    LinkedList() {
        c_items = 0;
    }

    int get_c_items() {
        return c_items;
    }

    void push(T new_value) {

        temp = new template_node<typeof(T)>;
        temp->value = new_value;

        if(c_items == 0) {
            head = temp;
            head->next = nullptr;
            end = head;
        }
        else {
            end->next = temp;
            end = temp;
            end->next = nullptr;
        }

        temp = nullptr;
        c_items++;
    }

    T pop() {
        template_node<typeof(T)> *aux_temp;
        T return_value;

        if(c_items == 0)
            return 0;
        else {
            temp = head;
            aux_temp = head;
            return_value = end->value;
            while (temp->next != nullptr) {
                aux_temp = temp;
                temp = temp->next;
            }
            end = aux_temp;
            end->next = nullptr;
            delete[] temp;
            c_items--;

            return return_value;
        }
    }

    ~LinkedList() {
        template_node<typeof(T)> *aux_temp;

        if(c_items != 0) {
            temp = head;
            while (temp->next != nullptr) {
                aux_temp = temp;
                temp = temp->next;
                delete[] aux_temp;
            }
        }
    }
};


template<typename T>
class DoubleStack {
private:
    doubly_node<typeof(T)> *head;
    doubly_node<typeof(T)> *temp;
    int c_items;
public:
    DoubleStack() {
        c_items = 0;
    }

    int get_c_items() {
        return c_items;
    }

    void push(T value) {

        temp = new doubly_node<typeof(T)>;
        temp->value = value;

        if(c_items == 0) {
            temp->next = temp;
            temp->last = temp;
            head = temp;
        } else if(c_items == 1) {
            temp->next = head;
            temp->last = head;
            head->last = temp;
            head->next = temp;
        } else {
            temp->next = head;
            temp->last = head->last;
            head->last->next = temp;
            head->last = temp;
        }

        c_items++;
        temp = nullptr;
    }

    T pop() {

        T r_value;

        if(c_items == 0)
            return 0;
        else {
            r_value = head->last->value;
            temp = head->last;
            head->last->last->next = head;
            head->last = head->last->last;
            delete[] temp;
        }

        c_items--;
        temp = nullptr;

        return r_value;
    }

    ~DoubleStack() {

        doubly_node<typeof(T)> *aux_temp;
        temp = head->last;

        if(c_items != 0) {
            while(temp != head) {
                aux_temp = temp;
                temp = temp->last;
                delete[] aux_temp;
                aux_temp = nullptr;
            }
            delete[] head;
        }
    }
};


template<typename T>
class BinaryTree {
private:

    virtual tNode<typeof(T)> parentNode(tNode<typeof(T)> node, tNode<typeof(T)> parent, T key) {

        temp = nullptr;

        if(node) {
            if(node->key == key)
                return parent;
            else {
                if(node->l_child) {
                    temp = parentNode(node->l_child, node, key);
                    if(temp)
                        return temp;
                }
                if(node->r_child) {
                    temp = parentNode(node->r_child, node, key);
                    if(temp)
                        return temp;
                }
                return temp;
            }
        } else {
            return nullptr;
        }
    }

    void pushNode(tNode<typeof(T)> node, std::string path, T key) {
        tNode<typeof(T)> aux_temp;
        temp = root;

        if(n_items == 0) {
            root = initNode(key);
        } else {
            for(int it = path.size() - 1; it > 0; it--) {
                if(path[it] == '0') {
                    if(!temp->l_child)
                        temp->l_child = initNode(key);
                    else
                        temp = temp->l_child;
                } else {
                    if(!temp->r_child)
                        temp->r_child = initNode(key);
                    else
                        temp = temp->r_child;
                }
            }
        }
    }

    void pushNodeSearch(tNode<typeof(T)> node, T key) {
        if(n_items == 0) {
            root = initNode(key);
            root->height = nodeHeight(key);
        } else {
            if(key < node->key) {
                if(node->l_child) {
                    pushNodeSearch(node->l_child, key);
                    node->l_child->height = nodeHeight(key);
                }
                else
                    node->l_child = initNode(key);

            } else if(key >= node->key) {
                if(node->r_child)
                    pushNodeSearch(node->r_child, key);
                else {
                    node->r_child = initNode(key);
                    node->r_child->height = nodeHeight(key);
                }
            }
        }

    }

    virtual T minNode(tNode<typeof(T)> node) {
        T minl = -1, minr = -1;
        if(node) {
            if(!node->l_child && !node->r_child)
                return node->key;
            if(node->l_child)
                minl = minNode(node->l_child);
            if(node->r_child)
                minr = minNode(node->r_child);
            if(minl < minr) {
                return minl;
            } else if(minr < node->key) {
                return minr;
            } else {
                return node->key;
            }

        } else
            return -1;
    }

    virtual T maxNode(tNode<typeof(T)> node) {
        T maxl = -1, maxr = -1;
        if(node) {
            if(!node->l_child && !node->r_child)
                return node->key;
            if(node->l_child)
                maxl = maxNode(node->l_child);
            if(node->r_child)
                maxr = maxNode(node->r_child);
            if(maxl < maxr) {
                return maxr;
            } else if(maxl > node->key) {
                return maxl;
            } else {
                return node->key;
            }
        } else
            return -1;
    }

    bool isBinaryNode(tNode<typeof(T)> node) {
        bool l_child = true, r_child = true;
        if(node) {
            if(!node->l_child && !node->r_child)
                return true;
            if(node->l_child) {
                if(node->l_child->key > node->key)
                    return false;
                l_child = isBinaryNode(node->l_child) && node->l_child->key < node->key;
            }
            if(node->r_child) {
                if(node->r_child->key < node->key)
                    return false;
                r_child = isBinaryNode(node->r_child) && node->r_child->key > node->key;
            }
            return l_child && r_child;
        } else {
            return false;
        }
    }

protected:
    tNode<typeof(T)> root;
    tNode<typeof(T)> temp;
    int n_items;

    unsigned short int findNodeHeight(tNode<typeof(T)> node, int key, unsigned short int height = 0) {
        if(node) {
            if(node->key == key)
                return height;
            if(node->key > key)
                return findNodeHeight(node->l_child, key, height + 1);
            else
                return findNodeHeight(node->r_child, key, height + 1);
        } else {
            return 0;
        }
    }

    bool equalValueNode(tNode<typeof(T)> node_t1, tNode<typeof(T)> node_t2) {
        bool l_child = true, r_child = true;
        if(node_t1 && node_t2) {
            // One of both of the nodes don't have a child the other one has
            if((node_t1->l_child && !node_t2->l_child) || (!node_t1->l_child && node_t2->l_child)
               || (node_t1->r_child && !node_t2->r_child) || (!node_t1->r_child && node_t2->r_child))
                return false;
            if(node_t1->l_child && node_t2->l_child) {
                if(node_t1->l_child->key == node_t2->l_child->key)
                    l_child = equalValueNode(node_t1->l_child, node_t2->l_child);
                else
                    return false;
            }
            if(node_t1->r_child && node_t2->r_child) {
                if(node_t1->r_child->key == node_t2->r_child->key)
                    r_child = equalValueNode(node_t1->r_child, node_t2->r_child);
                else
                    return false;
            }
            return l_child && r_child;
        } else {
            return false;
        }
    }

    tNode<typeof(T)> searchNode(tNode<typeof(T)> node, T key) {
        if(node) {
            if(node->key == key)
                return node;
            if(key < node->key)
                return searchNode(node->l_child, key);
            else
                return searchNode(node->r_child, key);
        } else {
            return nullptr;
        }
    }

    void printIdentation(tNode<typeof(T)> node, int idt = 0) {
        std::string ident;
        for(int i = 0; i < idt; i++)
            ident += "    ";
        if(node) {
            std::cout << ident << node->key << "(" << node->height << ", " << node->balance_factor << ")" << std::endl;
            printIdentation(node->l_child, idt + 1);
            printIdentation(node->r_child, idt + 1);
        } else {
            std::cout << ident << '#' << std::endl;
        }
    }

    tNode<typeof(T)> predecessorNode(tNode<typeof(T)> node) {
        if(node->r_child) {
            return predecessorNode(node->r_child);
        } else {
            temp = node;
            node = parent(node->key)->l_child;
            return temp;
        }
    }

    tNode<typeof(T)> successorNode(tNode<typeof(T)> node) {
        if(node->r_child) {
            return successorNode(node->l_child);
        } else {
            temp = node;
            node = parent(node->key)->r_child;
            return temp;
        }
    }

    bool degenerateTree(tNode<typeof(T)> node) {
        if(node) {
            if(node->l_child && node->r_child)
                return false;
            if(node->r_child)
                return degenerateTree(node->r_child);
            if(node->l_child)
                return degenerateTree(node->l_child);
            return true;
        } else {
            return false;
        }
    }

    bool simmetryNode(tNode<typeof(T)> node_a, tNode<typeof(T)> node_b) {
        bool lr = true, rl = true;
        if(node_a && node_b) {
            if(node_a->l_child && node_b->r_child)
                lr = simmetryNode(node_a->l_child, node_b->r_child);
            if(node_a->r_child && node_b->l_child)
                rl = simmetryNode(node_a->r_child, node_b->l_child);
            return lr && rl;
        } else {
            return false;
        }
    }

    void invertNode(tNode<typeof(T)> node) {
        if(node) {
            if(node->l_child)
                invertNode(node->l_child);
            if(node->r_child)
                invertNode(node->r_child);
            temp = node->l_child;
            node->l_child = node->r_child;
            node->r_child = temp;
            temp = nullptr;
        }
    }

    bool isAVLNode(tNode<typeof(T)> node) {
        bool l_child = true, r_child = true;
        if(node) {
            if(node->balance_factor != 1 || node->balance_factor != 1)
                return false;
            if(node->l_child)
                l_child = isAVLNode(node->l_child);
            if(node->r_child)
                r_child = isAVLNode(node->r_child);
            return l_child && r_child;
        } else
            return false;
    }

    tNode<typeof(T)> initNode(T key) {
        temp = new tree_node<typeof(T)>;
        temp->l_child = nullptr;
        temp->r_child = nullptr;
        temp->key = key;
        return temp;
    }

    // Traversals
    void inversePostorderTraversal(tNode<typeof(T)> node) {
        if(node) {
            if(node->r_child)
                inversePostorderTraversal(node->r_child);
            if(node->l_child)
                inversePostorderTraversal(node->l_child);
            std::cout << node->key << " ";
        }
    }

    void inversePreorderTraversal(tNode<typeof(T)> node) {
        if(node) {
            std::cout << node->key << " ";
            if(node->r_child)
                inversePreorderTraversal(node->r_child);
            if(node->l_child)
                inversePreorderTraversal(node->l_child);
        }
    }

    void inverseInorderTraversal(tNode<typeof(T)> node) {
        if(node) {
            if(node->r_child)
                inverseInorderTraversal(node->r_child);
            std::cout << node->key << " ";
            if(node->l_child)
                inverseInorderTraversal(node->l_child);
        }
    }

    void postorderTraversal(tNode<typeof(T)> node) {
        if(node) {
            if(node->l_child)
                postorderTraversal(node->l_child);
            if(node->r_child)
                postorderTraversal(node->r_child);
            std::cout << node->key << " ";
        }
    }

    void preorderTraversal(tNode<typeof(T)> node) {
        if(node) {
            std::cout << node->key << " ";
            if(node->l_child)
                preorderTraversal(node->l_child);
            if(node->r_child)
                preorderTraversal(node->r_child);
        }
    }

    void inorderTraversal(tNode<typeof(T)> node) {
        if(node) {
            if(node->l_child)
                inorderTraversal(node->l_child);
            std::cout << node->key << " ";
            if(node->r_child)
                inorderTraversal(node->r_child);
        }
    }
public:
    BinaryTree() {
        n_items = 0;
        root = nullptr;
    }

    virtual bool simmetry(BinaryTree<typeof(T)> *tree) { return simmetryNode(root, tree->root); }

    virtual tNode<typeof(T)> parent(int key) { return parentNode(root, nullptr, key); }

    unsigned short int nodeHeight(T key) { return findNodeHeight(root, key); }

    tNode<typeof(T)> search(T key) { return searchNode(root, key); }

    bool degenerate() { return degenerateTree(root); }

    bool isBinarySearch() { return isBinaryNode(root); }

    virtual T min() { return minNode(root); }

    virtual T max() { return maxNode(root); }

    bool isAVL() { return isAVLNode(root); }

    void invert() { invertNode(root); }

    void clear(tNode<typeof(T)> node) {
        if(node) {
            if (node->r_child)
                clear(node->r_child);
            if (node->l_child)
                clear(node->l_child);
            free(node);
        }
    }

    virtual void push(T key) {
        if(!search(key)) {
            pushNode(root, intToBinary(n_items + 1), key);
            n_items++;
        } else {
            std::cout << key << " key node is already in the tree" << std::endl;
        }
    }

    void pushSearch(T key) {
        if(!search(key)) {
            pushNodeSearch(root, key);
            n_items++;
        } else {
            std::cout << key << " key node is already in the tree" << std::endl;
        }
    }

    virtual void print() {
        if(root)
            printIdentation(root);
        else
            std::cout << "Empty Tree" << std::endl;
    }

    // Traversals
    void postorder() { postorderTraversal(root); }

    void preorder() { preorderTraversal(root); }

    void inorder() { inorderTraversal(root); }

    void inverseInorder() { inverseInorderTraversal(root); }

    void inversePreorder() { inversePreorderTraversal(root); }

    void inversePostorder() { inversePostorderTraversal(root); }

    //Operator Overloading
    bool operator==(BinaryTree<typeof(T)> *tree) { return equalValueNode(root, tree->root); }
};


template<typename T>
class BinarySearchTree : private BinaryTree<typeof(T)>{
private:
    using BinaryTree<typeof(T)>::equalValueNode;
    using BinaryTree<typeof(T)>::simmetryNode;
    using BinaryTree<typeof(T)>::initNode;
    using BinaryTree<typeof(T)>::n_items;
    using BinaryTree<typeof(T)>::root;
    using BinaryTree<typeof(T)>::temp;

    tNode<typeof(T)> parentNode(tNode<typeof(T)> node, tNode<typeof(T)> parent, T key) {
        if(node) {
            if(node->key == key)
                return parent;
            else if(node->key < key) {
                if(node->r_child)
                    return parentNode(node->r_child, node, key);
                else
                    return nullptr;
            } else {
                if(node->l_child)
                    return parentNode(node->l_child, node, key);
                else
                    return nullptr;
            }
        } else {
            return nullptr;
        }
    }

    void setNodesHeightBFactor(tNode<typeof(T)> node, int height) {
        short int l_height = 0, r_height = 0;

        if(node) {
            if(node->l_child) {
                setNodesHeightBFactor(node->l_child, height + 1);
                l_height = node->l_child->height + 1;
            }
            if(node->r_child) {
                setNodesHeightBFactor(node->r_child, height + 1);
                r_height = node->r_child->height + 1;
            }
            node->height = heightNode(node);
            node->balance_factor = r_height - l_height;
        }
    }

    bool findNode(tNode<typeof(T)> node, T key) {
        if(node) {
            if(node->key == key)
                return true;
            if(node->key < key)
                return findNode(node->r_child, key);
            if(node->key > key)
                return findNode(node->l_child, key);
        } else {
            return false;
        }
    }

    void pushNode(tNode<typeof(T)> node, T key) {
        if(n_items == 0) {
            root = initNode(key);
        } else {
            if(key < node->key) {
                if(node->l_child)
                    pushNode(node->l_child, key);
                else
                    node->l_child = initNode(key);
            } else if(key >= node->key) {
                if(node->r_child)
                    pushNode(node->r_child, key);
                else
                    node->r_child = initNode(key);
            }
        }

    }

    int notLeafNode(tNode<typeof(T)> node) {
        int l_child = 0, r_child = 0;
        if(node) {
            if(node->r_child && node->l_child) {
                if(node->l_child)
                    l_child = notLeafNode(node->l_child);
                if(node->r_child)
                    r_child = notLeafNode(node->r_child);
                return l_child + r_child + 1;
            }
        } else {
            return 0;
        }
    }

    int heightNode(tNode<typeof(T)> node) {
        int l_height = 0, r_height = 0;
        if(node) {
            if(node->l_child)
                l_height = heightNode(node->l_child) + 1;
            if(node->r_child)
                r_height = heightNode(node->r_child) + 1;
            if(l_height > r_height)
                return l_height;
            return r_height;
        } else {
            return 0;
        }
    }

    int leafNode(tNode<typeof(T)> node) {
        int l_child = 0, r_child = 0;
        if(node) {
            if(!node->r_child && !node->l_child)
                return 1;
            if(node->l_child)
                l_child = leafNode(node->l_child);
            if(node->r_child)
                r_child = leafNode(node->r_child);
            return r_child + l_child;
        } else {
            return 0;
        }
    }

    int nNodes(tNode<typeof(T)> node) {
        int l_child = 0, r_child = 0;
        if(node) {
            if(node->l_child)
                l_child = nNodes(node->l_child) + 1;
            if(node->r_child)
                r_child = nNodes(node->r_child) + 1;
            // This sum considers that the root node is not counted
            return l_child + r_child;
        } else {
            return 0;
        }
    }

    T minNode(tNode<typeof(T)> node) {
        if(node) {
            if(!node->l_child)
                return node->key;
            return minNode(node->l_child);
        }
        return -1;
    }

    T maxNode(tNode<typeof(T)> node) {
        if(node) {
            if(!node->r_child)
                return node->key;
            return maxNode(node->r_child);
        }
        return -1;
    }

public:
    using BinaryTree<typeof(T)>::inversePostorder;
    using BinaryTree<typeof(T)>::printIdentation;
    using BinaryTree<typeof(T)>::inversePreorder;
    using BinaryTree<typeof(T)>::inverseInorder;
    using BinaryTree<typeof(T)>::nodeHeight;
    using BinaryTree<typeof(T)>::degenerate;
    using BinaryTree<typeof(T)>::postorder;
    using BinaryTree<typeof(T)>::preorder;
    using BinaryTree<typeof(T)>::inorder;
    using BinaryTree<typeof(T)>::invert;
    using BinaryTree<typeof(T)>::search;
    using BinaryTree<typeof(T)>::isAVL;
    using BinaryTree<typeof(T)>::clear;

    BinarySearchTree() {
        n_items = 0;
        root = nullptr;
    }

    bool simmetry(BinarySearchTree<typeof(T)> *tree) { return simmetryNode(root, tree->root); }

    tNode<typeof(T)> parent(int key) { return parentNode(root, nullptr, key); }

    int notLeafs() { return notLeafNode(root); }

    int height() { return heightNode(root); }

    int nodes() { return nNodes(root) + 1; }

    int leafs() { return leafNode(root); }

    T deltaMaxMin() { return max() - min(); }

    T min() { return minNode(root); }

    T max() { return maxNode(root); }

    int getnItems() { return n_items; }

    void push(T key) {
        if(!search(key)) {
            pushNode(root, key);
            n_items++;
            setNodesHeightBFactor(root, 0);
        } else {
            std::cout << key << " key node is already in the tree" << std::endl;
        }
    }

    void print() {
        if(root)
            printIdentation(root);
        else
            std::cout << "Empty Tree" << std::endl;
    }

    //Operator Overloading
    bool operator==(BinarySearchTree<typeof(T)> *tree) { return equalValueNode(root, tree->root); }

    ~BinarySearchTree() {
        clear(root);
    }
};


#endif //ALGORITMOS_II_DATA_STRUCTURES_H
