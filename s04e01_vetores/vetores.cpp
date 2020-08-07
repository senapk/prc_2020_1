#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

void show(vector<int> vet){
    cout << "[ ";
    for(size_t i = 0; i < vet.size(); i++)
        cout << vet[i] << " ";
    cout << "]\n";
}

int main(){
    string line;
    vector<int> vet;
    while(true){
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "add"){
            int value;
            while(ss >> value){
                vet.push_back(value);
            }
        }else if(cmd == "show"){
            show(vet);
        }else{
            cout << "fail: comando invalido\n";
        }
    }

    return 0;
}