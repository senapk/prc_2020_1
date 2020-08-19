#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Cliente{
public:
    string id;
    string fullname;
    int divida;
    vector<int> extrato;
    Cliente(string id = "", string fullname = ""){
        this->id = id;
        this->fullname = fullname;
        this->divida = 0;
    }
    bool operator<(const Cliente& other){
        return id < other.id;
    }
    void addOperation(int value){
        extrato.push_back(value);
        divida += value;
    }

    string getExtrato(){
        string saida = "[ ";
        for(int value : extrato)
            saida += to_string(value) + " ";
        return saida + "]";
    }
};

ostream& operator<<(ostream& os, Cliente& cliente){
    os << "(" << cliente.id << ":" << cliente.fullname;
    os << ":" << cliente.divida << ")";
    return os;
}

class Sistema{
public:
    map<string, Cliente> clientes;
    
    bool inserirCliente(Cliente cliente){
        if(getCliente(cliente.id) == nullptr){
            clientes[cliente.id] = cliente;
            return true;
        }
        return false;
    }

    Cliente * getCliente(string id){
        auto it = clientes.find(id);
        if(it == clientes.end())
            return nullptr;
        return &it->second;
    }

    bool addOperacao(string id, int value){
        Cliente * cliente = getCliente(id);
        if(cliente == nullptr){
            cout << "fail: cliente " << id << " nao existe\n";
            return false;
        }
        cliente->addOperation(value);
        return true;
    }

    string getExtrato(string id){
        Cliente * cliente = getCliente(id);
        if(cliente == nullptr){
            cout << "fail: cliente " << id << " nao existe\n";
            return "";
        }
        return cliente->getExtrato();
    }
};

ostream& operator<<(ostream& os, Sistema& sistema){
    os << "[ ";
    for(auto& par : sistema.clientes)
        os << par.second << " ";
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
    sistema.addOperacao("ana", 50);
    sistema.addOperacao("ana", -20);
    sistema.addOperacao("ana", -10);
    sistema.addOperacao("zeca", 30);
    sistema.addOperacao("zeruela", 90);
    cout << sistema << endl;
    cout << sistema.getExtrato("ana") << endl;
}