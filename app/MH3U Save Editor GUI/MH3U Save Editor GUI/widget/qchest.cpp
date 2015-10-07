#include "qchest.hpp"

#include <QSignalMapper>
#include <QGridLayout>
#include <QPushButton>
#include <QTabWidget>

QChest::QChest(MH3U_SE *mh3u, QWidget *parent) : QWidget(parent)
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
            m_buttons[i][j] = new QPushButton(QString::number(mh3u->savedata->chest[i][j].id), tab);
            m_buttons[i][j]->setFixedHeight(32);
            m_buttons[i][j]->setFixedWidth(32);

            tab_layout->addWidget(m_buttons[i][j], j / 10, j % 10);

            signalMapper->setMapping(m_buttons[i][j], i * 100 + j);
            connect(m_buttons[i][j], SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
        }
    }

    QLayout *main_layout = new QGridLayout(this);
    main_layout->addWidget(tabs);
    this->setLayout(main_layout);
    this->setWindowTitle("Chest editor");
}

QChest::~QChest()
{
    this->mh3u = NULL;
}


void QChest::buttonClicked(int id)
{
    // std::cout << "Button " << id << " clicked!" << std::endl;

    QItem *qitem = new QItem(&(this->mh3u->savedata->chest[id / 100][id % 100]), this);
    qitem->setModal(true);
    qitem->exec();

    m_buttons[id / 100][id % 100]->setText(QString::number(this->mh3u->savedata->chest[id / 100][id % 100].id));
}
