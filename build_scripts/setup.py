import os
import subprocess
from sys import platform
from pathlib import Path

os.chdir(deps_dir)

########## OpenCV ##########
os.chdir(deps_dir)
opencv_root = deps_dir +"/opencv"
if not Path(opencv_root).is_dir():
    print_msg("opencv not found. Downloading...")
    git_clone("https://github.com/opencv/opencv.git")

os.chdir(opencv_root)
subprocess.run(["git","reset","--hard","725e440"],check=True)

print_msg("Build opencv")
mkdir("build",cd=True)

cmake_configure("..",generator)
cmake_build("Release",["opencv_imgproc","opencv_imgcodecs"])

cmake_args.append("-DDEPENDENCY_OPENCV_INCLUDE=" +opencv_root +"/include")
cmake_args.append("-DDEPENDENCY_OPENCV_MODULE_LOCATION=" +opencv_root +"/modules")
cmake_args.append("-DDEPENDENCY_OPENCV_BUILD_INCLUDE=" +opencv_root +"/build")
cmake_args.append("-DDEPENDENCY_OPENCV_LIBRARY_LOCATION=" +opencv_root +"/build")
