// viterbi_decoder.h

// Copyright 2016-2016 University of Electronic Science and Technology of China
//                     (author : Xiaoming Qin)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file expect in compliance with the License.

#ifndef VITERBI_DECODER_H
#define VITERBI_DECODER_H

#include <iostream>
#include <string>
#include "util.h"

class ViterbiDecoder {
    public:
        // the sequence of observations
        int *obs_seq;
        // the nost likely hidden state sequence
        int *hid_seq;
        // local probability
        float **delta;
        // store argmax index
        int **psi;

        // constructor
        ViterbiDecoder(int a, int b, int c, float** trans, float** emiss, float* pi)
                       : K(a), N(b), T(c), trans_prob(trans), emiss_prob(emiss), pi_prob(pi) { }
        // load observation sequence
        void load_obs_sequence(const string obs_file_name);
        void viterbi_computer();

    public:
        // number of hidden states
        int K;
        // number of possible observations
        int N;
        // length of the observation sequence
        int T;
        // transition probability
        float **trans_prob;
        // emission probability
        float **emiss_prob;
        // start probability pi
        float *pi_prob;

        // create array
        friend int* create_int_array(const int col);
        friend int** create_int_array(const int row, const int col);
        friend float** create_array(const int row, const int col);
        // read file into array
        friend void read_file_into_1d_array(const string file_name, const int col, int* data);

        friend void find_max_value_index(float *p, float *q, float d, const int K, float &delta_val, int &psi_idx);
        friend int find_max_index(float *p, const int K);
};

#endif // VITERBI_DECODER_H

// non-member friend function declaration in class interface HMM
int* create_int_array(const int col);
int** create_int_array(const int row, const int col);
float** create_array(const int row, const int col);
void read_file_into_1d_array(const string file_name, const int col, int* data);
void find_max_value_index(float *p, float *q, float d, const int K, float &delta_val, int &psi_idx);
int find_max_index(float *p, const int K);
