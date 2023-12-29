#include "test_myptrs.h"

void TEST_BUBBLESORT(){
    int items[10] = {1, 45, 67, 234, 6789, 1, 0, 4, -2, 7};
    int sorted[10] = {-2, 0, 1, 1, 4, 7, 45, 67, 234, 6789};
    ArraySequence<int> seq(items, 10);
    BubbleSort<int> sort;
    sort.ISort(&seq, &my_comparator, 0, 9);
    for(size_t i = 0; i < seq.GetLength(); i++){
        assert(seq.Get(i) == sorted[i]);
    }

    cout << endl << GREEN << "Bubble sorting algorithm works!" << DEF << endl;
};

void TEST_QUICKSORT(){
    int items[10] = {1, 45, 67, 234, 6789, 1, 0, 4, -2, 7};
    int sorted[10] = {-2, 0, 1, 1, 4, 7, 45, 67, 234, 6789};
    ArraySequence<int> seq(items, 10);
    QuickSort<int> sort;
    sort.ISort(&seq, &my_comparator, 0, 9);
    for(size_t i = 0; i < seq.GetLength(); i++){
        assert(seq.Get(i) == sorted[i]);
    }

    cout << endl << GREEN << "Quick sorting algorithm works!" << DEF << endl;
};

void TEST_SHAKERSORT(){
    int items[10] = {1, 45, 67, 234, 6789, 1, 0, 4, -2, 7};
    int sorted[10] = {-2, 0, 1, 1, 4, 7, 45, 67, 234, 6789};
    ArraySequence<int> seq(items, 10);
    CocktailSort<int> sort;
    sort.ISort(&seq, &my_comparator, 0, 9);
    for(size_t i = 0; i < seq.GetLength(); i++){
        assert(seq.Get(i) == sorted[i]);
    }

    cout << endl << GREEN << "Shaker sorting algorithm works!" << DEF << endl;
};