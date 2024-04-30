#ifndef LINKED_LIST
#define LINKED_LIST
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <iostream>
#include <sstream>
using namespace std;
template<class T>
class Node;
template<class T>
class LinkedList{
private:
    
    Node<T> *head;
    unsigned sz;
public:
    LinkedList() {
        head = nullptr;
        sz = 0;
    }
    T operator[](unsigned index);
    int search(T val);
    Node<T>* operator+(int index);
    Node<T> *searchptr(T val);
    bool is_found(T val);
    Node<T> *headgetter();
    Node<T> *tailgetter();
    int size();
    unsigned sizeno();
    bool is_empty();
    vector<T> to_vector();
    string to_string();
    stack<T> to_stack();
    queue<T> to_queue();
    deque<T> to_deque();
    void clear();
public:
    void insertfront1(const T val);
    void insertend1(const T val);
    void insert1(const T val,unsigned index);
    void insert1(const T val);
    void removefirst1();
    void removeafterpos1(unsigned index);
    void remove1(unsigned index);
    void removebyvalue1(T val);
    void removelast1();
public:
    void insertfront2(const T val);
    void insert2(const T val,unsigned index);
    void insert2(const T val);
    void insertend2(const T val);
    void removefirst2();
    void remove2(unsigned index);
    void removebyvalue2(const T val);
    void removelast2();
};
template<class T>
class Node{
    T data;
    Node* next;
    Node* prev;
public:
    Node(const T data) {
        this->data = data;
        next = nullptr;
        prev = nullptr;
    }
    Node() {
        next = nullptr;
        prev = nullptr;
    }
    T& operator*();
    template<typename E>
    friend class LinkedList;
    friend ostream& operator<< <>(ostream& COUT, Node<T>& node);
};
template<class T>
ostream& operator<<(ostream& COUT, Node<T>& node);
#include "put path of linked_list.cpp"
#endif // LINKED_LIST
