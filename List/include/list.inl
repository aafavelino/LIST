/*!
 *  @file list.inl 
 *  @brief Implementacao das funcoes da classe
 *
 *  Arquivo com a implementacao das funcoes
 */
 
#include <iostream>

#include  "list.h"

using namespace std;
template <typename T>
 List<T>::List( const List &_list){
    m_head = new Node (_list.m_head->data,_list.m_head->next, _list.m_head->after);
 	m_tail = new Node (_list.m_tail->data,_list.m_tail->next,_list.m_head->after);
 	this->m_size = _list.m_size;
      m_size = 0;
 }
 template <typename T>
 List<T>::List ( List &&_list )
 {
  
    m_head = new Node (_list.m_head->data,_list.m_head->next);
    m_tail = _list.m_tail;
    m_size = _list.m_size;
    _list.m_tail = new Node;
    _list.m_head->next = _list.m_tail;
    _list.m_tail->after = _list.m_head;
    _list.m_size = 0;
 }
template <typename T>
 int List<T>::size ( ) const {
    if (m_head==m_tail)
        return 0;
    else
    return m_size;
 }
 template <typename T>
 bool List<T>::empty ( ) const {
    if (m_head == m_tail)
        return true;
    else
        return false;
 }
 template <typename T>
 T &List<T>::front ( ){
     if (m_head == NULL)
        cout <<"ERRADO";
     else
        return m_head->next->data;
 }
 template <typename T>
 const T &List<T>::front ( ) const {
    if (m_head == NULL)
        cout << "ERRADO";
     else
        return m_head->next->data;
 }
 template <typename T>
 T &List<T>::back ( ){
        return m_tail->after->data;
 }
 template <typename T>
 const T &List<T>::back ( ) const
 {
     if (!(m_head == m_tail))
        return m_tail->after->data;
    else 
        cout << "ERRO";
 }
 template <typename T>
 void List<T>::push_front ( const T &x ){

    Node *slave = new Node;

    slave->data = x;
    slave->next = m_head->next;
    slave->after = m_head;
    m_head->next->after = slave;
    m_head->next = slave;
   // m_tail->after = slave->next;
    m_size++;


 }
template <typename T>
void List<T>::clear()
{
    Node *slave = m_head->next;
    while (slave != NULL)
    {
        Node *slave2 = slave;
        slave = slave->next;
        delete slave2;
    }
    
    
    m_head->next = m_tail;
    m_size = 0;
}
template <typename T>
 void List<T>::push_back ( const T &x ){
    if (m_head->next == NULL){
        push_front(x);
    }
    else{

    Node *slave = new Node;
    slave->data = x;
    slave->after = m_tail->after;
    slave->next = m_tail;
    m_tail->after = slave;
   // slave->next = m_tail;
   // m_head->after = slave;
    m_size++;
}
}
template <typename T>
 void List<T>::pop_front ( ){
    if (m_head != NULL)
    {
        Node *slave = m_head->next;
        m_head->next = slave->next;
        delete slave;
       // m_head = slave->next;
    }

    m_size--;
 }
 template <typename T>
 void List<T>::pop_back ()
 {
        Node *temp = m_tail->after;
        temp->after->next = m_tail;
        m_tail->after = temp->after;
        m_size--;
        delete temp;
    
 }
 template <typename T>
 void List<T>::assign ( const T &value ){
    if (m_head == m_tail)
    {
        push_front(value);
    }
    else
    {
    Node *slave = m_head;
    while (slave->next != m_tail) {
        slave = slave->next;
        slave->data = value;     
       }
       slave->data = value;
    }
 }


template <typename T>
typename List<T>::const_iterator List<T>::cbegin() const{
    return typename List<T>::const_iterator(m_head->next);
}

template <typename T>
typename List<T>::const_iterator List<T>::cend() const{
    return typename List<T>::const_iterator(m_tail);
}

template <typename T>
typename List<T>::const_iterator List<T>::cbefore_begin() const{
    return typename List<T>::const_iterator(m_head);
}

template <typename T>
typename List<T>::iterator List<T>::end(){
    return typename List<T>::iterator(m_tail);
}


template <typename T>
typename List<T>::iterator List<T>::begin(){
    return typename List<T>::iterator(m_head->next);
}


template <typename T>
typename List<T>::iterator List<T>::before_begin(){
    return typename List<T>::iterator(m_head);
}


template <typename T>
typename List<T>::const_iterator List<T>::find(const T &x)const
{   Node *slave = m_head->next;
    while(slave != NULL and slave->next != NULL){
        if(slave->data == x)
            return slave;
        slave = slave->next;
    }
    return NULL;
}

template <typename T>
void List<T>::assign(std::initializer_list <T> ilist){
    for (auto i = ilist.begin(); i != ilist.end(); i++)
    {
        push_back(*i);
    }
}

template <typename T>
typename List<T>::iterator List<T>::insert_after(const_iterator itr , const T &x ){
    Node *slave = new Node;
    slave->data = x;
    slave->next = itr.current->next;
    itr.current->next = slave;

    m_size++;
    return itr.current->next;

}

template <typename T>
typename List<T>::iterator List<T>::insert_after(const_iterator pos , std::initializer_list <T> ilist){
    
    for (auto i = ilist.begin(); i != ilist.end(); i++)
    {
        Node *slave = new Node;
        slave->data = *i;
        slave->next = pos.current->next;
        pos.current->next = slave;
        m_size++;
    }

    
    return pos.current->next;
}

template <typename T>
typename List<T>::iterator List<T>::erase_after (const_iterator itr){
    
    if (itr.current->next != NULL && itr.current->next->next != NULL)
    {
        Node *slave = itr.current->next;
        itr.current->next = slave->next;
        m_size--;
        delete slave;
                    
        
        return List<T>::iterator(itr.current->next);
    }
    return List<T>::iterator(itr.current);

}

template <typename T>
typename List<T>::iterator List<T>::erase_after (const_iterator first , const_iterator last){
    if (first.current != last.current)
    {
        Node *slave = new Node;
        Node *slave2 = new Node;
        slave = first.current->next;
        first.current->next = last.current;
        while(slave != NULL){
            slave2 = slave;
            slave = slave->next;
            delete slave2;
            m_size--;
        }
        return last.current;
    }
    return first.current;
}



