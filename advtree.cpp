#include "advtree.h"
#include <QDebug>

size_t AdvancedBinTree::countSymbols() {
    QString sorted = allSorted(root).replace("\n", "");
    return sorted.length();
}

void AdvancedBinTree::addNodeToTree(QTreeWidget* treeWidget, QTreeWidgetItem* parentItem, Node* node, int traversalType) {
    if (!node) return;
    QTreeWidgetItem* item = nullptr;
    switch (traversalType) {
    case 0: // In-order
        addNodeToTree(treeWidget, parentItem, node->left, traversalType);
        item = parentItem ? new QTreeWidgetItem(parentItem) : new QTreeWidgetItem(treeWidget);
        item->setText(0, QString("%1: %2").arg(node->key).arg(node->name));
        addNodeToTree(treeWidget, parentItem, node->right, traversalType);
        break;
    case 1: // Pre-order
        item = parentItem ? new QTreeWidgetItem(parentItem) : new QTreeWidgetItem(treeWidget);
        item->setText(0, QString("%1: %2").arg(node->key).arg(node->name));
        addNodeToTree(treeWidget, item, node->left, traversalType);
        addNodeToTree(treeWidget, item, node->right, traversalType);
        break;
    case 2: // Post-order
        addNodeToTree(treeWidget, parentItem, node->left, traversalType);
        addNodeToTree(treeWidget, parentItem, node->right, traversalType);
        item = parentItem ? new QTreeWidgetItem(parentItem) : new QTreeWidgetItem(treeWidget);
        item->setText(0, QString("%1: %2").arg(node->key).arg(node->name));
        break;
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

void AdvancedBinTree::addToTreeWidget(QTreeWidget* treeWidget, int traversalType) {
    addNodeToTree(treeWidget, nullptr, root, traversalType);
}

void AdvancedBinTree::subtreeInsertion(Node* oroot, Node* branch) {
    insertSubtree(oroot, branch, this);
}

QString AdvancedBinTree::findLCAPublic(size_t key1, size_t key2) {
    BinTree::Node* x = findLCA(root, key1, key2);
    return QString::number(x->key) + ": " + x->name;
}
