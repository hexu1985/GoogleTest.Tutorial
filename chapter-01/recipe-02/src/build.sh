cmake -H. -Bbuild \
    -Dgtest_INCLUDE_DIRS=~/local/googletest/include \
	-Dgtest_LIB_DIRS=~/local/googletest/lib
VERBOSE=1 cmake --build build
