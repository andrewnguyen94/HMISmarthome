#ifndef SMART_OBJECT_H
#define SMART_OBJECT_H

#include <qmesh.h>
#include <QMouseEvent>

class SmartObject: public SmartObject
{
    Q_OBJECT
public:
    explicit SmartObject(Qt3DRender::QMesh *parent = nullptr);
    ~SmartObject();

public slots:
    void setId(int id);
    int getId();
    void setSource(QUrl *url);
    float getLocal();

    int id;

private:
    QVector2D getPos(QMatrix projectionMatrix, QMatrix viewMatrix, QVector3D point3D, QVector2D viewSize, QVector2D viewOffset);
};

#endif // SMART_OBJECT_H
