#----------------------------------------------------------------------------
# Setup the project
#----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

# project NAME
set(project_name DirUtils)
project(${project_name})

set (CMAKE_CXX_STANDARD 11)

add_library(${project_name} ${LIB_TYPE} ${PROJECT_SOURCE_DIR}/src/${project_name}.cc ${PROJECT_SOURCE_DIR}/include/${project_name}.hh)

target_include_directories(${project_name} PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(${project_name} PUBLIC
)
