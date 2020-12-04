cmake -H. -Bbuild \
    -DCMAKE_CONFIGURATION_TYPES="Release;Debug" \
    -DCMAKE_INSTALL_PREFIX="D:\\local\\googletest"
cmake --build build --config Release --target install
