list(APPEND LDFLAGS -lm)
set(RUN_OPTIONS -dct int -ppm -outfile /dev/null input_large.jpg)
llvm_multisource(consumer-jpeg-decode)
llvm_test_data(consumer-jpeg-decode input_large.jpg input_large.ppm input_small.jpg input_small.ppm runme_large.sh runme_small.sh)
