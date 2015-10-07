#include "qitem.hpp"

#include <QHBoxLayout>

QItem::QItem(item_t *item, QWidget *parent) : QDialog(parent)
{
    this->item = item;

    m_id = new QComboBox(this);
    m_id->addItem("(None)", 0);
    for (uint32_t i = 0; i < MH3U_DS::items()->size(); i++)
    {
        m_id->addItem(QString(MH3U_DS::items()->at(i).identifier.c_str()), MH3U_DS::items()->at(i).count);
    }

    //m_id = new QSpinBox(this);
    //m_id->setMinimum(0x0000);
    //m_id->setMaximum(0xffff);

    m_count = new QSpinBox(this);
    m_count->setMinimum(0x0000);
    m_count->setMaximum(0xffff);

    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_id);
    layout->addWidget(m_count);
    this->setLayout(layout);
    this->setWindowTitle("Single item editor");

    this->load();
}

void QItem::load()
{
    m_id->setCurrentIndex(m_id->findData(item->id));
    m_count->setValue(item->count);
}

void QItem::save()
{
    item->id = (uint16_t) m_id->currentData().toInt();
    item->count = m_count->value();
}

void QItem::closeEvent(QCloseEvent *)
{
    save();
}
