set(INSTALL_PATH "modules/opencv")
pr_install_create_directory("${INSTALL_PATH}")
pr_install_targets(pr_opencv INSTALL_DIR "${INSTALL_PATH}")

if(WIN32)
    set(BIN_DIR "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/bin/Release/")
else()
    set(BIN_DIR "${DEPENDENCY_OPENCV_LIBRARY_LOCATION}/bin/")
endif()

if(UNIX)
    pr_install_binaries(opencv INSTALL_DIR "${INSTALL_PATH}")
endif()
