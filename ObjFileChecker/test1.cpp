#include "ObjFileChecker.h"
#include "gtest/gtest.h"

#include <iostream>

#include <windows.h>

using namespace std;

#define OBJ_FILE_PATH "FinalBaseMesh.obj"
#define OBJ_VERTEX_COUNT 24461
#define OBJ_NORMAL_COUNT 24460
#define OBJ_TEXTURE_VERTEX_COUNT 0
#define OBJ_FACE_COUNT 24459

TEST(ObjFileCheckerTest, CheckObjFile) {
    char cdir[255];
    GetCurrentDirectory(255,cdir);
    cout << "Current Directory : " << cdir << endl;

    ObjFileChecker objFileChecker(OBJ_FILE_PATH);
    EXPECT_TRUE(objFileChecker.checkObjFile()) << "Failed to check the .obj file.";

    EXPECT_EQ(objFileChecker.getVertexCount(), OBJ_VERTEX_COUNT) << "Vertex count mismatch.";
    EXPECT_EQ(objFileChecker.getNormalCount(), OBJ_NORMAL_COUNT) << "Normal count mismatch.";
    EXPECT_EQ(objFileChecker.getTextureVertexCount(), OBJ_TEXTURE_VERTEX_COUNT) << "Texture vertex count mismatch.";
    EXPECT_EQ(objFileChecker.getFaceCount(), OBJ_FACE_COUNT) << "Face count mismatch.";
}