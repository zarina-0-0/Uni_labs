#ifndef LAB2_BUBBLESORT_H
#define LAB2_BUBBLESORT_H

#include "ISorter.h"

template<class T>
class BubbleSort : ISorter<T>{

public:

    Sequence<T>* Sort(Sequence<T>*, bool (*comparator)(T,T), int left, int right) override;
};

template<class T>
Sequence<T>* BubbleSort<T>::Sort(Sequence<T>* seq, bool (*comparator)(T,T), int left, int right){
    Sequence<T>* res(seq);
    bool flag = true;
    int start = left;
    int end = right;
    while(flag){
        flag = false;
        for(int j = 0; j < end; ++j){
            if( my_comparator(res->Get(j), res->Get(j+1)) ){
                res->Swap(j, j+1);
                flag = true;
            }
        }
    }
    return res;
};

#endif //LAB2_BUBBLESORT_H
