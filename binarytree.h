#ifndef BINARYTREE_H
#define BINARYTREE_H

#include "cstddef"
#include <QString>
class BinTree
{
protected:
    typedef struct Node {
        size_t key;
        QString name;
        Node* left;
        Node* right;
        Node* parent;
        size_t height;
        Node(int k, QString s) { key = k; name = s; left = right = 0; height = 1; }
    } Node;

    Node *root;

    Node* insert(Node *x, Node *z);
    Node* deleteNode (Node *x, size_t id);
    size_t findMinKey(Node *t);
    QString findByKey(Node *x, size_t key);
    Node* findNodeByKey(Node *x, size_t key);
    size_t getHeight(Node *x);
    int balanceFactor(Node *x);
    void fixHeight(Node *x);
    Node* rotateRight(Node *x);
    Node* rotateLeft(Node *x);
    Node* balance(Node *x);
    Node* removeMin(Node *x);
    Node* findMin(Node *x);

    void deleteSubtree(Node* node);
    void insertSubtree(Node *x, Node *z, BinTree &resultTree);
    void treeInMap(Node *x, QMultiMap<int, QString> &m);
    void mapInTree(QMultiMap<int, QString> &m, BinTree &tree);
    void insertBranch(Node* x, Node* z, bool asLeftChild);
    void deleteBranch(Node* x, bool leftBranch);
    bool insertAtPosition(int parentKey, const QString& value, bool asLeftChild) ;


public :

    BinTree();
    ~BinTree();

    void insertion(size_t id, QString name);
    QString findByID(size_t id);
    void deleteByID(size_t id);
    QString allSorted(Node *x);
    QString keyNodeFirst(Node *x);
    QString keyNodeLast(Node *x);

    Node* getRoot() const;;
    Node* getLeft(Node *x);;
    Node* getRight(Node *x);;
    QString getName(Node *x) const;
    size_t getKey(Node *x) const;



};



// class BinaryTree
// {
// public:
//     BinaryTree();
// };

#endif // BINARYTREE_H
