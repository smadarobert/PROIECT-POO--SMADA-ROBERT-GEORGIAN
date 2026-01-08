# Aplicație pentru Gestionarea Proiectelor de Cercetare

Această aplicație C++ permite gestionarea completă a unui proiect de cercetare, incluzând alocarea resurselor umane și fizice, precum și monitorizarea progresului.

## Funcționalități Implementate

### 1. Gestionare Proiect
- [x] Creare proiect cu validare date.
- [x] Ștergere și curățare memorie la închiderea aplicației.

### 2. Echipa (OOP: Moștenire & Polimorfism)
- [x] Clasă abstractă `Persoana`.
- [x] Clase derivate: `Cercetator` (cu grad și specializare) și `Manager` (cu experiență).
- [x] Adăugare dinamică a membrilor în echipă.

### 3. Resurse (OOP: Abstractizare)
- [x] Clasă abstractă `Resursa`.
- [x] `Echipament` (gestiune pe bază de serie inventar).
- [x] `Consumabil` (gestiune stoc și unități de măsură).

### 4. Monitorizare (Logică Business)
- [x] Adăugare etape personalizate.
- [x] Actualizare progres per etapă.
- [x] Calcul automat progres total (media ponderată a etapelor).

### 5. Utilitare
- [x] Meniu interactiv (Switch-Case).
- [x] **Încărcare Date Demo**: Funcție rapidă pentru popularea aplicației cu date de test pentru prezentare.
- [x] Management corect al memoriei (Destructori virtuali).

## Cum se rulează
Proiectul este creat în Visual Studio. Se deschide fișierul `.sln` și se rulează cu `Local Windows Debugger`.
