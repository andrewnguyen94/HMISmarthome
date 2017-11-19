#include <QGuiApplication>
#include <Qt3DWindow>
#include <QHBoxLayout>
#include <QTreeWidget>

#include "view_3d_window.h"
#include "scene.h"
#include "treecombo.h"
#include "arraylist.h"

int main(int argc, char **argv){
    std::vector <string> labels;
    QApplication app(argc, argv);
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
    QWidget *container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);

    View3DWindow *widget = new View3DWindow();
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);
    widget->setWindowTitle(QStringLiteral("HMISmarthome"));

    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
    view->registerAspect(input);

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

    Qt3DRender::QCamera *cameraEntity = view->camera();

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    Scene *scene = new Scene(rootEntity);
    view->setRootEntity(rootEntity);

    QComboBox *smart_object_labels = new QComboBox(widget);
    labels.push_back("air conditional");
    labels.push_back("television");
    labels.push_back("lights");
    for(int i = 0; i < labels.size(); i++){
        QString str = QString::fromUtf8(labels[i].c_str());
        smart_object_labels->addItem(str);
    }
    vLayout->addWidget(smart_object_labels);

    return app.exec();
}



