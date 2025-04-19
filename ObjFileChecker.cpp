#include "ObjFileChecker.h"
#include <iostream>
#include <sstream>
#include <fstream>


ObjFileChecker::ObjFileChecker(const std::string& path) : filePath(path),
    v_num(0), vt_num(0), vn_num(0), f_num(0), f_v_num(0) {}

bool ObjFileChecker::checkFileValidity() {
    std::ifstream file(filePath);
    return file.is_open();
}

bool ObjFileChecker::checkObjFile() {
    if(!checkFileValidity()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return false;
    }

    std::ifstream file(filePath);

    std::string line;
    while(std::getline(file, line)) {
        std::istringstream iss(line);
        std::string prefix;
        iss >> prefix;

        if(prefix == "v") {
            v_num++;
        } else if(prefix == "vt") {
            vt_num++;
        } else if(prefix == "vn") {
            vn_num++;
        } else if(prefix == "f") {
            f_num++;
            std::string face;
            while(iss >> face) {
                std::istringstream faceStream(face);
                std::string vertexIndex;
                std::getline(faceStream, vertexIndex, '/');
                f_v_num++;
            }
        } else if(prefix == "mtllib") {
            iss >> mtlPath;
        }
    }

}