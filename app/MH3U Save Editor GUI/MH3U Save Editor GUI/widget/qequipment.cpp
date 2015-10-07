#include "qequipment.hpp"

#include <QHBoxLayout>

QEquipment::QEquipment(equipment_t *equipment, QWidget *parent) : QDialog(parent)
{
    if (equipment == NULL)
        return;

    this->equipment = equipment;

    m_equipmentType = new QComboBox(this);
    m_equipmentType->addItem("(None)", 0);
    for (uint32_t i = 0; i < MH3U_DS::equipmentTypes()->size(); i++)
    {
        m_equipmentType->addItem(QString(MH3U_DS::equipmentTypes()->at(i).identifier.c_str()), MH3U_DS::equipmentTypes()->at(i).count);
    }

    //m_foo11 = new QSpinBox(this);
    //m_foo11->setMinimum(0x00);
    //m_foo11->setMaximum(0xff);
    m_foo12 = new QSpinBox(this);
    m_foo12->setMinimum(0x00);
    m_foo12->setMaximum(0xff);
    m_foo21 = new QSpinBox(this);
    m_foo21->setMinimum(0x00);
    m_foo21->setMaximum(0xff);
    m_foo22 = new QSpinBox(this);
    m_foo22->setMinimum(0x00);
    m_foo22->setMaximum(0xff);
    m_foo31 = new QSpinBox(this);
    m_foo31->setMinimum(0x00);
    m_foo31->setMaximum(0xff);
    m_foo32 = new QSpinBox(this);
    m_foo32->setMinimum(0x00);
    m_foo32->setMaximum(0xff);
    m_foo41 = new QSpinBox(this);
    m_foo41->setMinimum(0x00);
    m_foo41->setMaximum(0xff);
    m_foo42 = new QSpinBox(this);
    m_foo42->setMinimum(0x00);
    m_foo42->setMaximum(0xff);
    m_foo51 = new QSpinBox(this);
    m_foo51->setMinimum(0x00);
    m_foo51->setMaximum(0xff);
    m_foo52 = new QSpinBox(this);
    m_foo52->setMinimum(0x00);
    m_foo52->setMaximum(0xff);
    m_foo61 = new QSpinBox(this);
    m_foo61->setMinimum(0x00);
    m_foo61->setMaximum(0xff);
    m_foo62 = new QSpinBox(this);
    m_foo62->setMinimum(0x00);
    m_foo62->setMaximum(0xff);
    m_foo71 = new QSpinBox(this);
    m_foo71->setMinimum(0x00);
    m_foo71->setMaximum(0xff);
    m_foo72 = new QSpinBox(this);
    m_foo72->setMinimum(0x00);
    m_foo72->setMaximum(0xff);
    m_foo81 = new QSpinBox(this);
    m_foo81->setMinimum(0x00);
    m_foo81->setMaximum(0xff);
    m_foo82 = new QSpinBox(this);
    m_foo82->setMinimum(0x00);
    m_foo82->setMaximum(0xff);


    QHBoxLayout *layout = new QHBoxLayout(this);
    layout->addWidget(m_equipmentType);
    layout->addWidget(m_foo12);
    layout->addWidget(m_foo21);
    layout->addWidget(m_foo22);
    layout->addWidget(m_foo31);
    layout->addWidget(m_foo32);
    layout->addWidget(m_foo41);
    layout->addWidget(m_foo42);
    layout->addWidget(m_foo51);
    layout->addWidget(m_foo52);
    layout->addWidget(m_foo61);
    layout->addWidget(m_foo62);
    layout->addWidget(m_foo71);
    layout->addWidget(m_foo72);
    layout->addWidget(m_foo81);
    layout->addWidget(m_foo82);
    this->setLayout(layout);
    this->setWindowTitle("Single equipment editor");

    this->load();
}

void QEquipment::load()
{
    m_equipmentType->setCurrentIndex(m_equipmentType->findData((*equipment)[ 0]));
    m_foo12->setValue((*equipment)[ 1]);
    m_foo21->setValue((*equipment)[ 2]);
    m_foo22->setValue((*equipment)[ 3]);
    m_foo31->setValue((*equipment)[ 4]);
    m_foo32->setValue((*equipment)[ 5]);
    m_foo41->setValue((*equipment)[ 6]);
    m_foo42->setValue((*equipment)[ 7]);
    m_foo51->setValue((*equipment)[ 8]);
    m_foo52->setValue((*equipment)[ 9]);
    m_foo61->setValue((*equipment)[10]);
    m_foo62->setValue((*equipment)[11]);
    m_foo71->setValue((*equipment)[12]);
    m_foo72->setValue((*equipment)[13]);
    m_foo81->setValue((*equipment)[14]);
    m_foo82->setValue((*equipment)[15]);
}

void QEquipment::save()
{
    (*equipment)[ 0] = (uint8_t) m_equipmentType->currentData().toInt();
    (*equipment)[ 1] = m_foo12->value();
    (*equipment)[ 2] = m_foo21->value();
    (*equipment)[ 3] = m_foo22->value();
    (*equipment)[ 4] = m_foo31->value();
    (*equipment)[ 5] = m_foo32->value();
    (*equipment)[ 6] = m_foo41->value();
    (*equipment)[ 7] = m_foo42->value();
    (*equipment)[ 8] = m_foo51->value();
    (*equipment)[ 9] = m_foo52->value();
    (*equipment)[10] = m_foo61->value();
    (*equipment)[11] = m_foo62->value();
    (*equipment)[12] = m_foo71->value();
    (*equipment)[13] = m_foo72->value();
    (*equipment)[14] = m_foo81->value();
    (*equipment)[15] = m_foo82->value();
}

void QEquipment::closeEvent(QCloseEvent *)
{
    save();
}
