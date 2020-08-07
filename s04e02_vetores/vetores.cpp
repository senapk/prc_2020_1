#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> vet = {1, 3, 4, 5, 6, 9};
    vet.push_back(7);
    {
        auto it = vet.begin();
        cout << (*it) << endl; //1
        it++;
        cout << (*it) << endl; //3
        cout << (*(vet.begin() + 4));//6
        vet.erase(vet.begin() + 4);
    }
    auto it = find(vet.begin(), vet.end(), 6);
    if(it != vet.end())
        cout << *it;
    else
        cout << "nao existe 6" << endl;
    for(auto it = vet.begin(); it != vet.end(); it++)
        cout << (*it);

}