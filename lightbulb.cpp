#include "lightbulb.h"
#include <iostream>

struct VertexData
{
    QVector3D position;
    QVector2D texCoord;
    QVector3D normal;
};

LightBulb::LightBulb(std::vector<glm::vec3> out_vertices, std::vector<glm::vec2> out_uvs, std::vector<glm::vec3> out_normal)
{
    this->out_vertices = out_vertices;
    this->out_uvs = out_uvs;
    this->out_normals = out_normal;
}

LightBulb::~LightBulb()
{

}

void LightBulb::drawLighBulb(QOpenGLShaderProgram *program)
{

}

void LightBulb::initLighBulbGeometry()
{

}


