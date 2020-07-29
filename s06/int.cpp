#include <iostream>
#include <vector>

int main(){
    std::vector<char*> vet(10);
    vet[4] = new char('b'); vet[6] = new char('g'); vet[7] = new char('z');
    
    for(char * value : vet){
        if(value == nullptr)
            std::cout << "- ";
        else
            std::cout << *value << " ";
    }
    std::cout << "\n";
}