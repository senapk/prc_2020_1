#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct Chave{
    int segredo;
    float dentes;

    friend ostream& operator<<(ostream& os, Chave chave){
        os << "chave:segredo:" << chave.segredo << ":dentes:" << chave.dentes;
        return os;
    }

    friend istream& operator>>(istream& is, Chave& chave){
        is >> chave.segredo >> chave.dentes;
        return is;
    }
};

int main(){
    cout << (Chave){4,5.6} << " " << (Chave){5,5.6} << endl;
    cout << "Digite uma chave\n";
    Chave ch;
    cin >> ch;
    cout << ch;
}


int main3(){
    stringstream ss("banana 123 4.5");
    string fruta;
    ss >> fruta;
    ss << " rapadura";
    cout << ss.str() << endl;
    return 0;
}

int main2(){
    ifstream arq_entrada("arq_entrada.txt");
    ofstream arq_saida("arq_saida.txt");
    if(!arq_entrada.is_open())
        cout << "erro na leitura\n";
    int value;
    cout << "Digite um inteiro\n";
    arq_entrada >> value;
    arq_saida << "Voce escreveu " << value << endl;
    return 0;
}