#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define NR_PROBE 3

struct Student {
    /*
    * int cod
    * char* numele studentului
    * int grupa
    * string disciplina
    * double punctaje[14] seminar/curs (14 saptamani)
    */

    int cod;
    char* nume;
    int grupa;
    std::string disciplina;
    double punctaje[NR_PROBE];

};

/*
* adaugare punctaj activitate
* initializare student cu valori implicite (fara parametri)
* initializare student prin parametri
* initializare student cu citire de la tastatura
* afisare situatie student
*/

void afiseaza_student(Student s) {
    std::cout << "cod: " << s.cod << std::endl;
    std::cout << "nume: " << s.nume << std::endl;
    std::cout << "grupa: " << s.grupa << std::endl;
    std::cout << "disciplina: " << s.disciplina << std::endl;
    std::cout << "punctaje: " << std::endl;
    for (int i = 0; i < NR_PROBE; i++) {
        std::cout << "\t" << i + 1 << "." << s.punctaje[i] << std::endl;
    }
}

Student citeste_student() {
    Student s;
    std::cout << "Introdu datele studentului" << std::endl;

    std::cout << "cod: ";
    std::cin >> s.cod;

    std::cout << "nume: ";
    char nume[30];
    std::cin >> nume;
    //alocam memorie
    s.nume = new char[strlen(nume) + 1];
    strcpy(s.nume, nume);


    std::cout << "grupa: ";
    std::cin >> s.grupa;

    std::cout << "disciplina: ";
    std::cin >> s.disciplina;

    std::cout << "punctaje: " << std::endl;
    for (int i = 0; i < NR_PROBE; i++) {
        std::cout << "\t" << i + 1 << ".";
        std::cin >> s.punctaje[i];
    }
    return s;
}

Student init_student(int cod, const char* nume, int grupa, std::string disciplina, double punctaje[NR_PROBE]) {
    Student s;
    s.cod = cod;
    s.nume = new char[strlen(nume) + 1];
    strcpy(s.nume, nume);
    s.grupa = grupa;
    s.disciplina = disciplina;

    for (int i = 0; i < NR_PROBE; i++) {
        s.punctaje[i] = punctaje[i];
    }

    return s;
}

int main()
{
    Student s = { 0 };
    delete s.nume;
    //s = citeste_student();
    double punctaje[] = { 1,1,0 };
    s = init_student(100, "Teodor Petrica", 1079, "POO", punctaje);
    afiseaza_student(s);
    //adauga_punctaj(s, 2, 0.5);

}
