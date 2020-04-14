mkdir build
cd build
cmake -Dgtest_INCLUDE_DIRS=~/local/include \
	-Dgtest_LIB_DIRS=~/local/lib ..
VERBOSE=1 cmake --build . 
