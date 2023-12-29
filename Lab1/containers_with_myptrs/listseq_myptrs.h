#ifndef INC_3SEM_LISTSEQ_WITH_PTRS_H
#define INC_3SEM_LISTSEQ_WITH_PTRS_H

#include "linkedlist.h"
#include "Sequence_container_interface.h"

template<class T>

class ListSequence : public Sequence<T>{

    LinkedList<T> *the_list;

public:

    ListSequence(T *elements, size_t the_size);
    ListSequence();
    ListSequence(const ListSequence<T> & list);

    size_t GetLength() const override {the_list->GetSize();};
    T& GetFirst() const override {the_list->GetFirst();};
    T& GetLast() const override {the_list->GetLast();};
    T& Get(int index) const override {the_list->Get(index)->data;};
    Sequence<T>& GetSubSequence(int start, int end) const override;

    void Append(T item) override;
    void Prepend(T item) override;
    void InsertAt(T item, int index) override;
    void Set(T item, int index) override;
    void Swap(int, int) override;
    void Resize(size_t) override;
    Sequence<T>& Concat(Sequence<T> *list) override;
    void Clear() override;
    void Remove(int index) override;


    T& operator[] (int i) const override;

    ~ListSequence();
};


#endif //INC_3SEM_LISTSEQ_WITH_PTRS_H
