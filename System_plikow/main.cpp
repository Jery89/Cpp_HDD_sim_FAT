#include<iostream>
#include<string>
#include"Drive.h"

using namespace std;

int main()
{
	int choice=0;
	Drive Moj_dysk;
	string nazwa;
	string data;

	do{

		

		cout << endl;
		cout << "PROGRAM SYMULUJACY DZAIALNIE SYSTEMU PLIKOW OPARTEGO NA TABLICY FAT" << endl;
		cout << endl;
		cout << "===================================================================" << endl;
		cout << endl;
		cout << "		DOKONAJ WYBORU Z LISTY" << endl;
		cout << endl;
		cout << "		1. AKTUALNA TABLICA FAT" << endl;
		cout << "		2. AKTUALNA ZAWARTOSC DYSKU" << endl;
		cout << "		3. ZAPIS PLIKU" << endl;
		cout << "		4. ODCZYT" << endl;
		cout << "		5. USUNIECIE PLIKU" << endl;

		cin >> choice;

		switch (choice)
		{

		case 1:

			Moj_dysk.Show_FAT();
			getchar();

		break;

		case 2:

			Moj_dysk.Show_Drive();
			getchar();

		break;

		case 3:
			cout << "Podaj nazwe pliku" << endl;

			
			cin >> nazwa;
			cout << "Podaj zawartosc pliku" << endl;
			
			cin >> data;
			Moj_dysk.Write(nazwa, data);
			getchar();

			break;

		case 5:
			cout << "Podaj nazwe usuwanego pliku" << endl;


			cin >> nazwa;
			Moj_dysk.Delete(nazwa);
			getchar();

			break;
		
			
		}







	} while (true);




	getchar();

}