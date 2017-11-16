#include <QGuiApplication>
#include <Qt3DWindow>
#include <QHBoxLayout>


#include "view_3d_window.h"


int main(int argc, char **argv){
    QApplication app(argc, argv);
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
    View3DWindow *container = new View3DWindow();
    container->createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);

    View3DWindow *widget = new View3DWindow();
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);

    return app.exec();
}
