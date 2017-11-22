#ifndef WINDOW_H
#define WINDOW_H

#include "glwidget.h"

#include <qwidget.h>

class MainWindow;

class Window : public QWidget
{
    Q_OBJECT
public:
    Window(MainWindow *mw);

private:
    MainWindow *mainWindow;
    GlWidget *glwidget;
};

#endif // WINDOW_H
