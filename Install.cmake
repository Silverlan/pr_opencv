pr_install_create_directory(modules/pr_opencv)
pr_install_targets(pr_opencv INSTALL_DIR "modules/pr_opencv/")

if(WIN32)
    pr_install_files(
        "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/bin/Release/${OS_LIB_BIN_PRE}opencv_imgproc470${OS_LIB_BIN_EXT}"
        "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/bin/Release/${OS_LIB_BIN_PRE}opencv_core470${OS_LIB_BIN_EXT}"
        "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/bin/Release/${OS_LIB_BIN_PRE}opencv_imgcodecs470${OS_LIB_BIN_EXT}"
        INSTALL_DIR "modules/pr_opencv/"
    )
else()
    pr_install_files(
        "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/${OS_LIB_BIN_PRE}opencv_imgproc${OS_LIB_BIN_EXT}"
        "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/${OS_LIB_BIN_PRE}opencv_core${OS_LIB_BIN_EXT}"
        "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/lib/${OS_LIB_BIN_PRE}opencv_imgcodecs${OS_LIB_BIN_EXT}"
        INSTALL_DIR "modules/pr_opencv/"
    )
endif()
