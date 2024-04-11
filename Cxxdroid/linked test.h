#ifndef LINKED_LIST
#define LINKED_LIST
enum print_order{
    Forward,
    Backward
};
template<class T>
class LinkedList{
private:
    class Node{ 
    public:
        T d;
        Node* next;
        Node* prev;
        Node(const T v){
            d=v;
            next = nullptr;
            prev = nullptr;
        }
        Node(){
            next=nullptr;
            prev=nullptr;
        }
    };
    Node *head;
    size_t sz;
public:
    LinkedList() {
        head = nullptr;
        sz = 0;
    }
    T operator[](unsigned index);
    Node* operator+(int index);
    int search(T c);
    Node *searchptr(T c);
    Node *headgetter();
    Node *tailgetter();
    size_t size();
    bool is_empty();
public:
    void printlinked1();
    void insertfront1(const T c);
    void insertend1(const T c);
    void insert1(const T c,unsigned index);
    void insert1(const T c);
    void removefirst1();
    void removeafterpos1(unsigned index);
    void remove1(unsigned index);
    void removelast1();
public:
    void printlinked2(print_order backward_or_forward); 
    void insertfront2(const T c);
    void insert2(const T o,unsigned index);
    void insert2(const T o);
    void insertend2(const T o);
    void removefirst2();
    void remove2(unsigned index);
    void removelast2();
};
#include "C:\Users\YOUSEF\OneDrive\Desktop\Cxxdroid\linked test.cxx"
#endif // LINKED_LIST