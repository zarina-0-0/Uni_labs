#ifndef LAB2_QUICKSORT_H
#define LAB2_QUICKSORT_H

#include "ISorter.h"

template<class T>
class QuickSort : ISorter<T>{
public:
    Sequence<T>* ISort(Sequence<T>*, bool (*comparator)(T,T), int left, int right) override;
    int Partition(Sequence<T>*, int, int);
};

template<typename T>
int QuickSort<T>::Partition(Sequence<T>* seq, int left, int right){
    T pivot = seq->Get(right);
    int i = left-1;

    for(size_t j = left; j <= right; j++){
        if(seq->Get(j) < pivot){
            i++;
            seq->Swap(i, j);
        }
    }
    seq->Swap(i+1, right);
    return i+1;
}

template <class T>
Sequence<T>* QuickSort<T>::ISort(Sequence<T>* seq, bool (*comparator)(T,T), int left, int right){
    if(right > left){
        int index_of_pivot = Partition(seq, left, right);

        ISort(seq, &my_comparator, left, index_of_pivot - 1);
        ISort(seq, &my_comparator, index_of_pivot + 1, right);
    }
    return seq;
}



#endif //LAB2_QUICKSORT_H
