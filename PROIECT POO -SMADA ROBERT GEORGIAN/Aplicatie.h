#ifndef APLICATIE_H
#define APLICATIE_H

#include <vector>
#include "Proiect.h"
#include "Persoane.h"
#include "Resurse.h"

class Aplicatie {
private:
    Proiect* proiectCurent;
    vector<Persoana*> toatePersoanele;
    vector<Resursa*> toateResursele;

    void afisareMeniu() const;
    void curataMemorie();
    void incarcaDateDemonstrative();

public:
    Aplicatie();
    ~Aplicatie();

    void run();
};

#endif
