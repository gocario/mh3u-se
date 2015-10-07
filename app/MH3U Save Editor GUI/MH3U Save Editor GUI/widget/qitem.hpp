#ifndef QITEM_HPP
#define QITEM_HPP

#include "main.hpp"

#include <QWidget>
#include <QDialog>
#include <QSpinBox>
#include <QComboBox>

class QItem : public QDialog
{
    Q_OBJECT
public:
    explicit QItem(item_t *item, QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *);

private:
    item_t *item;
    QComboBox *m_id;
    QSpinBox *m_count;

    void load();
    void save();
};

#endif // QITEM_HPP
