#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

#define NR_CAMERE 5

class Hotel {
	char* nume;
	char* adresa;
	int numar_stele;
	int camere_ocupate;
	double pret_camere[NR_CAMERE];
	bool deschis;

public:
	Hotel(const char* nume, const char* adresa, int numar_stele, int camere_ocupate, double pret_camere[NR_CAMERE], bool deschis) {
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
		this->numar_stele = numar_stele;
		this->camere_ocupate = camere_ocupate;
		for (int i = 0; i < NR_CAMERE; i++) {
			this->pret_camere[i] = pret_camere[i];
		}
		this->deschis = deschis;
	}

	Hotel() {
		this->nume = new char[strlen("Default") + 1];
		strcpy(this->nume, "Default");
		this->adresa = new char[strlen("str. X nr YY") + 1];
		strcpy(this->adresa, "str. X nr YY");
		this->numar_stele = 0;
		this->camere_ocupate = 0;
		for (int i = 0; i < NR_CAMERE; i++) {
			this->pret_camere[i] = 0;
		}
		this->deschis = false;
	}

	Hotel(Hotel& h) {
		delete[] nume;
		nume = new char[strlen(h.nume) + 1];
		strcpy(nume, h.nume);
		delete[] adresa;
		adresa = new char[strlen(h.adresa) + 1];
		strcpy(adresa, h.adresa);
		numar_stele = h.numar_stele;
		camere_ocupate = h.camere_ocupate;
		deschis = h.deschis;
		for (int i = 0; i < NR_CAMERE; i++) {
			pret_camere[i] = h.pret_camere[i];
		}
	}

	void deschide_hotel() {
		deschis = true;
		std::cout << "-- Hotelul a fost deschis.";
	}

	void inchide_hotel() {
		deschis = false;
		std::cout << "-- Hotelul a fost inchis.";
	}

	void citire_hotel() {
		std::cout << "Introdu date despre hotel: \n";
		std::cout << "- nume: ";
		delete[] nume;
		char nume[20];
		//std::cin >> nume;
		std::cin.getline(nume, 20);
		this->nume = new char[strlen(nume) + 1];
		strcpy(this->nume, nume);

		std::cout << "- adresa: ";
		delete[] adresa;
		char adresa[50];
		//std::cin >> adresa;
		std::cin.getline(adresa, 50);
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);

		std::cout << "- numar stele: ";
		std::cin >> numar_stele;

		std::cout << "- camere ocupate: ";
		std::cin >> camere_ocupate;

		std::cout << "- preturi per camera: \n";
		for (int i = 0; i < NR_CAMERE; i++) {
			std::cout << "\t--- " << i + 1 << ": ";
			std::cin >> pret_camere[i];
		}

		std::cout << "- deschis?: ";
		std::cin >> deschis;
	}

	void afiseaza_hotel() {
		std::cout << "Nume: " << nume << std::endl;
		std::cout << "Adresa: " << adresa << std::endl;
		std::cout << "Nr stele: " << numar_stele << std::endl;
		std::cout << "Camere ocupate: " << camere_ocupate << std::endl;
		std::cout << "Preturi camere: " << std::endl;
		for (int i = 0; i < NR_CAMERE; i++) {
			std::cout << "\t--- " << i + 1 << ": " << pret_camere[i] << std::endl;
		}
		std::cout << "Status deschis: " << (deschis ? "Da" : "Nu") << std::endl;
	}

	Hotel* duplica_hotel(const Hotel& h) {
		delete[] nume;
		nume = new char[strlen(h.nume) + 1];
		strcpy(nume, h.nume);
		delete[] adresa;
		adresa = new char[strlen(h.adresa) + 1];
		strcpy(adresa, h.adresa);
		numar_stele = h.numar_stele;
		camere_ocupate = h.camere_ocupate;
		deschis = h.deschis;
		for (int i = 0; i < NR_CAMERE; i++) {
			pret_camere[i] = h.pret_camere[i];
		}
		return this;
	}

	void copiaza_hotel(const Hotel& h) {
		delete[] nume;
		nume = new char[strlen(h.nume) + 1];
		strcpy(nume, h.nume);

		delete[] adresa;
		adresa = new char[strlen(h.adresa) + 1];
		strcpy(adresa, h.adresa);

		numar_stele = h.numar_stele;
		camere_ocupate = h.camere_ocupate;
		deschis = h.deschis;
		for (int i = 0; i < NR_CAMERE; i++) {
			pret_camere[i] = h.pret_camere[i];
		}
	}

	void set_pret_camera(int numar_camera, double pret) {
		if (numar_camera >= 1 && numar_camera <= NR_CAMERE) {
			pret_camere[numar_camera - 1] = pret;
		}
	}

	double calculeaza_pret_mediu() {
		double suma = 0;
		for (int i = 0; i < NR_CAMERE; i++) {
			suma += pret_camere[i];
		}
		return suma / NR_CAMERE;
	}

	double grad_ocupare() {
		return 100.0 * camere_ocupate / NR_CAMERE;
	}

	void citire_pret_camere() {
		std::cout << "Introdu valori pentru noile preturi: \n";
		for (int i = 0; i < NR_CAMERE; i++) {
			std::cout << "\t--- " << i + 1 << ".";
			std::cin >> pret_camere[i];
		}
	}

	int get_numar_camere_ocupate() {
		return camere_ocupate;
	}

	void afisare_numar_camere_ocupate() {
		std::cout << "Numar camere ocupate in " << nume << ": " << get_numar_camere_ocupate() << std::endl;
	}

	void set_numar_camere_ocupate() {
		std::cout << "Introdu numarul nou de camere ocupate in " << nume << ": ";
		int numar;
		std::cin >> numar;
		this->camere_ocupate = numar;
	}

	~Hotel() {
		delete[] nume;
		delete[] adresa;
	}
};

int main() {
	double preturi[] = { 250.5, 310.0, 399.9, 1700.0, 1250.7 };

	Hotel h1("Corinthia", "bd. Regina Elisabeta 21", 5, 2, preturi, true);
	//h1.afiseaza_hotel();
	h1.afisare_numar_camere_ocupate();
	h1.set_numar_camere_ocupate();
	h1.afisare_numar_camere_ocupate();

	Hotel h0(h1);
	h0.afiseaza_hotel();

	std::cout << "\n\n\n";

	Hotel h2;
	h2.afiseaza_hotel();
	
	Hotel h3;
	Hotel* p = h3.duplica_hotel(h1);
	h3.afiseaza_hotel();
	p->afiseaza_hotel();
	
	double preturi_capitol[] = { 505, 600, 690, 990, 1200 };
	
	Hotel h4("Capitol", "Calea Victoriei 29", 5, 5, preturi_capitol, true);
	h4.afiseaza_hotel();
	h4.inchide_hotel();
	h4.afiseaza_hotel();
	
	Hotel h5;
	h5.copiaza_hotel(h4);
	h5.afiseaza_hotel();
	std::cout << "Gradul de ocupare al hotelului: " << h5.grad_ocupare() << "%\n";
	
	Hotel h6;
	h6.citire_hotel();
	h6.afiseaza_hotel();
	
	Hotel h7;
	h7.copiaza_hotel(h6);
	std::cout << "Pret mediu: " << h7.calculeaza_pret_mediu() << std::endl;
	h7.citire_pret_camere();
	std::cout << "Pret mediu: " << h7.calculeaza_pret_mediu() << std::endl;
	h7.set_pret_camera(3, 2000);
	std::cout << "Pret mediu: " << h7.calculeaza_pret_mediu() << std::endl;
	
	_CrtDumpMemoryLeaks();
	return 0;
}