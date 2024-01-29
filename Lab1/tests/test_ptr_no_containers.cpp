#include "tests.h"

int PASS = 0;
int FAIL = 0;

void CONSTRUCTORS_TESTS_SHRD(){
    shrd_ptr<int> shared_ptr (new int(89));
    assert(*shared_ptr.Get() == 89);
    assert(shared_ptr.Count() == 1);

    shrd_ptr<int> shared_ptr_copy(shared_ptr);
    assert(*shared_ptr_copy.Get() == 89);
    assert(shared_ptr.Count() == 2);

    shrd_ptr<int> shared_ptr_assign;
    shared_ptr_assign = shared_ptr_copy;
    assert(*shared_ptr_assign.Get() == 89);
    assert(shared_ptr_assign.Count() == 3);

    cout << GREEN << "shrd: Passed tests for c-tors and copy c-tors and assignment operator" << DEF << endl;
    PASS++;
}
void CONSTRUCTORS_TESTS_UNQ(){
    unq_ptr<int> unique_ptr (new int(89));
    assert(*unique_ptr.Get() == 89);

    unq_ptr<int> unique_ptr_assign = move(unique_ptr);
    assert(*unique_ptr_assign.Get() == 89);
    assert(unique_ptr.Get() == nullptr);

    cout << GREEN << "unq: Passed tests for c-tors and move c-tors and assignment operator" << DEF << endl;
    PASS++;
}

void FUNCS_TESTS_UNQ(){

    int* ptr = new int(29);
    int* mptr = new int(5);
    unq_ptr<int> unique_ptr (new int(89));
    unique_ptr.Reset(ptr);
    assert(*unique_ptr.Get() == 29);
    unq_ptr<int> from_released(unique_ptr.Release());//it's better to release into another smrtptr because otherwise there can be memory leak
    assert(*from_released.Get() == 29);
    assert(unique_ptr.Get() == nullptr);
    unique_ptr.Reset(mptr);
    from_released.Swap(unique_ptr);
    assert(*unique_ptr.Get() == 29 && *from_released.Get() == 5);

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
        shared_ptr_char.Reset(my_vector_ch[i]);
        assert(*(shared_ptr_char.Get()) == 'a');
    }

    shrd_ptr<int> shared_ptr (new int(89));
    shrd_ptr<int> more_shared_ptr (new int(9));
    shared_ptr.Swap(more_shared_ptr);
    assert(*shared_ptr.Get() == 9 && *more_shared_ptr.Get() == 89);
    assert(shared_ptr.Count() == 1 && more_shared_ptr.Count() == 1);

    int* check = new int(7);
    shared_ptr.Reset(check);
    assert(*shared_ptr.Get() == 7);

    for(int i = 0; i < 10; i++){
        more_shared_ptr.Reset(my_vector[i]);
        assert(*more_shared_ptr.Get() == i);
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
    pvec_one.Swap(pvec);
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
    pvec_one.Swap(pvec);
    assert(pvec_one->operator[](0) == 2 && pvec->operator[](0) == 1);

    assert(*pvec_one == vec_one && *pvec == vec);

    char* c = new char('a');
    char* h = new char('b');
    unq_ptr<char> chptr(c);
    unq_ptr<char> chptr_one(h);

    chptr = std::move(chptr_one);
    assert(chptr_one.Get() == nullptr && *chptr.Get() == 'b');

    cout << GREEN << "unq: Passed tests for operators" << DEF << endl;
    PASS++;
}
