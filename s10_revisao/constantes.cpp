#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Pessoa{
    string nome;
    int idade;
public:
    Pessoa(string n, int i): nome(n), idade(i){}
    string getNome() const{
        return nome;
    }
    void envelhecer(){
        idade = idade + 1;
    }
};

void viver(const Pessoa& pessoa){
    Pessoa outra = pessoa;
    cout << outra.getNome();
    outra.envelhecer();
}


void soma_mais_um(const int& x){
    cout << (x + 1) << endl;
}

int main(){
    int x = 7;
    soma_mais_um(x);
    soma_mais_um((int){5});
    soma_mais_um(5);

}