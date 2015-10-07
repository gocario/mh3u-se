#include "widget.hpp"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    QPushButton *btn = new QPushButton("Button", this);

    connect(btn, SIGNAL(clicked(bool)), this, SLOT(clicked()));
}

Widget::~Widget()
{
}


void Widget::clicked()
{
    std::cout << "Clicked!" << std::endl;

    QDialog *w = new QDialog(this);
    w->show();


}
