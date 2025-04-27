#include "VertexDB.h"
#include "Vertex/Vertex.h"
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
    EXPECT_EQ(v.X(), 10);
    EXPECT_EQ(v.Y(), 20);
    EXPECT_EQ(v.Z(), 30);
    EXPECT_EQ(v.U(), 5);
    EXPECT_EQ(v.V(), 5);
    EXPECT_EQ(v.NX(), 0);
    EXPECT_EQ(v.NY(), 10);
    EXPECT_EQ(v.NZ(), 0);
}