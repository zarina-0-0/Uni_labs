#ifndef INC_3SEM_SEQUENCE_CONTAINER_INTERFACE_H
#define INC_3SEM_SEQUENCE_CONTAINER_INTERFACE_H
#include <iostream>
#include <string>
#include <sstream>
#include "../ptrs/shared.h"

template <class T>
class Sequence{

    friend std::ostream &operator <<(std::ostream &output, const Sequence<T> &arr){
        output<< arr.ToString();
        return output;
    }

public:
    virtual size_t GetLength() const = 0;
    virtual T& GetFirst() const = 0;
    virtual T& GetLast() const = 0;
    virtual T& Get(int index) const = 0;

    virtual Sequence<T>* GetSubSequence(int start, int end) = 0;
    virtual Sequence<T>* Concat(Sequence<T>* list) = 0;

    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;
    virtual void Set(T item, int index) = 0;
    virtual void Clear() = 0;
    virtual void Remove(int index) = 0;
    virtual void Swap(int i, int j) = 0;
    virtual void Resize(size_t) = 0;

    virtual T& operator[](int i) const = 0;

    std::string ToString() const;
    virtual ~Sequence() = default;
};

template<class T>
std::string Sequence<T>::ToString() const{
    if(GetLength() == 0){
        return "{ }";
    }
    std::ostringstream oss;
    oss << "{ " << this->GetFirst() << " ";
    for(int i = 1; i < GetLength(); i++){
        oss << this->Get(i) << " ";
    }
    oss << "}";
    return oss.str();
};

#endif //INC_3SEM_SEQUENCE_CONTAINER_INTERFACE_H
