#ifndef LINKED_LIST1
#define LINKED_LIST1
#include <iostream>
#include "C:\Users\YOUSEF\OneDrive\Desktop\Cxxdroid\linked test.h" //this is directory in my device change it to match yours also replace \ with /
/*
example:
#include "C:/medo/linked test.h"
#include "C:/saboy/didi/koko/linked test.h"
gave those examples to be clear
just to be clear
*/
using std::cout;
template<class T>
T LinkedList<T>::operator[](unsigned i){
    Node *n=head;
    while(i&&n){
        n=n->next;
        i--;
    }
    return n->d;
}
template<class T>
typename LinkedList<T>::Node* LinkedList<T>::operator+(int i){
    Node *n=head;
    while(i&&n){
        n=n->next;
        i--;
    }
    return n;
}
template<class T>
int LinkedList<T>::search(T c){
    Node *x=head;
    int i=0;
    while(x){
        if(x->d==c){
            return i;
        }
        x=x->next;
        i++;
    }
    return -1;
}
template<class T>
typename LinkedList<T>::Node *LinkedList<T>::searchptr(T c){
    Node *x=head;
    while(x){
        if(x->d==c){
            return x;
        }
        x=x->next;
    }
    return nullptr;
}
template<class T>
typename LinkedList<T>::Node *LinkedList<T>::headgetter(){
    return head;
}
template<class T>
typename LinkedList<T>::Node *LinkedList<T>::tailgetter(){
    Node *x=head;
    if(!head) return NULL;
    while(x->next){
        x=x->next;
    }
    return x;
}
template<class T>
void LinkedList<T>::printlinked1()
{
    if(!head){std::cout<<"no elements \n"; return;}
    Node *n=head;
    while (n)
    {
        cout << n->d << " ";
        n=n->next;
    }
}
template<class T>
size_t LinkedList<T>::size()
{
    return sz;
}
template<class T>
void LinkedList<T>::insertfront1(const T c){
    Node *n=new Node(c);
    n->next=head;
    head=n;
    sz++;
}
template<class T>
void LinkedList<T>::insertend1(const T c){
    Node *n=new Node(c);
    if(!head){
        head=n;
    }
    else{
        Node *n1=head;
        while(n1->next){
            n1=n1->next;
        }
        n1->next=n;
    }
    sz++;
}
template<class T>
bool LinkedList<T>::is_empty()
{
    return !head;
}
template<class T>
void LinkedList<T>::insert1(const T c,unsigned index)
{
    Node *p=head;
    if (!head)
    {
        insertfront1(c);
        return;
    }
    while(p->next&&index){
        p=p->next;
        index--;
    }
    Node *n = new Node(c);
    n->next = p->next;
    p->next = n;
    sz++;
}
template<class T>
void LinkedList<T>::insert1(const T c)
{
    insert1(c, sz - 1);
}
template<class T>
void LinkedList<T>::removefirst1()
{
    if (!head){
       cout<<"no element \n";
       return;
    }
    Node *n = head;
    head = head->next;
    delete n;
    sz--;
}
template<class T>
void LinkedList<T>::removelast1()
{
    remove1(sz - 1);
}
template<class T>
void LinkedList<T>::removeafterpos1(unsigned index)
{
    Node *d= operator+(index);
    Node *s=head;
    if(!d){
        return;
    }
    while(s!=d){
        s=s->next;
    }
    d = s->next;
    s->next = d->next;
    delete d;
    sz--;
}
template<class T>
void LinkedList<T>::remove1(unsigned index){
    removeafterpos1(index-1);
}
template<class T>
void LinkedList<T>::printlinked2(print_order backward_or_forward)
{
    switch(backward_or_forward){
        case Forward:
            printlinked1();
            break;
        default:
            Node *s = tailgetter();
            while(s){
                cout<<s->d<<" ";
                s=s->prev;
            }
            break;    
    }
}
template<class T>
void LinkedList<T>::insertfront2(const T c){
    Node *n=new Node(c);
    if(!head){head=n; return;}
    head->prev=head;
    n->next=head;
    head=n;
    sz++;
}
template<class T>
void LinkedList<T>::insert2(const T o,unsigned index)
{
    Node *node = new Node(o);
    Node *s=head;
    while(s->next&&index){
        s=s->next;
        index--;
    }
    node->next = s->next;
    s->next = node;
    node->prev=s;
    sz++;
}
template<class T>
void LinkedList<T>::insert2(const T o)
{
    insert2(o, sz - 1);
}
template<class T>
void LinkedList<T>::insertend2(const T o)
{
    Node *node = new Node(o);
    Node *s=tailgetter();
    if(!head){head=node; return;}
    s->next = node;
    node->prev=s;
    sz++;
}
template<class T>
void LinkedList<T>::removefirst2(){
    if(!head){cout<<"no elements \n"; return;}
    Node *s=head;
    head=head->next;
    free(s);
    head->prev=NULL;
    sz--;
}
template<class T>
void LinkedList<T>::remove2(unsigned index)
{
    if(!head){cout<<"no elements \n"; return;}
    Node *s=head;
    Node *node= operator+(index);
    while(s->next!=node){
        s=s->next;
    }
    s->next=node->next;
    s=node->prev;
    free(node);
    sz--;
}
template<class T>
void LinkedList<T>::removelast2()
{
    Node* tail = tailgetter();
    Node* it = head;
    while (it->next!=tail)
    {
        it = it->next;
    }
    it->next = nullptr;
    tail->prev = nullptr;
    delete tail;
    sz--;
}
#endif // LINKED_LIST1
