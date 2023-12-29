#ifndef INC_3SEM_UNIQUE_H
#define INC_3SEM_UNIQUE_H

#include <iostream>

template<class T>
class unq_ptr{ //similar size to raw ptr

private:
    T* object;
public:

    unq_ptr(): object(nullptr){};
    explicit unq_ptr(T* obj): object(obj){};
    unq_ptr(const unq_ptr& other) = delete; // prohibited copy constructor
    unq_ptr(unq_ptr&& other){
        object = other.release();
    }; //move constructor

    void swap(unq_ptr&);
    T* get() const {return object;};
    T* release();
    void reset(T*);

    operator bool() const;

    T& operator*(){return *object;};
    T* operator->(){return object;};

    unq_ptr<T> operator=(const unq_ptr&) = delete;

    unq_ptr& operator=(unq_ptr&& other) noexcept {
        auto temp = other.release();
        delete object;
        object = temp;
        return *this;
    }

    template<class T_Derived>
    requires std::derived_from<T_Derived, T>
    unq_ptr(unq_ptr<T_Derived>&& the_derived){
        T_Derived* pder = the_derived.release();
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

    void swap(unq_ptr);
    T* get(){return object;};
    T* release();
    void reset(T*);

    operator bool() const;

    T& operator*(){return *object;};
    T* operator->(){return object;};

    T& operator[](int id){return *(object + id);};

    unq_ptr<T> operator=(const unq_ptr& obj) = delete;

    ~unq_ptr(){if(object){ delete [] object; }};

};

#endif //INC_3SEM_UNIQUE_H
