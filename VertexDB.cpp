#include "Vertex.h"
#include "VertexDB.h"


Vertex VertexDB::getPoint(int idx) const {
    Vertex point(
        vertices[0][idx], vertices[1][idx], vertices[2][idx],
        normals[0][idx], normals[1][idx], normals[2][idx],
        texpos[0][idx], texpos[1][idx]
    );

    return point;
}