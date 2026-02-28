//
//  main.cpp
//  unique corn
//
//  Created by Marina Balamoon on 2/24/26.
//

#include <iostream>
#include <vector>

using namespace std;

class Unicorn {
private:
    string name;
    static vector<string> takenNames;

public:
    Unicorn(const string& name1) {
        bool taken = false;

        for (int i = 0; i < (int)takenNames.size(); i++) {
            if (takenNames[i] == name1) {
                taken = true;
                break;
            }
        }

        if (taken) {
            cout << "The name " << name1 << " is already taken" << endl;
            name = "";
        }
        else {
            name = name1;
            takenNames.push_back(name1);
        }
    }

    ~Unicorn() {
        if (name == ""){
            return;
        }
        for (int i = 0; i < (int)takenNames.size(); i++) {
            if (takenNames[i] == name) {
                takenNames.erase(takenNames.begin() + i);
                break;
            }
        }
    }
};
vector<string> Unicorn::takenNames;

int main() {
    vector<Unicorn*> unicorns;
        string user;

        while (true) {
            cout << "Enter a unicorn name: ";
            cin >> user;

            Unicorn* u = new Unicorn(user);
            unicorns.push_back(u);
        }
}
