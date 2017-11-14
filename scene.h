#ifndef SCENE_H
#define SCENE_H

#include <QtCore/QObject>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QConeMesh>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QPhongMaterial>
#include "smart_object.h"

class Scene : public QObject
{
    Q_OBJECT

public:
    explicit Scene(Qt3DCore::QEntity *rootEntity);
    ~Scene();

public slots:
    void addMesh(SmartObject *smart);
    void deleteMesh(SmartObject *smart);

private:
    Qt3DCore::QEntity *m_rootEntity;
    Qt3DCore::QEntity addMeshEntity();
    void deleteMeshEntity(Qt3DCore::QEntity *entity);
};

#endif // SCENE_H
