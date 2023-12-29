#ifndef INC_3SEM_DARR_MYPTRS_H
#define INC_3SEM_DARR_MYPTRS_H

#include <iostream>
#include <complex>
#include "../ptrs/shared.cpp"
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

    DynamicArray(): size(0){};
    explicit DynamicArray(size_t size) : array_ptr(size), size(size){};
    DynamicArray(T *items, size_t the_size);
    DynamicArray(const DynamicArray<T>& array);

    T& GetFrom(int i) const;
    size_t GetSize() const;
    void SetAt(int i, T element);
    void Resize(size_t size);

    void Clear();
    void swap_el(int i, int j);

    T& operator[](int i) {if(i > size || i < 0){throw OutOfRange();}return array_ptr[i];};
    DynamicArray& operator=(const DynamicArray&);
    shrd_ptr<T[]>& operator*(){return array_ptr;};

    ~DynamicArray() = default;

private:
    size_t size;
    shrd_ptr<T[]> array_ptr;
};



#endif //INC_3SEM_DARR_MYPTRS_H
