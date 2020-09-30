#include <iostream>
#include <string_view>
#include <string>
#include <map>
using namespace std;

class Conta{
    id
    cliente
    protected tipo
    saldo
    Conta(id, cliente)
        id = id
        cliente = cliente
        saldo = 0

    operator<<(){
        os << conta.id << conta.cliente << conta.saldo << conta.tipo;
    }

};
class ContaCorrente : public Conta{
    ContaCorrent(id, cliente):
        Conta {id, cliente}, tipo {"CC"}
    {
    }

};
class ContaPoupanca : public Conta{};

class Agencia{
    map<string, Cliente*> clientes;
    map<int, Conta*> contas; //slicering
    nextId = 0
    int fn(){
        contas[1] = new ContaCorrente(1, "David");
        contas[2] = new ContaPoupanca(2, "David");
    }
    void addCliente(string name){
        verifica se o mapa ja possui esse cliente
        se nao possuir
            cliente = new Cliente(name)
            cc = new ContaCorrente(nextId++, name)
            cp = new ContaPoupanca(nextId++, name)
            cliente.addConta(cc)
            cliente.addConta(cp)
            clientes[name] = cliente;
            contas[cc.id] = cc;
            contas[cp.id] = cp;

    }
}


class Animal { //abstract
protected:
    std::string m_name;
    Animal(const std::string &name): m_name{ name }{}
public:
    virtual const std::string& getName() const { return m_name; }
    virtual std::string_view speak() const = 0; //virtual puro
};

class Porco: public Animal{
public:
    Porco(const std::string &name): Animal{ name }{}
    virtual std::string_view speak() const{return "ionc";}
};



class Cat: public Animal
{
public:
    Cat(const std::string &name): Animal{ name }{}
    virtual std::string_view speak() const { return "Meow"; }
};
 
class Dog: public Animal
{
public:
    Dog(const std::string &name): Animal{ name }{}
    virtual std::string_view speak() const { return "Woof"; }
};

void report(const Animal &rAnimal){
    std::cout << rAnimal.getName() << " says " << rAnimal.speak() << '\n';
}

int main()
{
    Porco porco{ "Jose" };

    Cat fred{ "Fred" };
    Cat misty{ "Misty" };
    Cat zeke{ "Zeke" };
 
    Dog garbo{ "Garbo" };
    Dog pooky{ "Pooky" };
    Dog truffle{ "Truffle" };
 
    Animal *animals[]{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };
    for (const Animal* animal : animals)
       report(*animal);
 
    return 0;
}