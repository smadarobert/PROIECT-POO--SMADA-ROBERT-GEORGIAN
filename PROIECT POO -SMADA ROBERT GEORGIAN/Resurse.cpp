#include "Resurse.h"

Resursa::Resursa(string n, double v) : nume(n), valoareRON(v) {}

Resursa::~Resursa() {}

string Resursa::getNume() const {
    return nume;
}

Echipament::Echipament(string n, double v, string serie, string data)
    : Resursa(n, v), serieInventar(serie), dataAchizitie(data) {
}

void Echipament::afisareDetalii() const {
    cout << "  [Echipament] " << nume
        << " | Serie: " << serieInventar
        << " | Achizitionat: " << dataAchizitie
        << " | Valoare: " << valoareRON << " RON" << endl;
}

Consumabil::Consumabil(string n, double v, double cant, string um)
    : Resursa(n, v), cantitate(cant), unitateMasura(um) {
}

void Consumabil::afisareDetalii() const {
    cout << "  [Consumabil] " << nume
        << " | Stoc: " << cantitate << " " << unitateMasura
        << " | Valoare totala: " << valoareRON * cantitate << " RON" << endl;
}