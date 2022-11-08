# CMakeList.txt : CMake project for CTestLib, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("CTestLib")
# Add source to this project's executable.
add_library (CTestLib SHARED "CTestLib.c" "cJSON.c" "cJSON_Utils.c")
add_executable(cbj0  "cbj0.c" "cJSON.c" "cJSON_Utils.c")

# TODO: Add tests and install targets if needed.
