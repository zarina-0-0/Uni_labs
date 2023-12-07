#ifndef INC_3SEM_LISTSEQ_WITH_PTRS_H
#define INC_3SEM_LISTSEQ_WITH_PTRS_H

#include "Sequence_container_interface.h"
#include "linkedlist.cpp"

template<class T>

class ListSequence : public Sequence<T>{

    LinkedList<T> *the_list;

public:

    ListSequence(T *elements, size_t the_size);
    ListSequence();
    ListSequence(const ListSequence<T> & list);

    ~ListSequence() override;

    size_t GetLength() const override;
    T GetFirst() const override; //искл
    T GetLast() const override;  //искл
    T Get(int index) const override;  //искл
    Sequence<T> *GetSubSequence(int start, int end) const override; //искл

    void Append(T item) override;
    void Prepend(T item) override;
    void InsertAt(T item, int index) override; //исключения
    void Set(T item, int index) override;
    Sequence<T>* Concat(Sequence<T> *list) override;
    void clear() override;
    //Sequence<T>* Remove(int index) override;
    void remove(int index) override;


    T & operator[] (int i) const override;
};


#endif //INC_3SEM_LISTSEQ_WITH_PTRS_H
