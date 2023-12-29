#ifndef INC_3SEM_LINKEDLIST_H
#define INC_3SEM_LINKEDLIST_H
#include <iostream>

template<typename F>
struct Node{
    F data;
    Node<F>* next;
    Node(): next(nullptr), data() {};
    explicit Node(F the_data): data(the_data), next(nullptr){}; //can't be used for implicit conversions and copy initialization
    Node(F the_data, Node* ptr): data(the_data), next(new Node(ptr)){};
    friend std::ostream& operator<<(std::ostream& out, const Node& printable_node){
        out << printable_node.data << " ";
        return out;
    };
};

template<class T>
class LinkedList{

public:

    typedef Node<T> node; //declaring type of node which is object itself of type T

private:

    node* head;
    node* tail;
    size_t count;

public:

    LinkedList(): head(nullptr), count(0) {};
    LinkedList(T*, size_t) {};
    LinkedList(LinkedList&);

    T& GetFirst(){return head->data;};
    T& GetLast(){return tail->data;};
    node* Get(size_t);

    void Prepend(T);
    void Append(T);
    void Set(T, size_t);
    void insert(T, size_t);
    size_t GetSize() const {return count;};
    node* back();
    node* search(T);
    void swap(node*, node*);
    void pop_front();
    void pop_back();
    void erase_after(T*); //remove right after T*
    void erase_after(T*, T*); //removing range after first element of range
    void delete_node(T);
    void clear();
    //void remove_if(pred);

    bool is_empty() const {return (GetSize() == 0);};

    //begin and end iterators

    T& operator[](size_t id) const;

    friend std::ostream& operator<<(std::ostream& out, LinkedList& printable_list) {
        if (printable_list.is_empty())
            out << " no nodes ";
        else {
            for (size_t i = 0; i < printable_list.size(); i++) {
                out << "[" << printable_list[i] << " ->  ";
            }
        }
        return out;
    };

      ~LinkedList(){
        if(GetSize() >= 1){
            Node<T>* the_next = head;
            Node<T>* temp;
            while(the_next){
                temp = the_next;
                the_next = the_next->next;
                delete temp;
                --count;
            }
        }
    };
};


#endif //INC_3SEM_LINKEDLIST_H
