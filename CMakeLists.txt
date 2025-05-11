#C++のバージョン
cmake_minimum_required(VERSION 3.14)
#プロジェクト名と言語
project(GLPygameLoder CXX)

# C++17 + GNU拡張
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS ON)

# CygwinまたはMinGWの場合、POSIX機能を有効にする
if(CYGWIN OR MINGW)
	add_definitions(-D_GNU_SOURCE -D_POSIX_C_SOURCE=200809L -D_XOPEN_SOURCE=700)
endif()

#FetchContentを使う
include(FetchContent)

#googletestをFetchContentで取得する
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.17.0
)

#gtestを使うための設定(windowsの時はこれを使う)
if (MSVC)
	# Windowsの場合、gtestを静的ライブラリとしてリンクする
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()

FetchContent_MakeAvailable(googletest)


include_directories(
	${CMAKE_SOURCE_DIR}
)


#テストのためのビルド部分
enable_testing()

#テストを指定
add_executable(my_test ObjFileChecker/test1.cpp ObjFileChecker/ObjFileChecker.cpp)
#テストとgtestをリンクする
target_link_libraries(my_test gtest_main)
target_compile_features(my_test PRIVATE cxx_std_17)

#my_testの実行時にObjFileChecker/FinalBaseMesh.objをコピーする
add_custom_command(
	TARGET my_test POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy
	${CMAKE_SOURCE_DIR}/ObjFileChecker/FinalBaseMesh.obj
	$<TARGET_FILE_DIR:my_test>/FinalBaseMesh.obj
)

#mytestをbuild
include(GoogleTest)
gtest_discover_tests(my_test
    DISCOVERY_TIMEOUT 30
    PROPERTIES WORKING_DIRECTORY $<TARGET_FILE_DIR:my_test>
)

add_executable(my_test2 VertexDB/test2.cpp VertexDB/VertexDB.cpp)
#テストとgtestをリンクする
target_link_libraries(my_test2 gtest_main)
target_compile_features(my_test2 PRIVATE cxx_std_17)

gtest_discover_tests(my_test2
	DISCOVERY_TIMEOUT 30
	PROPERTIES WORKING_DIRECTORY $<TARGET_FILE_DIR:my_test2>
)
