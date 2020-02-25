#!/bin/bash

NAME=dreaming

/usr/bin/g++ -DEVAL -static -O2 -o $NAME grader.cpp $NAME.cpp
