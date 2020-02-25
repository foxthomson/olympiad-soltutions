#!/bin/bash

NAME=artclass

/usr/bin/g++ -DEVAL -fpermissive -static -O2 -o $NAME grader.c graderlib.c $NAME.cpp ./libjpeg-master/*.c
# -Ljpeglib/lib
#./libjpeg-master/*.c
#-Ijpeglib/include
