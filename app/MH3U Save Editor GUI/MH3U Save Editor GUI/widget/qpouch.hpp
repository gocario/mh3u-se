#ifndef QPOUCH_HPP
#define QPOUCH_HPP

#include "main.hpp"

#include "qitem.hpp"

#include <QWidget>
#include <QPushButton>

class QPouch : public QWidget
{
    Q_OBJECT
public:
    explicit QPouch(MH3U_SE *mh3u, QWidget *parent = 0);
    ~QPouch();

private:
    MH3U_SE *mh3u;
    QPushButton *m_buttons[4][8];

public slots:
    void buttonClicked(int id);
};

#endif // QPOUCH_HPP
