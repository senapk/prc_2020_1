#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Aluno; //forward declaration

class Disciplina{
    map<string, Aluno*> alunos;
    string nome;
public:
    Disciplina(string nome){
        this->nome = nome;
    }
    string getNome(){return nome;};
    void add_aluno(Aluno * aluno); //after
    void rm_aluno(string idAluno); //after
    friend ostream& operator<<(ostream& os, Disciplina& disciplina); //after
};

class Aluno{
    map<string, Disciplina*> disciplinas;
    string nome;
public:
    Aluno(string nome){
        this->nome = nome;
    }
    string getNome(){return nome;};
    friend void Disciplina::add_aluno(Aluno*);
    friend void Disciplina::rm_aluno(string);
    friend ostream& operator<<(ostream& os, Aluno& aluno){
        os << "- " << aluno.nome << "[ ";
        for(auto& [k, v] : aluno.disciplinas) //c++17
            os << v->getNome() << " ";
        os << "]";
        return os;
    }
};

void Disciplina::add_aluno(Aluno * aluno){
    if(this->alunos.count(aluno->nome) == 1)
        return;
    this->alunos[aluno->nome] = aluno;
    aluno->disciplinas[this->nome] = this;
}

void Disciplina::rm_aluno(string idAluno){
    if(this->alunos.count(idAluno) == 0)
        return;
    //se remover das disciplinas do aluno
    this->alunos[idAluno]->disciplinas.erase(this->nome);

    //remover o aluno da lista de alunos
    this->alunos.erase(idAluno);
}

ostream& operator<<(ostream& os, Disciplina& disciplina){
    os << "- " << disciplina.nome << "[ ";
    for(auto& par : disciplina.alunos) //c++17
        os << par.second->getNome() << " ";
    os << "]";
    return os;
}

template <class T>
T& get(map<string, T>& mapa, string key){
    if(mapa.count(key) == 0)
        throw string("chave " + key + " nao existe");
    return mapa[key];
}

class UFC{
    map<string, Disciplina> disciplinas;
    map<string, Aluno> alunos;
public:

    UFC(){
    }
    ~UFC(){

    }

    void nova_diciplina(string nome){
        if(disciplinas.count(nome) == 1)
            return;
        disciplinas[nome] = Disciplina(nome);
    }
    void novo_aluno(string nome){
        if(alunos.count(nome) == 1)
            return;
        alunos[nome] = Aluno(nome);
    }
    void matricular(string idDisciplina, string idAluno){
        get(disciplinas, idDisciplina)
        ->add_aluno(&alunos.at(idAluno));
    }
    friend ostream& operator<<(ostream& os, UFC& ufc){
        os << "alunos:\n";
        for(auto& [k, v] : ufc.alunos)
            os << *v << "\n";
        os << "discps:\n";
        for(auto& [k, v] : ufc.disciplinas)
            os << *v << "\n";
        return os;
    }
};

template<class T>
T get(istream& is){T t; is >> t; return t;}

int main(){
    UFC ufc;
    while(true){
        try{
            string cmd, value, line;
            getline(cin, line);
            stringstream ss(line);
            ss >> cmd;

            if(cmd == "end"){
                break;
            }else if(cmd == "nwdis"){
                while(ss >> value)
                    ufc.nova_diciplina(value);
            }else if(cmd == "nwalu"){
            while(ss >> value)
                    ufc.novo_aluno(value);
            }else if(cmd == "matricular"){
                string aluno = get<string>(ss);
                while(ss >> value){
                    ufc.matricular(value, aluno);
                }
            }else if(cmd == "show"){
                cout << ufc;
            }else{
                cout << "comando invalido" << endl;
            }
        }catch(string e){
            cout << e << endl;
        }catch(out_of_range& e){
            cout << e.what() << endl;
        }catch(...){
            cout << "sei que diabeisso nao";
        }
    }
    return 0;
}