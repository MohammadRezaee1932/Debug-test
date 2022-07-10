#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //////
   // connect(ui->Toggle,SIGNAL(clicked()),this,SLOT(Widget_Color_Change()));
    //connect(this,SIGNAL(bool_status(bool ch)),this,SLOT(Widget_Color_Change(bool ch)));
   ui->pushButton->setCheckable(true);
   ui->Hide_Button->setCheckable(true);
}
int i;
MainWindow::~MainWindow()
{
    delete ui;
}

/* void MainWindow::Widget_Color_Change(bool ch)
{


}*/


//ui->Widget_Color->setStyleSheet("background-color: \"red\"");




void MainWindow::on_pushButton_clicked(bool checked)
{

    if (checked){
    ui->Widget_Color->setStyleSheet("background-color: \"red\"");
    }
   else {
    ui->Widget_Color->setStyleSheet("background-color: \"blue\"");
    }
    qDebug()<<"Toggle is clicked"<<i;
    i++;
}




void MainWindow::on_Hide_Button_toggled(bool checked)
{
    if(checked){
        ui->pushButton->setVisible(false);
    }
    else{
        ui->pushButton->setVisible(true);
    }
}

