#include "mainwindow.h"
#include <QTextEdit>
#include <QFont>
#include<QLabel>
#include<QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Font Declarations
    QFont plaintext("Winterland",12,QFont::DemiBold);
    QFont label("Painted Paradise",12);
    // Text Edit
    QTextEdit *editor=new QTextEdit(this);
    editor->setFont(plaintext);
    editor->setStyleSheet(" border: 1px solid blue;color:orange;letter-spacing:3px;");
    editor->move(30,50);
    editor->setMinimumSize(491,291);
    editor->setMaximumSize(491,291);
    // Label
      QLabel *textlabel=new QLabel(this);
      textlabel->setGeometry(30,25,101,21);
      textlabel->setStyleSheet(" color:navy;background-color:yellow;letter-spacing:3px;");
      textlabel->setText(" Text Editor");
      textlabel->setFont(label);

      //QPush Button
      QPushButton *cut,*copy,*paste,*undo,*redo,*html;
      cut=new QPushButton(this);
      copy=new QPushButton(this);
      paste=new QPushButton(this);
      undo=new QPushButton(this);
      redo=new QPushButton(this);
      html=new QPushButton(this);
      cut->setText("Cut");
      cut->setGeometry(30,350,93,28);
      copy->setText("Copy");
      copy->setGeometry(130,350,93,28);
      paste->setText("Paste");
      paste->setGeometry(230,350,93,28);
      undo->setText("Undo");
      undo->setGeometry(330,350,93,28);
      redo->setText("Redo");
      redo->setGeometry(430,350,93,28);
      html->setText("HTML EXAMPLE");
      html->move(225,390);

      //actions
      connect(cut,&QPushButton::clicked,[=](){editor->cut();});
      connect(editor,&QTextEdit::textChanged,[=](){qDebug()<<"Text Changed";});
      connect(paste,&QPushButton::clicked,[=](){editor->paste();});
      connect(copy,&QPushButton::clicked,[=](){editor->copy();});
      connect(undo,&QPushButton::clicked,[=](){editor->undo();});
      connect(redo,&QPushButton::clicked,[=](){editor->redo();});
      //
      QString h1="<h1>This Is H&#49; tag</h1>";
      QString table="<table border=1><tr><th>This</th><th>Is A</th></tr><tr><td>table in </td><td>HTML</td></tr></table>";
      connect(html,&QPushButton::clicked,[=]{QString l="<br>"+h1+"<br>"+table;editor->setText(l);html->setEnabled(false);});
}

MainWindow::~MainWindow()
{
}

