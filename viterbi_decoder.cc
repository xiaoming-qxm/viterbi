// Copyright 2016-2016 University of Electronic Science and Technology of China
//                     (author : Xiaoming Qin)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file expect in compliance with the License.

#include "viterbi_decoder.h"

void ViterbiDecoder::load_obs_sequence(const string obs_file_name)
{
    obs_seq = create_int_array(T);
    read_file_into_1d_array(obs_file_name, T, obs_seq);
}

void ViterbiDecoder::viterbi_computer()
{
    // allocate memory
    hid_seq = create_int_array(T);
    delta   = create_array(T, K);
    psi     = create_int_array(T, K);

    for ( int i = 0; i != K; ++i )
    {
        delta[0][i] = pi_prob[i] * emiss_prob[obs_seq[0]][i];
        psi[0][i] = 0;
    }

    for ( int j = 1; j != T; ++j )
        for (int i = 0; i != K; ++i )
            find_max_value_index(delta[j-1], trans_prob[i], emiss_prob[obs_seq[j]][i], K, delta[j][i], psi[j][i]);

    hid_seq[T - 1] = find_max_index(delta[T - 1], K);

    for ( int t = T - 2; t != -1; --t )
    {
        hid_seq[t] = psi[t][hid_seq[t + 1]];
    }
}
