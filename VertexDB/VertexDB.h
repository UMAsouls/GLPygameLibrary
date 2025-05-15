#pragma once

#include "Vertex/Vertex.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>

class VertexDB {
private:
    glm::vec3* vertices; // 頂点座標
    glm::vec3* normals; // 法線座標
    glm::vec2* texpos; // テクスチャ座標

    int vhead;
    int vthead;
    int vnhead;

public:
    VertexDB(): vhead(0), vthead(0), vnhead(0) {
        vertices = nullptr;
        normals = nullptr;
        texpos = nullptr;
    }

    VertexDB(int v_num, int vt_num, int vn_num): vhead(0), vthead(0), vnhead(0) {
        vertices = new glm::vec3[v_num];
        normals = new glm::vec3[vn_num];
        texpos = new glm::vec2[vt_num];
    }

    ~VertexDB() {
        delete[] vertices;
        delete[] normals;
        delete[] texpos;
    }

    // Objファイルの一行を読み込む関数
    // 頂点情報を読み込む
    void loadObjLine(const std::string& line);


    Vertex getPoint(int) const;

};