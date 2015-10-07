#include "mh3u_sv.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

#include <QFileDialog>

//#define DEBUG

MH3U_SV::MH3U_SV(QWidget *parent) : QWidget(parent)
{
    if (!MH3U_DS::readData(LANG_EN))
    {
        MH3U_DS::deleteData();
        return;
    }

    this->mh3u = new MH3U_SE();

#ifdef DEBUG
    this->mh3u->load("H:/Users/Gocario/Documents/Monster Hunter/Monster Hunter 3 Ultimate/save/analyse/user3_eq_2");
#endif

    characterButton = new QPushButton("Character", this);
    connect(characterButton, SIGNAL(clicked(bool)), this, SLOT(openQCharacter()));
    inventoryButton = new QPushButton("Inventory", this);
    connect(inventoryButton, SIGNAL(clicked(bool)), this, SLOT(openQInventory()));
    pouchButton = new QPushButton("Pouch", this);
    connect(pouchButton, SIGNAL(clicked(bool)), this, SLOT(openQPouch()));
    chestButton = new QPushButton("Chest", this);
    connect(chestButton, SIGNAL(clicked(bool)), this, SLOT(openQChest()));
    boxButton = new QPushButton("Box", this);
    connect(boxButton, SIGNAL(clicked(bool)), this, SLOT(openQBox()));

    optButton = new QPushButton("Options", this);
    connect(optButton, SIGNAL(clicked(bool)), this, SLOT(openQOptions()));
    loadButton = new QPushButton("Load file", this);
    connect(loadButton, SIGNAL(clicked(bool)), this, SLOT(loadFile()));
    saveButton = new QPushButton("Save file", this);
    connect(saveButton, SIGNAL(clicked(bool)), this, SLOT(saveFile()));

    QHBoxLayout *saveloadLayout = new QHBoxLayout();
    saveloadLayout->addWidget(loadButton);
    saveloadLayout->addWidget(saveButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addWidget(characterButton);
    mainLayout->addWidget(inventoryButton);
    mainLayout->addWidget(pouchButton);
    mainLayout->addWidget(chestButton);
    mainLayout->addWidget(boxButton);
    mainLayout->addSpacing(10);
    mainLayout->addWidget(optButton);
    mainLayout->addLayout(saveloadLayout);
    this->setLayout(mainLayout);
    this->setWindowTitle("MH3U - Save viewer/editor");

    this->refresh();
}

MH3U_SV::~MH3U_SV()
{
    MH3U_DS::deleteData();
    cdelete(mh3u);
}


void MH3U_SV::refresh()
{
    if (this->mh3u->loaded())
    {
        characterButton->setDisabled(false);
        inventoryButton->setDisabled(false);
        pouchButton->setDisabled(false);
        chestButton->setDisabled(false);
        boxButton->setDisabled(false);
        optButton->setDisabled(false);
        loadButton->setDisabled(false);
        saveButton->setDisabled(false);
    }
    else
    {
        characterButton->setDisabled(true);
        inventoryButton->setDisabled(true);
        pouchButton->setDisabled(true);
        chestButton->setDisabled(true);
        boxButton->setDisabled(true);
        optButton->setDisabled(false);
        loadButton->setDisabled(false);
        saveButton->setDisabled(true);
    }
}


void MH3U_SV::openQCharacter()
{
    QCharacter *qView = new QCharacter(this->mh3u);
    qView->setModal(true);
    qView->show();
}

void MH3U_SV::openQInventory()
{
    QInventory *qView = new QInventory(this->mh3u);
    qView->show();
}

void MH3U_SV::openQPouch()
{
    QPouch *qView = new QPouch(this->mh3u);
    qView->show();
}

void MH3U_SV::openQChest()
{
    QChest *qView = new QChest(this->mh3u);
    qView->show();
}

void MH3U_SV::openQBox()
{
    QBox *qView = new QBox(this->mh3u);
    qView->show();
}


void MH3U_SV::openQOptions()
{
    QOption *qOption = new QOption();
    qOption->setModal(true);
    qOption->show();
}

void MH3U_SV::loadFile()
{
    std::cout << "Loading file!" << std::endl;

    QString filename = QFileDialog::getOpenFileName(this, "Ouvrir un fichier", QString(), "User files (user1;user2;user3);;All files (*)");

    if (!filename.isNull())
    {
        mh3u->load(filename.toStdString());
    }

    this->refresh();
}

void MH3U_SV::saveFile()
{
    std::cout << "Writing file!" << std::endl;

    QString filename = QFileDialog::getSaveFileName(this, "Ouvrir un fichier", QString(), "User files (user1;user2;user3);;All files (*)");

    if (!filename.isNull())
    {
        mh3u->save(filename.toStdString());
    }

    this->refresh();
}
