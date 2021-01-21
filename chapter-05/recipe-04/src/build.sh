mkdir build
cd build
cmake -DGTEST_ROOT=~/local \
    -DCMAKE_BUILD_TYPE=Release \
    ..
VERBOSE=1 cmake --build . 
