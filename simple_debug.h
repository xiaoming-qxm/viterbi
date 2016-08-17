// simple_debug.h

// Copyright 2016-2016 University of Electronic Science and Technology of China
//                     (author : Xiaoming Qin)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file expect in compliance with the License.

#ifndef SIMPLE_DEBUG_H
#define SIMPLE_DEBUG_H

#include <iostream>

using namespace std;

// print 1-d array(int)
void print_array(int* data, const int col);
// print 1-d array(float)
void print_array(float* data, const int col);
// print 2-d array
void print_array(float** data, const int row, const int col);

#endif // SIMPLE_DEBUG_H
