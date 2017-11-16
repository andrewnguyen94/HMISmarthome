#ifndef SMART_OBJECT_H
#define SMART_OBJECT_H

#include <qmesh.h>
#include <QMouseEvent>
#include <QComponent>
#include <qentity.h>
#include <qtransform.h>
#include <QMaterial>

class SmartObject: public Qt3DRender::QMesh
{
    Q_OBJECT

public:
    SmartObject();
    ~SmartObject();

    int id;
    Qt3DCore::QEntity *entity;
    char *name;
    Qt3DCore::QTransform *transform;
    Qt3DRender::QMaterial *material;

public slots:
    void setId(int id);
    int getId();
    void setName(char *name_object);
    char* getName();
    void setSource(QUrl url);
    Qt3DCore::QEntity* getParentEntity();
    void setParentEntity(Qt3DCore::QEntity *entity_parent);
    Qt3DCore::QTransform* createTransform();
    void setTransform(Qt3DCore::QTransform* transform_add);
    Qt3DCore::QTransform* getTransform();
    Qt3DRender::QMaterial *createMaterial();
    void setMaterial(Qt3DRender::QMaterial *material_set);
    Qt3DRender::QMaterial* getMaterial();

private:
    QVector2D getPos(QMatrix projectionMatrix, QMatrix viewMatrix, QVector3D point3D, QVector2D viewSize, QVector2D viewOffset);
};

#endif // SMART_OBJECT_H
