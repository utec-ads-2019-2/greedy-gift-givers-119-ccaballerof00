#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Persona
{
public:
    int money;
    string nombre;
    Persona():money(0){}
};

int main() {
    vector<Persona> nombres;
    int num;
    while(cin>>num) {
        string name;
        if (num != 0) {
            for (int i = 0; i < num; i++) {
                cin >> name;
                Persona nueva;
                nueva.nombre = name;
                nombres.push_back(nueva);
            }
            for (int i = 0; i < num; i++) {
                string nom_gastador;
                Persona auxi;
                cin >> nom_gastador;
                int k = 0;
                for (; k < num; k++) {
                    if (nombres[k].nombre == nom_gastador)
                        break;
                }
                int gasto;
                cin >> gasto;
                int personas;
                cin >> personas;
                if (gasto != 0) {
                    nombres[k].money -= (gasto / personas) * personas;
                }
                if (personas != 0) {
                    for (int j = 0; j < personas; j++) {
                        string nom;
                        cin >> nom;
                        for (int m = 0; m < num; m++) {
                            if (nom == nombres[m].nombre) {
                                nombres[m].money += gasto / personas;
                            }
                        }
                    }
                }
            }
            for (int i = 0; i < num; i++) {
                cout << nombres[i].nombre << " " << nombres[i].money;
                cout << endl;
                if (i == num - 1)cout << endl;
            }
            nombres.clear();
        }
    }
    return 0;
}