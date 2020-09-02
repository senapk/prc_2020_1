#include <iostream>
using namespace std;

#define MAX 5;

extern int y;//declaracao
extern int y;
extern int y;
extern int y;
extern int y;

int soma(int,int); //declarando
int soma(int,int); //declarando
int soma(int,int); //declarando
int soma(int,int); //declarando
int soma(int,int); //declarando

#include "pessoa.hpp"
int main(){
    Pessoa davi("David", 7);
    davi.envelhecer();
    cout << davi.idade << endl;
}