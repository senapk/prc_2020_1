#include <iostream>
#include <memory>
using namespace std;

struct Pessoa {
    string nome;
    int idade;

    Pessoa(string nome, int idade){
        this->nome = nome;
        this->idade = idade;
        cout << this->nome << " esta nascendo\n"; 
    }

    ~Pessoa(){
        cout << this->nome << " esta morrendo\n";
    }
};