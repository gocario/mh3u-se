#ifndef QCHARM_HPP
#define QCHARM_HPP

#include "main.hpp"

#include "qequipment.hpp"

#include <QWidget>
#include <QDialog>
#include <QSpinBox>
#include <QComboBox>

class QCharm : public QEquipment
{
    Q_OBJECT
public:
    explicit QCharm(charm_t *charm, QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *);

private:
    charm_t *charm;
    QComboBox *m_equipmentType;
    QSpinBox *m_slotsCount;
    QComboBox *m_identifier;
    QComboBox *m_firstSkillIdentifier;
    QSpinBox *m_firstSkillValue;
    QComboBox *m_secondSkillIdentifier;
    QSpinBox *m_secondSkillValue;
    QComboBox *m_firstJewelIdentifier;
    QComboBox *m_secondJewelIdentifier;
    QComboBox *m_thirdJewelIdentifier;
    QSpinBox *m_foo81;
    QSpinBox *m_foo82;

    void load();
    void save();
};

#endif // QCHARM_HPP
