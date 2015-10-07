#ifndef QCHARACTER_HPP
#define QCHARACTER_HPP

#include "main.hpp"

#include <QDialog>
#include <QSpinBox>
#include <QComboBox>
#include <QLineEdit>

class QCharacter : public QDialog
{
    Q_OBJECT
public:
    explicit QCharacter(MH3U_SE *mh3u, QWidget *parent = 0);
    ~QCharacter();

protected:
    void closeEvent(QCloseEvent *);

private:
    MH3U_SE *mh3u;
    QComboBox *m_sexs;
    QComboBox *m_faces;
    QComboBox *m_hairs;
    QLineEdit *m_name;
    QSpinBox *m_money;
    QComboBox *m_voices;
    QSpinBox *m_mogapoint;

    void load();
    void save();
};

#endif // QCHARACTER_HPP
