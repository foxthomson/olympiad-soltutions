#!/bin/bash

NAME=game

/usr/bin/g++ -DEVAL -static -O2 -g -o $NAME grader.c $NAME.cpp
