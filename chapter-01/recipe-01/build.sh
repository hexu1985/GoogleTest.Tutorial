mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=~/local/googletest \
    ..
cmake --build . --target install
