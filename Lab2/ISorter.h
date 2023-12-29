#ifndef LAB2_ISORTER_H
#define LAB2_ISORTER_H

#include "../Lab1/libs/except.h"
#include "../Lab1/containers_with_myptrs/Sequence_container_interface.h"

template<class T>
class ISorter{

    friend class Sequence<T>;

public:

    virtual Sequence<T>* ISort(Sequence<T>* seq, bool (*comparator)(T,T), int left, int right) = 0;

};

template<typename T> bool my_comparator(T, T);
template<typename T>
bool my_comparator(T l, T r){
    return(r < l);
};

template bool my_comparator<int>(int, int);


#endif //LAB2_ISORTER_H
