#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

class Restaurant {
    const int CUI;
    std::string denumire;
    double nota;
    char* telefon;
    static int TVA;
public:

    Restaurant():CUI(0) {
        denumire = "fara denumire";
        nota = 0.0;
        telefon = new char[strlen("0700000000") + 1];
        strcpy(this->telefon, telefon);
    }

    Restaurant(int CUI, std::string denumire, double nota, const char* telefon):CUI(CUI) {
        this->denumire = denumire;
        this->nota = nota;
        this->telefon = new char[strlen(telefon) + 1];
        strcpy(this->telefon, telefon);
    }

    Restaurant(const Restaurant& r) :CUI(r.CUI) {
        this->denumire = r.denumire;
        this->nota = r.nota;
        this->telefon = new char[strlen(r.telefon) + 1];
        strcpy(this->telefon, r.telefon);
    }

    int getCUI() {
        return CUI;
    }

    std::string getDenumire() {
        return denumire;
    }//Restaurant has an object string type called denumire

    void setDenumire(std::string denumire) {
        this->denumire = denumire;
    }

    double getNota() {
        return nota;
    }

    void setNota(double nota) {
        this->nota = nota;
    }

    char* getTelefon() {
        return telefon;
    }
    //shallow copy vs deep copy
    void setTelefon(char* telefon) {
        delete[]this->telefon;
        this->telefon = new char[strlen(telefon) + 1];
        strcpy(this->telefon, telefon);
    }

    int getTVA() {
        return TVA;
    }

    void setTVA(int TVA) {
        this->TVA = TVA;
    }

    ~Restaurant() {
        delete[] telefon;
    }

};

int Restaurant::TVA = 19;


int main()
{
    {
        std::cout << "Hello World!\n";
        Restaurant r1;
        Restaurant r2(12345, "Doi Cocosi", 87.9, "0712123456");
    }
    _CrtDumpMemoryLeaks();
    return 0;
}