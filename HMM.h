// HMM.h

// Copyright 2016-2016 University of Electronic Science and Technology of China
//                     (author : Xiaoming Qin)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file expect in compliance with the License.

#ifndef HMM_H
#define HMM_H

#include <iostream>
#include <string>

using namespace std;

class HMM {
    public:
        // transition probability
        float **trans_prob;
        // emission probability
        float **emiss_prob;
        // start probability pi
        float *pi_prob;

        // constructor of class HMM
        HMM(int a, int b) : K(a), N(b) { }
        // create all three matrix in Hidden Markov Model
        void create_prob_array(const string trans_file_name, const string emiss_file_name, const string pi_file_name);

    private:
        // number of hidden states
        int K;
        // number of observations
        int N;

        // create array
        friend float** create_array(const int row, const int col);
        friend float*  create_array(const int col);
        // read file into array
        friend void read_file_into_2d_array(const string file_name, const int row, const int col, float** data);
        friend void read_file_into_1d_array(const string file_name, const int col, float* data);
};

#endif // HMM_H

// non-member friend function declaration in class interface HMM
float** create_array(const int row, const int col);
float*  create_array(const int col);
void read_file_into_2d_array(const string file_name, const int row, const int col, float** data);
void read_file_into_1d_array(const string file_name, const int col, float* data);
