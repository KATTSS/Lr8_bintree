#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <cstddef>
#include <QString>
#include <QMultiMap>

class BinTree
{
protected:
    struct Node {
        size_t key;
        QString name;
        Node* left;
        Node* right;
        Node* parent;
        size_t height;
        Node(size_t k, QString s) : key(k), name(s), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
    };

    //Node* root;

    Node* insert(Node* x, Node* z);
    Node* deleteNode(Node* x, size_t id);
    size_t findMinKey(Node* t);
    QString findByKey(Node* x, size_t key);
    size_t getHeight(Node* x);
    int balanceFactor(Node* x);
    void fixHeight(Node* x);
    Node* rotateRight(Node* x);
    Node* rotateLeft(Node* x);
    Node* balance(Node* x);
    Node* removeMin(Node* x);
    Node* findMin(Node* x);
    void deleteSubtree(Node* node);
    void insertSubtree(Node* x, Node* z, BinTree* resultTree);
    void treeInMap(Node* x, QMultiMap<int, QString>& m);
    void mapInTree(QMultiMap<int, QString>& m, BinTree* tree);
    void insertBranch(Node* x, Node* z, bool asLeftChild);
    //bool insertAtPosition(size_t parentKey, const QString& value, bool asLeftChild);

public:

    // struct Node {
    //     size_t key;
    //     QString name;
    //     Node* left;
    //     Node* right;
    //     Node* parent;
    //     size_t height;
    //     Node(size_t k, QString s) : key(k), name(s), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
    // };

    BinTree();
    ~BinTree();

    void insertion(size_t id, QString name);
    QString findByID(size_t id);
    void deleteByID(size_t id);
    QString allSorted(Node* x);
    QString keyNodeFirst(Node* x);
    QString keyNodeLast(Node* x);
    Node* getRoot() const { return root; }
    Node* getLeft(Node* x) { return x ? x->left : nullptr; }
    Node* getRight(Node* x) { return x ? x->right : nullptr; }
    QString getName(Node* x) const { return x ? x->name : ""; }
    size_t getKey(Node* x) const { return x ? x->key : 0; }
    void deleteBranch(Node* x, bool leftBranch);
    Node* findNodeByKey(Node* x, size_t key);
    bool insertAtPosition(size_t parentKey, const QString& value, bool asLeftChild);

    Node* root;

// protected:
//     struct Node {
//         size_t key;
//         QString name;
//         Node* left;
//         Node* right;
//         Node* parent;
//         size_t height;
//         Node(size_t k, QString s) : key(k), name(s), left(nullptr), right(nullptr), parent(nullptr), height(1) {}
//     };

//     // Node* root;

//     Node* insert(Node* x, Node* z);
//     Node* deleteNode(Node* x, size_t id);
//     size_t findMinKey(Node* t);
//     QString findByKey(Node* x, size_t key);
//     size_t getHeight(Node* x);
//     int balanceFactor(Node* x);
//     void fixHeight(Node* x);
//     Node* rotateRight(Node* x);
//     Node* rotateLeft(Node* x);
//     Node* balance(Node* x);
//     Node* removeMin(Node* x);
//     Node* findMin(Node* x);
//     void deleteSubtree(Node* node);
//     void insertSubtree(Node* x, Node* z, BinTree* resultTree);
//     void treeInMap(Node* x, QMultiMap<int, QString>& m);
//     void mapInTree(QMultiMap<int, QString>& m, BinTree* tree);
//     void insertBranch(Node* x, Node* z, bool asLeftChild);
//     // bool insertAtPosition(size_t parentKey, const QString& value, bool asLeftChild);

};

#endif // BINARYTREE_H
