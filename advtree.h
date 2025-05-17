#ifndef ADVTREE_H
#define ADVTREE_H

#include <QTreeWidget>
#include "binarytree.h"

class AdvancedBinTree : public BinTree
{
public:
    AdvancedBinTree() : BinTree() { root = nullptr; }
    size_t countSymbols();
    void addToTreeWidget(QTreeWidget* treeWidget, int traversalType);
    void subtreeInsertion(Node* oroot, Node* branch);
    QString findLCAPublic(size_t key1, size_t key2);

    BinTree::Node* findNodeByKeyPublic(size_t key) {
        return findNodeByKey(root, key);
    }
    void deleteSubtreePublic(BinTree::Node* node) {
        deleteSubtree(node);
    }
    void insertBranchPublic(BinTree::Node* parent, BinTree::Node* branch, bool asLeftChild) {
        if (parent && branch)
        insertBranch(parent, branch, asLeftChild);
    }

private:
    void addNodeToTree(QTreeWidget* treeWidget, QTreeWidgetItem* parentItem, Node* node, int traversalType);
    BinTree::Node* findLCA(Node* root, size_t key1, size_t key2);
};

#endif // ADVTREE_H
