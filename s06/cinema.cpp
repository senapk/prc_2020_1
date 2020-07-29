#include <iostream>
#include <vector>

struct Cliente{
    std::string id;
    std::string fone;
    bool livre;
    Cliente(std::string id = "", std::string fone = "", bool livre = true):
        id(id), fone(fone), livre(livre){
    }
    std::string toString(){
        if(livre)
            return "-";
        return id + ":" + fone;
    }
};

struct Sala{
    std::vector<Cliente> cadeiras;
    Sala(int lotacao):
        cadeiras(lotacao){
    }
    std::string toString(){
        std::string saida;
        for(auto cliente : cadeiras){
            saida += cliente.toString() + " ";
        }
        return saida;
    }
    bool ingressar(std::string id, std::string fone, int indice){
        //1. Não inserir se o índice não for válido
        if(indice < 0 || indice >= (int) cadeiras.size()){    // -1 < indice < cadeiras.size() também funfa
            std::cout << "fail: indice invalido\n";
            return false;
        }
        //2. Não colocar a pessoa numa cadeira já ocupada
        if(!cadeiras[indice].livre){
            std::cout << "fail: cadeira ocupada\n";
            return false;
        }
        //3. Não inserir a pessoa se ela já estiver na sala com o mesmo id
        for(auto cli : cadeiras){
            if(!cli.livre && cli.id == id){
                std::cout << "fail: pessoa ja esta no cinema\n";
                return false;
            }
        }

        cadeiras[indice] = Cliente(id, fone, false);
        return true;
    }
};

int main(){
    Sala sala(5);
    sala.ingressar("Elvis", "88", 3);
    sala.ingressar("Janio", "88", 3); //cadeira ocupada
    sala.ingressar("Elvis", "88", 2); //ja esta no cinema
    sala.ingressar("Bia", "88", -1); //indice invalido
    sala.ingressar("Bia", "88", 5); //indice invalido
    
    
    //sala.cadeiras[3] = Cliente("Elvis", "88", false);
    std::cout << sala.toString() << "\n";
}
