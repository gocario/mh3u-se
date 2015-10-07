#include "main.hpp"

#include "mh3u_sv.hpp"
#include "widget/qinventory.hpp"
#include "widget/qpouch.hpp"
#include "widget/qchest.hpp"
#include "widget/qbox.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MH3U_SV w;
    w.show();

    return a.exec();
}
