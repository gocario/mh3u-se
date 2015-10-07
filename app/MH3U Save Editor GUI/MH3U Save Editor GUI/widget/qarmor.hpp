#ifndef QARMOR_HPP
#define QARMOR_HPP

#include "main.hpp"

#include "qequipment.hpp"

#include <QWidget>
#include <QDialog>
#include <QSpinBox>
#include <QComboBox>

class QArmor : public QEquipment
{
    Q_OBJECT
public:
    explicit QArmor(armor_t *armor, QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *);

private:
    armor_t *armor;
    QComboBox *m_equipmentType;
    QSpinBox *m_upgradeLevel;
    QComboBox *m_identifier;
    QSpinBox *m_foo31;
    QSpinBox *m_blueComponent;
    QSpinBox *m_greenComponent;
    QSpinBox *m_redComponent;
    QComboBox *m_firstJewelIdentifier;
    QComboBox *m_secondJewelIdentifier;
    QComboBox *m_thirdJewelIdentifier;
    QSpinBox *m_foo81;
    QSpinBox *m_foo82;

    void load();
    void save();
};

#endif // QARMOR_HPP
