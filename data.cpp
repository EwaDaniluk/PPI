#include<iostream>
#include <string>
#include <cstdlib>

using namespace std;

int pobierzPoprawnaIloscWypadkow() {
	bool czy_liczba;
	string liczba;
	do
	{
		czy_liczba = true;
		cin >> liczba;
		for (int i = 0; i < liczba.length(); i++)
		{
			if (!isdigit(liczba[i]))
				czy_liczba = false;
		}
		if (!czy_liczba)
			cout << "Nie podano liczby naturalnej. Popraw dane ;)" << endl;
	} while (!czy_liczba);

	int naturalna = stoi(liczba);
	//int naturalna = atoi(liczba.c_str());
	return naturalna;
}

void aktualizujKlaseSzkodWarta(int &aktualnaKlasa, int iloscSzkod) {
	if (iloscSzkod == 0) {
		if (aktualnaKlasa == 13)
			aktualnaKlasa--;
		aktualnaKlasa++;
	}
	else if (iloscSzkod == 1) {
		if (aktualnaKlasa == 1 || aktualnaKlasa == 2)
			aktualnaKlasa = 1;
		else if (aktualnaKlasa >= 3 && aktualnaKlasa <= 9)
			aktualnaKlasa = aktualnaKlasa - 2;
		else if (aktualnaKlasa == 10 || aktualnaKlasa == 11) {
			aktualnaKlasa = aktualnaKlasa - 3;
		}
		else if (aktualnaKlasa == 12 || aktualnaKlasa == 13) {
			aktualnaKlasa = aktualnaKlasa - 4;
		}
	}
	else if (iloscSzkod == 2) {
		if (aktualnaKlasa >= 1 && aktualnaKlasa <= 4)
			aktualnaKlasa = 1;
		else if (aktualnaKlasa >= 5 && aktualnaKlasa <= 6)
			aktualnaKlasa = 2;
		else if (aktualnaKlasa >= 7 && aktualnaKlasa <= 12)
			aktualnaKlasa = 3;
		else if (aktualnaKlasa == 13)
			aktualnaKlasa = 4;
	}
	else {
		aktualnaKlasa = 1;
	}
}

void obliczProcentSkladkiBazowejWarta(int klasa, int& procentSkladkiBazowej) {
	if (klasa == 1)
		procentSkladkiBazowej = 200;
	else if (klasa == 2)
		procentSkladkiBazowej = 150;
	else if (klasa == 3)
		procentSkladkiBazowej = 125;
	else if (klasa == 4)
		procentSkladkiBazowej = 100;
	else if (klasa == 5)
		procentSkladkiBazowej = 90;
	else if (klasa == 6)
		procentSkladkiBazowej = 80;
	else if (klasa == 7)
		procentSkladkiBazowej = 70;
	else if (klasa == 8)
		procentSkladkiBazowej = 60;
	else if (klasa == 9 || klasa == 10)
		procentSkladkiBazowej = 50;
	else if (klasa >= 11 && klasa <= 13)
		procentSkladkiBazowej = 40;
}

void aktualizujKlaseSzkodPzu(int& aktualnaKlasa, int iloscSzkod) {
	if (iloscSzkod == 0) {
		if (aktualnaKlasa == 13)
			aktualnaKlasa--;
		aktualnaKlasa++;
	}
	else if (iloscSzkod == 1) {
		if (aktualnaKlasa == 1 || aktualnaKlasa == 2)
			aktualnaKlasa = 1;
		else if (aktualnaKlasa >= 3 && aktualnaKlasa <= 13)
			aktualnaKlasa = aktualnaKlasa - 2;
	}
	else if (iloscSzkod == 2) {
		if (aktualnaKlasa >= 1 && aktualnaKlasa <= 4)
			aktualnaKlasa = 1;
		else if (aktualnaKlasa >= 5 && aktualnaKlasa <= 13)
			aktualnaKlasa = aktualnaKlasa - 4;
	}
	else if (iloscSzkod == 3) {
		if (aktualnaKlasa >= 1 && aktualnaKlasa <= 6)
			aktualnaKlasa = 1;
		else if (aktualnaKlasa >= 7 && aktualnaKlasa <= 13)
			aktualnaKlasa = aktualnaKlasa - 6;
	}
	else if (iloscSzkod == 4) {
		if (aktualnaKlasa >= 1 && aktualnaKlasa <= 8)
			aktualnaKlasa = 1;
		else if (aktualnaKlasa >= 9 && aktualnaKlasa <= 13)
			aktualnaKlasa = aktualnaKlasa - 8;
	}
	else if (iloscSzkod == 5) {
		if (aktualnaKlasa >= 1 && aktualnaKlasa <= 10)
			aktualnaKlasa = 1;
		else if (aktualnaKlasa >= 11 && aktualnaKlasa <= 13)
			aktualnaKlasa = aktualnaKlasa - 10;
	}
	else {
		aktualnaKlasa = 1;
	}
}

void obliczProcentSkladkiBazowejPzu(int klasa, int& procentSkladkiBazowej) {
	if (klasa == 1)
		procentSkladkiBazowej = 200;
	else if (klasa == 2)
		procentSkladkiBazowej = 150;
	else if (klasa == 3)
		procentSkladkiBazowej = 130;
	else if (klasa == 4)
		procentSkladkiBazowej = 115;
	else if (klasa == 5)
		procentSkladkiBazowej = 100;
	else if (klasa == 6)
		procentSkladkiBazowej = 90;
	else if (klasa == 7 || klasa == 8)
		procentSkladkiBazowej = 80;
	else if (klasa == 9)
		procentSkladkiBazowej = 70;
	else if (klasa == 10)
		procentSkladkiBazowej = 60;
	else if (klasa == 11 || klasa == 12)
		procentSkladkiBazowej = 50;
	else if (klasa == 13)
		procentSkladkiBazowej = 40;
}

int main() {
	cout << endl << "Witaj w wyszukiwarce najkorzystniejszego dla ciebie ubezpieczenia OC" << endl << endl;
	cout << "Program opiera sie na wyliczaniu wysokosci skladki na podstawie systemu bonus-malus" << endl << endl;
	cout << "Nacisnij klawisz \"k\" i \"Enter\" aby  kontynuowac" << endl;
	char pom;
	cin >> pom;
	if (pom == 'k') {
		system("cls");
	}
	cout << endl << "Uzupelnij informacje na temat historii twoich zdarzen drogowych z oststnich 10 lat: " << endl <<
		"(przy kazdej liczbie oznaczajacej rok wstecz wpisz ilosc spowodowanych przez ciebie szkod" << endl
		<< "za ktore zostalo wyplacone odszkodowanie)" << endl;
	int rok_1 = 0;
	int rok_2 = 0;
	int rok_3 = 0;
	int rok_4 = 0;
	int rok_5 = 0;
	int rok_6 = 0;
	int rok_7 = 0;
	int rok_8 = 0;
	int rok_9 = 0;
	int rok_10 = 0;

	cout << endl << "1 rok temu:  ";
	rok_1 = pobierzPoprawnaIloscWypadkow();
	cout << endl << "2 lata temu: ";
	rok_2 = pobierzPoprawnaIloscWypadkow();
	cout << endl << "3 lata temu: ";
	rok_3 = pobierzPoprawnaIloscWypadkow();
	cout << endl << "4 lata temu: ";
	rok_4 = pobierzPoprawnaIloscWypadkow();
	cout << endl << "5 lat temu:  ";
	rok_5 = pobierzPoprawnaIloscWypadkow();
	cout << endl << "6 lat temu:  ";
	rok_6 = pobierzPoprawnaIloscWypadkow();
	cout << endl << "7 lat temu:  ";
	rok_7 = pobierzPoprawnaIloscWypadkow();
	cout << endl << "8 lat temu:  ";
	rok_8 = pobierzPoprawnaIloscWypadkow();
	cout << endl << "9 lat temu:  ";
	rok_9 = pobierzPoprawnaIloscWypadkow();
	cout << endl << "10 lat temu: ";
	rok_10 = pobierzPoprawnaIloscWypadkow();
	system("cls");

	cout << endl << endl << "Wpisales nastepujace dane:" << endl;
	cout << " 1 rok temu:  " << rok_1 << endl;
	cout << " 2 lata temu: " << rok_2 << endl;
	cout << " 3 lata temu: " << rok_3 << endl;
	cout << " 4 lata temu: " << rok_4 << endl;
	cout << " 5 lat temu:  " << rok_5 << endl;
	cout << " 6 lat temu:  " << rok_6 << endl;
	cout << " 7 lat temu:  " << rok_7 << endl;
	cout << " 8 lat temu:  " << rok_8 << endl;
	cout << " 9 lat temu:  " << rok_9 << endl;
	cout << " 10 lat temu: " << rok_10 << endl;

	cout << endl << endl << "Nacisnij klawisz \"k\" i \"Enter\" aby  zobaczyc liste dostepnyh dla ciebie ofert!" << endl;
	cin >> pom;
	if (pom == 'k') {
		system("cls");
	}

	int skladka_bazowa_warta = 200;
	int klasa_warta = 4; // domyœlnie ustawione na klase neutraln¹ ze sk³adk¹ równ¹ 100% sk³adki bazowej
	aktualizujKlaseSzkodWarta(klasa_warta, rok_1);
	aktualizujKlaseSzkodWarta(klasa_warta, rok_2);
	aktualizujKlaseSzkodWarta(klasa_warta, rok_3);
	aktualizujKlaseSzkodWarta(klasa_warta, rok_4);
	aktualizujKlaseSzkodWarta(klasa_warta, rok_5);
	aktualizujKlaseSzkodWarta(klasa_warta, rok_6);
	aktualizujKlaseSzkodWarta(klasa_warta, rok_7);
	aktualizujKlaseSzkodWarta(klasa_warta, rok_8);
	aktualizujKlaseSzkodWarta(klasa_warta, rok_9);
	aktualizujKlaseSzkodWarta(klasa_warta, rok_10);
	int procent_skladki_bazowej_warta = 100;
	obliczProcentSkladkiBazowejWarta(klasa_warta, procent_skladki_bazowej_warta);

	int skladka_bazowa_pzu = 200;
	int klasa_pzu = 5; // domyœlnie ustawione na klase neutraln¹ ze sk³adk¹ równ¹ 100% sk³adki bazowej
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_1);
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_2);
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_3);
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_4);
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_5);
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_6);
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_7);
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_8);
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_9);
	aktualizujKlaseSzkodPzu(klasa_pzu, rok_10);
	int procent_skladki_bazowej_pzu = 100;
	obliczProcentSkladkiBazowejPzu(klasa_pzu, procent_skladki_bazowej_pzu);

	cout << endl << endl << "Najlepsze oferty:  " << endl;
	cout << "      Firma:    " << "wysokosc raty" << endl;
	if (((skladka_bazowa_warta * procent_skladki_bazowej_warta) / 100) < ((skladka_bazowa_pzu * procent_skladki_bazowej_pzu) / 100)) {
		cout << "      1. Warta:    " << (skladka_bazowa_warta * procent_skladki_bazowej_warta) / 100 << " zl" << endl;
		cout << "      2. PZU:      " << (skladka_bazowa_pzu * procent_skladki_bazowej_pzu) / 100 << " zl" << endl << endl << endl;
	}
	else {
		cout << "      1. PZU:      " << (skladka_bazowa_pzu * procent_skladki_bazowej_pzu) / 100 << " zl" << endl;
		cout << "      2. Warta:    " << (skladka_bazowa_warta * procent_skladki_bazowej_warta) / 100 << " zl" << endl << endl << endl;
	}
	system("pause");
	return 0;
}
