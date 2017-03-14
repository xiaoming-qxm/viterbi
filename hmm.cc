// HMM.cpp

// Copyright 2016-2016 University of Electronic Science and Technology of China
//                     (author : Xiaoming Qin)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file expect in compliance with the License.

#include "hmm.h"

void HMM::create_prob_array(const string trans_file_name, const string emiss_file_name, const string pi_file_name)
{
    trans_prob = create_array(K, K);
    emiss_prob = create_array(N, K);
    pi_prob = create_array(K);

    read_file_into_2d_array(trans_file_name, K, K, trans_prob);
    read_file_into_2d_array(emiss_file_name, N, K, emiss_prob);
    read_file_into_1d_array(pi_file_name, K, pi_prob);
}
