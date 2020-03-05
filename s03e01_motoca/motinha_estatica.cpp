#include <iostream>
#include <sstream>
using namespace std;

struct Pessoa {
    string nome;
    int idade;

    Pessoa(string nome = "", int idade = -1){
        this->nome = nome;
        this->idade = idade;
        cout << this->nome << " esta nascendo\n"; 
    }
    ~Pessoa(){
        cout << this->nome << " esta morrendo\n";
    }
};

struct Motinha{
    Pessoa pessoa; //composicao

    void embarcar(Pessoa pessoa){
        this->pessoa = pessoa;
    }
    
    void desembarcar(){
        this->pessoa = Pessoa();
    }

    void dirigir(){
        if(this->pessoa.idade >= 4)
            cout << pessoa.nome << ": Urruuu, dando uma voltinha\n";
        else if (this->pessoa.idade >= 0)
            cout << pessoa.nome << "Você não sabe andar ainda\n";
        else
            cout << "nao tem ninguem na motinha\n"; 
    }

};

int main() {
    Motinha motinha;
    while(true){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "embarcar"){//nome idade
            string nome;
            int idade;
            ss >> nome >> idade;
            motinha.embarcar(Pessoa(nome, idade));

        }else if(cmd == "dirigir"){
            motinha.dirigir();
        }else if(cmd == "desembarcar"){
            motinha.desembarcar();
        }else{
            cout << "comando invalido\n";
        }
    }
}

