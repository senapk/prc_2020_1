#include <stdio.h>

const char * fazer_barulho(){ //ok
    return "miau";
}

int rand_0_a_10(){
    static int init = 1;
    if(init == 1){
        srand(time(NULL));
        init = 0;
    }
    return rand() % 10;
}

int * retornar_coisa(){ //ok
    static int dummy = 5; //persistente
    return &dummy;
}

int main(){
    const char * nome = "Baritono";
    
    int * y = retornar_coisa;
    *y = 6;

    Animal *pAnimal{ &cat }; //c++11
    Animal *pAnimal = &cat; //c

}