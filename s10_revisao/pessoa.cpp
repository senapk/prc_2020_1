#include "pessoa.hpp"
#include <iostream>
using namespace std;


Pessoa::Pessoa(string n, int i){
    nome = n;
    idade = i;
}

string Pessoa::getNome() const{
        return nome;
}

void Pessoa::envelhecer(){
    idade = idade + 1;
}