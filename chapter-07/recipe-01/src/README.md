
```
$ make
$ rm -rf ./result
$ ./sample
$ lcov -d . -t 'sample' -o 'sample.info' -b . -c
$ genhtml -o result sample.info
```
