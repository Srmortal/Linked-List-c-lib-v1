#ifndef LINKED_LIST1
#define LINKED_LIST1
#include "put path of linked_list.h"
template<class T>
T LinkedList<T>::operator[](unsigned i){
    Node<T>* n = head;
    while (i && n) {
        n = n->next;
        i--;
    }
    return n->data;
}
template<class T>
ostream& operator<<(ostream& COUT, Node<T>& node)
{
    COUT << node.data;
    return COUT;
}
template<class T>
T& Node<T>::operator*()
{
    return data;
}
template<class T>
int LinkedList<T>::search(T c){
    Node<T> *x=head;
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
template<class T>
Node<T>* LinkedList<T>::operator+(int index)
{
    Node<T>* n = head;
    if (!index)
    {
        return head;
    }
    int pos = index - 1;
    while (pos && n) {
        n = n->next;
        pos--;
    }
    return n;
}
template<class T>
Node<T> *LinkedList<T>::searchptr(T c){
    Node<T> *x=head;
    while(x){
        if(x->data==c){
            return x;
        }
        x=x->next;
    }
    return nullptr;
}
template<class T>
bool LinkedList<T>::is_found(T val)
{
    return search(val)!=-1;
}
template<class T>
Node<T> *LinkedList<T>::headgetter(){
    return head;
}
template<class T>
Node<T> *LinkedList<T>::tailgetter(){
    Node<T> *x=head;
    if(is_empty()) return NULL;
    while(x->next){
        x=x->next;
    }
    return x;
}
template<class T>
int LinkedList<T>::size()
{
    int cnt = 0;
    Node<T>* it = head;
    while (it)
    {
        cnt++;
        it = it->next;
    }
    return cnt;
}
template<class T>
unsigned LinkedList<T>::sizeno()
{
    return sz;
}
template<class T>
void LinkedList<T>::insertfront1(const T c){
    Node<T> *n=new Node<T>(c);
    n->next=head;
    head=n;
}
template<class T>
void LinkedList<T>::insertend1(const T c){
    Node<T> *n=new Node<T>(c);
    if(is_empty()){
        head=n;
    }
    else{
        Node<T> *n1=head;
        while(n1->next){
            n1=n1->next;
        }
        n1->next=n;
    }
}
template<class T>
bool LinkedList<T>::is_empty()
{
    return !head;
}
template<class T>
vector<T> LinkedList<T>::to_vector()
{
    vector<T> res;
    Node<T>* it = head;
    while (it)
    {
        res.push_back(it->data);
        it = it->next;
    }
    return res;
}
template<class T>
string LinkedList<T>::to_string()
{
    stringstream ss;
    Node<T>* it = head;
    while (it)
    {
        ss << it->data;
        it = it->next;
    }
    string s;
    ss >> s;
    return s;
}
template<class T>
stack<T> LinkedList<T>::to_stack()
{
    stack<T> res;
    Node<T>* it = head;
    while (it)
    {
        res.push(it->data);
        it = it->next;
    }
    return res;
}
template<class T>
queue<T> LinkedList<T>::to_queue()
{
    queue<T> res;
    Node<T>* it = head;
    while (it)
    {
        res.push(it->data);
        it = it->next;
    }
    return res;
}
template<class T>
deque<T> LinkedList<T>::to_deque()
{
    deque<T> res;
    Node<T>* it = head;
    while (it)
    {
        res.push_back(it->data);
        it = it->next;
    }
    return res;
}
template<class T>
void LinkedList<T>::clear()
{
    Node<T>* tail = tailgetter();
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
    sz = 0;
}
template<class T>
void LinkedList<T>::insert1(const T c,unsigned index)
{
    Node<T> *p=head;
    if (is_empty())
    {
        insertfront1(c);
        return;
    }
    if (index==size()-1)
    {
        insertend1(c);
        return;
    }
    while(p->next&&index){
        p=p->next;
        index--;
    }
    Node<T> *n = new Node<T>(c);
    n->next = p->next;
    p->next = n;
}
template<class T>
void LinkedList<T>::insert1(const T c)
{
    insert1(c, size() - 1);
    sz++;
}
template<class T>
void LinkedList<T>::removefirst1()
{
    if (is_empty()){
       cout<<"no element \n";
       return;
    }
    Node<T> *n = head;
    head = head->next;
    delete n;
}
template<class T>
void LinkedList<T>::removelast1()
{
    remove1(size() - 1);
}
template<class T>
void LinkedList<T>::removeafterpos1(unsigned index)
{
    T c = operator[](index);
    Node<T> *d= searchptr(c);
    Node<T> *s=head;
    if(!d){
        return;
    }
    while(s!=d){
        s=s->next;
    }
    d = s->next;
    s->next = d->next;
    delete d;
}
template<class T>
void LinkedList<T>::remove1(unsigned index){
    sz--;
    if (index==0)
    {
        removefirst1();
        return;
    }
    if (index==size()-1)
    {
        removelast1();
    }
    removeafterpos1(index-1);
}
template<class T>
void LinkedList<T>::removebyvalue1(T val)
{
    int pos = search(val);
    if (!is_found(val))
    {
        cout << "not found";
        return;
    }
    remove1(pos);
}
template<class T>
void LinkedList<T>::insertfront2(const T c){
    Node<T> *n=new Node<T>(c);
    if(!head){head=n; return;}
    head->prev=head;
    n->next=head;
    head=n;
}
template<class T>
void LinkedList<T>::insert2(const T o,unsigned index)
{
    Node<T> *node = new Node<T>(o);
    Node<T> *s=head;
    if (is_empty())
    {
        insertfront2(o);
        return;
    }
    if (index==size()-1)
    {
        insertend2(o);
        return;
    }
    while(s->next&&index){
        s=s->next;
        index--;
    }
    node->next = s->next;
    s->next = node;
    node->prev=s;
}
template<class T>
void LinkedList<T>::insert2(const T o)
{
    insert2(o, size() - 1);
    sz++;
}
template<class T>
void LinkedList<T>::insertend2(const T o)
{
    Node<T> *node = new Node<T>(o);
    Node<T> *s=tailgetter();
    if(!head){head=node; return;}
    s->next = node;
    node->prev=s;
}
template<class T>
void LinkedList<T>::removefirst2(){
    if(!head){cout<<"no elements \n"; return;}
    Node<T> *s=head;
    head=head->next;
    free(s);
    head->prev=NULL;
}
template<class T>
void LinkedList<T>::remove2(unsigned index)
{
    if (is_empty())
    {
        cout << "no elements \n";
        return;
    }
    if (index == 0)
    {
        removefirst2();
        return;
    }
    if (index==size()-1)
    {
        removelast2();
    }
    Node<T>* s = head;
    T c = operator[](index);
    Node<T>* node = searchptr(c);
    if (!node)
    {
        return;
    }
    while (s->next != node) {
        s = s->next;
    }
    s->next = node->next;
    s = node->prev;
    free(node);
    sz--;
}
template<class T>
void LinkedList<T>::removebyvalue2(const T val)
{
    int pos = search(val);
    if (!is_found(val))
    {
        cout << "not found\n";
        return;
    }
    remove2(pos);
}
template<class T>
void LinkedList<T>::removelast2()
{
    Node<T>* tail = tailgetter();
    Node<T>* it = head;
    while (it->next!=tail)
    {
        it = it->next;
    }
    it->next = nullptr;
    tail->prev = nullptr;
    delete tail;
}
#endif //LINKED_LIST1
