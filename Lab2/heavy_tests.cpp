#include "test_myptrs.h"

void TEST_HEAVY_1000(){
    int SIZE = 1000;
    auto p = new int[SIZE];
    ArraySequence<int> arr(p, SIZE);
    Sequence<int>* seq = &arr;
    seq = SeqGenerator(seq, SIZE);
    QuickSort<int> sort;

    auto begin = chrono::high_resolution_clock::now();
    sort.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<chrono::milliseconds>(end - begin);

    cout << BLUE << "Time of sorting 1000 elements by quicksort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;


    seq = SeqGenerator(seq, SIZE);
    BubbleSort<int> sort_;

    auto begin_ = chrono::high_resolution_clock::now();
    sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end_ = chrono::high_resolution_clock::now();
    auto elapsed_ = duration_cast<chrono::milliseconds>(end_ - begin_);

    cout << BLUE << "Time of sorting 1000 elements by bubblesort " << DEF << (elapsed_.count()) << BLUE << " ms" << DEF << endl;

    seq = SeqGenerator(seq, SIZE);
    CocktailSort<int> _sort_;

    auto _begin_ = chrono::high_resolution_clock::now();
    _sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto _end_ = chrono::high_resolution_clock::now();
    auto _elapsed_ = duration_cast<chrono::milliseconds>(_end_ - _begin_);

    cout << BLUE << "Time of sorting 1000 elements by shakersort " << DEF << (_elapsed_.count()) << BLUE << " ms" << DEF << endl;
}

void TEST_HEAVY_5000(){
    cout << endl;
    int SIZE = 5000;
    auto p = new int[SIZE];
    ArraySequence<int> arr(p, SIZE);
    Sequence<int>* seq = &arr;
    seq = SeqGenerator(seq, SIZE);
    QuickSort<int> sort;

    auto begin = chrono::high_resolution_clock::now();
    sort.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<chrono::milliseconds>(end - begin);

    cout << BLUE << "Time of sorting 5000 elements by quicksort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;


    seq = SeqGenerator(seq, SIZE);
    BubbleSort<int> sort_;

    auto begin_ = chrono::high_resolution_clock::now();
    sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end_ = chrono::high_resolution_clock::now();
    auto elapsed_ = duration_cast<chrono::milliseconds>(end_ - begin_);

    cout << BLUE << "Time of sorting 5000 elements by bubblesort " << DEF << (elapsed_.count()) << BLUE << " ms" << DEF << endl;

    seq = SeqGenerator(seq, SIZE);
    CocktailSort<int> _sort_;

    auto _begin_ = chrono::high_resolution_clock::now();
    _sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto _end_ = chrono::high_resolution_clock::now();
    auto _elapsed_ = duration_cast<chrono::milliseconds>(_end_ - _begin_);

    cout << BLUE << "Time of sorting 5000 elements by shakersort " << DEF << (_elapsed_.count()) << BLUE << " ms" << DEF << endl;
}

void TEST_HEAVY_10000(){
    cout << endl;
    int SIZE = 10000;
    auto p = new int[SIZE];
    ArraySequence<int> arr(p, SIZE);
    Sequence<int>* seq = &arr;
    seq = SeqGenerator(seq, SIZE);
    QuickSort<int> sort;

    auto begin = chrono::high_resolution_clock::now();
    sort.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<chrono::milliseconds>(end - begin);

    cout << BLUE << "Time of sorting 10000 elements by quicksort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;


    seq = SeqGenerator(seq, SIZE);
    BubbleSort<int> sort_;

    auto begin_ = chrono::high_resolution_clock::now();
    sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end_ = chrono::high_resolution_clock::now();
    auto elapsed_ = duration_cast<chrono::milliseconds>(end_ - begin_);

    cout << BLUE << "Time of sorting 10000 elements by bubblesort " << DEF << (elapsed_.count()) << BLUE << " ms" << DEF << endl;

    seq = SeqGenerator(seq, SIZE);
    CocktailSort<int> _sort_;

    auto _begin_ = chrono::high_resolution_clock::now();
    _sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto _end_ = chrono::high_resolution_clock::now();
    auto _elapsed_ = duration_cast<chrono::milliseconds>(_end_ - _begin_);

    cout << BLUE << "Time of sorting 10000 elements by shakersort " << DEF << (_elapsed_.count()) << BLUE << " ms" << DEF << endl;
}

void TEST_HEAVY_25000(){
    cout << endl;
    int SIZE = 25000;
    auto p = new int[SIZE];
    ArraySequence<int> arr(p, SIZE);
    Sequence<int>* seq = &arr;
    seq = SeqGenerator(seq, SIZE);
    QuickSort<int> sort;

    auto begin = chrono::high_resolution_clock::now();
    sort.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<chrono::milliseconds>(end - begin);

    cout << BLUE << "Time of sorting 25000 elements by quicksort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;


    seq = SeqGenerator(seq, SIZE);
    BubbleSort<int> sort_;

    auto begin_ = chrono::high_resolution_clock::now();
    sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end_ = chrono::high_resolution_clock::now();
    auto elapsed_ = duration_cast<chrono::milliseconds>(end_ - begin_);

    cout << BLUE << "Time of sorting 25000 elements by bubblesort " << DEF << (elapsed_.count()) << BLUE << " ms" << DEF << endl;

    seq = SeqGenerator(seq, SIZE);
    CocktailSort<int> _sort_;

    auto _begin_ = chrono::high_resolution_clock::now();
    _sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto _end_ = chrono::high_resolution_clock::now();
    auto _elapsed_ = duration_cast<chrono::milliseconds>(_end_ - _begin_);

    cout << BLUE << "Time of sorting 25000 elements by shakersort " << DEF << (_elapsed_.count()) << BLUE << " ms" << DEF << endl;
}

void TEST_HEAVY_50000(){
    cout << endl;
    int SIZE = 50000;
    auto p = new int[SIZE];
    ArraySequence<int> arr(p, SIZE);
    Sequence<int>* seq = &arr;
    seq = SeqGenerator(seq, SIZE);
    QuickSort<int> sort;

    auto begin = chrono::high_resolution_clock::now();
    sort.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<chrono::milliseconds>(end - begin);

    cout << BLUE << "Time of sorting 50000 elements by quicksort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;


    seq = SeqGenerator(seq, SIZE);
    BubbleSort<int> sort_;

    auto begin_ = chrono::high_resolution_clock::now();
    sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end_ = chrono::high_resolution_clock::now();
    auto elapsed_ = duration_cast<chrono::milliseconds>(end_ - begin_);

    cout << BLUE << "Time of sorting 50000 elements by bubblesort " << DEF << (elapsed_.count()) << BLUE << " ms" << DEF << endl;

    seq = SeqGenerator(seq, SIZE);
    CocktailSort<int> _sort_;

    auto _begin_ = chrono::high_resolution_clock::now();
    _sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto _end_ = chrono::high_resolution_clock::now();
    auto _elapsed_ = duration_cast<chrono::milliseconds>(_end_ - _begin_);

    cout << BLUE << "Time of sorting 50000 elements by shakersort " << DEF << (_elapsed_.count()) << BLUE << " ms" << DEF << endl;
}

void TEST_HEAVY_100000(){
    cout << endl;
    int SIZE = 100000;
    auto p = new int[SIZE];
    ArraySequence<int> arr(p, SIZE);
    Sequence<int>* seq = &arr;
    seq = SeqGenerator(seq, SIZE);
    QuickSort<int> sort;

    auto begin = chrono::high_resolution_clock::now();
    sort.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<chrono::milliseconds>(end - begin);

    cout << BLUE << "Time of sorting 100000 elements by quicksort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;


    seq = SeqGenerator(seq, SIZE);
    BubbleSort<int> sort_;

    auto begin_ = chrono::high_resolution_clock::now();
    sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end_ = chrono::high_resolution_clock::now();
    auto elapsed_ = duration_cast<chrono::milliseconds>(end_ - begin_);

    cout << BLUE << "Time of sorting 100000 elements by bubblesort " << DEF << (elapsed_.count()) << BLUE << " ms" << DEF << endl;

    seq = SeqGenerator(seq, SIZE);
    CocktailSort<int> _sort_;

    auto _begin_ = chrono::high_resolution_clock::now();
    _sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto _end_ = chrono::high_resolution_clock::now();
    auto _elapsed_ = duration_cast<chrono::milliseconds>(_end_ - _begin_);

    cout << BLUE << "Time of sorting 100000 elements by shakersort " << DEF << (_elapsed_.count()) << BLUE << " ms" << DEF << endl;
}

void TEST_HEAVY_75000(){
    cout << endl;
    int SIZE = 75000;
    auto p = new int[SIZE];
    ArraySequence<int> arr(p, SIZE);
    Sequence<int>* seq = &arr;
    seq = SeqGenerator(seq, SIZE);
    QuickSort<int> sort;

    auto begin = chrono::high_resolution_clock::now();
    sort.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end = chrono::high_resolution_clock::now();
    auto elapsed = duration_cast<chrono::milliseconds>(end - begin);

    cout << BLUE << "Time of sorting 75000 elements by quicksort " << DEF << (elapsed.count()) << BLUE << " ms" << DEF << endl;


    seq = SeqGenerator(seq, SIZE);
    BubbleSort<int> sort_;

    auto begin_ = chrono::high_resolution_clock::now();
    sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto end_ = chrono::high_resolution_clock::now();
    auto elapsed_ = duration_cast<chrono::milliseconds>(end_ - begin_);

    cout << BLUE << "Time of sorting 75000 elements by bubblesort " << DEF << (elapsed_.count()) << BLUE << " ms" << DEF << endl;

    seq = SeqGenerator(seq, SIZE);
    CocktailSort<int> _sort_;

    auto _begin_ = chrono::high_resolution_clock::now();
    _sort_.Sort(seq, &my_comparator, 0, SIZE-1);
    auto _end_ = chrono::high_resolution_clock::now();
    auto _elapsed_ = duration_cast<chrono::milliseconds>(_end_ - _begin_);

    cout << BLUE << "Time of sorting 75000 elements by shakersort " << DEF << (_elapsed_.count()) << BLUE << " ms" << DEF << endl;
}