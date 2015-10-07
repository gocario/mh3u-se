#ifndef QINVENTORY_HPP
#define QINVENTORY_HPP

#include "main.hpp"

#include "qitem.hpp"

#include <QWidget>
#include <QPushButton>

class QInventory : public QWidget
{
    Q_OBJECT
public:
    explicit QInventory(MH3U_SE *mh3u, QWidget *parent = 0);
    ~QInventory();

private:
    MH3U_SE *mh3u;
    QPushButton *m_buttons[3][8];

public slots:
    void buttonClicked(int id);
};

#endif // QINVENTORY_HPP
