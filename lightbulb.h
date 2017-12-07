#ifndef LIGHTBULB_H
#define LIGHTBULB_H

#include <qvector.h>
#include <qopengl.h>
#include <QOpenGLFunctions>
#include <glm/glm.hpp>
#include <QOpenGLShaderProgram>
#include <QOpenGLBuffer>
#include <qvector3d.h>

using namespace std;

class LightBulb : protected QOpenGLFunctions
{
public:
    LightBulb(std::vector<glm::vec3> out_vertices, std::vector<glm::vec2> out_uvs, std::vector<glm::vec3> out_normals,
              QOpenGLFunctions *f, QMatrix4x4 *world,QMatrix4x4 *camera);
    virtual ~LightBulb();

    const GLfloat *constData() const { return m_data.constData(); }
    int count() const { return m_count; }
    int vertexCount() const { return m_count / 8; }

    void drawLighBulb(QOpenGLShaderProgram *program);

private:
    void setNameObject(QString name);
    QString getNameObject();
    void setObjectId(int id);
    int getObjectId();
    void initLighBulbGeometry();
    void setupVertexAttribs();
    QVector3D get_average_vector();

    QOpenGLBuffer arrayBuf;

    std::vector<glm::vec3> out_vertices;
    std::vector<glm::vec2> out_uvs;
    std::vector<glm::vec3> out_normals;
    QVector<GLfloat> m_data;
    int m_count;
    QString name_object;
    int object_id;

};

#endif // LIGHTBULB_H
