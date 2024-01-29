#ifndef INC_3SEM_UNIQUE_H
#define INC_3SEM_UNIQUE_H

#include <iostream>
#include <vector>
#include "../containers_with_myptrs/arrseq_myptrs.h"
#include "../containers_with_myptrs/Sequence_container_interface.h"

template<class T>
class unq_ptr{ //similar size to raw ptr

private:
    T* object;
public:

    unq_ptr(): object(nullptr){};
    explicit unq_ptr(T* obj): object(obj){};
    unq_ptr(const unq_ptr& other) = delete; // prohibited copy constructor
    unq_ptr(unq_ptr&& other){
        object = other.Release();
    }; //move constructor

    void Swap(unq_ptr&);
    T* Get() const {return object;};
    T* Release();
    void Reset(T*);

    operator bool() const;

    T& operator*(){return *object;};
    T* operator->(){return object;};

    unq_ptr<T> operator=(const unq_ptr&) = delete;

    unq_ptr& operator=(unq_ptr&& other) noexcept {
        auto temp = other.Release();
        delete object;
        object = temp;
        return *this;
    }

    template<class T_Derived>
    requires std::derived_from<T_Derived, T>
    unq_ptr(unq_ptr<T_Derived>&& the_derived){
        T_Derived* pder = the_derived.Release();
        object = static_cast<T*>(pder);
    }

    ~unq_ptr(){delete object;};
};


template<class T>
class unq_ptr<T[]>{

private:
    T* object;

public:

    unq_ptr(): object(nullptr){};
    explicit unq_ptr(size_t size): object(new T[size]){};
    unq_ptr(unq_ptr& other) = delete;
    unq_ptr(unq_ptr&& other){
        auto temp = other.release();
        delete [] object;
        object = temp;
    };

    void Swap(unq_ptr&);
    T* Get(){return object;};
    T* Release();
    void Reset(T*);

    operator bool() const;

    T& operator*(){return *object;};
    T* operator->(){return object;};

    T& operator[](int id){return *(object + id);};

    unq_ptr<T> operator=(const unq_ptr& obj) = delete;

    ~unq_ptr(){if(object){ delete [] object; }};

};


template<class T>
T* unq_ptr<T>::Release(){
    T* temp = object;
    object = nullptr;
    return temp;
}

template<class T>
void unq_ptr<T>::Swap(unq_ptr& ptr){
    T* temp = ptr.object;
    ptr.object = object;
    object = temp;
}

template<class T>
unq_ptr<T>::operator bool() const{
    return (object != nullptr);
}


template<class T>
void unq_ptr<T>::Reset(T* obj) {
    if (object != obj) {
        delete object;
        object = obj;
    }
}

#endif //INC_3SEM_UNIQUE_H
