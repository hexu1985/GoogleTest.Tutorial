mkdir build
cd build
cmake -DGTest_DIR=~/local/lib/cmake/GTest \
    ..
VERBOSE=1 cmake --build . 
