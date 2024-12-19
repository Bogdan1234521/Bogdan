#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> 
using namespace std;
 
void afiseazaPaharele(int pozitieMoneda, int mutare, int paharuri[3]) {
    for (int i = 0; i < 3; i++) {
        if (paharuri[i] == 1) {
            if (i + 1 == pozitieMoneda) {
                cout << "[M] ";
            } else {
                cout << "[ ] ";
            }
        } else {
            cout << "[ ] "; 
        }
    }
    cout << endl;
}

void mutaPaharele(int* paharuri) {
    for (int i = 0; i < 3; i++) {
        int randIndex = rand() % 3;
        swap(paharuri[i], paharuri[randIndex]);
    }
}
 
int main() {
    srand(static_cast<unsigned int>(time(0))); 
    int pozitieMoneda = rand() % 3 + 1;
    int paharuri[3] = {0, 0, 0}; 
    paharuri[pozitieMoneda - 1] = 1; 
 
    cout << "Bun venit la jocul cu pahare! Incearca sa ghicesti unde se afla moneda.\n";
    afiseazaPaharele(pozitieMoneda, 0, paharuri);
    
    cout << "Paharele vor fi mutate...\n";
    sleep(2); 
 
    mutaPaharele(paharuri); 
    cout << "Paharele s-au mutat!\n";
    afiseazaPaharele(pozitieMoneda, 0, paharuri); 
 
    int alegere;
    cout << "Alege un pahar (1, 2 sau 3): ";
    cin >> alegere;
    if (alegere < 1 || alegere > 3) {
        cout << "Alegerea ta este invalida! Te rugam sa alegi 1, 2 sau 3.\n";
    } else {
        if (paharuri[alegere - 1] == 1) {
            cout << "Felicitari! Ai gasit moneda!\n";
        } else {
            cout << "Din pacate, moneda este sub paharul " << pozitieMoneda << ", nu sub paharul " << alegere << ".\n";
        }
    }
 
    return 0;
}
