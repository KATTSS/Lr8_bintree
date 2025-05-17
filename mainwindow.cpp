#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTimer>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), currentChoice(-1), tree(new AdvancedBinTree()) {
    ui->setupUi(this);
    tree->insertion(2, "Kate");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_clicked() {
    if (currentChoice == 1) {
        input = ui->lineEdit->text();
        if (!isValidInt(input)) {
            ui->lineEdit->setText("Invalid ID");
            enableAll();
            return;
        }
        currentChoice++;
        switchMenu();
    } else if (currentChoice == 2) {
        tree->insertion(input.toInt(), ui->lineEdit->text());
        currentChoice = -1;
        enableAll();
        ui->lineEdit->clear();
    } else if (currentChoice == 3) {
        input = ui->lineEdit->text();
        if (!isValidInt(input)) {
            ui->lineEdit->setText("Invalid ID");
            enableAll();
            return;
        }
        QString result = tree->findByID(input.toInt());
        ui->lineEdit->setText(result);
        enableAll();
    } else if (currentChoice == 4) {
        input = ui->lineEdit->text();
        if (!isValidInt(input)) {
            ui->lineEdit->setText("Invalid ID");
            enableAll();
            return;
        }
        tree->deleteByID(input.toInt());
        ui->lineEdit->clear();
        enableAll();
    } else if (currentChoice == 10) {
        input = ui->lineEdit->text();
        if (!isValidInt(input)) {
            ui->lineEdit->setText("Invalid ID");
            enableAll();
            return;
        }
        currentChoice += 10;
        switchMenu();
    } else if (currentChoice == 20) {
        if (ui->lineEdit->text() == "l") {
                tree->deleteBranch(tree->findNodeByKeyPublic(input.toInt()), true);
        } else if (ui->lineEdit->text() == "r") {

                tree->deleteBranch(tree->findNodeByKeyPublic(input.toInt()), false);
        } else {
            ui->lineEdit->setText("Invalid input");
            return;
        }
        currentChoice = -1;
        enableAll();
        ui->lineEdit->clear();
    } else if(currentChoice==11) {
        input = ui->lineEdit->text();
        if (!isValidInt(input)) {
            ui->lineEdit->setText("Invalid key");
            enableAll();
            return;
        }
         AdvancedBinTree* branch = new AdvancedBinTree();
         branch->insertion(150, "Helga");
         branch->insertion(149, "Matrona");
         if (branch->getRoot()) {
             tree->insertBranchPublic(tree->findNodeByKeyPublic(input.toInt()), branch->getRoot(), true);
         }
         delete branch;
         ui->pushButton_11->setDisabled(true);
         mergeSubBranch = true;

    }
}

void MainWindow::on_pushButton_2_clicked() {
    currentChoice = 1;
    switchMenu();
}

void MainWindow::on_pushButton_3_clicked() {
    currentChoice = 3;
    switchMenu();
}

void MainWindow::on_pushButton_4_clicked() {
    currentChoice = 4;
    switchMenu();
}

void MainWindow::on_pushButton_6_clicked() {
    ui->treeWidget->clear();
    tree->addToTreeWidget(ui->treeWidget, 0);
}

void MainWindow::on_pushButton_7_clicked() {
    ui->treeWidget->clear();
    tree->addToTreeWidget(ui->treeWidget, 1);
}

void MainWindow::on_pushButton_8_clicked() {
    ui->treeWidget->clear();
    tree->addToTreeWidget(ui->treeWidget, 2);
}

void MainWindow::on_pushButton_9_clicked() {
    // BinTree::Node* node = tree->findNodeByKeyPublic(5);
    // if (node) {
        tree->deleteSubtreePublic(tree->findNodeByKeyPublic(5));
  //  }
}

void MainWindow::on_pushButton_10_clicked() {
    currentChoice = 10;
    switchMenu();
}

void MainWindow::on_pushButton_11_clicked() {
    currentChoice=11;
    switchMenu();
   //  AdvancedBinTree* branch = new AdvancedBinTree();
   //  branch->insertion(150, "Helga");
   //  branch->insertion(149, "Matrona");
   // // BinTree::Node* parent = tree->findNodeByKeyPublic(10);
   //  if (branch->getRoot()) {
   //      tree->insertBranchPublic(tree->findNodeByKeyPublic(2), branch->getRoot(), true);
   //  }
   //  delete branch;
   //  ui->pushButton_11->setDisabled(true);
   //  mergeSubBranch = true;
}

void MainWindow::on_pushButton_12_clicked() {
    AdvancedBinTree* other = new AdvancedBinTree();
    other->insertion(2, "Ellin");
    other->insertion(9, "Emma");
    other->insertion(1, "Melon");
    tree->subtreeInsertion(tree->getRoot(), other->getRoot());
    delete other;
    ui->pushButton_12->setDisabled(true);
    mergeSubTree = true;
}

void MainWindow::on_pushButton_13_clicked() {
    tree->insertAtPosition(5, "Helen", true);
}

void MainWindow::on_pushButton_14_clicked() {
    size_t key1 = 1;
    size_t key2 = 3;
    ui->lineEdit->setText(tree->findLCAPublic(key1, key2));
    // BinTree::Node* lca = tree->findLCA(key1, key2);
    // if (lca) {
    //     qDebug() << "LCA of" << key1 << "and" << key2 << "is" << lca->key;
    // } else {
    //     qDebug() << "LCA not found";
    // }
}

void MainWindow::switchMenu() {
    switch (currentChoice) {
    case 1:
    case 3:
    case 4:
    case 10: {
        ui->lineEdit->setText("put the ID");
        QTimer::singleShot(1000,this, [this] () {
            ui->lineEdit->clear();
        });
        disableAll();
        break;
    }
    case 2:
        ui->lineEdit->setText("put the name");
        QTimer::singleShot(1000, this, [this] () {
            ui->lineEdit->clear();
        });
        break;
    case 20:
        ui->lineEdit->setText("put l for left side, r - for right");
        QTimer::singleShot(1000, this, [this] () {
            ui->lineEdit->clear();
        });
        break;
    case 11: {
        ui->lineEdit->setText("put the key of insertion node");
        QTimer::singleShot(1000, this, [this] () {
            ui->lineEdit->clear();
        });
        break;
    }
    }

}

bool MainWindow::isValidInt(const QString& str) {
    bool ok;
    str.toInt(&ok);
    return ok;
}

void MainWindow::disableAll() {
    ui->pushButton_2->setDisabled(true);
    ui->pushButton_3->setDisabled(true);
    ui->pushButton_4->setDisabled(true);
    ui->pushButton_6->setDisabled(true);
    ui->pushButton_7->setDisabled(true);
    ui->pushButton_8->setDisabled(true);
    ui->pushButton_9->setDisabled(true);
    ui->pushButton_10->setDisabled(true);
    ui->pushButton_11->setDisabled(true);
    ui->pushButton_12->setDisabled(true);
    ui->pushButton_13->setDisabled(true);
    ui->pushButton_14->setDisabled(true);
}

void MainWindow::enableAll() {
    ui->pushButton_2->setDisabled(false);
    ui->pushButton_3->setDisabled(false);
    ui->pushButton_4->setDisabled(false);
    ui->pushButton_6->setDisabled(false);
    ui->pushButton_7->setDisabled(false);
    ui->pushButton_8->setDisabled(false);
    ui->pushButton_9->setDisabled(false);
    ui->pushButton_10->setDisabled(false);
    if (!mergeSubTree) ui->pushButton_12->setDisabled(false);
    if (!mergeSubBranch) ui->pushButton_11->setDisabled(false);
    ui->pushButton_13->setDisabled(false);
    ui->pushButton_14->setDisabled(false);
}
