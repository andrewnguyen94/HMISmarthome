#include "window.h"
#include "qlayout.h"
#include "glwidget.h"
#include "view_3d_window.h"

#include <QComboBox>

using namespace std ;
Window::Window(MainWindow *mw) :
    mainWindow(mw)
{
    vector <string> labels;
    View3DWindow *widget = new View3DWindow();
    glwidget = new GlWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;
    QHBoxLayout *container = new QHBoxLayout(widget);
    mainLayout->setAlignment(Qt::AlignTop);
    container->addWidget(glwidget, 1);
    container->addLayout(mainLayout);

    QComboBox *smart_object_labels = new QComboBox(widget);
    labels.push_back("air conditional");
    labels.push_back("television");
    labels.push_back("lights");
    for(int i = 0; i < labels.size(); i++){
        QString str = QString::fromUtf8(labels[i].c_str());
        smart_object_labels->addItem(str);
    }
    mainLayout->addWidget(smart_object_labels);

    widget->setWindowTitle("HMI Smarthome");

    widget->show();
}
