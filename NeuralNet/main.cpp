#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    srand (time(NULL) );
    QApplication a(argc, argv);
    MainWindow w(&a);

    w.show();
    return a.exec();

}
