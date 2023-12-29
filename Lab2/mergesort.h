#ifndef LAB2_MERGESORT_H
#define LAB2_MERGESORT_H

#include "ISorter.h"
#include "../Lab1/containers_with_myptrs/arrseq_myptrs.h"

template<class T>
class MergeSort : ISorter<T>{

public:
    Sequence<T>* ISort(Sequence<T>* seq, bool (*comparator)(T,T), int left, int right) override;
    ArraySequence<T> Merge(Sequence<T>*, Sequence<T>&, Sequence<T>&);
    void sort(Sequence<T>*);
};


template<class T>
Sequence<T>* MergeSort<T>::ISort(Sequence<T> *seq, bool (*comparator)(T, T), int left, int right){
    sort(seq);
    return seq;
}

template<class T>
ArraySequence<T> MergeSort<T>::Merge(Sequence<T>* seq, Sequence<T>& left_part, Sequence<T>& right_part){
    size_t left = 0;
    size_t right = 0;

    size_t size_left = left_part.GetLength();
    size_t right_size = right_part.GetLength();

    Sequence<T> res = *seq;

    while ((left < size_left) && (right < right_size)){
        if (left_part.Get(left) <= right_part.Get(right)){

            res.Append(left_part.Get(left));
            left++;

        }else{
            res.Append(right_part.Get(right));
            right++;
        }
    }
    while(left < size_left){

        res.Append(left_part.Get(left));
        left++;
    }
    while (right < right_size){

        res.Append(right_part.Get(right));
        right++;
    }
    return res;
}

template<class T>
void MergeSort<T>::sort(Sequence<T>* seq){
    if (seq->GetLength() <= 1){
        return;
    }

    int mid = seq->GetLength()/2;

    ArraySequence<T> left_seq;
    left_seq.Resize(0);
    ArraySequence<T> right_seq;
    right_seq.Resize(0);

    for (int i = 0; i < mid; i++){
        left_seq.Append(seq->Get(i));
    }

    for(int i = mid; i < seq->GetLength(); i++){
        right_seq.Append(seq->Get(i));
    }

    sort(&left_seq);
    sort(&right_seq);
    seq->Clear();
    seq = Merge(seq, left_seq, right_seq);
}

#endif //LAB2_MERGESORT_H
