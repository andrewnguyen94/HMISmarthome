#ifndef LIGHTBULB_H
#define LIGHTBULB_H

#include <qvector.h>
#include <qopengl.h>
#include <QOpenGLFunctions>
#include <glm/glm.hpp>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>

using namespace std;

class LightBulb : protected QOpenGLFunctions
{
public:
    LightBulb(std::vector<glm::vec3> out_vertices, std::vector<glm::vec2> out_uvs, std::vector<glm::vec3> out_normals);
    virtual ~LightBulb();

    const GLfloat *constData() const { return m_data.constData(); }
    int count() const { return m_count; }
    int vertexCount() const { return m_count / 6; }

    void drawLighBulb(QOpenGLShaderProgram *program);

private:

    void initLighBulbGeometry();
    QOpenGLBuffer arrayBuf;
    QOpenGLBuffer indexBuf;

    std::vector<glm::vec3> out_vertices;
    std::vector<glm::vec2> out_uvs;
    std::vector<glm::vec3> out_normals;
    QVector<GLfloat> m_data;
    int m_count;

protected:
};

#endif // LIGHTBULB_H
