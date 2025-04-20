cmake_minimum_required(VERSION 3.10)
project(GLPygameLoder CXX)

include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG main
)
FetchContent_MakeAvailable(googletest)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


#テストのためのビルド部分
enable_testing()

add_executable(my_test ObjFileChecker/test1.cpp ObjFileChecker/ObjFileChecker.cpp)
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