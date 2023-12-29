#include "darr_myptrs.h"

using namespace std;

template <class T>
DynamicArray<T>::DynamicArray(T *items, size_t the_size): array_ptr(the_size){
    size = the_size;
    for(int i = 0; i < the_size; i++){
        array_ptr[i] = items[i];
    }
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& array) : array_ptr (GetSize()){
    size = array.GetSize();
    for(size_t i = 0; i < size; i++){
        array_ptr[i] = array.GetFrom(i);
    }
} //to create new array and copy everything to it

template <class T>
size_t DynamicArray<T>::GetSize() const {
    return size;
}


template <class T>
void DynamicArray<T>::Resize(size_t the_size){
    if(the_size < 0){
        throw InvalidSize();
    }
    if(the_size > size){
        size_t new_capacity = max(the_size, (size * 2));
        T *new_data = new T[new_capacity];
        for(size_t i = 0; i < size; i++){
            new_data[i] = array_ptr[i];
        }
        array_ptr.reset(new_data);
    }
    size = the_size;
}

template <class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T> &other)
{
    if (&other != this)
    {
        if (size != other.size)
        {
            if(array_ptr)
                delete array_ptr.get();
            size = other.size;
            array_ptr = shrd_ptr<T[]>(size);
        }

        for (size_t i = 0; i < size; i++)
            array_ptr[i] = other.GetFrom(i);
    }

    return *this;
}

template <class T>
T& DynamicArray<T>::GetFrom(int i) const{
    if( (i < 0) || (i > size)){
        throw OutOfRange();
    }
    else{
        return *(array_ptr.get() + i);
    }
}

template <class T>
void DynamicArray<T>::SetAt(int i, T element){
    if( (i < 0) || (i > size)){
        throw OutOfRange();
    }
    else{
        array_ptr[i] = element;
    }
}

template <class T>
void DynamicArray<T>::Clear(){
    if(!(array_ptr)){
        throw Empty();
    }
    else{
        array_ptr.reset(new T[GetSize()]);
        for(int i = 0; i < GetSize(); i++){
            array_ptr = shrd_ptr<T[]>(GetSize());
        }
    }
}

template <class T>
void DynamicArray<T>::swap_el(int i, int j){
    if(!array_ptr){
        throw Empty();
    }
    else if((i > size) || (i < 0)){
        throw OutOfRange();
    }
    else if((j > size) || (j < 0)){
        throw OutOfRange();
    }
    else{
        T temp;
        temp = array_ptr[i];
        array_ptr[i] = array_ptr[j];
        array_ptr[j] = temp;
    }
};

template class DynamicArray<int>;
template class DynamicArray<int*>;
template class DynamicArray<char>;
template class DynamicArray<char*>;
template class DynamicArray<double>;
template class DynamicArray<double*>;
template class DynamicArray<complex<double>>;

