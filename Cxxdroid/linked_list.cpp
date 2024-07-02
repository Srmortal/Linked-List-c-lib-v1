#ifndef LINKED_LIST1
#define LINKED_LIST1
#include "C:\Users\YOUSEF\OneDrive\Desktop\Cxxdroid\linked test.h"
template<class t, linked_list_type LT>
linked_list_iterator<t,LT>& linked_list_iterator<t,LT>::operator++()
{
    if (Node)
    {
        this->Node = this->Node->next;
    }
    return *this;
}
template<class t, linked_list_type LT>
linked_list_iterator<t, LT> linked_list_iterator<t,LT>::operator++(int)
{
    linked_list_iterator<t,LT> temp = *this;
    ++(*this);
    return temp;
}
template<class T, linked_list_type LT>
linked_list_iterator<T, linked_list_type::doubly>& linked_list_iterator<T, LT>::operator--()
{
    static_assert(LT == linked_list_type::doubly, "decrement is only supported for doubly linked lists.");
    if (this->Node) {
        this->Node = this->Node->prev;
    }
    return *this;
}
template<class T, linked_list_type LT>
linked_list_iterator<T, linked_list_type::doubly> linked_list_iterator<T, LT>::operator--(int)
{
    static_assert(LT == linked_list_type::doubly, "decrement is only supported for doubly linked lists.");
    linked_list_iterator<T, LT> temp = *this;
    --(*this);
    return temp;
}
template<class T, linked_list_type LT>
T& linked_list_iterator<T,LT>::operator*()
{
    return this->Node->data;
}
template<class T,linked_list_type LT>
bool linked_list_iterator<T, LT>::operator!=(const linked_list_iterator iter)
{
    return this->Node != iter.Node;
}
template<class T,linked_list_type LT>
T& linked_list<T,LT>::operator[](unsigned i){
    linked_list<T, LT>::node* n = head;
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
    linked_list<T, LT>::node *x=head;
    int i=0;
    while(x){
        if(x->data==c){
            return i;
        }
        x=x->next;
        i++;
    }
    return -1;
}
template<class T,linked_list_type LT>
int linked_list<T,LT>::search_by_index(std::function<bool(const T&)> func)
{
    linked_list<T, LT>::node* it = head;
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
linked_list_iterator<T,LT> linked_list<T,LT>::search(std::function<bool(const T&)> func)
{
    linked_list<T, LT>::node* it = head;
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
linked_list_iterator<T, LT> linked_list<T, LT>::search(T c){
    linked_list<T, LT>::node *x=head;
    while(x){
        if(x->data==c){
            return x;
        }
        x=x->next;
    }
    return nullptr;
}
template<class T,linked_list_type LT>
size_t linked_list<T,LT>::size()
{
    return is_empty()? sz:sz+1;
}
template<class T,linked_list_type LT>
void linked_list<T,LT>::push_front(const T c){
    linked_list<T, LT>::node* n = new linked_list<T, LT>::node(c);
    if (is_empty()) { tail = head = n; return; }
    n->next = head;
    if (LT==linked_list_type::doubly)
    {
        head->prev = n;
    }
    head = n;
    sz++;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::push_back(const T c){
    if(is_empty()){
        push_front(c);
        return;
    }
    linked_list<T, LT>::node* n = new linked_list<T, LT>::node(c);
    tail->next = n;
    if (LT == linked_list_type::doubly)
    {
        n->prev = tail;
    }
    tail = n;
    sz++;
}
template<class T,linked_list_type LT>
bool linked_list<T,LT>::is_empty()
{
    return !head;
}
template<class T, linked_list_type LT>
std::vector<T> linked_list<T, LT>::to_vector()
{
    std::vector<T> res;
    linked_list<T, LT>::node* it = head;
    while (it)
    {
        res.push_back(it->data);
        it = it->next;
    }
    return res;
}
template<class T, linked_list_type LT>
std::string linked_list<T, LT>::to_string()
{
    std::stringstream ss;
    linked_list<T, LT>::node* it = head;
    while (it)
    {
        ss << it->data;
        it = it->next;
    }
    std::string s;
    ss >> s;
    return s;
}
template<class T, linked_list_type LT>
std::stack<T> linked_list<T, LT>::to_stack()
{
    std::stack<T> res;
    linked_list<T, LT>::node* it = head;
    while (it)
    {
        res.push(it->data);
        it = it->next;
    }
    return res;
}
template<class T, linked_list_type LT>
std::queue<T> linked_list<T, LT>::to_queue()
{
    std::queue<T> res;
    linked_list<T, LT>::node* it = head;
    while (it)
    {
        res.push(it->data);
        it = it->next;
    }
    return res;
}
template<class T, linked_list_type LT>
std::deque<T> linked_list<T, LT>::to_deque()
{
    std::deque<T> res;
    linked_list<T, LT>::node* it = head;
    while (it)
    {
        res.push_back(it->data);
        it = it->next;
    }
    return res;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::reverse()
{
    if (sz <= 1) {
        return;
    }
    linked_list<T, LT>::node* current = head;
    linked_list<T, LT>::node* prevNode = nullptr;
    linked_list<T, LT>::node* nextNode = nullptr;
    std::swap(head, tail);
    while (current != nullptr) {
        nextNode = current->next;
        current->next = prevNode;
        if (LT==linked_list_type::doubly)
        {
            current->prev = nextNode;
        }
        prevNode = current;
        current = nextNode;
    }
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::clear()
{
    linked_list<T, LT>::node* current = head;
    while (current != nullptr) {
        linked_list<T, LT>::node* next = current->next;
        delete current;
        current = next;
    }
    tail = head = nullptr;
    sz = 0;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::insert(const T c,unsigned index)
{
    if (is_empty()||index==0)
    {
        push_front(c);
        return;
    }
    if (index==sz)
    {
        push_back(c);
        return;
    }
    linked_list<T, LT>::node* p=head;
    while(p->next&&index){
        p=p->next;
        index--;
    }
    linked_list<T, LT>::node* n = new linked_list<T, LT>::node(c);
    n->next = p->next;
    p->next = n;
    if (LT==linked_list_type::doubly)
    {
        if (n->next) {
            n->next->prev = n;
        }
        n->prev = p;
    }
    sz++;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::pop_front()
{
    if (is_empty())
    {
        throw std::logic_error("List is empty");
    }
    linked_list<T, LT>::node* n = head;
    head = head->next;
    delete n;
    if (LT==linked_list_type::doubly)
    {
        head->prev = nullptr;
    }
    sz--;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::pop_back()
{
    linked_list<T, LT>::node* tail1 = tail;
    linked_list<T, LT>::node* it = head;
    while (it->next != tail1)
    {
        it = it->next;
    }
    it->next = nullptr;
    if (LT==linked_list_type::doubly)
    {
        tail1->prev = nullptr;
    }
    delete tail1;
    tail = it;
    sz--;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::erase(linked_list_iterator<T, LT> it){
    if (is_empty())
    {
        throw std::logic_error("List is empty");
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
    linked_list<T, LT>::node* s = head;
    if (it==end())
    {
        throw std::logic_error("element is not found");
    }
    while (s->next != it) {
        s = s->next;
    }
    node* e = it;
    s->next = e->next;
    if (LT==linked_list_type::doubly)
    {
        s = e->prev;
    }
    delete it;
    sz--;
}
template<class T, linked_list_type LT>
void linked_list<T, LT>::remove(T val)
{
    node* pos = search(val);
    erase(pos);
}
template<class T, linked_list_type LT>
linked_list_iterator<T, LT> linked_list<T, LT>::begin() const
{
    return linked_list_iterator<T,LT>(head);
}
template<class T, linked_list_type LT>
linked_list_iterator<T, LT> linked_list<T, LT>::end() const
{
    return linked_list_iterator<T,LT>(nullptr);
}
template<class T, linked_list_type LT>
linked_list_iterator<T, linked_list_type::doubly> linked_list<T, LT>::rbegin() const
{
    static_assert(LT == linked_list_type::doubly, "rend() is only supported for doubly linked lists.");
    return linked_list_iterator<T, linked_list_type::doubly>(tail);
}
template<class T, linked_list_type LT>
linked_list_iterator<T, linked_list_type::doubly> linked_list<T, LT>::rend() const
{
    static_assert(LT == linked_list_type::doubly, "rend() is only supported for doubly linked lists.");
    return linked_list_iterator<T, linked_list_type::doubly>(nullptr);
}
#endif //LINKED_LIST1
