#ifndef INC_3SEM_SHARED_H
#define INC_3SEM_SHARED_H

#include "iostream"

template <class T>
class shrd_ptr { //bigger than a raw pointer

private:
    T* object;
    size_t* use_count;

public:

    shrd_ptr(): object(nullptr), use_count(nullptr){};
    explicit shrd_ptr(T* obj) : object(obj), use_count(new size_t(1)) {};

    shrd_ptr(const shrd_ptr&);
    shrd_ptr(shrd_ptr&&);


    void swap(shrd_ptr&); // can be realised using overloaded funcs?
    T* get() { if(!object){return nullptr;}else{ return object;} }; //allows changing
    size_t& count() { return *use_count; };

    void reset(); //freeing the place where this ptr points to
    void reset(T *); //changing where this points to

    bool owner_before(const shrd_ptr &other); //checks if other is before this

    T& operator*() { return *object; };  //means that using * with shared ptr will return ref to it
    T* operator->() { return object; };  //allows to have access to object's methods
    shrd_ptr<T>& operator=(const shrd_ptr<T>&);
    shrd_ptr<T>& operator=(shrd_ptr<T>&&) noexcept;
    explicit operator bool() const; //returns true if object exists

    ~shrd_ptr() {
        if(!use_count)
            return;
        if(!object) {
            delete use_count;
            return;
        }
        else{
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

    shrd_ptr<T[]>(): object(nullptr), use_count(nullptr){};
    explicit shrd_ptr<T[]>(size_t the_size): object(new T[the_size]), use_count(new size_t(1)) {};

    shrd_ptr<T[]>(const shrd_ptr<T[]>&);
    shrd_ptr<T[]>(shrd_ptr<T[]>&& other);

    void swap(shrd_ptr&);
    T* get() const { return object; };
    size_t& count() { return *use_count; };

    void reset();
    void reset(T *);

    bool owner_before(const shrd_ptr &other);

    T& operator*() { return *object; };
    T* operator->() { return object; };
    T& operator[](int id){return *(object + id);};
    shrd_ptr<T[]>& operator=(const shrd_ptr<T[]>& other);
    explicit operator bool() const;

    ~shrd_ptr<T[]>() {
        if (!use_count)
            return;
        if (!object) {
            delete use_count;
            return;
        }
        --(*use_count);
        if (*use_count == 0) {
            delete[] object;
            delete use_count;
        }
    }

};

#endif //INC_3SEM_SHARED_H

