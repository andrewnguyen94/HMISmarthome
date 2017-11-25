#include "lightbulb.h"
#include <iostream>
#include <vector>

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

    initLighBulbGeometry();
}

LightBulb::~LightBulb()
{

}

void LightBulb::drawLighBulb(QOpenGLShaderProgram *program)
{

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
}


