#include <complex>
#include "listseq_myptrs.h"

template<class T>
ListSequence<T>::ListSequence(){
    the_list = new LinkedList<T>();
}

template<class T>
ListSequence<T>::ListSequence(T *items, size_t size){
    the_list = new LinkedList<T> (items, size);
}

template<class T>
ListSequence<T>::ListSequence(const ListSequence<T> & list){
    the_list = new LinkedList<T>(*list.the_list);
}

template<class T>
void ListSequence<T>::Append(T item){
    the_list->Append(item);
}

template<class T>
void ListSequence<T>::Prepend(T item){
    the_list->Prepend(item);
}

template<class T>
void ListSequence<T>::InsertAt(T item, int index){
    the_list->insert(item, index);
}

template<class T>
void ListSequence<T>::Set(T item, int index){
    the_list->Set(item, index);
}

//template<class T>
//Sequence<T>* ListSequence<T>::GetSubSequence(int s, int e) const{
//    auto list = new LinkedList<T>();
//    list = the_list->GetSublist(s, e);
//    return list;
//}
//
//template<class T>
//Sequence<T>* ListSequence<T>::Concat(Sequence<T> *t_list){
//    auto list = new LinkedList<T>();
//    list = the_list->Concat(t_list);
//    return list;
//}

template<class T>
void ListSequence<T>::Clear(){
    for(int i = 0; i < this->GetLength(); i++){
        this->Set(0, i);
    }
}

//template<class T>
//Sequence<T> *ListSequence<T>::Remove(int i){
//    Sequence<T> *list = new LinkedList<T>();
//    list = the_list->Remove(i);
//    return list;
//}

template<class T>
T &ListSequence<T>::operator[](int index) const{
    return the_list->operator[](index);
}

template<class T>
ListSequence<T>::~ListSequence(){
    delete the_list;
}

template class ListSequence<int>;
template class ListSequence<int*>;
template class ListSequence<char>;
template class ListSequence<char*>;
template class ListSequence<double>;
template class ListSequence<double*>;