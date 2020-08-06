#include <cstdio>
#include <vector>
#include <iostream>

template<class Coisa>
Coisa somatodos(Coisa vet[], int size){
    Coisa soma = 0;
    for(int i = 0; i < size; i++)
        soma += vet[i];
    soma.cantar();
    return soma;
};

template <class T>
void swap(T& a, T& b){
    T c = a;
    a = b;
    b = c;
}

class Pessoa{
public:
    std::string name;
    int idade;
    Pessoa(std::string name, int idade):
        name(name), idade(idade){
    }
};

std::ostream& operator<< (std::ostream &out, const Pessoa &pessoa){
    out << pessoa.name << ":" << pessoa.idade;
    return out;
}

template <class T>
class Bau{
public:
    T * value;
    bool open;
    Bau(){
        open = false;
        value = nullptr;
    }
    T * olhar(){
        if(open)
            return value;
        std::cout << "abra primeiro\n";
        return nullptr;
    }
    void abrir(){
        open = true;
    }
    void fechar(){
        open = false;
    }
    void guardar(T * value){
        if(!open){
            std::cout << "abra primeiro\n";
            return;
        }
        if(this->value == nullptr){
            this->value = value;
            return;
        }
        std::cout << "bau cheio\n";
    }
    T * retirar(){
        if(this->value == nullptr){
            std::cout << "bau vazio\n";
            return nullptr;
        }
        T * temp = value;
        this->value = nullptr;
        return temp;
    }
};


template <class T>
std::ostream& operator<< (std::ostream &out, const Bau<T> &bau){
    if(bau.value != nullptr)
        out << *bau.value;
    else
        out << "bau vazio";
    return out;
}

#include <map>
#include <vector>
#include <fstream>
int main(){

    std::ofstream arquivo("banana.txt");

    std::vector<int> vet = {3};
    vet.operator[](0);

    Bau<Pessoa> bau;
    Pessoa x("David", 36);
    Pessoa y("David", 39);
    Pessoa * value = bau.olhar();
    std::cout << bau << std::endl;
    
    bau.abrir();
    bau.guardar(&x);

    std::cout << bau<< std::endl;
    *bau.olhar() = Pessoa("Herick", 8);
    std::cout << bau << std::endl;
    bau.retirar();
    bau.guardar(&y);
    std::cout << bau << std::endl;


#if 0
    std::map<long, std::string> clientes;
    clientes[32259608] = "David";
    clientes[32260909] = "Francisco";

    std::vector<int> vet = {4, 3, 5};
    try{
        std::cout << vet.at(6) << "\n";
        std::cout << "sucesso\n";
    }catch(std::out_of_range e){
        std::cout << "fracasso\n";
    }
#endif
}