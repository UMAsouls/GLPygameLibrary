#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>



class Vertex {
private:
    glm::vec3 position; // Vertex coordinates
    glm::vec3 normal; // Normal coordinates
    glm::vec2 texcoord; // Texture coordinates

public:

    Vertex(float x, float y, float z, float nx, float ny, float nz, float u, float v)
        : position(x, y, z), normal(nx, ny, nz), texcoord(u, v) {}

    glm::vec3 getPosition() const { return position; }
    glm::vec3 getNormal() const { return normal; }
    glm::vec2 getTexcoord() const { return texcoord; }

    
    

}; 