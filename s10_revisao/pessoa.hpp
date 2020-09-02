#pragma once

#include <iostream>
using namespace std;

class Pessoa{
    string nome;
public:
    int idade;
    Pessoa(string n = "", int i = -1);
    string getNome() const;
    void envelhecer();
};
