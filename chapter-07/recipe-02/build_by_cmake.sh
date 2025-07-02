cmake -H. -Bbuild -DGTest_DIR=~/local/googletest/lib/cmake/GTest -DCMAKE_BUILD_TYPE=Debug
VERBOSE=1 cmake --build build
