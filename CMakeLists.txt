include(${CMAKE_SOURCE_DIR}/cmake/pr_common.cmake)

set(PROJ_NAME pr_opencv)
pr_add_library(${PROJ_NAME} SHARED)

pr_add_dependency(${PROJ_NAME} shared TARGET PUBLIC)

pr_add_external_dependency(${PROJ_NAME} opencv HEADER_ONLY)
pr_add_external_dependency(${PROJ_NAME} opencv_build HEADER_ONLY)

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

if(WIN32)
    target_link_libraries(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/Release/${OS_LIB_BIN_PRE}opencv_imgproc470${OS_LIB_SHARED_EXT}")
    target_link_libraries(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/Release/${OS_LIB_BIN_PRE}opencv_core470${OS_LIB_SHARED_EXT}")
    target_link_libraries(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/Release/${OS_LIB_BIN_PRE}opencv_imgcodecs470${OS_LIB_SHARED_EXT}")
else()
    target_link_libraries(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/${OS_LIB_BIN_PRE}opencv_imgproc${OS_LIB_SHARED_EXT}")
    target_link_libraries(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/${OS_LIB_BIN_PRE}opencv_core${OS_LIB_SHARED_EXT}")
    target_link_libraries(${PROJ_NAME} PRIVATE "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/${OS_LIB_BIN_PRE}opencv_imgcodecs${OS_LIB_SHARED_EXT}")
endif()

pr_add_headers(${PROJ_NAME} "include/")
pr_add_sources(${PROJ_NAME} "src/")

pr_finalize(${PROJ_NAME})
