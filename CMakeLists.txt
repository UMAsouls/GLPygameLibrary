#C++のバージョン
cmake_minimum_required(VERSION 3.10)
#プロジェクト名と言語
project(GLPygameLoder CXX)

#FetchContentを使う
include(FetchContent)

#googletestをFetchContentで取得する
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

#gtestを使うための設定(windowsの時はこれを使う)
if (WIN32)
	# Windowsの場合、gtestを静的ライブラリとしてリンクする
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif()


#テストのためのビルド部分
enable_testing()

#テストを指定
add_executable(my_test ObjFileChecker/test1.cpp ObjFileChecker/ObjFileChecker.cpp)
#テストとgtestをリンクする
target_link_libraries(my_test gtest_main)

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