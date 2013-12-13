#include "CQmlGui.h"
#include "Test.h"
#include <QApplication>
#include <QDebug>
#include <QOffscreenSurface>

int main(int argc, char **argv)
{
    Q_UNUSED(argc)
    Q_UNUSED(argv)

    QApplication *app;
    app = new QApplication(argc, argv);

    Test *test;
    test = new Test();

    CQmlGui *qmlGui;
    qmlGui = new CQmlGui("data/QML/test.qml", 800, 600, QWindow::fromWinId(test->getWinID()));
    qmlGui->show();

    qmlGui->connect(qmlGui, SIGNAL(beforeSynchronizing()), test, SLOT(paintSFML()), Qt::DirectConnection);

    while(test->update())
        continue;

    /*int returnCode;
    returnCode = app->exec();*/

    delete qmlGui;
    delete test;

    //return returnCode;
    return 0;
}
