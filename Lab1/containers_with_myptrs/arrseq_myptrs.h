#ifndef INC_3SEM_ARRSEQ_MYPTRS_H
#define INC_3SEM_ARRSEQ_MYPTRS_H

#include <iostream>
#include "Sequence_container_interface.h"
#include "darr_myptrs.h"
#include "../libs/except.h"

template<class T>
class ArraySequence: public Sequence<T>{

private:

    friend class DynamicArray<T>;
    friend class shared_ptr<T>;
    DynamicArray<T>* the_array;

public:
    ArraySequence(): the_array(0){};
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

    ArraySequence<T>* GetSubSequence(int start, int end) override;
    ArraySequence<T>* Concat(Sequence<T>* seq) override;

    void Append(T item) override;
    void Prepend(T item) override;
    void InsertAt(T item, int index) override;
    void Set(T item, int index) override;
    void Clear() override;
    void Remove(int index) override;
    void Swap(int i, int j) override {the_array->Swap(i,j);};
    void Resize(size_t size) override {the_array->Resize(size);};

    T& operator[](int index) const override;

    ~ArraySequence(){delete the_array;};
};

template<class T>
T& ArraySequence<T>::Get(int i) const{
    if((i < 0) || (i > this->GetLength())){
        throw OutOfRange();
    }
    return the_array->GetFrom(i);
}

template<class T>
void ArraySequence<T>::Prepend(T item){
    the_array->Resize(GetLength() + 1);
    for(int i = the_array->GetSize(); i >= 0; i--){
        if((i-1) < 0){
            the_array->SetAt(0, item);
            break;
        }
        the_array->SetAt(i, Get(i-1));
    }
}

template<class T>
void ArraySequence<T>::Append(T item){
    the_array->Resize(GetLength() + 1);
    the_array->SetAt(GetLength() - 1, item);
}

template<class T>
void ArraySequence<T>::InsertAt(T item, int index){
    if(index < 0 || index > GetLength()){
        throw OutOfRange();
    }else if(index == 0){
        Prepend(item);
    }else if(index == GetLength()){
        Append(item);
    }
    else{
        the_array->Resize(GetLength() + 1);
        for(int i = GetLength(); i >= index; i--){
            if((i-1) < index){
                the_array->SetAt(index, item);
                break;
            }
            the_array->SetAt(i, the_array->GetFrom(i-1));
        }
    }
}

template<class T>
void ArraySequence<T>::Set(T item, int index){
    if((index < 0) || (index > this->GetLength())){
        throw OutOfRange();
    }
    the_array->SetAt(index, item);
}

template<class T>
void ArraySequence<T>::Clear(){
    the_array->Clear();
}

template<class T>
void ArraySequence<T>::Remove(int index){
    if(index < 0 || index > GetLength()){
        throw OutOfRange();
    }
    for(int i = index; i < (GetLength() - 1); i++){
        if((i + 1) > GetLength()){
            break;
        }
        this->Set(Get(i+1), index);
    }
    the_array->Resize(GetLength() - 1);
}

template<class T>
ArraySequence<T>* ArraySequence<T>::Concat(Sequence<T> *seq){
    size_t len = GetLength();
    size_t lenn = (seq ? seq->GetLength() : 0);
    size_t the_size = len + lenn;

    T* items = new T[the_size];

    for(size_t i = 0; i < len; ++i) {
        items[i] = Get(i);
    }

    for(size_t j = 0; j < lenn; ++j) {
        items[j + len] = seq->Get(j);
    }

    ArraySequence<T>* result = new ArraySequence<T>(items, the_size);
    // No need to delete[] items here as ownership is transferred to the ArraySequence

    return result;
}

template<class T>
ArraySequence<T>* ArraySequence<T>::GetSubSequence(int start, int end){
    if (start < 0 || start >= GetLength() || end < 0 || end >= GetLength() || end < start) {
        throw OutOfRange(); // You may want to define and throw this exception appropriately
    }

    size_t the_size = end - start + 1; // Adjust the size calculation

    T* items = new T[the_size];

    for (int i = 0; i < the_size; ++i) {
        items[i] = Get(start + i); // Use start + i instead of incrementing start directly
    }

    ArraySequence<T>* res = new ArraySequence<T>(items, the_size);
    // No need to delete[] items here as ownership is transferred to the ArraySequence

    return res;
}


template<class T>
T& ArraySequence<T>::operator[](int index) const{
    return the_array->operator[](index);
}

#endif //INC_3SEM_ARRSEQ_MYPTRS_H
