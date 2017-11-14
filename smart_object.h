#ifndef SMART_OBJECT_H
#define SMART_OBJECT_H

#include <qmesh.h>
#include <QMouseEvent>
#include <QComponent>

class SmartObject: public Qt3DRender::QMesh
{
    Q_OBJECT

public:
    SmartObject();
    ~SmartObject();

    int id;
    Qt3DCore::QEntity *entity;

public slots:
    void setId(int id);
    int getId();
    void setSource(QUrl url);
    Qt3DCore::QEntity getParentEntity();
    void setParentEntity(Qt3DCore::QEntity *entity);
private:
    QVector2D getPos(QMatrix projectionMatrix, QMatrix viewMatrix, QVector3D point3D, QVector2D viewSize, QVector2D viewOffset);
};

#endif // SMART_OBJECT_H
