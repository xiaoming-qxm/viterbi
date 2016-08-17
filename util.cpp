// util.cpp

// Copyright 2016-2016 University of Electronic Science and Technology of China
//                     (author : Xiaoming Qin)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file expect in compliance with the License.

#include "util.h"
#include <string>

float** create_array(const int row, const int col)
{
    float **p;
    p = new float*[row];
    for (int i = 0; i <= row; ++i)
        p[i] = new float[col];
    return p;
}

float* create_array(const int col)
{
    float *p;
    p = new float[col];
    return p;
}

int** create_int_array(const int row, const int col)
{
    int **p;
    p = new int*[row];
    for (int i = 0; i <= row; ++i)
        p[i] = new int[col];
    return p;
}

int* create_int_array(const int col)
{
    int *p;
    p = new int[col];
    return p;
}

// read file into a 2-d array
void read_file_into_2d_array(const string file_name, const int row, const int col, float** data)
{
    std::ifstream file(file_name);

    for (int i = 0; i < row; ++i)
    {
        std::string line;
        std::getline(file, line);
        if(!file.good())
            break;

        std::stringstream iss(line);

        for (int j = 0; j < col; ++j)
        {
            std::string val;
            std::getline(iss, val, ',');
            if (!iss.good())
                break;

            std::stringstream convertor(val);
            convertor >> data[i][j];
        }
    }
}

// read file into an 1-d array(float)
void read_file_into_1d_array(const string file_name, int col, float* data)
{
    std::ifstream file(file_name);

    std::string line;
    std::getline(file, line);
    if(!file.good())
        return;

    std::stringstream iss(line);

    for (int j = 0; j < col; ++j)
    {
        std::string val;
        std::getline(iss, val, ',');
        if (!iss.good())
            break;

        std::stringstream convertor(val);
        convertor >> data[j];
    }
}

// read file into an 1-d array(int)
void read_file_into_1d_array(const string file_name, const int col, int* data)
{
    std::ifstream file(file_name);

    std::string line;
    std::getline(file, line);
    if(!file.good())
        return;

    std::stringstream iss(line);

    for (int j = 0; j < col; ++j)
    {
        std::string val;
        std::getline(iss, val, ',');
        if (!iss.good())
            break;

        std::stringstream convertor(val);
        convertor >> data[j];
    }
}

// find maximum value and index
void find_max_value_index(float *p, float *q, float d, const int K, float &delta_val, int &psi_idx)
{
    float tmp = 0.0;
    int max_index = 0;
    float max_val = p[0] * q[0] * d;

    for (int i = 1; i != K; ++i )
    {
        tmp = p[i] * q[i] * d;
        if ( max_val < tmp)
        {
            max_val = tmp;
            max_index = i;
        }

    }

    delta_val = max_val;
    psi_idx = max_index;
}

int find_max_index(float *p, const int K)
{
    float max_val = p[0];
    int max_index = 0;

    for (int i = 1; i != K; ++i )
    {
        if ( max_val < p[i])
        {
            max_val = p[i];
            max_index = i;
        }
    }

    return max_index;
}
