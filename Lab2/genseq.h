#ifndef LAB2_GENSEQ_H
#define LAB2_GENSEQ_H

#include<cstdlib>
//#include "ArraySequence.h"
#include "../Lab1/containers_with_myptrs/arrseq_myptrs.h"

template<typename T> Sequence<T>* seq_generator(Sequence<T>* seq, size_t length);
template<typename T>
Sequence<T>* seq_generator(Sequence<T>* seq, size_t length){
    srand((unsigned) time(NULL));
    Sequence<T>* the_seq(seq);
    for(int i = 0; i < length; i++){
        T random_val = 2.4 * (rand() % 200);
        the_seq->Set(random_val, i);
    }
    return the_seq;
}

#endif //LAB2_GENSEQ_H
