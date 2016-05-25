# Implementing the List Abstract Data Type

## Descrição

    O projeto em questão foi realizado para a disciplina de Liguagem de Programação I e visa o desenvolvimento de três classes, um vector, uma forward_list e um list (vetor, lista encadeada e lista duplamente encadeada). Para que essas classes se comportassem de forma semelhante as da biblioteca do c++ std, foi necessário desenvolver mais duas classes para cada estrutura de dado, um const_iterator e um iterator. Essas duas classes auxiliares tinham métodos de acesso a determinados pontos das estruturas de forma que se comportavam como ponteiros encapsulados.
    A implementacao consiste em desenvolver funcoes basicas como: inserir elementos de diversas formas, remover elementos, modificar valores, atribuir valores, colher valores. Na implementacao tambem foi necessario o desenvolvimento de iteradores em todas as tres classes solicitadas no documento. Em virtude de facilidade de testes os drivers dos programas foram divididos em tres partes.


## Compilação e Execucao
### Dentro de seu respectivo diretorio executar o comando referente 

####Vector

g++ -std=c++11 -I include/ src/drive_vector.cpp -o bin/exe && ./bin/exe

####Forward_list

g++ -std=c++11 -I include/ src/drive_forward_list.cpp -o bin/exe && ./bin/exe

####List

g++ -std=c++11 -I include/ src/drive.cpp -o bin/exe  && ./bin/exe


## Autores:
* Adelino Afonso Fernandes Avelino - adelino-afonso@hotmail.com

* Irene Ginani Costa Pinheiro - ireneginani@gmail.com


