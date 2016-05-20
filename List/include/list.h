/*!
 *  @file list.h 
 *  @brief Corpo da Classe List
 *
 *  Arquivo com a classe List
 */
#include <iostream>

#ifndef __LES_V1_H__
#define __LES_V1_H__

using namespace std;

/**
 * @brief Classe List
 *
 * Assinaturas das funções e definição da classe List
 */
template <typename T>
class List{
 public:

/**
 * @brief Classe const_iterator
 *
 * Assinatura da classe const_iterator
 */
class const_iterator;
/**
 * @brief Classe iterator
 *
 * Assinatura da classe iterator
 */
class iterator;

/**
 * @brief Construtor padrão da classe List
 * Seta os valores alocando novos nós
 */
 List ( ){
    m_size = 0;
    m_head = new Node;
    m_tail = new Node;
    m_head->next = m_tail;
    m_tail->after = m_head;
 }
 /**
 * @brief Destrutor da classe List
 * Destroi o m_head e o m_tail
 */
 ~List ( ){
    delete m_head;
    delete m_tail;
 }
 /**
 * @brief Construtor cópia da classe List
 * Faz uma cópia de todos os valores do objeto no qual se quer copiar
 */
 List( const List &_list);
 /**
 * @brief Construtor move da classe List
 * Move todos os elementos de um objeto de uma classe para outro objeto
 */
 List ( List &&_list );

 /**
  * @brief Sobrecarga do operador cópia
  * @ Param list O elemento a ser copiado
  * @return O this do elemento copiado
  */
 List & operator = ( const List &_list ){
    m_head = new Node (_list.m_head->data,_list.m_head->next, _list.m_head->after);
 	m_tail = new Node (_list.m_tail->data,_list.m_tail->next, _list.m_tail->after);
 	this->m_size = _list.m_size;
 	return (*this);
 }

 /**
  * @brief Sobrecarga do operador move
  * @ Param list O elemento a ser movido
  * @return O this do elemento movido
  */
 List & operator = ( List &&_list )
 {

    delete m_head;
 	delete m_tail;
 	m_head = new Node (_list.m_head->data,_list.m_head->next, _list.m_head->after);
 	m_tail = new Node (_list.m_tail->data,_list.m_tail->next, _list.m_tail->after);
 	m_size = _list.m_size;
 	_list.m_head = nullptr;
 	_list.m_tail = nullptr;
 	_list.m_size = 0;
 	return (*this);
 }



/**
  * @brief Pega um iterador apontando para o inicio da lista
  * @return Um iterador para o inicio da lista
  */
 iterator before_begin();

 /**
  * @brief Pega um iterador apontando para o primeiro elemento da lista
  * @return Um iterador apontando para o primeiro elemento da lista
  */
 iterator begin();

 /**
  * @brief Pega um iterador apontando para o ultimo elemento da lista
  * @return Um iterador apontando para o ultimo elemento da lista
  */
 iterator end();

/**
  * @brief Pega um iterador apontando para o inicio da lista
  * @return Um iterador para o inicio da lista
  */
 const_iterator cbefore_begin()const;

  /**
  * @brief Pega um iterador const apontando para o primeiro elemento da lista
  * @return Um iterador apontando para o primeiro elemento da lista
  */
 const_iterator cbegin()const;


 /**
  * @brief Pega um iterador const apontando para o ultimo elemento da lista
  * @return Um iterador apontando para o ultimo elemento da lista
  */
 const_iterator cend()const;

/**
 * @brief Colhe o tamanho da lista 
 * @return O tamanho da Forward list
 */
 int size ()const;

/**
 * @brief Verifica se a lista está vazia 
 * @return True se estiver vazia, ou False se não estiver vazia
 */
 bool empty ()const;

/**
 * @brief Deleta todos os elementos da lista 
 * @return void
 */
 void clear ();

/**
 * @brief Pega o elemento da frente da lista
 * @return A referência para o primeiro elemento
 */ 
 T &front ();

/**
 * @brief Pega o elemento da frente da lista
 * @return A referência const para o primeiro elemento
 */ 
 const T &front()const;

/**
 * @brief Pega o elemento do final da lista
 * @return A referência para o ultimo elemento
 */ 
 T &back();

/**
 * @brief Pega o elemento do final da lista
 * @return A referência const para o ultimo elemento
 */ 
 const T &back()const;

/**
 * @brief Insere Elementos na frente da lista
 * @param x O elemento a ser inserido 
 * @return void
 */ 
 void push_front(const T &x);

/**
 * @brief Insere Elementos no final da lista
 * @param x O elemento a ser inserido 
 * @return void
 */ 
 void push_back(const T &x);

/**
 * @brief Deleta Elementos na frente da lista
 * @return void
 */  
 void pop_front();

/**
 * @brief Deleta Elementos no final da lista 
 * @return void
 */ 
 void pop_back();

 /**
 * @brief Insere o elemento em todas as posicoes da lista
 * @param value Elemento a ser inserido 
 * @return void
 */ 
 void assign(const T &value);





void assign(std::initializer_list <T> ilist);

 /**
  * @brief Insere um elemento em uma posicao passada por parametro
  * @param itr O iterador para posicao a ser inserido o elemento
  * @param x O elemento a ser inserido
  * @return O iterador para o elemento inserido
  */
 iterator insert_after(const_iterator itr , const T &x );

 /**
  * @brief Insere uma lista na lista iterador passada por parametro
  * @param pos O iterador para posicao a ser inserido o elemento
  * @param ilist A lista a ser inserida
  * @return O iterador para o ultimo elemento adicionado
  */
 iterator insert_after(const_iterator pos , std::initializer_list <T> ilist);
 

 /**
  * @brief Apaga um elemento em uma posicao passada por parametro
  * @param itr O iterador para posicao a ser apagada
  * @return A posicao do elemento apagado
  */
 iterator erase_after (const_iterator itr);

 /**
  * @brief Apaga os elementos em um intervalo passado por parametro
  * @param first O iterador para primeira posicao a ser apagada
  * @param last O iterador para ultima posicao a ser apagada
  * @return A posicao do ultimo elemento apagado
  */
 iterator erase_after (const_iterator first , const_iterator last);

 /**
  * @brief Procura um elemento na lista
  * @param x O elemento a ser procurado
  * @return Um Iterador const para o elemento encontrado
  */
 const_iterator find (const T & x)const;


 private:
     struct Node {
 T data ; // <! Data field
 Node *next ; // <! Pointer to the next node in the list .
 Node *after;
 // <! Basic constructor .
 Node ( const T &d = T ( ) , Node * p = nullptr , Node * n = nullptr )
 : data ( d ), next ( n ) { /* Empty */ }
 };
 int m_size ;
 Node * m_head ;
 Node * m_tail ;
 };

 template <typename T>
class List<T>::const_iterator {
public:

 /**
  * @brief Construtor padrao
  */
const_iterator ()
{
    current = new Node;
}


 /**
  * @brief Sobrecarga para o operador *
  */
 const T & operator * ( ) const
 {
     return current->data;
 }


 /**
  * @brief Sobrecarga para o operador ++ (Infixo)
  */
 const_iterator & operator ++ ( )
 {
    current = current -> next;
    return (*this);
 } // ++ it;

 /**
  * @brief Sobrecarga para o operador ++ (Posfixo)
  */
const_iterator operator ++ (int) {
        List<T>::const_iterator slave = current;
        current = current->next;
        return slave;
 }
 // it ++;
 const_iterator & operator -- ( )
 {
    current = current -> after;
    return (*this);
 } // ++ it;

 /**
  * @brief Sobrecarga para o operador ++ (Posfixo)
  */
const_iterator operator -- (int) {
        List<T>::const_iterator slave = current;
        current = current->after;
        return slave;
 }
 /**
  * @brief Sobrecarga para o operador ==
  */
 bool operator == ( const const_iterator & rhs ) const{
    return (current == rhs.current);

 }

 /**
  * @brief Sobrecarga para o operador !=
  */
 bool operator != ( const const_iterator & rhs ) const {
    return !(*this==rhs);

}

protected:
 Node *current; // <! Ponteiro para Forward list
 const_iterator (Node * p):current (p){} // <! Construtor padrao
 friend class List<T>; // <! Classe amiga da List
 };


/**
 * @brief Classe iterator
 */
template <typename T>
class List<T>::iterator : public List<T>::const_iterator {
 public:

 /**
  * @brief Construtor padrao
  */
 iterator ():const_iterator(){ /* Empty */ }

 /**
  * @brief Sobrecarga para o operador *
  */
 const T & operator * ( )const 
 {
    return const_iterator::current->data;
 }
 
 /**
  * @brief Sobrecarga para o operador *
  */
 T & operator * ( )
 {
    return const_iterator::current->data;
 }
 


 /**
  * @brief Sobrecarga para o operador ++ (Infixo)
  */
 iterator & operator ++ ( )
 {

    const_iterator::current = const_iterator::current->next;
    return const_iterator::current;
 }
 
 /**
  * @brief Sobrecarga para o operador ++ (Posfixo)
  */
 iterator operator ++ ( int )
 {
    iterator slave(const_iterator::current);
    const_iterator::current = const_iterator::current->next;
    return slave;
 }

 protected:
 iterator (Node *p):const_iterator (p){} // <! Construtor padrao
 friend class List <T>; // <! Classe amiga da List
 };


#include "list.inl"

#endif