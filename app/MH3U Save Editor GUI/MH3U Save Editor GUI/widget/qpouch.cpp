#include "qpouch.hpp"

#include <QSignalMapper>
#include <QGridLayout>
#include <QPushButton>
#include <QTabWidget>

QPouch::QPouch(MH3U_SE *mh3u, QWidget *parent) : QWidget(parent)
{
    this->mh3u = mh3u;

    QSignalMapper *signalMapper = new QSignalMapper(this);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(buttonClicked(int)));

    QTabWidget *tabs = new QTabWidget(this);
    QWidget *tab;
    QGridLayout *tab_layout;
    for (uint32_t i = 0; i < 4; i++)
    {
        tab = new QWidget(this);
        tabs->addTab(tab, QString("Panel ") + QString::number(i+1));

        tab_layout = new QGridLayout(tab);
        tab->setLayout(tab_layout);

        for (uint32_t j = 0; j < 8; j++)
        {
            m_buttons[i][j] = new QPushButton(QString::number(mh3u->savedata->pouch[i][j].id), tab);
            m_buttons[i][j]->setFixedHeight(32);
            m_buttons[i][j]->setFixedWidth(32);

            tab_layout->addWidget(m_buttons[i][j]);

            signalMapper->setMapping(m_buttons[i][j], i * 8 + j);
            connect(m_buttons[i][j], SIGNAL(clicked(bool)), signalMapper, SLOT(map()));
        }
    }

    QLayout *main_layout = new QGridLayout(this);
    main_layout->addWidget(tabs);
    this->setLayout(main_layout);
    this->setWindowTitle("Pouch editor");
}

QPouch::~QPouch()
{
    this->mh3u = NULL;
}


void QPouch::buttonClicked(int id)
{
    // std::cout << "Button " << id << " clicked!" << std::endl;

    QItem *qitem = new QItem(&(this->mh3u->savedata->pouch[id / 8][id % 8]), this);
    qitem->setModal(true);
    qitem->exec();

    m_buttons[id / 8][id % 8]->setText(QString::number(this->mh3u->savedata->pouch[id / 8][id % 8].id));
}
