#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QValidator>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    currentChoice=-1;


  //  ui->lineEdit->setText("before any kind of additing the tree");
    tree = new AdvancedBinTree();
   // tree->addToTreeWidget(ui->treeWidget, false, true, false);
    // currentChoice=-1;

    other = new AdvancedBinTree();
    other->insertion(2, "Ellin");
    other->insertion(9, "Emma");
    other->insertion(1, "Melon");
    // ui->treeWidget->clear();
    // other->addToTreeWidget(ui->treeWidget, false, true, false);
    tree->subtreeInsertion(tree, other);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::on_pushButton_clicked()
// {
//     if (currentChoice==1) {
//         input = ui->lineEdit->text();
//         if (!isValidInt(input)){
//             qDebug() << "wrong id " << input;
//             enableAll();
//             ui->lineEdit->clear();
//             return;
//         }
//         currentChoice++;
//         switchMenu();
//     }
//     else if (currentChoice==2) {
//         tree->insertion(input.toInt(), ui->lineEdit->text());
//         currentChoice=-1;
//     }
//     else if(currentChoice==3) {
//         input = ui->lineEdit->text();
//         if (!isValidInt(input)){
//             enableAll();
//             ui->lineEdit->clear();
//             return;
//         }
//         ui->lineEdit->setText(tree->findByID(input.toInt()));
//     }
//     else if (currentChoice ==4) {
//         input = ui->lineEdit->text();
//         if (!isValidInt(input)){
//             enableAll();
//             ui->lineEdit->clear();
//             return;
//         }
//         tree->deleteByID(input.toInt());
//     }

//     if (currentChoice!=2) {
//         currentChoice=-1,
//             input.clear();
//         enableAll();
//     }
//     //ui->lineEdit->clear();

// }


// void MainWindow::on_pushButton_2_clicked()
// {
//     //add node
//     currentChoice=1;
//     switchMenu();
// }


// void MainWindow::on_pushButton_3_clicked()
// {
//     //find by key
//     currentChoice=3;
//     switchMenu();
// }


// void MainWindow::on_pushButton_4_clicked()
// {
//     //del by key
//     currentChoice=4;
//     switchMenu();
// }


// void MainWindow::on_pushButton_5_clicked()
// {
//     //count
//     ui->lineEdit->setText(QString::number(tree->countSymbols()));

// }
// void MainWindow::on_pushButton_6_clicked()
// {
//     //straight
//     ui->treeWidget->clear();
//     tree->addToTreeWidget(ui->treeWidget, true, false, false);
// }

// void MainWindow::on_pushButton_7_clicked()
// {
//     //root first
//     ui->treeWidget->clear();
//     tree->addToTreeWidget(ui->treeWidget, false, true, false);
// }

// void MainWindow::on_pushButton_8_clicked()
// {
//     //root last
//     ui->treeWidget->clear();
//     tree->addToTreeWidget(ui->treeWidget, false, false, true);
// }
// void MainWindow::switchMenu()
// {
//     switch (currentChoice) {
//     case 1:
//     case 3:
//     case 4:    {
//         ui->lineEdit->setText("put the ID");
//         QTimer::singleShot(1000, [this] () {
//             ui->lineEdit->clear();
//         });
//         disableAll();

//         break;
//     }
//     case 2:{
//         ui->lineEdit->setText("put the name");
//         QTimer::singleShot(1000, [this] () {
//             ui->lineEdit->clear();
//         });
//         break;
//     }
//     }
// }


// bool MainWindow::isValidInt(QString &str)
// {
//     QIntValidator validator;
//     int pos = 0;
//     return validator.validate(str, pos) == QValidator::Acceptable;
// }

// void MainWindow::disableAll()
// {
//     ui->pushButton_2->setDisabled(true);
//     ui->pushButton_3->setDisabled(true);
//     ui->pushButton_4->setDisabled(true);
//     ui->pushButton_5->setDisabled(true);
//     ui->pushButton_6->setDisabled(true);
//     ui->pushButton_7->setDisabled(true);
//     ui->pushButton_8->setDisabled(true);
// }

// void MainWindow::enableAll()
// {
//     ui->pushButton_2->setDisabled(false);
//     ui->pushButton_3->setDisabled(false);
//     ui->pushButton_4->setDisabled(false);
//     ui->pushButton_5->setDisabled(false);
//     ui->pushButton_6->setDisabled(false);
//     ui->pushButton_7->setDisabled(false);
//     ui->pushButton_8->setDisabled(false);
// }

