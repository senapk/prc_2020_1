#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    map<string, int> mapa;
    mapa["david"] = 32233;
    mapa["petrucio"] = 445522;
    mapa["ana"] = 12223;

    for(pair<string, int> par : mapa)
        cout << par.first << " " << par.second << endl;
    

    auto it = mapa.find("ana");
    if(it != mapa.end())
        cout << it->second << endl;
        
    cout << mapa["ana"] << endl;
    cout << mapa.at("rodolfo") << endl;
    
    for(pair<string, int> par : mapa)
        cout << par.first << " " << par.second << endl;
}

