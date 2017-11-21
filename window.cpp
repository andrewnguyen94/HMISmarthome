#include "window.h"
#include "qlayout.h"

Window::Window(MainWindow *mw) :
    mainWindow(mw)
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *container = new QHBoxLayout;
    container->addWidget();
}
