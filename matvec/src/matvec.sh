#!/bin/sh

# TODO Exclude xlarge when testing correctness
declare -a versions=("s" "p")
declare -a sizes=("small" "medium" "large" "xlarge")

## Loop over the sizes for both serial and parallel versions
for version in "${versions[@]}"
do
  for size in "${sizes[@]}"
  do
    # First compile with printing to test correctness...
    xmtcc matvec.$version.c -include ../data/$size/matvec.h ../data/$size/matvec.xbo -D PRINT_RESULT -quiet -o matvec.$version
    xmtfpga matvec.$version.b -o myFile${size^}.txt > /dev/null
    diff -b myFile${size^}.txt ../data/small/resultFile${size^}.txt

    # ...then compile without printing to count clocks
    xmtcc matvec.$version.c -include ../data/$size/matvec.h ../data/$size/matvec.xbo -quiet -o matvec.$version
    xmtfpga matvec.$version.b -o myFile${size^}.txt
  done
done
