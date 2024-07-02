#ifndef LINKED_LIST
#define LINKED_LIST
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <sstream>
#include <functional>
#include <stdexcept>
#include <initializer_list>
enum class linked_list_type:bool{
    singly=false,
    doubly=true
};
template<class T, linked_list_type LT>
class linked_list_iterator;
template<class T,linked_list_type LT=linked_list_type::singly>
class linked_list{
    class node {
        T data;
        node* next;
        node* prev;
    public:
        node(const T data = T()) {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }
        friend class linked_list;
        friend class linked_list_iterator<T, LT>;
    } *head, *tail;
    size_t sz;
public:
    linked_list() {
        tail = head = nullptr;
        sz = 0;
    }
    linked_list(std::initializer_list<T> ils) {
        for (auto& i : ils)
        {
            push_back(i);
        }
    }
    T& operator[](unsigned index);
    int search_by_index(T val);
    int search_by_index(std::function<bool(const T&)> func); //this is for user defined classes like search by name,age,etc...
    linked_list_iterator<T,LT> search(std::function<bool(const T&)> func); //this is for user defined classes like search by name,age,etc...
    linked_list_iterator<T,LT> search(T val);
    linked_list_iterator<T,LT> begin() const;
    linked_list_iterator<T, LT> end() const;
    linked_list_iterator<T, linked_list_type::doubly> rbegin() const;
    linked_list_iterator<T, linked_list_type::doubly> rend() const;
    size_t size();
    bool is_empty();
    std::vector<T> to_vector();
    std::string to_string();
    std::stack<T> to_stack();
    std::queue<T> to_queue();
    std::deque<T> to_deque();
    void clear();
    ~linked_list() {
        clear();
    }
public:
    void push_front(const T val);
    void push_back(const T val);
    void insert(const T val,unsigned index);
    void pop_front();
    void erase(linked_list_iterator<T, LT> it);
    void remove(T val);
    void pop_back();
    void reverse();
    using iterator = linked_list_iterator<T,LT>;
    friend class linked_list_iterator<T, LT>;
};
template<class T, linked_list_type LT=linked_list_type::singly>
class linked_list_iterator{
    typename linked_list<T, LT>::node* Node;
public:
    linked_list_iterator(typename linked_list<T, LT>::node* n) : Node(n) {}
    operator typename linked_list<T, LT>::node* () {
        return Node;
    }
    linked_list_iterator& operator++();
    linked_list_iterator operator++(int);
    T& operator*();
    bool operator!=(const linked_list_iterator iter);
    linked_list_iterator<T, linked_list_type::doubly>& operator--();
    linked_list_iterator<T, linked_list_type::doubly> operator--(int);
    friend class linked_list<T,LT>::node;
};
#include "C:\Users\YOUSEF\OneDrive\Desktop\Cxxdroid\linked test.cxx"
#endif //LINKED_LIST
