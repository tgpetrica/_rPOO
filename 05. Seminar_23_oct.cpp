#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define NR_SAPT 3

class Student {
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
    double punctaje[NR_SAPT];

public:

    /*
    * adaugare punctaj activitate
    * initializare student cu valori implicite (fara parametri)
    * initializare student prin parametri
    * initializare student cu citire de la tastatura
    * afisare situatie student
    */

    void afiseaza_student() {
        std::cout << "cod: " << cod << std::endl;
        std::cout << "nume: " << nume << std::endl;
        std::cout << "grupa: " << grupa << std::endl;
        std::cout << "disciplina: " << disciplina << std::endl;
        std::cout << "punctaje: " << std::endl;
        for (int i = 0; i < NR_SAPT; i++) {
            std::cout << "\t" << i + 1 << "." << punctaje[i] << std::endl;
        }
    }

    void citeste_student() {// primeste obiectul curent prin pointerul this ca parametru
        std::cout << "Introdu datele studentului" << std::endl;

        std::cout << "cod: ";
        std::cin >> cod;

        std::cout << "nume: ";
        char nume[30];
        std::cin >> nume;
        //alocam memorie
        this->nume = new char[strlen(nume) + 1]; // pointer la clasa , refera obiectul curent
        strcpy(this->nume, nume);


        std::cout << "grupa: ";
        std::cin >> grupa;

        std::cout << "disciplina: ";
        std::cin >> disciplina;

        std::cout << "punctaje: " << std::endl;
        for (int i = 0; i < NR_SAPT; i++) {
            std::cout << "\t" << i + 1 << ".";
            std::cin >> punctaje[i];
        }
    }

    Student (int cod, const char* nume, int grupa, std::string disciplina, double punctaje[NR_SAPT]) {
        this->cod = cod;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->grupa = grupa;
        this->disciplina = disciplina;

        for (int i = 0; i < NR_SAPT; i++) {
            this->punctaje[i] = punctaje[i];
        }
    }

    Student() {
        this->cod = 0;
        this->nume = new char[strlen("NumeDefault") + 1];
        strcpy(this->nume, "NumeDefault");
        this->grupa = 1000;
        this->disciplina = "AAA";
        for (int i = 0; i < NR_SAPT; i++) {
            this->punctaje[i] = 0;
        }
    }
   
    void seteaza_punctaj(Student& s, int numar_seminar, double punctaj) {
        punctaje[numar_seminar - 1] = punctaj;
    }

    void afiseaza_situatie(Student s) {
        std::cout << "Studentul " << s.nume << " a obtinut urmatoarele punctaje: \n";
        for (int i = 0; i < NR_SAPT; i++) {
            std::cout << "\t" << i + 1 << ". " << s.punctaje[i] << "\n";
        }
    }

    Student copiaza_student(Student s) {
        Student c;
        c.cod = s.cod;
        c.nume = new char[strlen(s.nume) + 1];
        strcpy(c.nume, s.nume);
        c.grupa = s.grupa;
        c.disciplina = s.disciplina;
        for (int i = 0; i < NR_SAPT; i++) {
            c.punctaje[i] = s.punctaje[i];
        }

        return c;
    }

    ~Student() {
        delete[] nume;
    }
};


int main()
{
    {
    //Student s = { 0 };
    //delete s.nume;
    //s = citeste_student();
    double punctaje[] = { 1,1,0 };
    Student s (100, "Teodor Petrica", 1079, "POO", punctaje);
    s.afiseaza_student();

    Student u;
    //u.citeste_student();
    u.afiseaza_student();
    }
    _CrtDumpMemoryLeaks();

    //Student t = t.init_student_implicit();
    //t.afiseaza_student(t);

    //t. seteaza_punctaj(t, 1, 2);

    //t.afiseaza_student();

    //t.seteaza_punctaj(t, 2, 3.2);
    //t.seteaza_punctaj(t, 3, 4.3);
    //t.afiseaza_student();
    //t.afiseaza_situatie();
    //
    //Student c = c.copiaza_student(t);
    //c.afiseaza_student();
    //adauga_punctaj(s, 2, 0.5);

}
