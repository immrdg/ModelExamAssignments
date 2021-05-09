#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QString>
#include<QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
     QStringList fruits;
     fruits<<"Apple"<<"Blueberries"<<"Cherries"<<"Dragon Fruit"<<"Apricots";
     for(int i=0;i<fruits.size();i++)
         ui->comboBox->addItem(QIcon(":/icons/"+fruits.at(i)+".png"),fruits.at(i));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_capture_clicked()
{
    int i=ui->comboBox->currentIndex();
    QString value=ui->comboBox->currentText();
    qDebug()<<"Index Of Current Item="<<QString::number(i);
    qDebug()<<"Current Item Text :"<<value;
}

void MainWindow::on_setvalue_clicked()
{
    ui->comboBox->setCurrentIndex(2);
}

void MainWindow::on_displayvalues_clicked()
{
    qDebug("The Current Items in Combo Box Are:");
    for(int i=0;i<ui->comboBox->count();i++)
    {
        qDebug()<<"Index : "<<QString::number(i)<<"-->"<<ui->comboBox->itemText(i);
    }
}
