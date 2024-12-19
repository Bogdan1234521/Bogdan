#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
 
using namespace std;
 
int calculeazaScor(const vector<int>& mana) {
    int scor = 0;
    int numarAsi = 0;
 
    for (int card : mana) {
        if (card >= 10) {
            scor += 10;
        } else {
            scor += card;
        }
 
        if (card == 1) {
            numarAsi++;
        }
    }
 
    while (scor <= 11 && numarAsi > 0) {
        scor += 10;
        numarAsi--;
    }
 
    return scor;
}
 
void afiseazaMana(const vector<int>& mana, string nume) {
    cout << nume << ": ";
    for (int card : mana) {
        cout << card << " ";
    }
    cout << "(Scor: " << calculeazaScor(mana) << ")" << endl;
}
 
int traseazaCarte() {
    int carte = rand() % 13 + 1;
    return (carte > 10) ? 10 : carte;
}
 
int main() {
    srand(time(NULL));
    vector<int> manaJucator;
    vector<int> manaDealer;
 
    manaJucator.push_back(traseazaCarte());
    manaJucator.push_back(traseazaCarte());
    manaDealer.push_back(traseazaCarte());
    manaDealer.push_back(traseazaCarte());
 
    afiseazaMana(manaJucator, "Jucator");
    afiseazaMana(manaDealer, "Dealer (una este ascunsa)");
 
    while (true) {
        char optiune;
        cout << "Vrei sa ceri o carte (c), sau sa stai (s)? ";
        cin >> optiune;
 
        if (optiune == 'c') {
            manaJucator.push_back(traseazaCarte());
            afiseazaMana(manaJucator, "Jucator");
 
            if (calculeazaScor(manaJucator) > 21) {
                cout << "Ai depasit 21! Ai pierdut!" << endl;
                return 0;
            }
        } else if (optiune == 's') {
            break;
        } else {
            cout << "Optiune invalida. Te rog alege 'c' sau 's'." << endl;
        }
    }
 
    while (calculeazaScor(manaDealer) < 17) {
        manaDealer.push_back(traseazaCarte());
    }
 
    afiseazaMana(manaDealer, "Dealer");
 
    int scorJucator = calculeazaScor(manaJucator);
    int scorDealer = calculeazaScor(manaDealer);
 
    if (scorDealer > 21 || scorJucator > scorDealer) {
        cout << "Jucatorul câștigă!" << endl;
    } else if (scorJucator < scorDealer) {
        cout << "Dealer câștigă!" << endl;
    } else {
        cout << "Este o egalitate!" << endl;
    }
 
    return 0;
}