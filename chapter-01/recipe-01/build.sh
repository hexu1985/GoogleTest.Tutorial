mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=~/local \
    ..
cmake --build . --target install
