#include "shoyu.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    shoyu w;
    w.show();
    return a.exec();
}
