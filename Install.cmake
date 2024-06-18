set(INSTALL_PATH "modules/opencv")
pr_install_create_directory("${INSTALL_PATH}")
pr_install_targets(pr_opencv INSTALL_DIR "${INSTALL_PATH}")

if(WIN32)
    set(BIN_DIR "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/bin/Release/")
else()
    set(BIN_DIR "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/bin/")
endif()
pr_install_binary(BIN_DIR "${BIN_DIR}" WIN "opencv_imgproc470.dll" LIN "libopencv_imgproc.so" INSTALL_DIR "${INSTALL_PATH}")
pr_install_binary(BIN_DIR "${BIN_DIR}" WIN "opencv_core470.dll" LIN "libopencv_core.so" INSTALL_DIR "${INSTALL_PATH}")
pr_install_binary(BIN_DIR "${BIN_DIR}" WIN "opencv_imgcodecs470.dll" LIN "libopencv_imgcodecs.so" INSTALL_DIR "${INSTALL_PATH}")
