#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <algorithm>
using namespace std;

class Fone{
public:
    int index;
    string id;
    string fone;

    Fone(int index, string id = "", string fone = ""){
        this->index = index;
        this->id = id;
        this->fone = fone;
    }

    static bool validar(string number){
        string valid = "0123456789()-.";
        for(char c : number)
            if(valid.find(c) == string::npos)
                return false;
        return true;
    }
};

ostream& operator<<(ostream& ost, const Fone& fone){
    ost << "[" << fone.index << ":" << fone.id << ":" << fone.fone << "]";
    return ost;
}

class Contato{
public:
    string name;
    vector<Fone> fones;
    Contato(string name = "", vector<Fone> fones = vector<Fone>()):
        name(name), fones(fones){
    }

    string getName(){
        return name;
    }
    void addFone(string id, string fone){
        if(Fone::validar(fone))
            fones.push_back(Fone(this->fones.size(), id, fone));
        else
            cout << "fail: fone invalido" << endl;
    }
    void rmFone(int index){
        if(index < 0 || index >= (int) fones.size())
            return;
        fones.erase(fones.begin() + index);
        for(int i = 0; i < (int) fones.size(); i++)
            fones[i].index = i;
    }
    vector<Fone> getFones(){
        return fones;
    }
};


ostream& operator<<(ostream& ost, Contato& contato){
    ost << "- " << contato.getName();
    if(!contato.getFones().empty())
        cout << " ";
    for(Fone fone : contato.getFones())
        ost << fone;
    return ost;
}

template <class T>
T get(stringstream& ss){
    T t;
    ss >> t;
    return t;
}

int main(int argc, char const *argv[]){
    Contato contato;
    while(true){
        string line, cmd;
        getline(cin, line);
        cout << "$" << line << endl;
        stringstream ss(line);
        ss >> cmd;
        if(cmd == "end"){
            break;
        }
        else if(cmd == "init"){//name
            contato = Contato(get<string>(ss));
        }
        else if(cmd == "add"){//id fone
            string id = get<string>(ss);
            string fone = get<string>(ss);
            contato.addFone(id, fone); //composição
        }
        else if(cmd == "rm"){
            contato.rmFone(get<int>(ss));
        }
        else if(cmd == "show"){
            cout << contato << "\n";
        }
        else{
            cout << "fail: comando invalido";
        }
    }
}
/*

int main(){
    string line;
    getline(cin, line);
    stringstream ss(line);
    string cmd;
    ss >> cmd;
    if(cmd == "add"){
        string nome;
        ss >> nome;
        string id_fone;//id:fone
        Contato contato(nome);
        while(ss >> id_fone){
            stringstream sif(id_fone);
            string id, fone;
            getline(sif, id, ':');
            sif >> fone;
            contato.addFone(id, fone);
        }
    }

    std::sort(vet.begin(), vet.end(), )

}
*/