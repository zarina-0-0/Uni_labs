#ifndef LAB2_COCKTAILSORT_H
#define LAB2_COCKTAILSORT_H

#include "ISorter.h"

template<class T>
class CocktailSort : ISorter<T>{

public:
    Sequence<T>* ISort(Sequence<T>* seq,bool (*comparator)(T,T), int left, int right) override;
};

template<class T>
Sequence<T>* CocktailSort<T>::ISort(Sequence<T>* seq, bool (*comparator)(T,T), int left, int right){
    Sequence<T>* res(seq);
    bool swapped = true;
    int start = left;
    int end = right;
    while(swapped){
        swapped = false;
        for(int i = start; i < end; i++){
            if(my_comparator(res->Get(i), res->Get(i+1))){
                res->Swap(i, i+1);
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
        swapped = false;
        --end;
        for(int i = end - 1; i >= start; i--){
            if(my_comparator(res->Get(i), res->Get(i + 1))){
                res->Swap(i, i + 1);
                swapped = true;
            }
        }
        ++start;
    }
    return res;
};

//template<class T> // I thought it works like this
//Sequence<T>* CocktailSort<T>::ISort(Sequence<T>* seq, bool (*comp)(T, T)){
//    Sequence<T>* res(seq);
//    bool flag1 = true, flag2 = true;
//    while(flag1 || flag2){
//        flag1 = false, flag2 = false;
//        for(int i = 0; i < seq->GetLength()-1; i++){
//            if(my_comparator(res->Get(i+1), res->Get(i))){
//                flag1 = true;
//                res->Swap(i, i+1);
//            }
//            if(my_comparator(res->Get(res->GetLength()-1 -i), res->Get(res->GetLength()-2 - i))){
//                flag2 = true;
//                res->Swap(seq->GetLength()-1 -i, seq->GetLength()-2 - i);
//            }
//        }
//    }
//    return res;
//};


#endif //LAB2_COCKTAILSORT_H
