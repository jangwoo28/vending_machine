#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoke->setEnabled(false);
    ui->pbReturn->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}



void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
}

void Widget::checkMoney(int m){
    if(m>0){
        ui->pbReturn->setEnabled(true);
    }
    else{
        ui->pbReturn->setEnabled(false);
    }

    if(m>=100){
        ui->pbCoffee->setEnabled(true);
    }
    if(m>=150){
        ui->pbTea->setEnabled(true);
    }
    if(m>=200){
        ui->pbCoke->setEnabled(true);
    }

    if(m<100){
        ui->pbCoffee->setEnabled(false);
    }
    if(m<150){
        ui->pbTea->setEnabled(false);
    }
    if(m<200){
        ui->pbCoke->setEnabled(false);
    }


}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    checkMoney(money);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
    checkMoney(money);

}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    checkMoney(money);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    checkMoney(money);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
    checkMoney(money);
    QMessageBox msg;
    msg.information(nullptr,"Buy Success","[Coffee]");
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
    checkMoney(money);
    QMessageBox msg;
    msg.information(nullptr,"Buy Success","[Tea]");
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
    checkMoney(money);
    QMessageBox msg;
    msg.information(nullptr,"Buy Success","[Coke]");

}

void Widget::on_pbReturn_clicked()
{
    int coin_500;
    int coin_100;
    int coin_50;
    int coin_10;

    QString res;

    QString ret_money = QString::number(money);
    QMessageBox msg;

    coin_500 = money / 500;
    coin_100 = money % 500 / 100;
    coin_50 = money % 500 % 100 / 50;
    coin_10 = money % 500 % 100 % 50 / 10;

    res.sprintf("Total : %d\n500W : %d\n100W : %d\n50W : %d\n10W : %d\n",money,coin_500,coin_100,coin_50,coin_10);

    msg.information(nullptr,"Return Money",res);

    money = 0;
    ui->lcdNumber->display(money);
    checkMoney(money);


}
