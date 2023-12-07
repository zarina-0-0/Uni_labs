#ifndef TEST_PTR_NO_CONTAINERS_h
#define TEST_PTR_NO_CONTAINERS_h

#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include "../libs/colour.h"
#include <ostream>
#include <vector>
#include "../ptrs/shared.cpp"
#include "../ptrs/unique.cpp"

using namespace std;


int PASS = 0;
int FAIL = 0;


void CONSTRUCTORS_TESTS_SHRD(){
    shrd_ptr<int> shared_ptr (new int(89));
    assert(*shared_ptr.get() == 89);
    assert(shared_ptr.count() == 1);

    shrd_ptr<int> shared_ptr_copy(shared_ptr);
    assert(*shared_ptr_copy.get() == 89);
    assert(shared_ptr.count() == 2);

    shrd_ptr<int> shared_ptr_assign;
    shared_ptr_assign = shared_ptr_copy;
    assert(*shared_ptr_assign.get() == 89);
    assert(shared_ptr_assign.count() == 3);

    cout << GREEN << "shrd: Passed tests for c-tors and copy c-tors and assignment operator" << DEF << endl;
    PASS++;
}
void CONSTRUCTORS_TESTS_UNQ(){
    unq_ptr<int> unique_ptr (new int(89));
    assert(*unique_ptr.get() == 89);

    unq_ptr<int> unique_ptr_assign = move(unique_ptr);
    assert(*unique_ptr_assign.get() == 89);
    assert(unique_ptr.get() == nullptr);

    cout << GREEN << "unq: Passed tests for c-tors and move c-tors and assignment operator" << DEF << endl;
    PASS++;
}

void FUNCS_TESTS_UNQ(){

    int* ptr = new int(29);
    int* mptr = new int(5);
    unq_ptr<int> unique_ptr (new int(89));
    unique_ptr.reset(ptr);
    assert(*unique_ptr.get() == 29);
    unq_ptr<int> from_released(unique_ptr.release());//it's better to release into another smrtptr because otherwise there can be memory leak
    assert(*from_released.get() == 29);
    assert(unique_ptr.get() == nullptr);
    unique_ptr.reset(mptr);
    from_released.swap(unique_ptr);
    assert(*unique_ptr.get() == 29 && *from_released.get() == 5);

    cout << GREEN << "unq: Passed tests for functions" << DEF << endl;
    PASS++;
}

void FUNCS_TESTS_SHRD(){

    vector<int*> my_vector(10);
    for(int i = 0; i < 10; i++){
        my_vector[i] = new int(i);
    }

    vector<char*> my_vector_ch(10);
    for(int i = 0; i < 10; i++){
        my_vector_ch[i] = new char('a');
    }

    shrd_ptr<char> shared_ptr_char;

    for(int i = 0; i < 10; i++){
        shared_ptr_char.reset(my_vector_ch[i]);
        assert(*(shared_ptr_char.get()) == 'a');
    }

    shrd_ptr<int> shared_ptr (new int(89));
    shrd_ptr<int> more_shared_ptr (new int(9));
    shared_ptr.swap(more_shared_ptr);
    assert(*shared_ptr.get() == 9 && *more_shared_ptr.get() == 89);
    assert(shared_ptr.count() == 1 && more_shared_ptr.count() == 1);

    shared_ptr.reset();
    assert(shared_ptr.get() == nullptr);

    int* check = new int(7);
    shared_ptr.reset(check);
    assert(*shared_ptr.get() == 7);

    assert(shared_ptr.owner_before(more_shared_ptr));

    for(int i = 0; i < 10; i++){
        more_shared_ptr.reset(my_vector[i]);
        assert(*more_shared_ptr.get() == i);
    } // more_shared_ptr.reset was included in cycle because it takes management of pointers and delete them if there is no use


    cout << GREEN << "shrd: Passed tests for functions" << DEF << endl;
    PASS++;
}

void OPERATOR_TESTS_SHRD(){
    vector<int> vec(10);
    for(int i = 0; i < 10; i++){
        vec[i] = i+1;
    }

    vector<int> vec_one (10);
    for(int i = 0; i < 10; i++){
        vec_one[i] = i+2;
    }

    shrd_ptr<vector<int>> pvec_one(new vector(vec));
    shrd_ptr<vector<int>> pvec(new vector(vec_one));
    pvec_one.swap(pvec);
    assert(pvec_one->operator[](0) == 2 && pvec->operator[](0) == 1);

    assert(*pvec_one == vec_one && *pvec == vec);

    cout << GREEN << "shrd: Passed tests for operators" << DEF << endl;
    PASS++;
}

void OPERATOR_TESTS_UNQ(){
    vector<int> vec(10);
    for(int i = 0; i < 10; i++){
        vec[i] = i+1;
    }

    vector<int> vec_one (10);
    for(int i = 0; i < 10; i++){
        vec_one[i] = i+2;
    }

    unq_ptr<vector<int>> pvec_one(new vector(vec));
    unq_ptr<vector<int>> pvec(new vector(vec_one));
    pvec_one.swap(pvec);
    assert(pvec_one->operator[](0) == 2 && pvec->operator[](0) == 1);

    assert(*pvec_one == vec_one && *pvec == vec);

    char* c = new char('a');
    char* h = new char('b');
    unq_ptr<char> chptr(c);
    unq_ptr<char> chptr_one(h);

    chptr = std::move(chptr_one);
    assert(chptr_one.get() == nullptr && *chptr.get() == 'b');

    cout << GREEN << "unq: Passed tests for operators" << DEF << endl;
    PASS++;
}

#endif