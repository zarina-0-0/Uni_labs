#include "unique.h"

template<class T>
T* unq_ptr<T>::release(){
    T* temp = object;
    object = nullptr;
    return temp;
}

template<class T>
void unq_ptr<T>::swap(unq_ptr& ptr){
    T* temp = ptr.object;
    ptr.object = object;
    object = temp;
}

template<class T>
unq_ptr<T>::operator bool() const{
    return (object != nullptr);
}


template<class T>
void unq_ptr<T>::reset(T* obj) {
    delete object;
    object = obj;
}

template class unq_ptr<int>;
template class unq_ptr<char>;
template class unq_ptr<double>;
template class unq_ptr<std::vector<int>>;
template class unq_ptr<std::vector<double>>;
template class unq_ptr<std::vector<char>>;