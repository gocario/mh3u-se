#include "qbox.hpp"

#include <QSignalMapper>
#include <QGridLayout>
#include <QPushButton>
#include <QTabWidget>

QBox::QBox(MH3U_SE *mh3u, QWidget *parent) : QWidget(parent)
{
    this->mh3u = mh3u;

    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(buttonClicked(int)));

    QTabWidget *tabs = new QTabWidget(this);
    QWidget *tab;
    QGridLayout *tab_layout;
    for (uint32_t i = 0; i < 10; i++)
    {
        tab = new QWidget(this);
        tabs->addTab(tab, QString("Panel ") + QString::number(i+1));

        tab_layout = new QGridLayout(tab);
        tab->setLayout(tab_layout);

        for (uint32_t j = 0; j < 100; j++)
        {
            m_buttons[i][j] = new QPushButton(QString::number(mh3u->savedata->box[i][j][2] + mh3u->savedata->box[i][j][3] * 0x100), tab);
            m_buttons[i][j]->setFixedHeight(48);
            m_buttons[i][j]->setFixedWidth(48);

            tab_layout->addWidget(m_buttons[i][j], j / 10, j % 10);

            signalMapper->setMapping(m_buttons[i][j], i * 100 + j);
            connect(m_buttons[i][j], SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
        }
    }

    QLayout *main_layout = new QGridLayout(this);
    main_layout->addWidget(tabs);
    this->setLayout(main_layout);
    this->setWindowTitle("Box editor");
}

QBox::~QBox()
{
    this->mh3u = NULL;
}

void QBox::buttonClicked(int id)
{
    equipment_type_e newType(MH3U_Type::NoneType), oldType(MH3U_Type::NoneType);
    equipment_subtype_e subtype;

    do
    {
        oldType = (equipment_type_e) this->mh3u->savedata->box[id / 100][id % 100][0];
        subtype = MH3U_Armory::convertSubtype(oldType);

        switch (subtype)
        {
            case MH3U_Type::ArmorSubtype:
            {
                armor_t armor = MH3U_Armory::convertEquipmentToArmor(this->mh3u->savedata->box[id / 100][id % 100]);

                QArmor *qarmor = new QArmor(&armor, this);
                qarmor->setModal(true);
                qarmor->exec();

                MH3U_Armory::convertArmorToEquipment(armor, this->mh3u->savedata->box[id / 100][id % 100]);
                break;
            }
            case MH3U_Type::CharmSubtype:
            {
                charm_t charm = MH3U_Armory::convertEquipmentToCharm(this->mh3u->savedata->box[id / 100][id % 100]);

                QCharm *qcharm = new QCharm(&charm, this);
                qcharm->setModal(true);
                qcharm->exec();

                MH3U_Armory::convertCharmToEquipment(charm, this->mh3u->savedata->box[id / 100][id % 100]);
                break;
            }
            case MH3U_Type::WeaponSubtype:
            {
                std::cout << "Weapon!" << std::endl;

                weapon_t weapon = MH3U_Armory::convertEquipmentToWeapon(this->mh3u->savedata->box[id / 100][id % 100]);

                QWeapon *qweapon = new QWeapon(&weapon, this);
                qweapon->setModal(true);
                qweapon->exec();

                MH3U_Armory::convertWeaponToEquipment(weapon, this->mh3u->savedata->box[id / 100][id % 100]);

                break;
            }
            default:
            {
                QEquipment *qequipment = new QEquipment(&(this->mh3u->savedata->box[id / 100][id % 100]), this);
                qequipment->setModal(true);
                qequipment->exec();
                break;
            }
        }

        newType = (equipment_type_e) this->mh3u->savedata->box[id / 100][id % 100][0];

    } while (oldType != newType);

    m_buttons[id / 100][id % 100]->setText(QString::number(this->mh3u->savedata->box[id / 100][id % 100][2] + this->mh3u->savedata->box[id / 100][id % 100][3] * 0x100));
}
