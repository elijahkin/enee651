#!/bin/sh

# Testing correctness (no xlarge)
xmtcc matvec.s.c -include ../data/small/matvec.h ../data/small/matvec.xbo -D PRINT_RESULT -quiet -o matvec.s
xmtfpga matvec.s.b -o myFileSmall.txt
diff -b myFileSmall.txt ../data/small/resultFileSmall.txt

xmtcc matvec.s.c -include ../data/medium/matvec.h ../data/medium/matvec.xbo -D PRINT_RESULT -quiet -o matvec.s
xmtfpga matvec.s.b -o myFileMedium.txt
diff -b myFileMedium.txt ../data/medium/resultFileMedium.txt

xmtcc matvec.s.c -include ../data/large/matvec.h ../data/large/matvec.xbo -D PRINT_RESULT -quiet -o matvec.s
xmtfpga matvec.s.b -o myFileLarge.txt
diff -b myFileLarge.txt ../data/large/resultFileLarge.txt

# Clock counting (printing disabled)
xmtcc matvec.s.c -include ../data/small/matvec.h ../data/small/matvec.xbo -quiet -o matvec.s
xmtfpga matvec.s.b

xmtcc matvec.s.c -include ../data/medium/matvec.h ../data/medium/matvec.xbo -quiet -o matvec.s
xmtfpga matvec.s.b

xmtcc matvec.s.c -include ../data/large/matvec.h ../data/large/matvec.xbo -quiet -o matvec.s
xmtfpga matvec.s.b

xmtcc matvec.s.c -include ../data/xlarge/matvec.h ../data/xlarge/matvec.xbo -quiet -o matvec.s
xmtfpga matvec.s.b
