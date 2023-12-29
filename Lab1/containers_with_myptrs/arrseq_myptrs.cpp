#include "arrseq_myptrs.h"

template<class T>
T& ArraySequence<T>::Get(int i) const{
    if((i < 0) || (i > this->GetLength())){
        throw OutOfRange();
    }
    return the_array->GetFrom(i);
}

template<class T>
ArraySequence<T>& ArraySequence<T>::GetSubSequence(int start, int end) const{
    if(start < 0 || start >= GetLength()){
        throw OutOfRange();
    }
    if(end < 0 || end >= GetLength()){
        throw OutOfRange();
    }
    if(end < start){
        throw InvalidOrder();
    }
    size_t the_size = end-start;
    T* items = new T[the_size];
    for(int i = 0; i < the_size; i++){
        items[i] = Get(start++);
    }
    ArraySequence<T>* res = (new ArraySequence<T> (items, the_size));
    return *res;
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
ArraySequence<T>& ArraySequence<T>::Concat(Sequence<T> *seq){
    size_t len = GetLength();
    size_t lenn = 0;
    if(seq){
        lenn = seq->GetLength();
    }
    size_t the_size = (len + lenn);
    T* items = new T [the_size];
    for(int i = 0; i < len; i++){
        items[i] = Get(i);
    }
    for(int j = 0; j < lenn; j++){
        items[j+len] = seq->Get(j);
    }
    ArraySequence<T>* res = (new ArraySequence<T> (items, the_size));
    return *res;
}

template<class T>
T& ArraySequence<T>::operator[](int index) const{
    return the_array->operator[](index);
}

template class ArraySequence<int>;
template class ArraySequence<int*>;
template class ArraySequence<char>;
template class ArraySequence<char*>;
template class ArraySequence<double>;
template class ArraySequence<double*>;
template class ArraySequence<complex<double>>;
