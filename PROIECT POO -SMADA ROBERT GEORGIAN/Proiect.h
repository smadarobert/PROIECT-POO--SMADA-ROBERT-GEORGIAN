#ifndef PROIECT_H
#define PROIECT_H

#include <iostream>
#include <string>
#include <vector>
#include "Persoane.h"
#include "Resurse.h"

using namespace std;

struct Etapa {
    string titlu;
    int progres;

    Etapa(string t) : titlu(t), progres(0) {}
};

class Proiect {
private:
    string titluProiect;
    string deadline;

    vector<Etapa> etape;
    vector<Persoana*> echipa;
    vector<Resursa*> resurseAlocate;

public:
    Proiect(string titlu, string dl);
    ~Proiect();

    void adaugaMembru(Persoana* p);
    void adaugaResursa(Resursa* r);
    void adaugaEtapa(string numeEtapa);

    void actualizeazaProgres(int indexEtapa, int procentNou);

    void afisareCompleta() const;
    void afisareProgres() const;
};

#endif