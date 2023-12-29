#include "linkedlist.h"

template<class T> //exception out of range
T& LinkedList<T>::operator[](size_t id) const{
    if(id < 0 || count <= id){
        std::cerr << "OUT OF RANGE";
    }else{
        if(count == 1){
            return (head->data);
        } else if (count > 1) {
            T curr_data;
            Node<T>* curr = nullptr;
            size_t it = 0;
            for (curr = head; it != id; curr = curr->next) {
                it++;
            }
            curr_data = curr->data;
            return curr_data;
        } else
            std::cerr << "EMPTY LIST";
    }
};

template<class T>
void LinkedList<T>::swap(Node<T>* the_node, Node<T>* a_node){
    T temp_data = the_node->data;
    the_node->data = a_node->data;
    a_node->data = temp_data;
}

template<class T>
void LinkedList<T>::Prepend(T the_data) {
    if (is_empty()) {
        count = 1;
        head = new Node<T>(the_data);
    } else if (count > 0) {
        auto the_node = new Node(the_data);
        the_node->next = head;
        head = the_node;
        count++;
    }
}

template<class T>
void LinkedList<T>::insert(T data, size_t index) {
    node* left = Get(index);
    if (left == NULL) return;

    node* right = left->next;
    node* the_node = new Node(data);

    left->next = the_node;
    the_node->next = right;
    if (right == NULL) tail = the_node;
}

template<class T>
Node<T>* LinkedList<T>::Get(size_t index){
    if (index < 0) return NULL;

    node* the_node = head;
    int n = 0;
    while (the_node && n != index && the_node->next) {
        the_node = the_node->next;
        n++;
    }

    return (n == index) ? the_node : NULL;
}


template<class T>
void LinkedList<T>::Append(T the_data){
    if (is_empty()) {
        count = 1;
        head = new Node<T>(the_data);
    } else if(count >= 1){
        auto the_last = new Node<T>(the_data);
        if(count == 1){
            head->next = the_last;
            count++;
        } else if(count > 1){
            Node<T>* the_node = head;
            while(the_node->next != nullptr){
                the_node = the_node->next;
            }
            the_node->next = the_last;
            count++;
        }
    }
}

template<class T>
void LinkedList<T>::pop_front(){
    if(is_empty()){
        return;
    }else{
        if(count == 1){
            delete head;
            count--;
            return;
        }else{
            node* tmp = head;
            tmp = head->next;
            delete head;
            head = tmp;
            --count;
            return;
        }
    }
}

template<class T>
void LinkedList<T>::pop_back(){
    if(is_empty()){
        std::cerr << "EMPTY LIST";
    } else if(count == 1){
        auto temp = head->next;
        head = temp;
        delete temp;
        --count;
        return;
    } else if(count > 1){
        delete (this->back());
        --count;
    }
}

//template<class T>
//void LinkedList<T>::delete_node(T find_data){
//    Node<T>* the_node = search(find_data);
//    auto tmp = head;
//    if(tmp == the_node){
//        delete head;
//        (*count)--;
//    } else if(the_node){
//        while(tmp){
//            if(tmp->next == the_node){
//                tmp->next = the_node->next;
//                (*count)--;
//                return;
//            }
//            tmp = tmp->next;
//        }
//        delete tmp;
//    }
//}

template<class T>
Node<T>* LinkedList<T>::back() {
    if(is_empty()){
        std::cerr << "EMPTY LIST";
    } else if(count == 1){
        return head;
    } else if(count > 1){
        auto temp = head;
        auto the_next = head;
        while(the_next){
            temp = temp->next;
            the_next = temp->next;
        }
        return temp;
    }
}

template<class T>
void LinkedList<T>::erase_after(T *, T *) {

}

template<class T>
Node<T>* LinkedList<T>::search(T find_data){
    auto the_node = new Node<T>(head->data);
    Node<T>* a_node = head;
    while(a_node->data != find_data){
        if(a_node->next == nullptr){
            return nullptr;
        } else {
            a_node = a_node->next;
        }
    }
    return a_node;
}

//template<class T>
//T& LinkedList<T>::get_elem(size_t index){
//    size_t i = 0;
//    auto the_node = new Node<T>(head->data);
//    Node<T>* a_node = head;
//    while(i != index){
//        if(a_node->next == nullptr){
//            return head->data;
//        } else {
//            a_node = a_node->next;
//            ++i;
//        }
//    }
//    return a_node->data;
//}

template class LinkedList<int>;
template class LinkedList<int*>;
template class LinkedList<char>;
template class LinkedList<char*>;
template class LinkedList<double>;
template class LinkedList<double*>;

