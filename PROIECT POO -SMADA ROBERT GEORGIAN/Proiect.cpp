#include "Proiect.h"

Proiect::Proiect(string titlu, string dl)
    : titluProiect(titlu), deadline(dl) {
}

Proiect::~Proiect() {
    echipa.clear();
    resurseAlocate.clear();
    etape.clear();
}

void Proiect::adaugaMembru(Persoana* p) {
    echipa.push_back(p);
}

void Proiect::adaugaResursa(Resursa* r) {
    resurseAlocate.push_back(r);
}

void Proiect::adaugaEtapa(string numeEtapa) {
    Etapa e(numeEtapa);
    etape.push_back(e);
}

void Proiect::actualizeazaProgres(int indexEtapa, int procentNou) {
    if (indexEtapa >= 0 && indexEtapa < etape.size()) {
        if (procentNou > 100) procentNou = 100;
        if (procentNou < 0) procentNou = 0;
        etape[indexEtapa].progres = procentNou;
        cout << ">> Progres actualizat pentru etapa '" << etape[indexEtapa].titlu << "'." << endl;
    }
    else {
        cout << "!! Index etapa invalid." << endl;
    }
}

void Proiect::afisareCompleta() const {
    cout << "\n=============================================" << endl;
    cout << "PROIECT: " << titluProiect << " | Deadline: " << deadline << endl;
    cout << "=============================================" << endl;

    cout << "\n--- ECHIPA ---" << endl;
    if (echipa.empty()) cout << " (Niciun membru alocat)" << endl;
    for (auto* p : echipa) {
        p->afisare();
    }

    cout << "\n--- RESURSE ---" << endl;
    if (resurseAlocate.empty()) cout << " (Nicio resursa alocata)" << endl;
    for (auto* r : resurseAlocate) {
        r->afisareDetalii();
    }

    afisareProgres();
}

void Proiect::afisareProgres() const {
    cout << "\n--- STATUS PROIECT ---" << endl;
    if (etape.empty()) {
        cout << "Nu exista etape definite." << endl;
        return;
    }

    double total = 0;
    for (size_t i = 0; i < etape.size(); i++) {
        cout << i + 1 << ". " << etape[i].titlu
            << " [" << etape[i].progres << "%]" << endl;
        total += etape[i].progres;
    }

    double media = total / etape.size();
    cout << ">> PROGRES TOTAL PROIECT: " << media << "%" << endl;
    if (media == 100) cout << ">> PROIECT FINALIZAT!" << endl;
}