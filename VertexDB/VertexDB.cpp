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

// Objファイルの一行を読み込む関数
// 頂点情報を読み込む
void VertexDB::loadObjLine(const std::string& line) {
    
    if (line._Starts_with("vn")) {
        sscanf(line.c_str(), "vn %f %f %f", &normals[0][vnhead], &normals[1][vnhead], &normals[2][vnhead]);
        vnhead++;
    } else if (line._Starts_with("vt")) {
        sscanf(line.c_str(), "vt %f %f", &texpos[0][vthead], &texpos[1][vthead]);
        vthead++;
    }else if (line._Starts_with("v ")) {
        sscanf(line.c_str(), "v %f %f %f", &vertices[0][vhead], &vertices[1][vhead], &vertices[2][vhead]);
        vhead++;
    }
}