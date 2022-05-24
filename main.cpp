#include "Shop.h"
#include "widget.h"
#include "disk.h"
#include <QMessageBox>
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    w.resize(500, 500);
    return a.exec();
}
