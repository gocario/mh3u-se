#ifndef QWEAPON_H
#define QWEAPON_H

#include "main.hpp"

#include "qequipment.hpp"

#include <QWidget>
#include <QDialog>

class QWeapon : public QEquipment
{
    Q_OBJECT
public:
    explicit QWeapon(weapon_t *weapon, QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *);

private:
    weapon_t *weapon;
    QComboBox *m_equipmentType;
    QSpinBox *m_foo12;
    QComboBox *m_identifier;
    QSpinBox *m_foo31;
    QSpinBox *m_foo32;
    QSpinBox *m_foo41;
    QSpinBox *m_foo42;
    QComboBox *m_firstJewelIdentifier;
    QComboBox *m_secondJewelIdentifier;
    QComboBox *m_thirdJewelIdentifier;
    QSpinBox *m_foo81;
    QSpinBox *m_foo82;

    void load();
    void save();
};

#endif // QWEAPON_H
