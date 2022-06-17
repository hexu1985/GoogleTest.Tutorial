./build/sample
lcov -d . -t 'sample' -o 'build/sample.info' -b build/sample.dir -c
genhtml -o build/cov build/sample.info
echo "result is in build/cov/"
