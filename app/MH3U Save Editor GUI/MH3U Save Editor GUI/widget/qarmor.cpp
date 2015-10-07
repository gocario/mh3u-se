#include "qarmor.hpp"

#include <QGridLayout>
#include <QLabel>

QArmor::QArmor(armor_t *armor, QWidget *parent) : QEquipment(NULL, parent)
{
    this->armor = armor;

    m_equipmentType = new QComboBox(this);
    m_equipmentType->addItem("(None)", 0);
    for (uint32_t i = 0; i < MH3U_DS::equipmentTypes()->size(); i++)
    {
        m_equipmentType->addItem(QString(MH3U_DS::equipmentTypes()->at(i).identifier.c_str()), MH3U_DS::equipmentTypes()->at(i).count);
    }

    m_upgradeLevel = new QSpinBox(this);
    m_upgradeLevel->setMinimum(0x00);
    m_upgradeLevel->setMaximum(0xff);

    const dataset_t *identifier = NULL;
    switch ((equipment_type_e) armor->equipmentType)
    {
        case MH3U_Type::ChestType:
        {
            identifier = MH3U_DS::chestArmors();
            break;
        }
        case MH3U_Type::ArmsType:
        {
            identifier = MH3U_DS::armsArmors();
            break;
        }
        case MH3U_Type::WaistType:
        {
            identifier = MH3U_DS::waistArmors();
            break;
        }
        case MH3U_Type::LegsType:
        {
            identifier = MH3U_DS::legsArmors();
            break;
        }
        case MH3U_Type::HeadType:
        {
            identifier = MH3U_DS::headArmors();
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
    m_blueComponent = new QSpinBox(this);
    m_blueComponent->setMinimum(0x00);
    m_blueComponent->setMaximum(0xff);
    m_greenComponent = new QSpinBox(this);
    m_greenComponent->setMinimum(0x00);
    m_greenComponent->setMaximum(0xff);
    m_redComponent = new QSpinBox(this);
    m_redComponent->setMinimum(0x00);
    m_redComponent->setMaximum(0xff);

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
    layout->addWidget(new QLabel("Upgrade level", this), 0, 1);
    layout->addWidget(new QLabel("Identifier", this), 0, 2);
    layout->addWidget(new QLabel("Unknown", this), 0, 3);
    layout->addWidget(new QLabel("Blue Component", this), 0, 4);
    layout->addWidget(new QLabel("Green Component", this), 0, 5);
    layout->addWidget(new QLabel("Red Component", this), 0, 6);
    layout->addWidget(new QLabel("First Jewel's Identifier", this), 0, 7);
    layout->addWidget(new QLabel("Second Jewel's Identifier", this), 0, 8);
    layout->addWidget(new QLabel("Third Jewel's Identifier", this), 0, 9);
    layout->addWidget(new QLabel("Unknown", this), 0, 10);
    layout->addWidget(new QLabel("Unknown", this), 0, 11);
    layout->addWidget(m_equipmentType, 1, 0);
    layout->addWidget(m_upgradeLevel, 1, 1);
    layout->addWidget(m_identifier, 1, 2);
    layout->addWidget(m_foo31, 1, 3);
    layout->addWidget(m_blueComponent, 1, 4);
    layout->addWidget(m_greenComponent, 1, 5);
    layout->addWidget(m_redComponent, 1, 6);
    layout->addWidget(m_firstJewelIdentifier, 1, 7);
    layout->addWidget(m_secondJewelIdentifier, 1, 8);
    layout->addWidget(m_thirdJewelIdentifier, 1, 9);
    layout->addWidget(m_foo81, 1, 10);
    layout->addWidget(m_foo82, 1, 11);
    this->setLayout(layout);
    this->setWindowTitle("Single armor editor");

    this->load();
}


void QArmor::closeEvent(QCloseEvent *)
{
    save();

    armor = NULL;
}


void QArmor::load()
{
    m_equipmentType->setCurrentIndex(m_equipmentType->findData(armor->equipmentType));
    m_upgradeLevel->setValue(armor->upgradeLevel);
    m_identifier->setCurrentIndex(m_identifier->findData(armor->identifier));
    m_foo31->setValue(armor->foo31);
    m_blueComponent->setValue(armor->blueComponent);
    m_greenComponent->setValue(armor->greenComponent);
    m_redComponent->setValue(armor->redComponent);
    m_firstJewelIdentifier->setCurrentIndex(m_firstJewelIdentifier->findData(armor->firstJewelIdentifier));
    m_secondJewelIdentifier->setCurrentIndex(m_secondJewelIdentifier->findData(armor->secondJewelIdentifier));
    m_thirdJewelIdentifier->setCurrentIndex(m_firstJewelIdentifier->findData(armor->thirdJewelIdentifier));
    m_foo81->setValue(armor->foo81);
    m_foo82->setValue(armor->foo82);
}

void QArmor::save()
{
    armor->equipmentType = (uint8_t) m_equipmentType->currentData().toInt();
    armor->upgradeLevel = m_upgradeLevel->value();
    armor->identifier = (uint16_t) m_identifier->currentData().toInt();
    armor->foo31 = m_foo31->value();
    armor->blueComponent = m_blueComponent->value();
    armor->greenComponent = m_greenComponent->value();
    armor->redComponent = m_redComponent->value();
    armor->firstJewelIdentifier = (uint16_t) m_firstJewelIdentifier->currentData().toInt();
    armor->secondJewelIdentifier = (uint16_t) m_secondJewelIdentifier->currentData().toInt();
    armor->thirdJewelIdentifier = (uint16_t) m_thirdJewelIdentifier->currentData().toInt();
    armor->foo81 = m_foo81->value();
    armor->foo82 = m_foo82->value();
}
