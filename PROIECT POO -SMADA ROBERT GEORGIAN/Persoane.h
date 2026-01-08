#ifndef PERSOANE_H
#define PERSOANE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Persoana {
protected:
    string nume;
    string prenume;
    string email;

public:
    Persoana(string n, string p, string e);
    virtual ~Persoana();

    virtual void afisare() const = 0;
    string getNumeComplet() const;
};

class Cercetator : public Persoana {
private:
    string specializare;
    string grad;

public:
    Cercetator(string n, string p, string e, string spec, string gr);
    void afisare() const override;
};

class Manager : public Persoana {
private:
    int aniExperienta;
    string departament;

public:
    Manager(string n, string p, string e, int ani, string dep);
    void afisare() const override;
};

#endif
