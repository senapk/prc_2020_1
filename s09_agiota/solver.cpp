#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Cliente{
public:
    string id;
    string fullname;
    Cliente(string id, string fullname){
        this->id = id;
        this->fullname = fullname;
    }
    bool operator<(const Cliente& other){
        return id < other.id;
    }
};

bool compara_cliente(Cliente one, Cliente two){
    return one.fullname < two.fullname;
}

ostream& operator<<(ostream& os, Cliente& cliente){
    os << "(" << cliente.id << ":" << cliente.fullname << ")";
    return os;
}

class Sistema{
public:
    //map<string, Cliente> clientes;
    vector<Cliente> clientes;

    bool inserirCliente(Cliente cliente){
        for(Cliente cli : clientes){
            if(cliente.id == cli.id)
                return false;
        }
        clientes.push_back(cliente);

        std::sort(clientes.begin(), clientes.end(), compara_cliente);

        return true;
    }
};

ostream& operator<<(ostream& os, Sistema& sistema){
    os << "[ ";
    for(auto& cliente : sistema.clientes)
        os << cliente << " ";
    os << "]";
    return os;
}

int main(){
    Sistema sistema;
    sistema.inserirCliente(Cliente("mario", "Armario Quintana"));
    sistema.inserirCliente(Cliente("ana", "Mariana Amelia"));
    sistema.inserirCliente(Cliente("zeca", "Zeh Carioca"));
    cout << sistema << endl;
    //cout << (Cliente("ana", "Ana Maria") < Cliente("Zeca", "Z"));
}