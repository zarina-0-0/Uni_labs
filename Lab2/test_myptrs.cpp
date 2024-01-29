#include "test_myptrs.h"

void TEST_BUBBLESORT(){
    int* items = new int[10];
    int stack_array[10] = {1, 45, 67, 234, 6789, 1, 0, 4, -2, 7};
    for(int i = 0; i < 10; i++){
        items[i] = stack_array[i];
    };
    int sorted[10] = {-2, 0, 1, 1, 4, 7, 45, 67, 234, 6789};
    ArraySequence<int> seq(items, 10);
    BubbleSort<int> sort;
    sort.Sort(&seq, &my_comparator, 0, 9);
    for(size_t i = 0; i < seq.GetLength(); i++){
        assert(seq.Get(i) == sorted[i]);
    }

    ArraySequence<int> zero(0);
    sort.Sort(&zero, &my_comparator, 0, 0);
    assert(zero.GetLength() == 0);

    int* one = new int(7);
    ArraySequence<int> one_seq(one, 1);
    sort.Sort(&one_seq, &my_comparator, 0, 0);
    assert(one_seq.GetLength() == 1);
    assert(one_seq.GetFirst() == 7);

    int* two = new int[2];
    two[0] = 35, two[1] = 1;
    ArraySequence<int> two_seq(two, 2);
    sort.Sort(&two_seq, &my_comparator, 0, 1);
    assert(two_seq.GetLength() == 2);
    assert(two_seq.GetFirst() == 1);
    assert(two_seq.Get(1) == 35);

    int* three = new int[3];
    three[0] = 37, three[1] = -2, three[2] = 0;
    ArraySequence<int> three_seq(three, 3);
    sort.Sort(&three_seq, &my_comparator, 0, 2);
    assert(three_seq.GetLength() == 3);
    assert(three_seq.GetFirst() == -2);
    assert(three_seq.Get(1) == 0);
    assert(three_seq.Get(2) == 37);

    cout << endl << GREEN << "Bubble sorting algorithm works!" << DEF << endl;
    cout << endl << GREEN << "Bubble sorting algorithm works for sequences of 0, 1, 2, 3 elements." << DEF << endl;

};

void TEST_QUICKSORT(){
    int* items = new int[10];
    int stack_array[10] = {1, 45, 67, 234, 6789, 1, 0, 4, -2, 7};
    for(int i = 0; i < 10; i++){
        items[i] = stack_array[i];
    };
    int sorted[10] = {-2, 0, 1, 1, 4, 7, 45, 67, 234, 6789};
    ArraySequence<int> seq(items, 10);
    QuickSort<int> sort;
    sort.Sort(&seq, &my_comparator, 0, 9);
    for(size_t i = 0; i < seq.GetLength(); i++){
        assert(seq.Get(i) == sorted[i]);
    }

    ArraySequence<int> zero(0);
    sort.Sort(&zero, &my_comparator, 0, 0);
    assert(zero.GetLength() == 0);

    int* one = new int(7);
    ArraySequence<int> one_seq(one, 1);
    sort.Sort(&one_seq, &my_comparator, 0, 0);
    assert(one_seq.GetLength() == 1);
    assert(one_seq.GetFirst() == 7);

    int* two = new int[2];
    two[0] = 35, two[1] = 1;
    ArraySequence<int> two_seq(two, 2);
    sort.Sort(&two_seq, &my_comparator, 0, 1);
    assert(two_seq.GetLength() == 2);
    assert(two_seq.GetFirst() == 1);
    assert(two_seq.Get(1) == 35);

    int* three = new int[3];
    three[0] = 37, three[1] = -2, three[2] = 0;
    ArraySequence<int> three_seq(three, 3);
    sort.Sort(&three_seq, &my_comparator, 0, 2);
    assert(three_seq.GetLength() == 3);
    assert(three_seq.GetFirst() == -2);
    assert(three_seq.Get(1) == 0);
    assert(three_seq.Get(2) == 37);

    cout << endl << GREEN << "Quick sorting algorithm works!" << DEF << endl;
    cout << endl << GREEN << "Quick sorting algorithm works for sequences of 0, 1, 2, 3 elements!" << DEF << endl;
};

void TEST_SHAKERSORT(){
    int* items = new int[10];
    int stack_array[10] = {1, 45, 67, 234, 6789, 1, 0, 4, -2, 7};
    for(int i = 0; i < 10; i++){
        items[i] = stack_array[i];
    };
    int sorted[10] = {-2, 0, 1, 1, 4, 7, 45, 67, 234, 6789};
    ArraySequence<int> seq(items, 10);
    CocktailSort<int> sort;
    sort.Sort(&seq, &my_comparator, 0, 9);
    for(size_t i = 0; i < seq.GetLength(); i++){
        assert(seq.Get(i) == sorted[i]);
    }

    ArraySequence<int> zero(0);
    sort.Sort(&zero, &my_comparator, 0, 0);
    assert(zero.GetLength() == 0);

    int* one = new int(7);
    ArraySequence<int> one_seq(one, 1);
    sort.Sort(&one_seq, &my_comparator, 0, 0);
    assert(one_seq.GetLength() == 1);
    assert(one_seq.GetFirst() == 7);

    int* two = new int[2];
    two[0] = 35, two[1] = 1;
    ArraySequence<int> two_seq(two, 2);
    sort.Sort(&two_seq, &my_comparator, 0, 1);
    assert(two_seq.GetLength() == 2);
    assert(two_seq.GetFirst() == 1);
    assert(two_seq.Get(1) == 35);

    int* three = new int[3];
    three[0] = 37, three[1] = -2, three[2] = 0;
    ArraySequence<int> three_seq(three, 3);
    sort.Sort(&three_seq, &my_comparator, 0, 2);
    assert(three_seq.GetLength() == 3);
    assert(three_seq.GetFirst() == -2);
    assert(three_seq.Get(1) == 0);
    assert(three_seq.Get(2) == 37);

    cout << endl << GREEN << "Shaker sorting algorithm works!" << DEF << endl;
    cout << endl << GREEN << "Shaker sorting algorithm works for sequences of 0, 1, 2, 3 elements." << DEF << endl;
};