#ifndef QEQUIPMENT_HPP
#define QEQUIPMENT_HPP

#include "main.hpp"

#include <QWidget>
#include <QDialog>
#include <QSpinBox>
#include <QComboBox>

class QEquipment : public QDialog
{
    Q_OBJECT
public:
    explicit QEquipment(equipment_t *equipment, QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *);

private:
    equipment_t *equipment;
    QComboBox *m_equipmentType;
    QSpinBox *m_foo12;
    QSpinBox *m_foo21;
    QSpinBox *m_foo22;
    QSpinBox *m_foo31;
    QSpinBox *m_foo32;
    QSpinBox *m_foo41;
    QSpinBox *m_foo42;
    QSpinBox *m_foo51;
    QSpinBox *m_foo52;
    QSpinBox *m_foo61;
    QSpinBox *m_foo62;
    QSpinBox *m_foo71;
    QSpinBox *m_foo72;
    QSpinBox *m_foo81;
    QSpinBox *m_foo82;

    void load();
    void save();
};

#endif // QEQUIPMENT_HPP
