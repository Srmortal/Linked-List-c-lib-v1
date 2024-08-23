#ifndef LINKED_LIST1
#define LINKED_LIST1
#include "C:\Users\YOUSEF\OneDrive\Desktop\Cxxdroid\linked list.h"
#include <iostream>
#include <vector>
#include <algorithm>
template<class t, linked_list_type LT>
forward_linked_list_iterator<t,LT>& forward_linked_list_iterator<t,LT>::operator++()
{
    if (this->Node)
    {
        this->Node = this->Node->next;
    }
    return *this;
}
template<class t, linked_list_type LT>
forward_linked_list_iterator<t, LT> forward_linked_list_iterator<t,LT>::operator++(int)
{
    forward_linked_list_iterator<t,LT> temp = *this;
    ++(*this);
    return temp;
}
template<class T, linked_list_type LT>
forward_linked_list_iterator<T, LT> forward_linked_list_iterator<T, LT>::operator+(int index)
{
    node* it = Node;
    for (int i = 0; i < index; i++)
    {
        if (!it) return forward_linked_list_iterator(nullptr);
        it = it->next;
    }
    return forward_linked_list_iterator(it);
}
template<class T, linked_list_type LT>
bidirectional_linked_list_iterator<T,LT>& bidirectional_linked_list_iterator<T, LT>::operator--()
{
    if (this->Node)
    {
        this->Node = this->Node->prev;
    }
    return *this;
}
template<class T, linked_list_type LT>
bidirectional_linked_list_iterator<T,LT> bidirectional_linked_list_iterator<T, LT>::operator--(int)
{
    bidirectional_linked_list_iterator<T, LT> temp = *this;
    --(*this);
    return temp;
}
template<class T, linked_list_type LT>
T& forward_linked_list_iterator<T,LT>::operator*() const
{
    return this->Node->data;
}
template<class T, linked_list_type LT>
T* forward_linked_list_iterator<T, LT>::operator->() const
{
    return &(Node->data);
}
template<class T,linked_list_type LT>
bool forward_linked_list_iterator<T, LT>::operator!=(const forward_linked_list_iterator& iter)
{
    return this->Node != iter.Node;
}
template<class T, linked_list_type LT>
bool forward_linked_list_iterator<T, LT>::operator==(const forward_linked_list_iterator& iter)
{
    return this->Node==iter.Node;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::update_tail()
{
    node* it = head;
    tail = nullptr;
    while (it)
    {
        if (it->next == nullptr)
        {
            if constexpr (LT == linked_list_type::doubly) {
                tail = static_cast<doublynode*>(it);
            }
            else {
                tail = it;
            }
        }
        it = it->next;
    }
}
template<class T, linked_list_type LT>
typename linked_list<T, LT>::nodetype* linked_list<T, LT>::split(typename linked_list<T, LT>::nodetype* headptr)
{
    if (!headptr ||!headptr->next) {
        return nullptr;
    }
    node* slow = headptr;
    node* fast = headptr;
    while (fast && fast->next)
    {
        fast = fast->next->next;
        if (fast) {
            slow = slow->next;
        }
    }
    node* mid = slow->next;
    slow->next = nullptr;
    if constexpr (LT==linked_list_type::doubly)
    {
        if (mid) {
            auto* mid_node = static_cast<doublynode*>(mid);
            mid_node->prev = nullptr;
        }
        node* current = headptr;
        while (current) {
            if (current->next) {
                auto* next_node = static_cast<doublynode*>(current->next);
                next_node->prev = static_cast<doublynode*>(current);
            }
            current = current->next;
        }
    }
    return static_cast<nodetype*>(mid);
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::update_prevs()
{
    if constexpr (LT == linked_list_type::doubly)
    {
        node* it = head;
        while (it)
        {
            auto* doubly_it = static_cast<doublynode*>(it);
            doubly_it->prev = nullptr;
            if (it->next)
            {
                auto* doubly_node = static_cast<doublynode*>(it->next);
                doubly_node->prev = doubly_it;
            }
            it = it->next;
        }
    }
}
template<class T, linked_list_type LT>
template<typename _Comparator>
typename linked_list<T, LT>::nodetype* linked_list<T, LT>::merge(typename linked_list<T, LT>::nodetype* headptr1, typename linked_list<T, LT>::nodetype* headptr2,_Comparator comp)
{
    if (!headptr1) return headptr2;
    if (!headptr2) return headptr1;
    nodetype* res = nullptr;
    if constexpr (LT==linked_list_type::singly)
    {
        if (comp(headptr1->data,headptr2->data)) {
            res = headptr1;
            res->next = merge(headptr1->next, headptr2,comp);
        }
        else
        {
            res = headptr2;
            res->next = merge(headptr1, res->next,comp);
        }
    }
    else if constexpr(LT==linked_list_type::doubly)
    {
        auto* node1 = static_cast<doublynode*>(headptr1);
        auto* node2 = static_cast<doublynode*>(headptr2);
        if (comp(node1->data, node2->data)) {
            res = node1;
            auto* node1_d = static_cast<doublynode*>(node1->next);
            res->next = merge(node1_d, node2,comp);
            if (res->next) static_cast<doublynode*>(res->next)->prev = res;
        }
        else
        {
            res = headptr2;
            auto* node2_d = static_cast<doublynode*>(node2->next);
            res->next = merge(node1, node2_d,comp);
            if (res->next) static_cast<doublynode*>(res->next)->prev = res;
        }
        if (res) res->prev = nullptr;
    }
    return res;
}
template<class T, linked_list_type LT>
template<typename _Comparator>
void linked_list<T, LT>::mergesort(typename linked_list<T, LT>::nodetype** headptr, _Comparator comp)
{
    nodetype* head1=*headptr;
    if (!head1 || !head1->next) return;
    nodetype* mid = split(head1);
    mergesort(&head1,comp);
    mergesort(&mid,comp);
    *headptr = merge(head1, mid,comp);
}
template<class T,linked_list_type LT>
T& linked_list<T,LT>::operator[](unsigned i){
    node* n = head;
    while (i && n) {
        n = n->next;
        i--;
    }
    if (n == nullptr || i >= size()) {
        throw std::out_of_range("out of bounds");
    }
    return n->data;
}
template<class T,linked_list_type LT>
int linked_list<T,LT>::search_by_index(T c){
    if (empty())
    {
        throw std::logic_error("List is empty");
    }
    node* x=head;
    int i=0;
    while(x!=end()){
        if(x->data==c){
            return i;
        }
        x=x->next;
        i++;
    }
    return -1;
}
template<class T, linked_list_type LT>
int linked_list<T, LT>::search_by_index(std::function<bool(const T&)> func)
{
    if (empty())
    {
        throw std::logic_error("List is empty");
    }
    node* it = head;
    int i = 0;
    while (it != nullptr)
    {
        if (func(it->data)) {
            return i;
        }
        i++;
        it = it->next;
    }
    return -1;
}
template<class T,linked_list_type LT>
typename linked_list<T, LT>::iterator linked_list<T, LT>::search(std::function<bool(const T&)> func)
{
    if (empty())
    {
        throw std::logic_error("List is empty");
    }
    node* it = head;
    while (it!=nullptr)
    {
        if (func(it->data)) {
            return it;
        }
        it = it->next;
    }
    return nullptr;
}
template<class T, linked_list_type LT>
typename linked_list<T, LT>::iterator linked_list<T, LT>::search(T c){
    if (empty())
    {
        throw std::logic_error("List is empty");
    }
    node* x=head;
    while(x!=nullptr){
        if(x->data==c){
            return x;
        }
        x=x->next;
    }
    return nullptr;
}
template<class T,linked_list_type LT>
size_t linked_list<T, LT>::size()
{
    return empty()? sz:sz+1;
}
template<class T,linked_list_type LT>
void linked_list<T, LT>::push_front(const T value){
    nodetype* new_node = new nodetype(value);
    if (empty()) { tail = head = new_node; return; }
    new_node->next = head;
    if constexpr (LT==linked_list_type::doubly)
    {
        head->prev = new_node;
    }
    head = new_node;
    sz++;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::push_back(const T value){
    if(empty()){
        push_front(value);
        return;
    }
    nodetype* new_node = new nodetype(value);
    tail->next = new_node;
    if constexpr(LT == linked_list_type::doubly)
    {
        new_node->prev = tail;
    }
    tail = new_node;
    sz++;
}
template<class T,linked_list_type LT>
bool linked_list<T, LT>::empty()
{
    return !head;
}
template<class T, linked_list_type LT>
template<class order>
void linked_list<T, LT>::sort(order o)
{
    if (sz <= 1) {
        return;
    }
    std::vector<T> temp(begin(),end());
    std::sort(temp.begin(), temp.end(), o);
    clear();
    for (const auto& i : temp)
    {
        push_back(i);
    }
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::reverse()
{
    if (sz <= 1) {
        return;
    }
    nodetype* current = head;
    nodetype* prevNode = nullptr;
    nodetype* nextNode = nullptr;
    std::swap(head, tail);
    while (current != end()) {
        nextNode = current->next;
        current->next = prevNode;
        if constexpr(LT==linked_list_type::doubly)
        {
            current->prev = nextNode;
        }
        prevNode = current;
        current = nextNode;
    }
}
template<class T, linked_list_type LT>
template<typename _Comparator>
void linked_list<T, LT>::merge_sort(_Comparator comp)
{
    mergesort(&head,comp);
    update_tail();
    update_prevs();
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::clear()
{
    if (empty())
    {
        return;
    }
    node* current = head;
    while (current != nullptr) {
        node* next = current->next;
        delete current;
        current = next;
    }
    tail = head = nullptr;
    sz = 0;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::insert(const T c,unsigned index)
{
    if (empty()||index==0)
    {
        push_front(c);
        return;
    }
    if (index==sz)
    {
        push_back(c);
        return;
    }
    nodetype* it=head;
    while(it->next&&index){
        it=it->next;
        index--;
    }
    nodetype* new_node = new nodetype(c);
    new_node->next = it->next;
    it->next = new_node;
    if  constexpr (LT==linked_list_type::doubly)
    {
        if (new_node->next) {
            static_cast<doublynode*>(new_node->next)->prev = new_node;
        }
        new_node->prev = it;
    }
    sz++;
}
template<class T, linked_list_type LT>
template<typename _Comparator>
void linked_list<T, LT>::insert_sorted(const T val, _Comparator comp)
{
    if (empty()|| comp(val, head->data)) {
        push_front(val);
        return;
    }
    nodetype* new_node = new nodetype(val);
    nodetype* it = head;
    while (it->next&& !comp(val, it->next->data))
    {
        it = static_cast<nodetype*>(it->next);
    }
    new_node->next = it->next;
    it->next = new_node;
    if constexpr (LT == linked_list_type::doubly)
    {
        new_node->prev = it;
        if (new_node->next) {
            static_cast<doublynode*>(new_node->next)->prev = new_node;
        }
    }
    sz++;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::pop_front()
{
    if (empty())
    {
        throw std::underflow_error("List is empty");
    }
    nodetype* n = head;
    head = static_cast<nodetype*>(head->next);
    delete n;
    if constexpr (LT==linked_list_type::doubly)
    {
        if(head)head->prev = nullptr;
    }
    sz--;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::remove(std::function<bool(const_reference)> func)
{
    if (empty())
    {
        throw std::underflow_error("List is empty");
    }
    nodetype* it = search(func);
    if (it == end())
    {
        throw std::logic_error("element is not found");
    }
    if (it == head)
    {
        pop_front();
        return;
    }
    if (it == tail)
    {
        pop_back();
        return;
    }
    nodetype* start = head;
    nodetype* nit = it;
    while (start->next != nit) {
        start = start->next;
    }
    start->next = nit->next;
    if constexpr (LT == linked_list_type::doubly)
    {
        start = nit->prev;
    }
    delete nit;
    sz--;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::pop_back()
{
    if (empty())
    {
        throw std::underflow_error("List is empty");
    }
    if constexpr(LT==linked_list_type::singly)
    {
        node* tail1 = tail;
        node* it = head;
        while (it->next != tail1)
        {
            it = it->next;
        }
        it->next = nullptr;
        delete tail1;
        tail = it;
    }
    else
    {
        doublynode* tail1 = tail;
        tail = tail->prev;
        tail->next = nullptr;
        tail1->prev = nullptr;
        delete tail1;
    }
    sz--;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::remove(T val)
{
    if (empty())
    {
        throw std::underflow_error("List is empty");
    }
    nodetype* it = search(val);
    if (it == end())
    {
        throw std::logic_error("element is not found");
    }
    if (it == head)
    {
        pop_front();
        return;
    }
    if (it == tail)
    {
        pop_back();
        return;
    }
    nodetype* start = head;
    nodetype* nit = it;
    while (start->next != nit) {
        start = start->next;
    }
    start->next = nit->next;
    if constexpr (LT == linked_list_type::doubly)
    {
        start = nit->prev;
    }
    delete nit;
    sz--;
}
template<class T, linked_list_type LT>
typename linked_list<T, LT>::iterator linked_list<T, LT>::begin() const
{
    return iterator(head);
}
template<class T, linked_list_type LT>
typename linked_list<T, LT>::iterator linked_list<T, LT>::end() const
{
    return iterator(nullptr);
}
template<class T, linked_list_type LT>
T linked_list<T, LT>::back() const
{
    return tail->data;
}
template<class T, linked_list_type LT>
T linked_list<T, LT>::front() const
{
    return head->data;
}
#endif //LINKED_LIST1
