// Copyright 2016-2016 University of Electronic Science and Technology of China
//                     (author : Xiaoming Qin)
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file expect in compliance with the License.

#include <iostream>
#include "hmm.h"
#include "util.h"
#include "simple_debug.h"
#include "viterbi_decoder.h"

using namespace std;

int main()
{
    // transposed transition matrix file name
    const string trans_file_name = "./data/trans.txt";
    // transposed emission matrix file name
    const string emiss_file_name = "./data/emiss.txt";
    // start probilities pi file name
    const string pi_file_name = "./data/pi.txt";
    // observation sequence file name
    const string obs_file_name = "./data/obs.txt";
    
    // number of hidden state
    const int num_state = 2;
    // number of possible observation state
    const int num_obs_space = 3;
    // length of the sequence of observation
    const int num_obs_seq = 3;

    // create a Hidden Markov Model
    HMM hmm(num_state, num_obs_space);
    // create all three matrix in HMM
    hmm.create_prob_array(trans_file_name, emiss_file_name, pi_file_name);

    // create a viterbi decoder
    ViterbiDecoder viterbi(num_state, num_obs_space, num_obs_seq, hmm.trans_prob, hmm.emiss_prob, hmm.pi_prob);
    // load the sequence of observation
    viterbi.load_obs_sequence(obs_file_name);
    // find the most likely path using viterbi algorithm
    viterbi.viterbi_computer();

    // print
    cout << "*** Example of viterbi algorithm from Wikipedia ***" << endl;
    cout << "transition matrix(transposed)" << endl;
    print_array(hmm.trans_prob, num_state, num_state);
    cout << "emission matrix(transposed)" << endl;
    print_array(hmm.emiss_prob, num_obs_space, num_state);
    cout << "initial probabilities" << endl;
    print_array(hmm.pi_prob, num_state);
    cout << " the observation sequence" << endl;
    print_array(viterbi.obs_seq, num_obs_seq);
    cout << "the most likely state sequence" << endl;
    print_array(viterbi.hid_seq, num_obs_seq);

    return 0;
}
