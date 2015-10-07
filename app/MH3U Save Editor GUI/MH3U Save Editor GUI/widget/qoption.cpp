#include "qoption.hpp"

#include <QGridLayout>
#include <QLabel>

QOption::QOption(QWidget *parent) : QDialog(parent)
{
    m_languageButton = new QComboBox();
    m_languageButton->addItem("English", LANG_EN);
    m_languageButton->addItem("French", LANG_FR);

    QGridLayout *layout = new QGridLayout(this);
    layout->addWidget(new QLabel("Language", this), 0, 0);
    layout->addWidget(m_languageButton, 1, 0);
    this->setLayout(layout);
    this->setWindowTitle("MH3U - Options");

    this->load();
}


void QOption::closeEvent(QCloseEvent *)
{
    this->save();
}


void QOption::load()
{
    m_languageButton->setCurrentIndex(m_languageButton->findData(MH3U_DS::lang()));
}

void QOption::save()
{
    MH3U_DS::readData((lang_t) m_languageButton->currentData().toUInt());
}
