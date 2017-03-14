// simple_debug.cpp

// Copyright 2016-2016 University of Electronic Science and Technology of China
//                     (author : Xiaoming Qin)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file expect in compliance with the License.

#include "simple_debug.h"

// print 1-d array(int)
void print_array(int* data, const int col)
{
    cout << "------------------" << endl;

    for ( int i = 0; i != col; ++i )
        cout << data[i] << " ";
    cout << endl;

    cout << "------------------" << endl;
}

// print 1-d array(float)
void print_array(float* data, const int col)
{
    cout << "------------------" << endl;

    for ( int i = 0; i != col; ++i )
        cout << data[i] << " ";
    cout << endl;

    cout << "------------------" << endl;
}

// print 2-d array
void print_array(float** data, const int row, const int col)
{
    cout << "------------------" << endl;

    for ( int i = 0; i != row; ++i )
    {
        for (int j = 0; j != col; ++j)
            cout << data[i][j] << " ";
        cout << endl;
    }

    cout << "------------------" << endl;
}
