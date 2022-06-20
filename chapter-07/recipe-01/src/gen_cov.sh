./sample
lcov -d . -t 'sample' -o 'sample.info' -b . -c
genhtml -o cov_report sample.info
echo "result is in cov_report/"
