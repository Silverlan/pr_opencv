cmake_minimum_required(VERSION 3.12)

include("./CMakeShared.txt")

set(PROJ_NAME pr_opencv)

project(${PROJ_NAME} CXX)

add_include_dir(opencv_build)
add_include_dir(opencv)
link_external_library(util_image)

link_generic_module_libraries()
register_pragma_module(${PROJ_NAME})

target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/video/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/stitching/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/photo/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/objdetect/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/ml/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/imgproc/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/videoio/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/imgcodecs/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/highgui/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/dnn/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/flann/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/features2d/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/calib3d/include")
target_include_directories(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_MODULE_LOCATION}/core/include")

target_link_libraries(${PROJ_NAME} "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/Release/${OS_LIB_BIN_PRE}opencv_imgproc470${OS_LIB_SHARED_EXT}")
target_link_libraries(${PROJ_NAME} "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/Release/${OS_LIB_BIN_PRE}opencv_core470${OS_LIB_SHARED_EXT}")
target_link_libraries(${PROJ_NAME} "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/Release/${OS_LIB_BIN_PRE}opencv_imgcodecs470${OS_LIB_SHARED_EXT}")
