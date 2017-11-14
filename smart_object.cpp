#include "smart_object.h"
#include <QPoint>



void SmartObject::setId(int id)
{
    this->id = id;
}

int SmartObject::getId()
{
    return this->id;
}

void SmartObject::setSource(QUrl *url)
{
    Qt3DRender::QMesh::setSource(url);
}

QVector2D SmartObject::getPos(QMatrix projectionMatrix, QMatrix viewMatrix, QVector3D point3D, QVector2D viewSize,
                           QVector2D viewOffset)
{
    QVector4D clipSpacePos = projectionMatrix * (viewMatrix * QVector4D(point3D, 1.0));
    QVector3D ndcSpacePos = clipSpacePos.xyz / clipSpacePos.w;
    QVector2D windowSpacePos = ((ndcSpacePos.xy + 1.0) / 2.0) * viewSize + viewOffset;
    return windowSpacePos;
}

float getLocal(){
    return &this;
}
