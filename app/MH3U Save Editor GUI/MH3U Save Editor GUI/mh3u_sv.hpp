#ifndef MH3U_SV_HPP
#define MH3U_SV_HPP

#include "main.hpp"

#include "widget/qcharacter.hpp"
#include "widget/qinventory.hpp"
#include "widget/qpouch.hpp"
#include "widget/qchest.hpp"
#include "widget/qbox.hpp"

#include "widget/qoption.hpp"

#include <QWidget>

class MH3U_SV : public QWidget
{
    Q_OBJECT
public:
    explicit MH3U_SV(QWidget *parent = 0);
    ~MH3U_SV();

    void refresh();

private:
    MH3U_SE *mh3u;
    QPushButton *characterButton;
    QPushButton *inventoryButton;
    QPushButton *pouchButton;
    QPushButton *chestButton;
    QPushButton *boxButton;
    QPushButton *optButton;
    QPushButton *loadButton;
    QPushButton *saveButton;

public slots:
    void openQCharacter();
    void openQInventory();
    void openQPouch();
    void openQChest();
    void openQBox();

    void openQOptions();

    void loadFile();
    void saveFile();
};

#endif // MH3U_SV_HPP
