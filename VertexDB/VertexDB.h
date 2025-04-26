#pragma once

#include "Vertex.h"
#include <string>

class VertexDB {
private:
    float* vertices[3];
    float* normals[3];
    float* texpos[2];

    int vhead;
    int vthead;
    int vnhead;

public:
    VertexDB(): vhead(0), vthead(0), vnhead(0) {
        for (int i = 0; i < 3; ++i) {
            vertices[i] = nullptr;
            normals[i] = nullptr;
            if(i<2) texpos[i] = nullptr;
        }
    }

    VertexDB(int v_num, int vt_num, int vn_num): vhead(0), vthead(0), vnhead(0) {
        for (int i = 0; i < 3; ++i) {
            vertices[i] = new float[v_num];
            normals[i] = new float[vn_num];
            if(i<2) texpos[i] = new float[vt_num];
        }
    }

    ~VertexDB() {
        for (int i = 0; i < 3; ++i) {
            delete[] vertices[i];
            delete[] normals[i];
            if(i<2) delete[] texpos[i];
        }
    }

    // Objファイルの一行を読み込む関数
    // 頂点情報を読み込む
    void loadObjLine(const std::string& line);


    Vertex getPoint(int) const;

};