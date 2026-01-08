#ifndef RESURSE_H
#define RESURSE_H

#include <iostream>
#include <string>

using namespace std;

class Resursa {
protected:
    string nume;
    double valoareRON;

public:
    Resursa(string n, double v);
    virtual ~Resursa();

    virtual void afisareDetalii() const = 0;
    string getNume() const;
};

class Echipament : public Resursa {
private:
    string serieInventar;
    string dataAchizitie;

public:
    Echipament(string n, double v, string serie, string data);
    void afisareDetalii() const override;
};

class Consumabil : public Resursa {
private:
    double cantitate;
    string unitateMasura;

public:
    Consumabil(string n, double v, double cant, string um);
    void afisareDetalii() const override;
};

#endif
