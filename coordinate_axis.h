#ifndef COORDINATE_AXIS_H
#define COORDINATE_AXIS_H

#include <qvector.h>
#include <qvector3d.h>
#include <qopengl.h>
#include <qopenglbuffer.h>
#include <qopenglfunctions.h>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>
#include <qmatrix4x4.h>

class Coordinate_Axis : protected QOpenGLFunctions
{
public:
    Coordinate_Axis(QOpenGLFunctions *f, qreal x, qreal y, qreal z, QMatrix4x4 world);
    ~Coordinate_Axis();

    const GLfloat *constData() const { return m_data.constData(); }
    int count() const { return m_count; }
    int vertexCount() const { return m_count / 6; }

private:
    void addLine(const QVector3D &v, const QVector3D &n);
    void line(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, const QVector3D &n);
    void initCoordinateAxisGeometry();
    void setupVertexAttributes(QOpenGLFunctions *f);
    void drawCoordinateAxisGeometry();

    QVector<GLfloat> m_data;
    QOpenGLBuffer arrayBuf;
    int m_count;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLFunctions *f;
    QOpenGLShaderProgram *m_program;
    int m_projMatrixLoc;
    int m_mvMatrixLoc;
    int m_normalMatrixLoc;
    int m_lightPosLoc;
    QMatrix4x4 m_proj;
    QMatrix4x4 m_camera;
    QMatrix4x4 m_world;
    bool m_transparent;
    qreal x, y, z;
};

#endif // COORDINATE_AXIS_H
