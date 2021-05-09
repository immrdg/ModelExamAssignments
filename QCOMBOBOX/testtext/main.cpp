#include "mainwindow.h"
#include<QFile>
#include <QApplication>
QString readTextFile(QString path)
{
    QFile file(path);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        QTextStream in(&file);
        return in.readAll();
    }
    return " ";
}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(538,240);
    QString css=readTextFile(":/css/stylesheet.txt");
    if(css.length()>0)
           a.setStyleSheet(css);
    w.show();
    return a.exec();
}
