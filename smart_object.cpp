#include "smart_object.h"
#include <QPoint>


//set id for smart object
SmartObject::SmartObject(){

}

SmartObject::~SmartObject(){


}

void SmartObject::setId(int id)
{
    this->id = id;
}

//get the id of smart object
int SmartObject::getId()
{
    return this->id;
}

void SmartObject::setName(char *name_object)
{
    this->name = name_object;
}

char *SmartObject::getName()
{
    return this->name;
}

//set source method for object. Load the mesh from obj, fbx file
void SmartObject::setSource(QUrl url)
{
    Qt3DRender::QMesh::setSource(url);
}

//get the entity that wrap the mesh
Qt3DCore::QEntity* SmartObject::getParentEntity()
{
    return entity;
}

//set the entity that wrap the mesh
void SmartObject::setParentEntity(Qt3DCore::QEntity *entity_parent)
{
    entity = entity_parent;
}

Qt3DCore::QTransform *SmartObject::createTransform()
{
    Qt3DCore::QTransform *new_transform;
    new_transform = new Qt3DCore::QTransform();
    return new_transform;
}

void SmartObject::setTransform(Qt3DCore::QTransform *transform_add)
{
    transform = transform_add;
}

Qt3DCore::QTransform *SmartObject::getTransform()
{
    return transform;
}

Qt3DRender::QMaterial *SmartObject::createMaterial()
{
    Qt3DRender::QMaterial *new_material;
    new_material = new Qt3DRender::QMaterial();
    return new_material;
}

void SmartObject::setMaterial(Qt3DRender::QMaterial *material_set)
{
    material = material_set;
}

Qt3DRender::QMaterial *SmartObject::getMaterial()
{
    return material;
}

//convert mesh's world coordinates into window coordinates and return the location of mesh on window coordinates
//QVector2D SmartObject::getPos(QMatrix projectionMatrix, QMatrix viewMatrix, QVector3D point3D, QVector2D viewSize,
//                           QVector2D viewOffset)
//{
//    QVector4D clipSpacePos = projectionMatrix * (viewMatrix * QVector4D(point3D, 1.0));
//    QVector3D ndcSpacePos = clipSpacePos.xyz / clipSpacePos.w;
//    QVector2D windowSpacePos = ((ndcSpacePos.xy + 1.0) / 2.0) * viewSize + viewOffset;
//    return windowSpacePos;
//}

//get the local of object

