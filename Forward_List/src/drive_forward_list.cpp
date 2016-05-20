/*!
 *  @mainpage Forward List
 *  @author Adelino Afonso Fernandes Avelino
 *  @author Irene Ginani Costa Pinheiro
 *  @date May, 2016
 *  @version 1.0
 *
 *  @file drive_forward_list.cpp
 *
 *  @brief Arquivo driver
 *
 *  Arquivo com os testes das funcoes da classe forward_list
 */

#include <iostream>
#include <cassert>
#include "forward_list.h"

using namespace std;
int main ( int argc, char const *argv[] ) {
Forward_list <int> lista; //Declaração da lista
Forward_list <int>::const_iterator it; //Declaração do Iterador

//Testes push_front()

for (int i = 10; i >= 0 ; i--)
   lista.push_front(i);

//Teste front()
assert(lista.front() == 0);
//Teste back()
assert(lista.back() == 10);

//Testes push_back()

for (int i = 0; i <= 10 ; i++)
    lista.push_back(i);

//Teste front()
assert(lista.front() == 0);
//Teste back()
assert(lista.back() == 10);

//Teste pop_back();
for (int i = 0; i < 5; ++i)
    lista.pop_back();

assert(lista.back() == 5);

//Teste pop_front();
for (int i = 0; i < 5; ++i)
    lista.pop_front();

assert(lista.front() == 5);

//Teste size()
lista.size();
assert(lista.size() == 12);


//Teste assign();
lista.assign(13);

assert(lista.front() == 13);
assert(lista.back() == 13);

//Teste find();
it = lista.find(13);
assert(*it == 13);

//Teste insert_after()
std::initializer_list <int> nums({1,2,3,4,5});
it = lista.insert_after(lista.before_begin(), nums);
assert(lista.front() == 5);
it = lista.insert_after(lista.before_begin(), 3);
assert(lista.front() == 3);

//Teste erase_after()
it = lista.erase_after(lista.before_begin());
assert(lista.front() == 5);

//Teste size()
lista.size();
assert(lista.size() == 17);

//Teste construtor Cópia
Forward_list <int> list(lista);
assert(lista.size() == 17);

//Teste construtor move
Forward_list <int> move(list);
assert(lista.size() == 17);

    cout << "\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}
