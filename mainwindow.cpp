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
    connect(this,SIGNAL(can_sent(int)),ui->CAN_Id,SLOT(display(int)));
   ui->pushButton->setCheckable(true);
   ui->Hide_Button->setCheckable(true);

}

int j=0;
int i=0;
int h=0;
MainWindow::~MainWindow()
{
    delete ui;
    //connect(ui->User_setting1,SIGNAL(valueChanged(int)),this,SLOT((int)));
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




void MainWindow::on_Hide_Button_toggled(bool checked) // we have git added huhu!
{
    if(checked){
        ui->pushButton->setVisible(false);
    }
    else{
        ui->pushButton->setVisible(true);
    }
}


/*void MainWindow::on_User_setting1_sliderMoved(int position)
{
   ui->progressBar->setValue(position);
   qDebug()<<j;
   j++;
}*/

/*void MainWindow::on_User_setting1_rangeChanged(int min, int max)
{
    //ui->progressBar->setValue(position);
    qDebug()<<max;
    qDebug()<<min;

}*/

void MainWindow::on_User_setting1_valueChanged(int value)
{
    ui->progressBar->setValue(value);
    ui->lcdNumber->display(value);
    qDebug()<<value;

}


void MainWindow::on_pushButton_2_clicked()
{
   can_frame A;
   A.can_id =0x50;
   A.can_dlc=8;
   A.data[0]=0b00001111;
   qDebug()<<"Name:A--ID:0x50--dlc:8--data:0xFF\n";
  emit can_sent(A.data[0]);

}
