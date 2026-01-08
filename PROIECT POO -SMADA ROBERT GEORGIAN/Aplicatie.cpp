#include "Aplicatie.h"
#include <iostream>

using namespace std;

Aplicatie::Aplicatie() {
    proiectCurent = nullptr;
}

Aplicatie::~Aplicatie() {
    curataMemorie();
}

void Aplicatie::curataMemorie() {
    if (proiectCurent != nullptr) {
        delete proiectCurent;
        proiectCurent = nullptr;
    }

    for (auto p : toatePersoanele) {
        delete p;
    }
    toatePersoanele.clear();

    for (auto r : toateResursele) {
        delete r;
    }
    toateResursele.clear();
}

void Aplicatie::afisareMeniu() const {
    cout << "\n--- GESTIUNE PROIECTE CERCETARE ---" << endl;
    cout << "1. Creare Proiect Nou" << endl;
    cout << "2. Adaugare Membru in Echipa" << endl;
    cout << "3. Adaugare Resursa" << endl;
    cout << "4. Definire Etapa Proiect" << endl;
    cout << "5. Actualizare Progres Etapa" << endl;
    cout << "6. Afisare Raport Complet Proiect" << endl;
    cout << "7. INCARCA DATE DEMO (Pentru prezentare)" << endl;
    cout << "0. Iesire" << endl;
    cout << "Alegeti optiunea: ";
}

void Aplicatie::incarcaDateDemonstrative() {
    curataMemorie();

    cout << ">> Se incarca datele demonstrative..." << endl;

    proiectCurent = new Proiect("Sistem AI Avansat", "15/07/2024");

    Persoana* m = new Manager("Popescu", "Ion", "ion.pop@test.ro", 10, "IT");
    Persoana* c = new Cercetator("Ionescu", "Maria", "maria.i@test.ro", "Robotica", "Senior");

    toatePersoanele.push_back(m);
    toatePersoanele.push_back(c);

    proiectCurent->adaugaMembru(m);
    proiectCurent->adaugaMembru(c);

    Resursa* r1 = new Echipament("Server Dell", 15000, "SV-2024-X", "01/01/2024");
    Resursa* r2 = new Consumabil("Cabluri retea", 500, 100, "metri");

    toateResursele.push_back(r1);
    toateResursele.push_back(r2);

    proiectCurent->adaugaResursa(r1);
    proiectCurent->adaugaResursa(r2);

    proiectCurent->adaugaEtapa("Analiza Cerinte");
    proiectCurent->adaugaEtapa("Implementare Algoritm");
    proiectCurent->adaugaEtapa("Testare Finala");

    proiectCurent->actualizeazaProgres(0, 100);
    proiectCurent->actualizeazaProgres(1, 50);

    cout << ">> Datele au fost incarcate cu succes! Puteti afisa raportul (Optiunea 6)." << endl;
}

void Aplicatie::run() {
    int optiune;
    do {
        afisareMeniu();
        cin >> optiune;

        switch (optiune) {
        case 1: {
            string titlu, data;
            cout << "Titlu proiect: "; cin >> titlu;
            cout << "Deadline (zi/luna/an): "; cin >> data;

            if (proiectCurent != nullptr) delete proiectCurent;
            proiectCurent = new Proiect(titlu, data);
            cout << "Proiect creat cu succes!" << endl;
            break;
        }
        case 2: {
            if (!proiectCurent) { cout << "Creati intai un proiect!" << endl; break; }
            int tip;
            cout << "Tip membru (1-Manager, 2-Cercetator): "; cin >> tip;
            string n, p, e;
            cout << "Nume: "; cin >> n;
            cout << "Prenume: "; cin >> p;
            cout << "Email: "; cin >> e;

            Persoana* nouMembru = nullptr;
            if (tip == 1) {
                int ani; string dep;
                cout << "Ani experienta: "; cin >> ani;
                cout << "Departament: "; cin >> dep;
                nouMembru = new Manager(n, p, e, ani, dep);
            }
            else {
                string spec, grad;
                cout << "Specializare: "; cin >> spec;
                cout << "Grad (Junior/Senior): "; cin >> grad;
                nouMembru = new Cercetator(n, p, e, spec, grad);
            }
            proiectCurent->adaugaMembru(nouMembru);
            toatePersoanele.push_back(nouMembru);
            break;
        }
        case 3: {
            if (!proiectCurent) { cout << "Creati intai un proiect!" << endl; break; }
            int tip;
            cout << "Tip resursa (1-Echipament, 2-Consumabil): "; cin >> tip;
            string n; double v;
            cout << "Denumire: "; cin >> n;
            cout << "Valoare (RON): "; cin >> v;

            Resursa* nouaResursa = nullptr;
            if (tip == 1) {
                string serie, data;
                cout << "Serie Inventar: "; cin >> serie;
                cout << "Data Achizitie: "; cin >> data;
                nouaResursa = new Echipament(n, v, serie, data);
            }
            else {
                double cant; string um;
                cout << "Cantitate: "; cin >> cant;
                cout << "Unitate masura: "; cin >> um;
                nouaResursa = new Consumabil(n, v, cant, um);
            }
            proiectCurent->adaugaResursa(nouaResursa);
            toateResursele.push_back(nouaResursa);
            break;
        }
        case 4: {
            if (!proiectCurent) { cout << "Creati intai un proiect!" << endl; break; }
            string numeEtapa;
            cout << "Nume etapa: "; cin >> numeEtapa;
            proiectCurent->adaugaEtapa(numeEtapa);
            break;
        }
        case 5: {
            if (!proiectCurent) { cout << "Creati intai un proiect!" << endl; break; }
            proiectCurent->afisareProgres();
            int idx, proc;
            cout << "Introduceti numarul etapei de actualizat: "; cin >> idx;
            cout << "Nou procentaj (0-100): "; cin >> proc;
            proiectCurent->actualizeazaProgres(idx - 1, proc);
            break;
        }
        case 6: {
            if (!proiectCurent) { cout << "Creati intai un proiect!" << endl; break; }
            proiectCurent->afisareCompleta();
            break;
        }
        case 7: {
            incarcaDateDemonstrative();
            break;
        }
        case 0:
            cout << "La revedere!" << endl;
            break;
        default:
            cout << "Optiune invalida!" << endl;
        }

    } while (optiune != 0);
}