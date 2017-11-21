#include "scene.h"
#include "smart_object.h"
#include "view_3d_window.h"

#include <QtCore/QDebug>
#include <QMouseEvent>

//m_rootEntity is the root of all entities
Scene::Scene(Qt3DCore::QEntity *rootEntity)
    : m_rootEntity(rootEntity){

}

//add new mesh into scene3d
void Scene::addMesh(SmartObject *smart)
{
    Qt3DCore::QEntity *meshEntity = addMeshEntity();
    meshEntity->addComponent(smart);
    smart->setParentEntity(meshEntity);
}

// delete the mesh that add into entity and scene3d
void Scene::deleteMesh(SmartObject *smart)
{
    Qt3DCore::QEntity *parent = smart->getParentEntity();
    parent->removeComponent(smart);
}

//add new entity to wrap the mesh
Qt3DCore::QEntity* Scene::addMeshEntity()
{
    Qt3DCore::QEntity *newEntity;
    newEntity = new Qt3DCore::QEntity(m_rootEntity);
    return newEntity;
}

//remove the entity that wrap the mesh
void Scene::deleteMeshEntity(Qt3DCore::QEntity *entity)
{
    free(entity);
}


