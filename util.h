// util.h

// Copyright 2016-2016 University of Electronic Science and Technology of China
//                     (author : Xiaoming Qin)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file expect in compliance with the License.

#ifndef UTIL_H
#define UTIL_H

#include <fstream>
#include <sstream>

using namespace std;

int* create_int_array(const int col);
int** create_int_array(const int row, const int col);
float* create_array(const int col);
float** create_array(const int row, const int col);

void read_file_into_2d_array(const string file_name, const int row, const int col, float** data);
void read_file_into_1d_array(const string file_name, int col, float* data);
void read_file_into_1d_array(const string file_name, int col, int* data);

void find_max_value_index(float *p, float *q, float d, const int K, float &delta_val, int &psi_idx);
int  find_max_index(float *p, const int K);
#endif // UTIL_H
