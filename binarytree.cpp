#include "binarytree.h"
#include <QDebug>

BinTree::Node* BinTree::insert(Node* x, Node* z) {
    if (!x) {
        z->parent = nullptr;
        return z;
    }
    if (z->key < x->key) {
        x->left = insert(x->left, z);
        if (x->left) x->left->parent = x;
    } else {
        x->right = insert(x->right, z);
        if (x->right) x->right->parent = x;
    }
    return balance(x);
}

BinTree::Node* BinTree::deleteNode(Node* x, size_t id) {
    if (!x) return nullptr;

    if (id < x->key) {
        x->left = deleteNode(x->left, id);
        if (x->left) x->left->parent = x;
    } else if (id > x->key) {
        x->right = deleteNode(x->right, id);
        if (x->right) x->right->parent = x;
    } else {
        if (x->left == nullptr && x->right == nullptr) {
            if (x->key == root->key) {
                root = nullptr;
                //qDebug () << root;
            }
            delete x;
            return nullptr;
        }
        Node* q = x->left;
        Node* r = x->right;
        Node* parent = x->parent;

        if (!r) {
            if (q) q->parent = parent;
            delete x;
            return q;
        }

        if (!q) {
            if (r) r->parent = parent;
            delete x;
            return r;
        }

        Node* min = findMin(r);
        x->key = min->key;
        x->name = min->name;
        x->right = deleteNode(r, min->key);
        if (x->right) x->right->parent = x;
        return balance(x);
    }

    return balance(x);
}

BinTree::BinTree() : root(nullptr) {}

BinTree::~BinTree() {
    deleteSubtree(root);
}

void BinTree::insertion(size_t id, QString name) {
    if (findNodeByKey(root, id)) {
        qDebug() << "Key already exists";
        return;
    }
    Node* newNode = new Node(id, name);
    root = insert(root, newNode);
}

QString BinTree::findByID(size_t id) {
    return findByKey(root, id);
}

void BinTree::deleteByID(size_t id) {
    root = deleteNode(root, id);
    if (root) root->parent = nullptr;
}

size_t BinTree::findMinKey(Node* t) {
    while (t->left) t = t->left;
    return t->key;
}

QString BinTree::findByKey(Node* x, size_t key) {
    if (!x) return "no such key in tree";
    if (x->key == key) return x->name;
    return key < x->key ? findByKey(x->left, key) : findByKey(x->right, key);
}

BinTree::Node* BinTree::findNodeByKey(Node* x, size_t key) {
    if (!x) return nullptr;
    if (x->key == key) return x;
    return key < x->key ? findNodeByKey(x->left, key) : findNodeByKey(x->right, key);
}

size_t BinTree::getHeight(Node* x) {
    return x ? x->height : 0;
}

int BinTree::balanceFactor(Node* x) {
    return getHeight(x->right) - getHeight(x->left);
}

void BinTree::fixHeight(Node* x) {
    size_t h1 = getHeight(x->left);
    size_t h2 = getHeight(x->right);
    x->height = (h1 > h2 ? h1 : h2) + 1;
}

void BinTree::deleteSubtree(Node* node) {
    if (node) {
        deleteSubtree(node->left);
        deleteSubtree(node->right);
        delete node;
    }
}

void BinTree::treeInMap(Node* x, QMultiMap<int, QString>& m) {
    if (x) {
        m.insert(x->key, x->name);
        treeInMap(x->left, m);
        treeInMap(x->right, m);
    }
}

void BinTree::mapInTree(QMultiMap<int, QString>& m, BinTree* tree) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        tree->insertion(it.key(), it.value());
    }
}

void BinTree::insertBranch(Node* x, Node* z, bool asLeftChild) {
    if (!x || !z) return;
    Node* currentParent = x;
    Node* currentBranch = z;
    while (currentBranch) {
        Node* newNode = new Node(currentBranch->key, currentBranch->name);
        if (asLeftChild) {
            currentParent->left = newNode;
        } else {
            currentParent->right = newNode;
        }
        newNode->parent = currentParent;
        currentParent = newNode;
        currentBranch = currentBranch->left;
    }
    root = balance(root);
}

void BinTree::deleteBranch(Node* x, bool leftBranch) {
    if (!x) return;
    Node* branch = leftBranch ? x->left : x->right;
    deleteSubtree(branch);
    if (leftBranch) {
        x->left = nullptr;
    } else {
        x->right = nullptr;
    }
    root = balance(root);
}

bool BinTree::insertAtPosition(size_t parentKey, const QString& value, bool asLeftChild) {
    Node* parent = findNodeByKey(root, parentKey);
    if (!parent) return false;
    Node* newNode = new Node(parentKey + 1, value);
    if (asLeftChild) {
        if (parent->left) deleteSubtree(parent->left);
        parent->left = newNode;
    } else {
        if (parent->right) deleteSubtree(parent->right);
        parent->right = newNode;
    }
    newNode->parent = parent;
    root = balance(root);
    return true;
}

void BinTree::insertSubtree(Node* x, Node* z, BinTree* resultTree) {
    QMultiMap<int, QString> mergedMap;
    if (x) treeInMap(x, mergedMap);
    if (z) treeInMap(z, mergedMap);
    resultTree->deleteSubtree(resultTree->root);
    resultTree->root = nullptr;
    mapInTree(mergedMap, resultTree);
}

BinTree::Node* BinTree::rotateRight(Node* x) {
    Node* q = x->left;
    if (!q) return x;
    x->left = q->right;
    if (q->right) q->right->parent = x;
    q->right = x;
    q->parent = x->parent;
    x->parent = q;
    fixHeight(x);
    fixHeight(q);
    return q;
}

BinTree::Node* BinTree::rotateLeft(Node* x) {
    Node* q = x->right;
    if (!q) return x;
    x->right = q->left;
    if (q->left) q->left->parent = x;
    q->left = x;
    q->parent = x->parent;
    x->parent = q;
    fixHeight(x);
    fixHeight(q);
    return q;
}

BinTree::Node* BinTree::balance(Node* x) {
    fixHeight(x);
    if (balanceFactor(x) == 2) {
        if (balanceFactor(x->right) < 0)
            x->right = rotateRight(x->right);
        return rotateLeft(x);
    }
    if (balanceFactor(x) == -2) {
        if (balanceFactor(x->left) > 0)
            x->left = rotateLeft(x->left);
        return rotateRight(x);
    }
    return x;
}

BinTree::Node* BinTree::removeMin(Node* x) {
    if (!x->left) {
        Node* right = x->right;
        if (right) right->parent = x->parent;
        delete x;
        return right;
    }
    x->left = removeMin(x->left);
    return balance(x);
}

BinTree::Node* BinTree::findMin(Node* x) {
    return x->left ? findMin(x->left) : x;
}

QString BinTree::allSorted(Node* x) {
    if (!x) return "";
    return allSorted(x->left) + x->name + "\n" + allSorted(x->right);
}

QString BinTree::keyNodeFirst(Node* x) {
    if (!x) return "";
    return x->name + "\n" + keyNodeFirst(x->left) + keyNodeFirst(x->right);
}

QString BinTree::keyNodeLast(Node* x) {
    if (!x) return "";
    return keyNodeLast(x->left) + keyNodeLast(x->right) + x->name + "\n";
}
