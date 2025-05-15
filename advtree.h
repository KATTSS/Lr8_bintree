#ifndef ADVTREE_H
#define ADVTREE_H

// #ifndef ADVANCEDBINTREE_H
// #define ADVANCEDBINTREE_H
#include <QTreeWidget>
#include "binarytree.h"

class AdvancedBinTree : public BinTree
{
public:
    AdvancedBinTree() : BinTree() {};
    size_t countSymbols();
    void addToTreeWidget(QTreeWidget* treeWidget, bool straight, bool left, bool right);
    void subtreeInsertion(AdvancedBinTree *root, AdvancedBinTree *branch);
    BinTree::Node* findLCA(size_t key1, size_t key2);
private:
    void addNodeToTree(QTreeWidget* treeWidget, QTreeWidgetItem* parentItem, Node* node, bool straight, bool left, bool right);
    BinTree::Node* findLCA(Node* root, size_t key1, size_t key2);
};

//#endif // ADVANCEDBINTREE_H


// class AdvTree
// {
// public:
//     AdvTree();
// };

#endif // ADVTREE_H
