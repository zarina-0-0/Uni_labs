#ifndef INC_3SEM_TEST_DERIVED_H
#define INC_3SEM_TEST_DERIVED_H

#include "../containers_with_myptrs/arrseq_myptrs.h"
#include "../ptrs/shared.cpp"
#include "../ptrs/unique.h"
//#include "../shapes/circle.h"
//#include "../shapes/Square.h"
//#include "../shapes/shapes.h"

void TEST_DERIVED() {
    //ArraySequence is derived class and Sequence is a base class
    int *items = new int[26];
    ArraySequence<int> *arr_seq(new ArraySequence<int>(items, 26));

    unq_ptr<ArraySequence<int>> derived_arr_seq(arr_seq);
    unq_ptr<Sequence<int>> base_seq = std::move(derived_arr_seq);
    unq_ptr<ArraySequence<int>> derived = move(derived_arr_seq);
}
#endif
