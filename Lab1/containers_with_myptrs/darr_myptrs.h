#ifndef INC_3SEM_DARR_MYPTRS_H
#define INC_3SEM_DARR_MYPTRS_H

#include <iostream>
#include <complex>
#include "../ptrs/shared.h"
#include "../libs/except.h"

template <class T>
class DynamicArray {

    friend std::ostream& operator <<(std::ostream &output, DynamicArray<T> &arr){
        for(size_t i = 0; i < arr.GetSize(); i++){
            output << arr[i] << " ";
        }
        return output;
    };
    friend std::istream& operator >>(std::istream &input, DynamicArray<T> &arr){
        for(size_t i = 0; i < arr.GetSize(); i++){
            input >> arr[i];
        }
        return input;
    };
public:

    DynamicArray(): size(0), array_ptr(){};
    explicit DynamicArray(size_t size) : array_ptr(size), size(size){};
    DynamicArray(T *items, size_t the_size);
    DynamicArray(const DynamicArray<T>& array);

    T& GetFrom(int i) const;
    size_t GetSize() const;
    void SetAt(int i, T element);
    void Resize(size_t size);

    void Clear();
    void Swap(int i, int j);

    T& operator[](int i) {if(i > size || i < 0){throw OutOfRange();}return array_ptr[i];};
    DynamicArray& operator=(const DynamicArray&);
    shrd_ptr<T[]>& operator*(){return array_ptr;};

    ~DynamicArray() = default;

private:
    size_t size = 0;
    shrd_ptr<T[]> array_ptr;
};

using namespace std;

template <class T>
DynamicArray<T>::DynamicArray(T *items, size_t the_size): array_ptr(the_size){
    size = the_size;
    for(int i = 0; i < the_size; i++){
        array_ptr[i] = items[i];
    }
    delete[] items;
}

template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& array) : array_ptr (GetSize()){
    size = array.GetSize();
    for(size_t i = 0; i < size; i++){
        array_ptr[i] = array.GetFrom(i);
    }
} //to create new array and copy everything to it

template <class T>
size_t DynamicArray<T>::GetSize()const{
    if(size == 0)
        return 0;
    return size;
}


template <class T>
void DynamicArray<T>::Resize(size_t the_size){
    if(the_size < 0){
        throw InvalidSize();
    }
    if(the_size > size){
        size_t new_capacity = max(the_size, (size * 2));
        T* new_data = new T[new_capacity];
        for(size_t i = 0; i < size; i++){
            new_data[i] = array_ptr[i];
        }
        array_ptr.Reset(new_data);
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
                delete array_ptr.Get();
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
        if(size == 0)
            return *(array_ptr.Get());
        return *(array_ptr.Get() + i);
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
        array_ptr.Reset(new T[GetSize()]);
        for(int i = 0; i < GetSize(); i++){
            array_ptr = shrd_ptr<T[]>(GetSize());
        }
    }
}

template <class T>
void DynamicArray<T>::Swap(int i, int j){
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


#endif //INC_3SEM_DARR_MYPTRS_H
