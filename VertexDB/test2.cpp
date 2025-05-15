#include "VertexDB.h"
#include "Vertex/Vertex.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <gtest/gtest.h>

#include <iostream>

using namespace std;


TEST(VertexDBTest, LoadObjLine) {
    VertexDB vertexDB(3, 3, 3); // Initialize with dummy sizes

    // Example line from an OBJ file
    std::string line[3] = {
        "v 10 20 30", // Vertex line
        "vt 5 5",    // Texture vertex line
        "vn 0 10 0" // Normal line
    };

    // Load the line into the VertexDB
    for(int i = 0; i < 3; ++i) {
        vertexDB.loadObjLine(line[i]);
    }

    // Check if the vertex was loaded correctly
    Vertex v = vertexDB.getPoint(0);
    glm::vec3 position = v.getPosition();
    glm::vec3 normal = v.getNormal();
    glm::vec2 texcoord = v.getTexcoord();
    EXPECT_EQ(position.x, 10);
    EXPECT_EQ(position.y, 20);
    EXPECT_EQ(position.z, 30);
    EXPECT_EQ(texcoord.x, 5);
    EXPECT_EQ(texcoord.y, 5);
    EXPECT_EQ(normal.x, 0);
    EXPECT_EQ(normal.y, 10);
    EXPECT_EQ(normal.z, 0);
}