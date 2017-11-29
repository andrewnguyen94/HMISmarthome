#include "lightbulb.h"
#include <iostream>
#include <vector>
#include <QVector>
#include <qopengl.h>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};

LightBulb::LightBulb(std::vector<glm::vec3> out_vertices, std::vector<glm::vec2> out_uvs, std::vector<glm::vec3> out_normal)
{
    initializeOpenGLFunctions();
    this->out_vertices = out_vertices;
    this->out_uvs = out_uvs;
    this->out_normals = out_normal;
    this->m_count = 0;
    this->arrayBuf.create();

    initLighBulbGeometry();
}

LightBulb::~LightBulb()
{
    this->arrayBuf.destroy();
}

void LightBulb::setNameObject(QString name)
{
    this->name_object = name;
}

QString LightBulb::getNameObject()
{
    return name_object;
}

void LightBulb::setObjectId(int id)
{
    this->object_id = id;
}

int LightBulb::getObjectId()
{
    return object_id;
}

void LightBulb::initLighBulbGeometry()
{
    m_data.resize(this->out_vertices.size() * 3 +
                  this->out_uvs.size() * 2 +
                  this->out_normals.size() * 3);
    GLfloat *p = m_data.data() + m_count;
    for(unsigned int i = 0; i < this->out_vertices.size(); i++){
        *p++ = this->out_vertices[i].x;
        *p++ = this->out_vertices[i].y;
        *p++ = this->out_vertices[i].z;
        *p++ = this->out_uvs[i].x;
        *p++ = this->out_uvs[i].y;
        *p++ = this->out_normals[i].x;
        *p++ = this->out_normals[i].y;
        *p++ = this->out_normals[i].z;
        m_count += 8;
    }
    arrayBuf.bind();
    arrayBuf.allocate(constData(), count() * sizeof(GLfloat));
}

void LightBulb::setupVertexAttribs()
{

}

QVector3D LightBulb::get_average_vector()
{
    float avg_x, avg_y, avg_z;
    float tmp_x = 0.0f;
    float tmp_y = 0.0f;
    float tmp_z = 0.0f;
    float tmp = 0.0f;
    for(unsigned int i = 0; i < this->out_vertices.size(); i++){
        tmp_x += this->out_vertices[i].x * sqrt(pow(this->out_vertices[i].x,2) + pow(this->out_vertices[i].y,2
                                                + pow(this->out_vertices[i].z,2)));
        tmp += sqrt(pow(this->out_vertices[i].x,2) + pow(this->out_vertices[i].y,2
                        + pow(this->out_vertices[i].z,2)));
        tmp_y += this->out_vertices[i].y * sqrt(pow(this->out_vertices[i].x,2) + pow(this->out_vertices[i].y,2
                                                + pow(this->out_vertices[i].z,2)));
        tmp_z += this->out_vertices[i].z * sqrt(pow(this->out_vertices[i].x,2) + pow(this->out_vertices[i].y,2
                                                + pow(this->out_vertices[i].z,2)));
    }
    avg_x = tmp_x/tmp;
    avg_y = tmp_y/tmp;
    avg_z = tmp_z/tmp;
    return QVector3D(avg_x, avg_y, avg_z);
}

void LightBulb::drawLighBulb(QOpenGLShaderProgram *program)
{
    // Tell OpenGL which VBOs to use
    arrayBuf.bind();

    // Offset for position
    quintptr offset = 0;

    //Tell OpenGL programmable pipeline how to locate vertex position data
    int a_position =


