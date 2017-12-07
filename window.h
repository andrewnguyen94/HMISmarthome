#ifndef WINDOW_H
#define WINDOW_H

#include <qwidget.h>

using namespace std;
QT_BEGIN_NAMESPACE
class QComboBox;
QT_END_NAMESPACE

class MainWindow;
class GlWidget;

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
