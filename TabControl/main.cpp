#include "tabcontrol.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    TabControl w;


//    QFile style(":/style.qss");
//    if(style.open(QIODeviceBase::ReadOnly))
//    {
//        w.setStyleSheet(style.readAll());
//    }

    w.show();
    return a.exec();
}
