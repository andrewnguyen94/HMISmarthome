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

//set source method for object. Load the mesh from obj, fbx file
void SmartObject::setSource(QUrl url)
{
    Qt3DRender::QMesh::setSource(url);
}

//get the entity that wrap the mesh
Qt3DCore::QEntity SmartObject::getParentEntity()
{
    return entity;
}

//set the entity that wrap the mesh
void SmartObject::setParentEntity(Qt3DCore::QEntity *entity)
{
    this->entity = entity;
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

