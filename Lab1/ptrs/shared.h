#ifndef INC_3SEM_SHARED_H
#define INC_3SEM_SHARED_H

#include "iostream"

template <class T>
class shrd_ptr { //bigger than a raw pointer

private:
    T* object;
    size_t* use_count;

public:

    shrd_ptr(): object(), use_count(){};
    explicit shrd_ptr(T* obj) : object(obj), use_count(new size_t(1)) {};

    shrd_ptr(const shrd_ptr&);
    shrd_ptr(shrd_ptr&&);


    void Swap(shrd_ptr&); // can be realised using overloaded funcs?
    T* Get() { if(!object){return nullptr;}else{ return object;} }; //allows changing
    size_t& Count() { return *use_count; };
    void Reset(T *); //changing where this points to
    T* Release();

    T& operator*() { return *object; };  //means that using * with shared ptr will return ref to it
    T* operator->() { return object; };  //allows to have access to object's methods
    shrd_ptr<T>& operator=(const shrd_ptr<T>&);
    shrd_ptr<T>& operator=(shrd_ptr<T>&&) noexcept;
    explicit operator bool() const; //returns true if object exists

    ~shrd_ptr(){
        if(!use_count)
            return;
        if(!object){
            delete use_count;
            return;
        }else{
            --(*use_count);
            if (*use_count == 0) {
                delete object;
                delete use_count;
            }
        }
    }

    template<class T_Derived>
    requires std::derived_from<T_Derived, T>
    shrd_ptr(shrd_ptr<T_Derived>&& the_derived){
        T_Derived* pder = the_derived.object;
        object = nullptr;
        object = static_cast<T*>(pder);
    }


};

template <class T>
class shrd_ptr<T[]>{ //for array

private:
    T* object;
    size_t* use_count;

public:

    shrd_ptr<T[]>(): object(), use_count(){};
    explicit shrd_ptr<T[]>(size_t the_size): object(new T[the_size]), use_count(new size_t(1)) {};

    shrd_ptr<T[]>(const shrd_ptr<T[]>&);
    shrd_ptr<T[]>(shrd_ptr<T[]>&& other);

    void Swap(shrd_ptr&);
    T* Get() const { return object; };
    size_t& Count() { return *use_count; };

    void Reset(T *);
    T* Release();

    T& operator*() { return *object; };
    T* operator->() { return object; };
    T& operator[](int id){return *(object + id);};
    shrd_ptr<T[]>& operator=(const shrd_ptr<T[]>& other);
    explicit operator bool() const;

    ~shrd_ptr<T[]>() {
        if(!use_count)
            return;
        if(!object) {
            delete use_count;
            return;
        }
        else{
            --(*use_count);
            if (*use_count == 0) {
                delete [] object;
                delete use_count;
            }
        }
    }
};

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
    other.use_count = nullptr;
    other.object = nullptr;
    use_count = temp_count;
    object = temp_obj;
}


template<class T>
shrd_ptr<T>& shrd_ptr<T>::operator=(const shrd_ptr<T>& other){
    if(use_count){
        --(*use_count);
    }
    if(other){
        object = other.object;
        use_count = other.use_count;
        ++(*use_count);
    }else{
        object = nullptr;
        use_count = nullptr;
    }
    return *this;
}

template<class T>
shrd_ptr<T[]>& shrd_ptr<T[]>::operator=(const shrd_ptr<T[]>& other) {
    if(use_count){
        --(*use_count);
    }
    if(other){
        object = other.object;
        use_count = other.use_count;
        ++(*use_count);
    }else{
        object = nullptr;
        use_count = nullptr;
    }
    return *this;
}

template<class T>
shrd_ptr<T>& shrd_ptr<T>::operator=(shrd_ptr<T>&& other) noexcept{
    object = other.object;
    use_count = other.use_count;
    return *this;
}

template<class T>
void shrd_ptr<T>::Swap(shrd_ptr& ptr) {
    T* temp = ptr.object;
    size_t* ref = ptr.use_count;
    ptr.object = object;
    ptr.use_count = use_count;
    object = temp;
    use_count = ref;
}

template<class T>
T* shrd_ptr<T>::Release(){
    T* temp = object;
    if (use_count && *use_count > 0) {
        (*use_count)--;
        if (*use_count == 0) {
            delete object;
            delete use_count;
            object = nullptr;
            use_count = nullptr;
        }
    }
    return temp;
}

template<class T>
void shrd_ptr<T>::Reset(T* obj){
    if (object != obj) {
        Release();
        object = obj;
        use_count = new size_t(1);
    }
}

template<class T>
T* shrd_ptr<T[]>::Release(){
    T* temp = object;
    if (use_count && *use_count > 0) {
        (*use_count)--;
        if (*use_count == 0) {
            delete[] object;
            delete use_count;
            object = nullptr;
            use_count = nullptr;
        }
    }
    return temp;
}

template<class T>
void shrd_ptr<T[]>::Reset(T* obj) {
    if (object != obj) {
        Release();
        object = obj;
        use_count = new size_t(1);
    }
}

template<class T>
shrd_ptr<T>::operator bool() const {
    return (object != nullptr);
}

template<class T>
shrd_ptr<T[]>::operator bool() const {
    return (object != nullptr);
}

#endif //INC_3SEM_SHARED_H

