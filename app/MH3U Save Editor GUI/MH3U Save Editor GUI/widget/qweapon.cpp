#include "qweapon.hpp"

#include <QGridLayout>
#include <QLabel>

QWeapon::QWeapon(weapon_t *weapon, QWidget *parent) : QEquipment(NULL, parent)
{
    this->weapon = weapon;

    m_equipmentType = new QComboBox(this);
    m_equipmentType->addItem("(None)", 0);
    for (uint32_t i = 0; i < MH3U_DS::equipmentTypes()->size(); i++)
    {
        m_equipmentType->addItem(QString(MH3U_DS::equipmentTypes()->at(i).identifier.c_str()), MH3U_DS::equipmentTypes()->at(i).count);
    }

    m_foo12 = new QSpinBox(this);
    m_foo12->setMinimum(0x00);
    m_foo12->setMaximum(0xff);

    const dataset_t *identifier = NULL;
    switch ((equipment_type_e) weapon->equipmentType)
    {
        case MH3U_Type::GSType:
        {
            identifier = MH3U_DS::gsWeapons();
            break;
        }
        case MH3U_Type::SNSType:
        {
            identifier = MH3U_DS::snsWeapons();
            break;
        }
        case MH3U_Type::HType:
        {
            identifier = MH3U_DS::hWeapons();
            break;
        }
        case MH3U_Type::LType:
        {
            identifier = MH3U_DS::lWeapons();
            break;
        }
        case MH3U_Type::HBGType:
        {
            identifier = MH3U_DS::hbgWeapons();
            break;
        }
        case MH3U_Type::LBGType:
        {
            identifier = MH3U_DS::lbgWeapons();
            break;
        }
        case MH3U_Type::LSType:
        {
            identifier = MH3U_DS::lsWeapons();
            break;
        }
        case MH3U_Type::SAType:
        {
            identifier = MH3U_DS::saWeapons();
            break;
        }
        case MH3U_Type::GLType:
        {
            identifier = MH3U_DS::glWeapons();
            break;
        }
        case MH3U_Type::BowType:
        {
            identifier = MH3U_DS::bowWeapons();
            break;
        }
        case MH3U_Type::DBType:
        {
            identifier = MH3U_DS::dbWeapons();
            break;
        }
        case MH3U_Type::HHType:
        {
            identifier = MH3U_DS::hhWeapons();
            break;
        }
        default:
        {
            identifier = MH3U_DS::charms();
            break;
        }
    }

    m_identifier = new QComboBox(this);
    m_identifier->addItem("(None)", 0);
    for (uint32_t i = 0; i < identifier->size(); i++)
    {
        m_identifier->addItem(QString(identifier->at(i).identifier.c_str()), identifier->at(i).count);
    }
    identifier = NULL;

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
    layout->addWidget(new QLabel("Unknown", this), 0, 1);
    layout->addWidget(new QLabel("Identifier", this), 0, 2);
    layout->addWidget(new QLabel("Unknown", this), 0, 3);
    layout->addWidget(new QLabel("Unknown", this), 0, 4);
    layout->addWidget(new QLabel("Unknown", this), 0, 5);
    layout->addWidget(new QLabel("Unknown", this), 0, 6);
    layout->addWidget(new QLabel("First Jewel's Identifier", this), 0, 7);
    layout->addWidget(new QLabel("Second Jewel's Identifier", this), 0, 8);
    layout->addWidget(new QLabel("Third Jewel's Identifier", this), 0, 9);
    layout->addWidget(new QLabel("Unknown", this), 0, 10);
    layout->addWidget(new QLabel("Unknown", this), 0, 11);
    layout->addWidget(m_equipmentType, 1, 0);
    layout->addWidget(m_foo12, 1, 1);
    layout->addWidget(m_identifier, 1, 2);
    layout->addWidget(m_foo31, 1, 3);
    layout->addWidget(m_foo32, 1, 4);
    layout->addWidget(m_foo41, 1, 5);
    layout->addWidget(m_foo42, 1, 6);
    layout->addWidget(m_firstJewelIdentifier, 1, 7);
    layout->addWidget(m_secondJewelIdentifier, 1, 8);
    layout->addWidget(m_thirdJewelIdentifier, 1, 9);
    layout->addWidget(m_foo81, 1, 10);
    layout->addWidget(m_foo82, 1, 11);
    this->setLayout(layout);
    this->setWindowTitle("Single weapon editor");

    this->load();
}


void QWeapon::closeEvent(QCloseEvent *)
{
    save();

    weapon = NULL;
}


void QWeapon::load()
{
    m_equipmentType->setCurrentIndex(m_equipmentType->findData(weapon->equipmentType));
    m_foo12->setValue(weapon->foo12);
    m_identifier->setCurrentIndex(m_identifier->findData(weapon->identifier));
    m_foo31->setValue(weapon->foo31);
    m_foo32->setValue(weapon->foo32);
    m_foo41->setValue(weapon->foo41);
    m_foo42->setValue(weapon->foo42);
    m_firstJewelIdentifier->setCurrentIndex(m_firstJewelIdentifier->findData(weapon->firstJewelIdentifier));
    m_secondJewelIdentifier->setCurrentIndex(m_secondJewelIdentifier->findData(weapon->secondJewelIdentifier));
    m_thirdJewelIdentifier->setCurrentIndex(m_firstJewelIdentifier->findData(weapon->thirdJewelIdentifier));
    m_foo81->setValue(weapon->foo81);
    m_foo82->setValue(weapon->foo82);
}

void QWeapon::save()
{
    weapon->equipmentType = (uint8_t) m_equipmentType->currentData().toInt();
    weapon->foo12 = m_foo12->value();
    weapon->identifier = (uint16_t) m_identifier->currentData().toInt();
    weapon->foo31 = m_foo31->value();
    weapon->foo32 = m_foo32->value();
    weapon->foo41 = m_foo41->value();
    weapon->foo42 = m_foo42->value();
    weapon->firstJewelIdentifier = (uint16_t) m_firstJewelIdentifier->currentData().toInt();
    weapon->secondJewelIdentifier = (uint16_t) m_secondJewelIdentifier->currentData().toInt();
    weapon->thirdJewelIdentifier = (uint16_t) m_thirdJewelIdentifier->currentData().toInt();
    weapon->foo81 = m_foo81->value();
    weapon->foo82 = m_foo82->value();
}
