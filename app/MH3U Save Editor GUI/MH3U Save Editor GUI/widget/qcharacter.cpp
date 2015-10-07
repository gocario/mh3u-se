#include "qcharacter.hpp"

#include <QGridLayout>
#include <QLabel>

QCharacter::QCharacter(MH3U_SE *mh3u, QWidget *parent) : QDialog(parent)
{
    this->mh3u = mh3u;

    m_sexs = new QComboBox(this);
    for (uint32_t i = 0; i < MH3U_DS::sexs()->size(); i++)
    {
        m_sexs->addItem(QString(MH3U_DS::sexs()->at(i).identifier.c_str()), MH3U_DS::sexs()->at(i).count);
    }

    m_faces = new QComboBox(this);
    for (uint32_t i = 0; i < MH3U_DS::faces()->size(); i++)
    {
        m_faces->addItem(QString(MH3U_DS::faces()->at(i).identifier.c_str()), MH3U_DS::faces()->at(i).count);
    }

    m_hairs = new QComboBox(this);
    for (uint32_t i = 0; i < MH3U_DS::hairs()->size(); i++)
    {
        m_hairs->addItem(QString(MH3U_DS::hairs()->at(i).identifier.c_str()), MH3U_DS::hairs()->at(i).count);
    }

    m_name = new QLineEdit(this);
    m_name->setMaxLength(NAME_SIZE);
    m_money = new QSpinBox(this);
    m_money->setMinimum(0x0000000);
    m_money->setMaximum(0xfffffff);

    m_voices = new QComboBox(this);
    for (uint32_t i = 0; i < MH3U_DS::voices()->size(); i++)
    {
        m_voices->addItem(QString(MH3U_DS::voices()->at(i).identifier.c_str()), MH3U_DS::voices()->at(i).count);
    }

    m_mogapoint = new QSpinBox(this);
    m_mogapoint->setMinimum(0x0000000);
    m_mogapoint->setMaximum(0xfffffff);


    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(new QLabel("Sex", this), 0, 0);
    layout->addWidget(new QLabel("Face", this), 0, 1);
    layout->addWidget(new QLabel("Hairstyle", this), 0, 2);
    layout->addWidget(new QLabel("Name", this), 0, 3);
    layout->addWidget(new QLabel("Money", this), 0, 4);
    layout->addWidget(new QLabel("Voice", this), 0, 5);
    layout->addWidget(new QLabel("Moga Point", this), 0, 6);
    layout->addWidget(m_sexs, 1, 0);
    layout->addWidget(m_faces, 1, 1);
    layout->addWidget(m_hairs, 1, 2);
    layout->addWidget(m_name, 1, 3);
    layout->addWidget(m_money, 1, 4);
    layout->addWidget(m_voices, 1, 5);
    layout->addWidget(m_mogapoint, 1, 6);
    this->setLayout(layout);
    this->setWindowTitle("Character data editor");

    this->load();
}

QCharacter::~QCharacter()
{
    this->mh3u = NULL;
}


void QCharacter::load()
{
    m_sexs->setCurrentIndex(m_sexs->findData(mh3u->savedata->sex +1));
    m_faces->setCurrentIndex(m_faces->findData(mh3u->savedata->face +1));
    m_hairs->setCurrentIndex(m_hairs->findData(mh3u->savedata->hair +1));
    m_name->setText(reinterpret_cast<const char*>(mh3u->savedata->name));
    m_money->setValue(mh3u->savedata->money);
    m_voices->setCurrentIndex(m_voices->findData(mh3u->savedata->voice +1));
    m_mogapoint->setValue(mh3u->savedata->mogapoint);
}

void QCharacter::save()
{
    mh3u->savedata->sex = m_sexs->currentData().toInt() -1;
    mh3u->savedata->face = m_faces->currentData().toInt() -1;
    mh3u->savedata->hair = m_hairs->currentData().toInt() -1;
    strncpy((char*) mh3u->savedata->name, m_name->text().toStdString().c_str(), NAME_SIZE);
    mh3u->savedata->money = m_money->value();
    mh3u->savedata->voice = m_voices->currentData().toInt() -1;
    mh3u->savedata->mogapoint = m_mogapoint->value();
}

void QCharacter::closeEvent(QCloseEvent *)
{
    save();
}
