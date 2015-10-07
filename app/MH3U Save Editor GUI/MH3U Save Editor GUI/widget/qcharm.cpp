#include "qcharm.hpp"

#include <QGridLayout>
#include <QLabel>

QCharm::QCharm(charm_t *charm, QWidget *parent) : QEquipment(NULL, parent)
{
    this->charm = charm;

    m_equipmentType = new QComboBox(this);
    m_equipmentType->addItem("(None)", 0);
    for (uint32_t i = 0; i < MH3U_DS::equipmentTypes()->size(); i++)
    {
        m_equipmentType->addItem(QString(MH3U_DS::equipmentTypes()->at(i).identifier.c_str()), MH3U_DS::equipmentTypes()->at(i).count);
    }

    m_slotsCount = new QSpinBox(this);
    m_slotsCount->setMinimum(0x00);
    m_slotsCount->setMaximum(0xff);

    m_identifier = new QComboBox(this);
    m_identifier->addItem("(None)", 0);
    for (uint32_t i = 0; i < MH3U_DS::charms()->size(); i++)
    {
        m_identifier->addItem(QString(MH3U_DS::charms()->at(i).identifier.c_str()), MH3U_DS::charms()->at(i).count);
    }

    m_firstSkillIdentifier = new QComboBox(this);
    m_secondSkillIdentifier = new QComboBox(this);
    m_firstSkillIdentifier->addItem("(None)", 0);
    m_secondSkillIdentifier->addItem("(None)", 0);
    for (uint32_t i = 0; i < MH3U_DS::skills()->size(); i++)
    {
        m_firstSkillIdentifier->addItem(QString(MH3U_DS::skills()->at(i).identifier.c_str()), MH3U_DS::skills()->at(i).count);
        m_secondSkillIdentifier->addItem(QString(MH3U_DS::skills()->at(i).identifier.c_str()), MH3U_DS::skills()->at(i).count);
    }
    m_firstSkillValue = new QSpinBox(this);
    m_firstSkillValue->setMinimum(0x00);
    m_firstSkillValue->setMaximum(0xff);
    m_secondSkillValue = new QSpinBox(this);
    m_secondSkillValue->setMinimum(0x00);
    m_secondSkillValue->setMaximum(0xff);

    m_firstJewelIdentifier = new QComboBox(this);
    m_secondJewelIdentifier = new QComboBox(this);
    m_thirdJewelIdentifier = new QComboBox(this);
    m_firstJewelIdentifier->addItem("(None)", 0);
    m_secondJewelIdentifier->addItem("(None)", 0);
    m_thirdJewelIdentifier->addItem("(None)", 0);
    for (uint32_t i = 0; i < MH3U_DS::jewels()->size(); i++)
    {
        m_firstJewelIdentifier->addItem(QString(MH3U_DS::jewels()->at(i).identifier.c_str()), MH3U_DS::jewels()->at(i).count);
        m_secondJewelIdentifier->addItem(QString(MH3U_DS::jewels()->at(i).identifier.c_str()), MH3U_DS::jewels()->at(i).count);
        m_thirdJewelIdentifier->addItem(QString(MH3U_DS::jewels()->at(i).identifier.c_str()), MH3U_DS::jewels()->at(i).count);
    }

    m_foo81 = new QSpinBox(this);
    m_foo81->setMinimum(0x00);
    m_foo81->setMaximum(0xff);
    m_foo82 = new QSpinBox(this);
    m_foo82->setMinimum(0x00);
    m_foo82->setMaximum(0xff);


    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(new QLabel("Equipment type", this), 0, 0);
    layout->addWidget(new QLabel("Slots count", this), 0, 1);
    layout->addWidget(new QLabel("Identifier", this), 0, 2);
    layout->addWidget(new QLabel("First Skill's Identifier", this), 0, 3);
    layout->addWidget(new QLabel("First Skill's Value", this), 0, 4);
    layout->addWidget(new QLabel("Second Skill's Identifier", this), 0, 5);
    layout->addWidget(new QLabel("Second Skill's Value", this), 0, 6);
    layout->addWidget(new QLabel("First Jewel's Identifier", this), 0, 7);
    layout->addWidget(new QLabel("Second Jewel's Identifier", this), 0, 8);
    layout->addWidget(new QLabel("Third Jewel's Identifier", this), 0, 9);
    layout->addWidget(new QLabel("Unknown", this), 0, 10);
    layout->addWidget(new QLabel("Unknown", this), 0, 11);
    layout->addWidget(m_equipmentType, 1, 0);
    layout->addWidget(m_slotsCount, 1, 1);
    layout->addWidget(m_identifier, 1, 2);
    layout->addWidget(m_firstSkillIdentifier, 1, 3);
    layout->addWidget(m_firstSkillValue, 1, 4);
    layout->addWidget(m_secondSkillIdentifier, 1, 5);
    layout->addWidget(m_secondSkillValue, 1, 6);
    layout->addWidget(m_firstJewelIdentifier, 1, 7);
    layout->addWidget(m_secondJewelIdentifier, 1, 8);
    layout->addWidget(m_thirdJewelIdentifier, 1, 9);
    layout->addWidget(m_foo81, 1, 10);
    layout->addWidget(m_foo82, 1, 11);
    this->setLayout(layout);
    this->setWindowTitle("Single charm editor");

    this->load();
}


void QCharm::load()
{
    m_equipmentType->setCurrentIndex(m_equipmentType->findData(charm->equipmentType));
    m_slotsCount->setValue(charm->slotsCount);
    m_identifier->setCurrentIndex(m_identifier->findData(charm->identifier));
    m_firstSkillIdentifier->setCurrentIndex(m_firstSkillIdentifier->findData(charm->firstSkillIdentifier));
    m_firstSkillValue->setValue(charm->firstSkillValue);
    m_secondSkillIdentifier->setCurrentIndex(m_secondSkillIdentifier->findData(charm->secondSkillIdentifier));
    m_secondSkillValue->setValue(charm->secondSkillValue);
    m_firstJewelIdentifier->setCurrentIndex(m_firstJewelIdentifier->findData(charm->firstJewelIdentifier));
    m_secondJewelIdentifier->setCurrentIndex(m_secondJewelIdentifier->findData(charm->secondJewelIdentifier));
    m_thirdJewelIdentifier->setCurrentIndex(m_thirdJewelIdentifier->findData(charm->thirdJewelIdentifier));
    m_foo81->setValue(charm->foo81);
    m_foo82->setValue(charm->foo82);
}

void QCharm::save()
{
    charm->equipmentType = (uint8_t) m_equipmentType->currentData().toInt();
    charm->slotsCount = m_slotsCount->value();
    charm->identifier = (uint16_t) m_identifier->currentData().toInt();
    charm->firstSkillIdentifier = (uint8_t) m_firstSkillIdentifier->currentData().toInt();
    charm->firstSkillValue = m_firstSkillValue->value();
    charm->secondSkillIdentifier = (uint8_t) m_secondSkillIdentifier->currentData().toInt();
    charm->secondSkillValue = m_secondSkillValue->value();
    charm->firstJewelIdentifier = (uint16_t) m_firstJewelIdentifier->currentData().toInt();
    charm->secondJewelIdentifier = (uint16_t) m_secondJewelIdentifier->currentData().toInt();
    charm->thirdJewelIdentifier = (uint16_t) m_thirdJewelIdentifier->currentData().toInt();
    charm->foo81 = m_foo81->value();
    charm->foo82 = m_foo82->value();
}

void QCharm::closeEvent(QCloseEvent *)
{
    save();

    charm = NULL;
}
