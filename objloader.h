#ifndef OBJLOADER_H
#define OBJLOADER_H
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

using namespace std;
class ObjLoader
{
public:
    ObjLoader();
    ~ObjLoader();

    bool loadObj(const char * path,
                 std::vector < glm::vec3 > & out_vertices,
                 std::vector < glm::vec2 > & out_uvs,
                 std::vector < glm::vec3 > & out_normals);

private:
    std::vector< unsigned int > vertexIndices, uvIndices, normalIndices;
    std::vector< glm::vec3 > temp_vertices;
    std::vector< glm::vec2 > temp_uvs;
    std::vector< glm::vec3 > temp_normals;

};

#endif // OBJLOADER_H
