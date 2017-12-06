#include "coordinate_axis.h"


Coordinate_Axis::Coordinate_Axis(QOpenGLFunctions *f, qreal x, qreal y, qreal z, QMatrix4x4 world)
    :f(f),
     x(x),
     y(y),
     z(z),
     m_world(world)
{
    initializeOpenGLFunctions();
    initCoordinateAxisGeometry();
//generate shader program
    m_program = new QOpenGLShaderProgram;
    m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/coor_vshader.glsl");
    m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, ":/coor_fshader_glsl");
    m_program->bindAttributeLocation("vertex", 0);
    m_program->bindAttributeLocation("normal", 1);
    m_program->link();

    m_program->bind();
    m_projMatrixLoc = m_program->uniformLocation("projMatrix");
    m_mvMatrixLoc = m_program->uniformLocation("mvMatrix");
    m_normalMatrixLoc = m_program->uniformLocation("normalMatrix");
    m_lightPosLoc = m_program->uniformLocation("lightPos");

//VAO binder
    m_vao.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

//create arrayBuf
    arrayBuf.create();
    arrayBuf.bind();
    arrayBuf.allocate(constData(), count() * sizeof(GLfloat));
    setupVertexAttributes(f);

    // Our camera never changes in this example.
    m_camera.setToIdentity();
    m_camera.translate(0, 0, -1);

    // Light position is fixed.
    m_program->setUniformValue(m_lightPosLoc, QVector3D(0, 0, 70));

    m_program->release();
}

Coordinate_Axis::~Coordinate_Axis(){
    arrayBuf.destroy();
}

void Coordinate_Axis::addLine(const QVector3D &v, const QVector3D &n)
{
    GLfloat *p = m_data.data() + m_count;
    *p++ = v.x();
    *p++ = v.y();
    *p++ = v.z();
    *p++ = n.x();
    *p++ = n.y();
    *p++ = n.z();
    m_count += 6;
}

void Coordinate_Axis::line(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, const QVector3D &n)
{
    addLine(QVector3D(x1, y1, z1), n);
    addLine(QVector3D(x2, y2, z2), n);
}

void Coordinate_Axis::initCoordinateAxisGeometry()
{
    m_data.resize(6 * 6);
    QVector3D n_y = QVector3D(0.0f, 0.1f, 0.0f);
    QVector3D n_x = QVector3D(0.1f, 0.0f, 0.0f);
    QVector3D n_z = QVector3D(0.0f, 0.0f, 0.1f);
    line(x, y, z, x, y + 1.0f, z, n_y);
    line(x, y, z, x + 1.0f, y, z, n_x);
    line(x, y, z, x, y, z + 1.0f, n_z);
}

void Coordinate_Axis::setupVertexAttributes(QOpenGLFunctions *f)
{
    arrayBuf.bind();
    f->glEnableVertexAttribArray(0);
    f->glEnableVertexAttribArray(1);
    f->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), 0);
    f->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), reinterpret_cast<void *>(3 * sizeof(GLfloat)));
    arrayBuf.release();
}

void Coordinate_Axis::drawCoordinateAxisGeometry()
{
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);
    m_program->bind();
    m_program->setUniformValue(m_projMatrixLoc, m_proj);
    m_program->setUniformValue(m_mvMatrixLoc, m_camera * m_world);
    QMatrix3x3 normalMatrix = m_world.normalMatrix();
    m_program->setUniformValue(m_normalMatrixLoc, normalMatrix);
    glDrawArrays(GL_LINES, 0, m_logo.vertexCountLine());
}
