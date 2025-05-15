#include "advtree.h"
#include <QDebug>

size_t AdvancedBinTree::countSymbols()
{
    qDebug () << "count all symbols in: " << allSorted(root);
    return (allSorted(root).replace("\n", "")).length();
}


void AdvancedBinTree::addNodeToTree(QTreeWidget* treeWidget, QTreeWidgetItem* parentItem, Node* node, bool straight, bool left, bool right) {
    if (!node) return;

    QTreeWidgetItem* item = nullptr;
    if (straight) {
        addNodeToTree(treeWidget, parentItem, node->left, straight, left, right);
        if (parentItem)
            item = new QTreeWidgetItem(parentItem);
        else
            item = new QTreeWidgetItem(treeWidget);
        item->setText(0, QString("%1: %2").arg(node->key).arg(node->name));
        addNodeToTree(treeWidget, parentItem, node->right, straight, left, right);
    } else if (left) {
        if (parentItem)
            item = new QTreeWidgetItem(parentItem);
        else
            item = new QTreeWidgetItem(treeWidget);
        item->setText(0, QString("%1: %2").arg(node->key).arg(node->name));
        addNodeToTree(treeWidget, item, node->left, straight, left, right);
        addNodeToTree(treeWidget, item, node->right, straight, left, right);
    } else if (right) {
        addNodeToTree(treeWidget, parentItem, node->left, straight, left, right);
        addNodeToTree(treeWidget, parentItem, node->right, straight, left, right);
        if (parentItem)
            item = new QTreeWidgetItem(parentItem);
        else
            item = new QTreeWidgetItem(treeWidget);
        item->setText(0, QString("%1: %2").arg(node->key).arg(node->name));
    }
}

BinTree::Node* AdvancedBinTree::findLCA(Node* root, size_t key1, size_t key2) {
    if (!root) return nullptr;
    if (root->key == key1 || root->key == key2) return root;

    Node* leftLCA = findLCA(root->left, key1, key2);
    Node* rightLCA = findLCA(root->right, key1, key2);

    if (leftLCA && rightLCA) return root;
    return leftLCA ? leftLCA : rightLCA;
}

void AdvancedBinTree::addToTreeWidget(QTreeWidget* treeWidget, bool straight, bool left, bool right) {
    addNodeToTree(treeWidget, nullptr, root, straight, left, right);
}

void AdvancedBinTree::subtreeInsertion(AdvancedBinTree *oroot, AdvancedBinTree *branch)
{
    insertSubtree(oroot->root, branch->root, *oroot);
}

BinTree::Node* AdvancedBinTree::findLCA(size_t key1, size_t key2) {
    return findLCA(root, key1, key2);
}

