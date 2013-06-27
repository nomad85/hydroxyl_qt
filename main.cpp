#include "dialog.h"
#include <QApplication>
#include "initwindow.h"
#include "managewindow.h"
#include "optionswindow.h"
#include "exitwindow.h"
#include "hydroxyl.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ManageWindow* manageWindow = new ManageWindow();
    Hydroxyl*  hydroxyl = new Hydroxyl();
    InitWindow *initWindow = new InitWindow();
    initWindow->showFullScreen();
    initWindow->setManageWindow(*manageWindow);
//    OptionsWindow* optionsWindow = new OptionsWindow();
//    optionsWindow->showFullScreen();
    return a.exec();
}
