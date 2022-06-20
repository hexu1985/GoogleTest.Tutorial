./build/sample
lcov -d . -t 'sample' -o 'build/sample.info' -b build/sample.dir -c
genhtml -o cov_report build/sample.info
echo "result is in cov_report/"
