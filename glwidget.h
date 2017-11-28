#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <qopengl.h>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <qmatrix4x4.h>

class GlWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT
public:
    GlWidget(QWidget *parent = 0);
    ~GlWidget();

    void setCameraTranslation(float x, float y, float z);
    void setCameraTranslationX(float x);
    void setCameraTranslationY(float y);
    void setCameraTranslationZ(float z);
    float getCameraTranslationX();
    float getCameraTranslationY();
    float getCameraTranslationZ();
    void setNearPlane(float n);
    float getNearPlane();
    void setFarPlane(float f);
    float getFarPlane();
    void setFov(float fov);
    float getFov();
    void setProjMatrix(QMatrix4x4 m_proj);
    QMatrix4x4 getProjMatrix();
    void setCameraMatrix(QMatrix4x4 m_camera);
    QMatrix4x4 getCameraMatrix();

public slots:

private:
    QMatrix4x4 m_camera;
    QMatrix4x4 m_proj;
    QMatrix4x4 m_world;
    float near_plane, far_plane, fov;
    float x_camera, y_camera, z_camera;
    int m_projMatrixLoc, m_mvMatrixLoc;
protected:

signals:

};

#endif // GLWIDGET_H
