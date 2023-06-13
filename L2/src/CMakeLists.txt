project(eigen_use)
find_package(glog)
find_package(Eigen3)

if(Eigen3_FOUND)
    message(STATUS "eigen found " ${EIGEN3_INCLUDE_DIR})
else()
    message(STATUS "eigen not found")
endif()
INCLUDE_DIRECTORIES(${EIGEN3_INCLUDE_DIR} ${useEigen_include_dir})


AUX_SOURCE_DIRECTORY(. SRC)
message(STATUS "src dir " ${SRC})
add_executable(main ${SRC})
target_link_libraries(main glog::glog)
