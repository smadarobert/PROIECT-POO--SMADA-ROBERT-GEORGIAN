#include "Persoane.h"

Persoana::Persoana(string n, string p, string e)
    : nume(n), prenume(p), email(e) {
}

Persoana::~Persoana() {
}

string Persoana::getNumeComplet() const {
    return nume + " " + prenume;
}

Cercetator::Cercetator(string n, string p, string e, string spec, string gr)
    : Persoana(n, p, e), specializare(spec), grad(gr) {
}

void Cercetator::afisare() const {
    cout << "  [Cercetator] " << nume << " " << prenume
        << " | Specializare: " << specializare
        << " | Grad: " << grad
        << " | Email: " << email << endl;
}

Manager::Manager(string n, string p, string e, int ani, string dep)
    : Persoana(n, p, e), aniExperienta(ani), departament(dep) {
}

void Manager::afisare() const {
    cout << "  [Manager]    " << nume << " " << prenume
        << " | Exp: " << aniExperienta << " ani"
        << " | Dept: " << departament
        << " | Email: " << email << endl;
}