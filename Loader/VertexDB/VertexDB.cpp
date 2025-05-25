#include "Vertex/Vertex.h"
#include "VertexDB.h"


Vertex VertexDB::getPoint(int idx) const {
    Vertex point(
        vertices[idx].x, vertices[idx].y, vertices[idx].z,
        normals[idx].x, normals[idx].y, normals[idx].z,
        texpos[idx].x, texpos[idx].y
    );

    return point;
}

// Objファイルの一行を読み込む関数
// 頂点情報を読み込む
void VertexDB::loadObjLine(const std::string& line) {
    
    if(line.size() < 2) return; // Ignore empty lines

    std::string prefix = line.substr(0, 2);
    if (prefix == "vn") {
        sscanf(line.c_str(), "vn %f %f %f", &normals[vnhead].x, &normals[vnhead].y, &normals[vnhead].z);
        vnhead++;
    } else if (prefix == "vt") {
        sscanf(line.c_str(), "vt %f %f", &texpos[vthead].x, &texpos[vthead].y);
        vthead++;
    }else if (prefix == "v ") {
        sscanf(line.c_str(), "v %f %f %f", &vertices[vhead].x, &vertices[vhead].y, &vertices[vhead].z);
        vhead++;
    }
}