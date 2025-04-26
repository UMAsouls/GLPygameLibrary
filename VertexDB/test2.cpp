#include "VertexDB.h"
#include "Vertex.h"
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
    EXPECT_EQ(v.x, 10);
    EXPECT_EQ(v.y, 20);
    EXPECT_EQ(v.z, 30);
    EXPECT_EQ(v.u, 5);
    EXPECT_EQ(v.v, 5);
    EXPECT_EQ(v.nx, 0);
    EXPECT_EQ(v.ny, 10);
    EXPECT_EQ(v.nz, 0);
}