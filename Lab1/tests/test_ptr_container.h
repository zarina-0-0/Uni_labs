#include "../containers_with_myptrs/arrseq_myptrs.h"
#include "test_ptr_no_containers.h"

void ARRAY_SEQUENCE_TEST(){

    int* p = new int[10];
    ArraySequence<int> array_seq(p, 10);

    for(int i = 0; i < 10; i++){
        array_seq.Set(i+1, i);
    }
    assert(array_seq.GetLength() == 10);
    assert(array_seq.Get(5) == 6);
    assert(array_seq.GetFirst() == 1);
    assert(array_seq.GetLast() == 10);
    array_seq.Append(6);
    assert(array_seq.GetLength() == 11 && array_seq.GetLast() == 6);
    array_seq.Prepend(20);
    assert(array_seq.GetLength() == 12 && array_seq.GetFirst() == 20);

    int* ptr = new int[10];
    shrd_ptr<ArraySequence<int>> seq(new ArraySequence<int>(ptr, 10));
    for(int i = 0; i < 10; i++){
        seq->Set(9, i);
    }

    shrd_ptr<ArraySequence<int>> the_seq (&array_seq.Concat(seq.get()));
    assert(the_seq.get()->GetLength() == 22);
    assert(the_seq.get()->GetLast() == 9 && the_seq.get()->GetFirst() == 20);
    the_seq.get()->InsertAt(77, 15);
    assert(the_seq.get()->GetLength() == 23 && the_seq.get()->Get(15) == 77);

    shrd_ptr<ArraySequence<int>> the_subseq (&(the_seq.get()->GetSubSequence(5,20)));
    assert(the_subseq.get()->GetLength() == 15);

    the_subseq.get()->Clear();

    char* ch = new char[10];
    ArraySequence<char> char_seq(ch, 10);
    char_seq.InsertAt('a', 3);
    assert(char_seq.Get(3) == 'a');
    shrd_ptr<ArraySequence<char>> char_subseq(&char_seq.GetSubSequence(5,7));
    assert(char_subseq.get()->GetLength() == 2);

    cout << GREEN << "ArraySequence with shrd_ptr: Passed tests for functions" << DEF << endl;
    PASS++;
}