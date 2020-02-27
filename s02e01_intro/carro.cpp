#include <iostream>
using namespace std;

struct Carro{
    int nPessoas = 0;
    int maxPessoas = 2;
    float gasolina = 0;

    bool embarcar(){
        if (this->nPessoas < this->maxPessoas){
            this->nPessoas += 1;
            cout << "embarcou\n";
            return true;
        }
        cout << "ta lotado\n";
        return false;
    }
};

int main() {
    Carro * carro = new Carro();
    Carro * carro2 = carro;
    carro->embarcar();
    carro->embarcar();
    carro->embarcar();
    cout << carro->nPessoas << "\n";
    cout << carro2->nPessoas << "\n";
    return 0;
}

