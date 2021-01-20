mkdir build
cd build
cmake -DGTEST_ROOT=~/local \
    ..
VERBOSE=1 cmake --build . 
