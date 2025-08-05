include(${CMAKE_SOURCE_DIR}/cmake/pr_common.cmake)

set(PROJ_NAME pr_opencv)
pr_add_module(${PROJ_NAME} SHARED "modules/opencv/")

pr_add_dependency(${PROJ_NAME} shared TARGET PUBLIC)

find_package(opencv REQUIRED)
pr_add_external_dependency(${PROJ_NAME} opencv LIBRARY)

pr_add_headers(${PROJ_NAME} "include/")
pr_add_sources(${PROJ_NAME} "src/")

pr_finalize(${PROJ_NAME})
