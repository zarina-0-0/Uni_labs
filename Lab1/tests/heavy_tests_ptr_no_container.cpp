#include "tests.h"

using namespace chrono;
typedef high_resolution_clock C;

void HEAVY_FUNCS_TESTS_SHRD(){
    shared_ptr<int> shared_ptr_one(new int(0));
    shared_ptr<int> shared_ptr_two(new int(1));
    shrd_ptr<int> my_shared_ptr_one(new int(2));
    shrd_ptr<int> my_shared_ptr_two(new int(3));

    vector<int*> leaking_vector(100);
    vector<shrd_ptr<int>> my_shrd_notleaking_vector(1000000);
    vector<shared_ptr<int>> shrd_notleaking_vector(1000000);

    auto begin = C::now();
    for (int i = 0; i < 100000; i++) {
        my_shared_ptr_one.reset(new int(i));
    }
    auto end = C::now();
    auto elapsed = duration_cast<milliseconds>(end - begin);
    cout << BLUE << "Time of reseting my shared ptrs: " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;

    auto beginn = C::now();
    for (int i = 0; i < 100000; i++) {
        shared_ptr_one.reset(new int(i));
    }
    auto endd = C::now();
    auto elapsedd = duration_cast<milliseconds>(endd - beginn);
    cout << BLUE << "Time of reseting library shared pts: " << DEF << (elapsedd.count()) << BLUE << " ms" << DEF << endl;
//----------------------------------------------------------------------------------------------------------------------
    auto ibegin = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        my_shared_ptr_one.swap(my_shared_ptr_two);
    }
    auto iend = high_resolution_clock::now();
    auto ielapsed = duration_cast<milliseconds>(iend - ibegin);
    cout << BLUE << "Time of swaping my shared pts: " << DEF << (ielapsed.count()) << BLUE << " ms" << DEF << endl;

    auto iibegin = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        shared_ptr_one.swap(shared_ptr_two);
    }
    auto iiend = high_resolution_clock::now();
    auto iielapsed = duration_cast<milliseconds>(iiend - iibegin);
    cout << BLUE << "Time of swaping library shared pts: " << DEF << (iielapsed.count()) << BLUE << " ms" << DEF << endl;

//----------------------------------------------------------------------------------------------------------------------
    for(int i = 0; i < 10; i++){
        leaking_vector[i] = new int(i);
    }
    for(int i = 0; i < 10; i++){
        my_shared_ptr_one.reset(leaking_vector[i]);
    }
    for(int i = 0; i < 1000000; i++){
        my_shrd_notleaking_vector[i].reset(new int(i));
    }
    for(int i = 0; i < 1000000; i++){
        shrd_notleaking_vector[i].reset(new int(i));
    }

    auto thebegin = high_resolution_clock::now();
    for(int i = 0; i < 1000000; i++){
        my_shrd_notleaking_vector[999999-i].swap(my_shrd_notleaking_vector[i]);
    }
    auto theend = high_resolution_clock::now();
    auto theelapsed = duration_cast<milliseconds>(theend - thebegin);
    cout << BLUE << "Time of swaping my shared ptrs in vector: " << DEF << (theelapsed.count()) << BLUE << " ms" << DEF << endl;

    auto be = high_resolution_clock::now();
    for(int i = 0; i < 1000000; i++){
        shrd_notleaking_vector[999999-i].swap(shrd_notleaking_vector[i]);
    }
    auto en = high_resolution_clock::now();
    auto el = duration_cast<milliseconds>(en - be);
    cout << BLUE << "Time of swaping library shared ptrs in vector: " << DEF << (el.count()) << BLUE << " ms" << DEF << endl;
}

void HEAVY_FUNCS_TESTS_UNQ(){
    unique_ptr<int> unique_ptr_one(new int(4));
    unique_ptr<int> unique_ptr_two(new int(5));
    unq_ptr<int> my_unique_ptr_one(new int(6));
    unq_ptr<int> my_unique_ptr_two(new int(7));

    vector<int*> leaking_vector(100);
    vector<unq_ptr<int>> my_unq_notleaking_vector(10);
    vector<unique_ptr<int>> unq_notleaking_vector(10);

    auto begin = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        my_unique_ptr_one.swap(my_unique_ptr_two);
    }
    auto end = high_resolution_clock::now();
    auto elapsed = duration_cast<milliseconds>(end - begin);
    cout << BLUE << "Time of swaping my unique pts: " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;

    auto begg = high_resolution_clock::now();
    for (int i = 0; i < 1000000; i++) {
        unique_ptr_one.swap(unique_ptr_two);
    }
    auto ee = high_resolution_clock::now();
    auto elapss = duration_cast<milliseconds>(ee - begg);
    cout << BLUE << "Time of swaping library unique pts: " << DEF << (elapss.count()) << BLUE << " ms" << DEF << endl;
}