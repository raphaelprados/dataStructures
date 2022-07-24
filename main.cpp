
#include "iostream"
#include "includes/dataStructure.h"
#include "includes/utilities.h"

#define TAM 32

int main() {

    BinarySearchTree<int> bst = BinarySearchTree<int>();
    BinarySearchTree<int> bst2 = BinarySearchTree<int>();
    BinaryTree<int> bt = BinaryTree<int>();
    BinaryTree<int> btex15a = BinaryTree<int>();
    BinaryTree<int> btex15b = BinaryTree<int>();

//    std::random_device dev;
//    std::mt19937 rng(dev());
//    std::uniform_int_distribution<std::mt19937::result_type> dist32768(1, 32768);

    // Geração de números aleatórios e inserção na arvore
//    vector[0] = dist32768(rng);
//    for(int i = 1; i < TAM; i++) {
//        vector[i] = dist32768(rng);
//        if(vector[i] > vector[i - 1])
//            vector[i] = vector[i] - vector[i - 1];
//        bst.push(vector[i]);
//    }

    int vector[TAM] = {3303, 3798, 2381, 1233, 3992, 702, 1225, 3030, 1364, 3099,
                       3656, 3576, 1912, 891, 3200, 1468, 737, 2722, 746,
                       1574, 914, 3374, 4016, 3380, 3969, 931, 1312, 1923,
                       3184, 1516, 3534, 1829};
    int vector2[(TAM / 4) - 1] = {20, 10, 30, 5, 15, 25, 35};
    for(auto x : vector) {
        bst.push(x);
        bst2.push(x);
        bt.pushSearch(x);
    }
    for(auto x : vector2) {
        btex15a.push(x);
        btex15b.push(x);
    }
    btex15a.invert();
    bst.print();

    std::cout << "Min (BST): " << bst.min() << std::endl;
    std::cout << "Max (BST): " << bst.max() << std::endl;
    std::cout << "Min (BT): " << bst.min() << std::endl;
    std::cout << "Min (BT): " << bst.max() << std::endl;
    std::cout << "Altura: " << bst.height() << std::endl;
    std::cout << "Numero de nodos: " << bst.nodes() << std::endl;
    std::cout << "Folhas: " << bst.leafs() << std::endl;
    std::cout << "Nao Folhas: " << bst.notLeafs() << std::endl;
    std::cout << "Max - Min: " << bst.deltaMaxMin() << std::endl;
    std::cout << "Pai (BST) (3969): " << bst.parent(3969)->key << std::endl;
    std::cout << "Pai (BT) (891): " << bt.parent(891)->key << std::endl;
    std::cout << "Arvore binaria (BT): " << bt.isBinarySearch() << std::endl;
    std::cout << "Altura (1312): " << bst.nodeHeight(1312) << std::endl;
    std::cout << "Degenerada (BT): " << bt.degenerate() << std::endl;
    std::cout << "Degenerada (BST): " << bst.degenerate() << std::endl;
    std::cout << "AVL (BST): " << bst.isAVL() << std::endl;
    std::cout << "BT == BST: " << (bst == &bst2) << std::endl;
    bst.invert();
    std::cout << "BT == BST: " << (bst == &bst2) << std::endl;
    std::cout << "BT == ~BST: " << bst.simmetry(&bst2) << std::endl;
    bst.invert();
    std::cout << "BT == BST: " << (bst == &bst2) << std::endl;
    std::cout << "btex == ~btex: " << btex15a.simmetry(&btex15b) << std::endl;
    bst.inorder();
    std::cout << std::endl;
    bst.inverseInorder();
    std::cout << std::endl;
    bst.inversePostorder();
    std::cout << std::endl;
    bst.inversePreorder();

    return 0;
}
