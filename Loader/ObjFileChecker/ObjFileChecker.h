#pragma once
#include <string>
#include <fstream>
#include <vector>

class ObjFileChecker {
private:
    std::string filePath; // Path to the .obj file
    std::string mtlPath; // Path to the .mtl file

    int v_num; // Number of vertices
    int vt_num; // Number of texture vertices
    int vn_num; // Number of normals
    int f_num; // Number of faces

    int f_v_num; // Number of vertex indices in faces

    std::vector<std::string> datas; // Array to store the data from the .obj file
    int line_num = 0; // Line number in the .obj file

public:
    ObjFileChecker(const std::string& path) : filePath(path),
     v_num(0), vt_num(0), vn_num(0), f_num(0), f_v_num(0) {}

    ~ObjFileChecker() { } // Destructor to clean up the data array
     
    std::string getMtlPath() const { return mtlPath; } // Get the path to the .mtl file
    int getVertexCount() const { return v_num; } // Get the number of vertices
    int getTextureVertexCount() const { return vt_num; } // Get the number of texture vertices
    int getNormalCount() const { return vn_num; } // Get the number of normals
    int getFaceCount() const { return f_num; } // Get the number of faces

    bool checkObjFile(); // Check the .obj file for validity
};