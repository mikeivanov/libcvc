cmake_minimum_required(VERSION 2.8)
project( cvc )
find_package( OpenCV REQUIRED )
include_directories( ${OpenCV_INCLUDE_DIRS} ./)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
add_library( cvc SHARED
  version.cpp types.cpp core.cpp videoio.cpp highgui.cpp
  dnn.cpp imgcodecs.cpp imgproc.cpp)
target_link_libraries( cvc ${OpenCV_LIBS} )
