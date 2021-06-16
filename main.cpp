#include "shoyu.h"

#include <sodium.h>
#include <iostream>
using namespace std;
#include <QApplication>

int main(int argc, char *argv[])
{
    if (sodium_init() < 0) {
        cout << "Error on libsodium init!\n";
        return -1;
    }
    QApplication a(argc, argv);
    shoyu w;
    w.show();
    return a.exec();
}
