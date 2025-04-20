cmake_minimum_required(VERSION 3.10)
project(GLPygameLoder CXX)

enable_testing()

add_executable(my_test ObjFileChecker/test1.cpp ObjFileChecker/ObjFileChecker.cpp)
add_test(NAME MyTest COMMAND my_test)

add_custom_command(
        TARGET my_test POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
            ${CMAKE_SOURCE_DIR}/ObjFileChecker/FinalBaseMesh.obj
            $<TARGET_FILE_DIR:my_test>/FinalBaseMesh.obj
    )