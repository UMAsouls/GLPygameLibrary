#include "ObjFileChecker.h"
#include <iostream>
#include <sstream>
#include <fstream>

// objが正しいか確認する関数
// 頂点数などもカウントする
bool ObjFileChecker::checkObjFile() {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filePath << std::endl;
        return false;
    }
    

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

            int n = 0;
            std::string face;
            while(iss >> face) n++;

            if(n >= 4) f_v_num = 6;
            else if(n == 3) f_v_num = 3;

        } else if(prefix == "mtllib") {
            iss >> mtlPath;
        }

        line_num++;
        datas.push_back(line); // Store the line in the datas array
    }
    file.close();

    return true;

}