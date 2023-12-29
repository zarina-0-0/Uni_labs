#ifndef INC_3SEM_SHARED_CPP
#define INC_3SEM_SHARED_CPP
#include "shared.h"

template<class T>
shrd_ptr<T>::shrd_ptr(const shrd_ptr<T>& other){
    use_count = other.use_count;
    object = other.object;
    if(other)
       ++(*use_count);
}

template<class T>
shrd_ptr<T>::shrd_ptr(shrd_ptr<T>&& other){
    auto temp_count = other.use_count;
    auto temp_obj = other.object;
    other.object = nullptr;
    other.use_count = nullptr;
    use_count = temp_count;
    object = temp_obj;
}


template<class T>
shrd_ptr<T>& shrd_ptr<T>::operator=(const shrd_ptr<T>& other) {
    if(other){
        object = other.object;
        use_count = other.use_count;
    }
    ++(*use_count);
    return *this;
}

template<class T>
shrd_ptr<T[]>& shrd_ptr<T[]>::operator=(const shrd_ptr<T[]>& other) {
    if(other){
        object = other.object;
        use_count = other.use_count;
    }
    ++(*use_count);
    return *this;
}

template<class T>
shrd_ptr<T>& shrd_ptr<T>::operator=(shrd_ptr<T>&& other) noexcept{
    object = other.object;
    use_count = other.use_count;
    delete other.object;
    delete other.use_count;
    return *this;
}

template<class T>
void shrd_ptr<T>::swap(shrd_ptr& ptr) {
    T* temp = ptr.object;
    size_t* ref = ptr.use_count;
    ptr.object = object;
    ptr.use_count = use_count;
    object = temp;
    use_count = ref;
}

template<class T>
void shrd_ptr<T>::reset() {
    if(!use_count) {
        return;
    }
    if(*use_count > 1) {
        (*use_count)--;
        delete object;
        object = nullptr;
    }else if(*use_count == 1){
        delete object;
        object = nullptr;
        delete use_count;
        use_count = nullptr;
    }else if(*use_count == 0) {
        object = nullptr;
    } else {
       return;
    }
}

template<class T>
void shrd_ptr<T[]>::reset() {
    if(!use_count) {
        return;
    }
    if(*use_count > 1) {
        (*use_count)--;
        delete [] object;
        object = nullptr;
    }else if(*use_count == 1){
        delete [] object;
        object = nullptr;
        delete use_count;
        use_count = nullptr;
    }else if(*use_count == 0) {
        object = nullptr;
    } else {
        return;
    }
}

template<class T>
void shrd_ptr<T>::reset(T* obj){
    if(!use_count) {
        object = obj;
        use_count = new size_t(1);
        return;
    }else if(*use_count > 1) {
        (*use_count)--;
        object = nullptr;
        use_count = nullptr;
        object = obj;
        use_count = new size_t(1);
    }else if(*use_count == 1) {
        delete object;
        object = nullptr;
        object = obj;
    }else if(*use_count == 0) {
        object = obj;
        *use_count = 1;
    }
}

template<class T>
void shrd_ptr<T[]>::reset(T* obj){
    if(!use_count) {
        object = obj;
        use_count = new size_t(1);
        return;
    }else if(*use_count > 1) {
        (*use_count)--;
        object = nullptr;
        use_count = nullptr;
        object = obj;
        use_count = new size_t(1);
    }else if(*use_count == 1) {
        delete [] object;
        object = nullptr;
        object = obj;
    }else if(*use_count == 0) {
        object = obj;
        *use_count = 1;
    }
}

template<class T>
bool shrd_ptr<T>::owner_before(const shrd_ptr<T> &other){
    if(&other < this)
        return true;
    else
        return false;
} //checks if other was made before this

template<class T>
bool shrd_ptr<T[]>::owner_before(const shrd_ptr<T[]> &other){
    if(&other < this)
        return true;
    else
        return false;
}

template<class T>
shrd_ptr<T>::operator bool() const {
    return (object != nullptr);
}

template<class T>
shrd_ptr<T[]>::operator bool() const {
    return (object != nullptr);
}

template class shrd_ptr<int>;
template class shrd_ptr<char>;
template class shrd_ptr<double>;
template class shrd_ptr<int[]>;
template class shrd_ptr<char[]>;
template class shrd_ptr<double[]>;

#endif
































