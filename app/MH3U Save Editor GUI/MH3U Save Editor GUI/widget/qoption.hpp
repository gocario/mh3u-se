#ifndef QOPTION_H
#define QOPTION_H

#include <QDialog>
#include <QComboBox>

#include "../../MH3U Save Editor/MH3U Save Editor/mh3u_ds.hpp"

class QOption : public QDialog
{
    Q_OBJECT
public:
    explicit QOption(QWidget *parent = 0);

protected:
    void closeEvent(QCloseEvent *);

private:
    QComboBox *m_languageButton;

    void load();
    void save();
};

#endif // QOPTION_H
