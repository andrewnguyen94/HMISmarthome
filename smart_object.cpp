#include "smart_object.h"

SmartObject::SmartObject(QOpenGLFunctions *f, QMatrix4x4 *world,QMatrix4x4 *camera, QMatrix4x4 *proj,
             std::vector<glm::vec3> out_vertices, std::vector<glm::vec2> out_uvs, std::vector<glm::vec3> out_normal)
    : function(f),
     m_camera(camera),
     m_world(world),
     out_vertices(out_vertices),
     out_uvs(out_uvs),
     out_normals(out_normal),
     m_count(0),
     m_proj(proj)
{
    initializeOpenGLFunctions();
    initObjectGeometry();
    m_program = new QOpenGLShaderProgram;

// VAO binder
    m_vao.create();
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);

//  buffer create
    arrayBuf = new QOpenGLBuffer;
    arrayBuf->create();
    arrayBuf->bind();
    arrayBuf->allocate(constData(), count() * sizeof(GLfloat));
}

SmartObject::~SmartObject()
{

}

int SmartObject::setLocationShaderAtrrs(const char *shader_attrs)
{
    return m_program->uniformLocation(shader_attrs);
}


QOpenGLShaderProgram *SmartObject::getShaderProgram()
{
    return this->m_program;
}

void SmartObject::initObjectGeometry()
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

QOpenGLBuffer *SmartObject::getArrayBuf()
{
    return arrayBuf;
}

void SmartObject::draw(const char *drawMode)
{
    QOpenGLVertexArrayObject::Binder vaoBinder(&m_vao);
    m_program->bind();
    if(strcmp(drawMode,"GL_TRIANGLES") == 0){
        glDrawArrays(GL_TRIANGLES, 0, vertexCount());
    }else if(strcmp(drawMode, "GL_TRIANGLE_STRIP") == 0){
        glDrawArrays(GL_TRIANGLE_STRIP, 0, vertexCount());
    }else if(strcmp(drawMode, "GL_LINES") == 0){
        glDrawArrays(GL_LINES, 0, vertexCount());
    }else if(strcmp(drawMode, "GL_POINTS") == 0){
        glDrawArrays(GL_POINTS, 0, vertexCount());
    }
    m_program->release();
}

//type is source type, exp: vertex, fragment. 0 is vertex, 1 is fragment
void SmartObject::addShaderFromSourceCode(int type, const char *source)
{
    if(type == 0){
        m_program->addShaderFromSourceCode(QOpenGLShader::Vertex, source);
    }else if(type == 1){
        m_program->addShaderFromSourceCode(QOpenGLShader::Fragment, source);
    }
}

//type is source type, exp: vertex, fragment. 0 is vertex, 1 is fragment
void SmartObject::addShaderFromFile(int type, const char *path)
{
    if(type == 0){
        m_program->addShaderFromSourceFile(QOpenGLShader::Vertex, path);
    }else if(type == 1){
        m_program->addShaderFromSourceFile(QOpenGLShader::Fragment, path);
    }
}
