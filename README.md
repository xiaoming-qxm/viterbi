# Viterbi  
[![Build Status](https://travis-ci.org/daoliker/viterbi.svg?branch=master)](https://travis-ci.org/daoliker/viterbi)
[![License](https://img.shields.io/badge/License-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)  
## C++ implement for Viterbi algorithm and Hidden Markov Model
   
     To run the demo in linux(unix), type the following command:
     (1) $ make
     (2) $ ./viterbi_demo
 
 
 Example of viterbi algorithm in the viterbi_demo is from Wikipedia. if you are interested in the detail, please access "https://en.wikipedia.org/wiki/Viterbi_algorithm".
 

*NOTE: For programming simplicity, I use transposed transition matrix and transposed emission matrix. Check this in the viterbi_demo.*


**Before replacement, please transpose your own matrix firstly.**

If you want to use your own data:
   
     (1) replace four txt in the data folder
     (2) change num_state, num_obs_space, num_seq, into your own courterpart.
