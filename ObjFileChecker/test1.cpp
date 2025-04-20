#include "ObjFileChecker.h"

#include <iostream>

using namespace std;

int main() {
    // Create an instance of ObjFileChecker with the path to the .obj file
    ObjFileChecker checker("FinalBaseMesh.obj");

    // Check the .obj file for validity
    if (checker.checkObjFile()) {
        std::cout << "OBJ file is valid." << std::endl;
        std::cout << "Number of vertices: " << checker.getVertexCount() << std::endl;
        std::cout << "Number of texture vertices: " << checker.getTextureVertexCount() << std::endl;
        std::cout << "Number of normals: " << checker.getNormalCount() << std::endl;
        std::cout << "Number of faces: " << checker.getFaceCount() << std::endl;
    } else {
        std::cerr << "OBJ file is invalid." << std::endl;
    }

    return 0;
}