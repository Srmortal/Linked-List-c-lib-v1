#ifndef LINKED_LIST
#define LINKED_LIST
#include <functional>
#include <stdexcept>
enum class linked_list_type:bool{
    singly=false,
    doubly=true
};
template<class T, linked_list_type LT>
class forward_linked_list_iterator;
template<class T,linked_list_type LT>
class bidirectional_linked_list_iterator;
template<class T,linked_list_type LT=linked_list_type::singly>
class linked_list{
    struct node{
        T data;
        node* next;
        node(const T data = T()){
            this->data = data;
            next = nullptr;
        }
    };
    struct doublynode: node
    {
        doublynode* prev;
        doublynode(const T data=T()):node(data),prev(nullptr){}
    };
    using nodetype = std::conditional_t<LT == linked_list_type::doubly, doublynode, node>;
    nodetype* head, * tail;
    size_t sz;
    void update_tail();
    void update_prevs();
    nodetype* split(nodetype* headptr);
    template<typename _Comparator>
    nodetype* merge(nodetype* headptr1, nodetype* headptr2,_Comparator comp);
    template<typename _Comparator>
    void mergesort(nodetype** headptr, _Comparator comp);
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference =const value_type&;
    using size_type = size_t;
    using iterator = std::conditional_t<LT==linked_list_type::doubly, bidirectional_linked_list_iterator<value_type,LT>, forward_linked_list_iterator<value_type,LT>>;
    linked_list(){
        tail = head = nullptr;
        sz = 0;
    }
    linked_list(std::initializer_list<value_type> ils) {
        for (auto i = ils.begin(); i != ils.end(); i++)
        {
            push_back(*i);
        }
    }
    template<typename _Iterator>
    linked_list(_Iterator start, _Iterator end):head(nullptr),tail(nullptr),sz(0){
        for (_Iterator i = start; i != end; i++)
        {
            push_back(*i);
        }
    }
    reference operator[](unsigned index);
    int search_by_index(value_type val);
    int search_by_index(std::function<bool(const_reference)> func); //this is for user defined classes like search by name,age,etc...
    iterator search(std::function<bool(const_reference)> func); //this is for user defined classes like search by name,age,etc...
    iterator search(value_type val);
    iterator begin() const;
    iterator end() const;
    template <linked_list_type X = LT, typename std::enable_if_t<X == linked_list_type::doubly, int> = 0>
    iterator rbegin() const {
        return iterator(tail);
    }
    template <linked_list_type X = LT, typename std::enable_if_t<X == linked_list_type::doubly, int> = 0>
    iterator rend() const {
        return iterator(nullptr);
    }
    value_type back() const;
    value_type front() const;
    size_type size();
    bool empty();
    template<class order>
    void sort(order o);
    void sort(){
        sort(std::less<value_type>());
    }
    template<typename _Comparator>
    void merge_sort(_Comparator comp);
    void merge_sort(){
        merge_sort(std::less<value_type>());
    }
    void clear();
    ~linked_list(){
        clear();
    }
public:
    void push_front(const value_type val);
    void push_back(const value_type val);
    void insert(const value_type val,unsigned index);
    template<typename _Comparator>
    void insert_sorted(const value_type val,_Comparator comp);
    void pop_front();
    void remove(value_type val);
    void remove(std::function<bool(const_reference)> func);
    void pop_back();
    void reverse();
    friend class forward_linked_list_iterator<value_type,LT>;
    friend class bidirectional_linked_list_iterator<value_type,LT>;
};
template<class T,linked_list_type LT>
class forward_linked_list_iterator{
protected:
    using node = typename linked_list<T, LT>::node;
    node* Node;
public:
    using iterator_category = std::forward_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = value_type*;
    using reference = value_type&;
    forward_linked_list_iterator(node* n) : Node(n) {}
    operator typename linked_list<value_type, LT>::nodetype* () {
        return Node;
    }
    forward_linked_list_iterator& operator++();
    forward_linked_list_iterator operator++(int);
    forward_linked_list_iterator operator+(int index);
    reference operator*() const;
    pointer operator->() const;
    bool operator!=(const forward_linked_list_iterator& iter);
    bool operator==(const forward_linked_list_iterator& iter);
    friend struct linked_list<value_type,LT>::node;
    friend struct linked_list<value_type,LT>::doublynode;
};
template<class T,linked_list_type LT>
class bidirectional_linked_list_iterator : public forward_linked_list_iterator<T,LT>{
    using node = typename linked_list<T, LT>::doublynode;
public:    
    using iterator_category = std::bidirectional_iterator_tag;
    bidirectional_linked_list_iterator(node* n) :forward_linked_list_iterator<T, LT>(n) {}
    bidirectional_linked_list_iterator& operator--();
    bidirectional_linked_list_iterator operator--(int);
};
#include "C:\Users\YOUSEF\OneDrive\Desktop\Cxxdroid\linked list.cxx"
#endif //LINKED_LIST
