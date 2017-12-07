#ifndef SMART_OBJECT_H
#define SMART_OBJECT_H

#include <qvector.h>
#include <qopengl.h>
#include <qopenglbuffer.h>
#include <qopenglvertexarrayobject.h>
#include <qopenglfunctions.h>
#include <qopenglshaderprogram.h>
#include <glm/glm.hpp>

class SmartObject : protected QOpenGLFunctions
{
public:
    SmartObject(QOpenGLFunctions *f, QMatrix4x4 *world,QMatrix4x4 *camera, QMatrix4x4 *proj,
                std::vector<glm::vec3> out_vertices, std::vector<glm::vec2> out_uvs, std::vector<glm::vec3> out_normal);
    ~SmartObject();

    const GLfloat *constData() const { return m_data.constData(); }
    int count() const { return m_count; }
    int vertexCount() const { return m_count / 8; }

private:
    void addShaderFromSourceCode(int type, const char *source);
    void addShaderFromFile(int type, const char *path);
    int setLocationShaderAtrrs(const char *shader_attrs);
    QOpenGLShaderProgram *getShaderProgram();
    void initObjectGeometry();
    QOpenGLBuffer *getArrayBuf();

    void draw(const char *drawMode);

    QVector<GLfloat> m_data;
    QOpenGLBuffer *arrayBuf;
    int m_count;
    QOpenGLVertexArrayObject m_vao;
    QOpenGLFunctions *function;
    QOpenGLShaderProgram *m_program;
    int m_projMatrixLoc;
    int m_mvMatrixLoc;
    int m_normalMatrixLoc;
    int m_lightPosLoc;
    QMatrix4x4 *m_proj;
    QMatrix4x4 *m_camera;
    QMatrix4x4 *m_world;
    bool m_transparent;
    std::vector<glm::vec3> out_vertices;
    std::vector<glm::vec2> out_uvs;
    std::vector<glm::vec3> out_normals;
};

#endif
