#ifndef WIDGET_HPP
#define WIDGET_HPP

#include <iostream>

#include <QWidget>
#include <QPushButton>

#include "widget/qitem.hpp"

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void clicked();
};

#endif // WIDGET_HPP
