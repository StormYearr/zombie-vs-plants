#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MainWindowServer serverWindow;
    serverWindow.show();



    return app.exec();
}
