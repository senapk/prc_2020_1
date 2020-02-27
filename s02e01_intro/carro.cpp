#include <iostream>
#include <sstream>
using namespace std;

struct Carro{
    int nPessoas = 0;
    int maxPessoas = 2;
    float gasolina = 0;
    float maxGasolina = 100;
    float odometro;

    bool embarcar(){
        if (this->nPessoas < this->maxPessoas){
            this->nPessoas += 1;
            cout << "embarcou\n";
            return true;
        }
        cout << "ta lotado\n";
        return false;
    }

    void abastecer(float gasolina){
        this->gasolina += gasolina;
        if(this->gasolina > this->maxGasolina)
            this->gasolina = this->maxGasolina;
    }

    void dirigir(float distancia){
        if(this->nPessoas == 0){
            cout << "Nao tem quem dirija\n";
            return;
        }
        if(this->gasolina >= distancia){
            this->gasolina -= distancia;
            this->odometro += distancia;
            cout << "Dirigindo\n";
            return;
        }
        cout << "nao tem gasolina\n";
    }
};

int main() {
    Carro carro;
    while(true){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "embarcar"){
            carro.embarcar();
        }else if(cmd == "abastecer"){
            float qtd;
            ss >> qtd;
            carro.abastecer(qtd);
        }else if(cmd == "dirigir"){
            float qtd;
            ss >> qtd;
            carro.dirigir(qtd);
        }else{
            cout << "comando invalido\n";
        }
    }
}

