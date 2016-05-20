/*!
 *  @mainpage Vector
 *  @author Adelino Afonso Fernandes Avelino
 *  @author Irene Ginani Costa Pinheiro
 *  @date May, 2016
 *  @version 1.0
 *
 *  @file drive_vector.cpp
 *
 *  @brief Arquivo driver
 *
 *  Arquivo com os testes das funcoes da classe Vector
 */

#include <iostream>
#include <cassert>
#include "vector.h"


using namespace std;
int main(int argc, char const *argv[])
{
	
Vector<int> vetor(30);
Vector<int> vetor2;
int j = 0;

  
//Teste size()
assert(vetor.size() == 0);
assert(vetor2.size() == 0);

assert(vetor.capacity() == 30);
assert(vetor2.capacity() == 1);

//Testes push_back()
for (int i = 0; i < 20; i++) 
    vetor.push_back(i);

for (int i = 0; i < 20; i++) 
    vetor2.push_back(i);
 
//Testes Front()
assert(vetor.front() == 0);
assert(vetor2.front() == 0);

//Testes Back()
assert(vetor.back() == 19);
assert(vetor2.back() == 19);


//Teste size()
assert(vetor.size() == 20);
assert(vetor2.size() == 20);

//Teste pop_back();
vetor.pop_back();
vetor2.pop_back();

//Testes begin() e and()
for (auto i = vetor.begin(); i != vetor.end(); i++)
{
	assert(*i == j);
	j++;
}
assert(j == 19);
	
	j = 0;
for (auto i = vetor.begin(); i != vetor.end(); ++i)
{
	assert(*i == j);
	j++;
}
assert(j == 19);

	j = 0;
//Testes cbegin() e cand()
for (auto i = vetor.cbegin(); i != vetor.cend(); i++)
{
	assert(*i == j);
	j++;
}
assert(j == 19);
	
	j = 0;
for (auto i = vetor.cbegin(); i != vetor.cend(); ++i)
{
	assert(*i == j);
	j++;
}
assert(j == 19);


//Testes assingn()
vetor.assign(1);
vetor2.assign(3);

for (int i = 0; i < 19; ++i)
{
assert(vetor[i] == 1);
assert(vetor2[i] == 3);
}
 
//Testes clear()
vetor.clear();
vetor2.clear();

//Teste size()
assert(vetor.size() == 0);
assert(vetor2.size() == 0); 


    cout << "\n>>> Normal exiting...\n";
    return EXIT_SUCCESS;
}