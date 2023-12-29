#ifndef INC_3SEM_ARRSEQ_MYPTRS_H
#define INC_3SEM_ARRSEQ_MYPTRS_H

#include <iostream>
#include "Sequence_container_interface.h"
#include "darr_myptrs.h"
#include "../libs/except.h"

template<class T>
class ArraySequence : public Sequence<T>{

private:

    friend class DynamicArray<T>;
    friend class shared_ptr<T>;
    DynamicArray<T>* the_array;

public:
    ArraySequence(): the_array(){};
    ArraySequence(size_t size): the_array(new DynamicArray<T>(size)){};
    ArraySequence(T* items, size_t the_size): the_array(new DynamicArray<T>(items, the_size)){};
    ArraySequence(shrd_ptr<T[]> items, size_t the_size){
        the_array = new DynamicArray<T>;
        for(int i = 0; i < the_size; i++) {
            the_array->SetAt(i, items[i]);
        }
    };
    ArraySequence(const ArraySequence<T>& arr) : the_array(new DynamicArray<T>(*arr.the_array)){};

    size_t GetLength() const override {return the_array->GetSize();};
    T& GetFirst() const override {return the_array->GetFrom(0);};
    T& GetLast() const override {return the_array->GetFrom(GetLength()-1);};
    T& Get(int i) const override;
    ArraySequence<T>& GetSubSequence(int start, int end) const override;

    void Append(T item) override;
    void Prepend(T item) override;
    void InsertAt(T item, int index) override;
    void Set(T item, int index) override;
    ArraySequence<T>&  Concat(Sequence<T>* seq) override;
    void Clear() override;
    void Remove(int index) override;
    void Swap(int i, int j) override {the_array->swap_el(i,j);};
    void Resize(size_t size) override {the_array->Resize(size);};

    T& operator[](int index) const override;

    ~ArraySequence(){delete the_array;};
};

#endif //INC_3SEM_ARRSEQ_MYPTRS_H
