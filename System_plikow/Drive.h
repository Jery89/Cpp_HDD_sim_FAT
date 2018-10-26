#include<iostream>
#include<string>
#include"Sector.h"
#include<vector>
#include"FAT.h"

using namespace std;

class Drive
{
private:

	Sector dysk[32]; // dysk twardy z 32 sektorami po 32 miejsca znakowe
	FAT FAT_tab; // tablica alokacji dla dysku
	
public:

	int SpaceCheck()
	{
		int g = 0;
		for (int i=0; i < 32; i++)
		{

			if (FAT_tab.empty_sectors()[i] == 0);
			g++;
		}

		return g;
	}

	void Write(string name, string data)
	{


		//DANE WYMIAROW PLIKU

		int needed_sector=0;
		
		int full_sector_needed=data.length()/32;
		int rest = data.length() % 32;



		// SPRAWDZENIE MIEJSCA

		if (rest > 0)
		{
			needed_sector = full_sector_needed + 1;
		}
		else
			needed_sector = full_sector_needed;

		if (needed_sector > SpaceCheck())
		{
			cout << "BRAK MIEJSCA NA DYSKU !!!" << endl;
			
		}

		else
		{

			int temp_index = 0; // indeks odczytanego pliku
			vector<int>temp_alloc_vec;
			int x = 0;
			for (int a = 0; a < needed_sector; a++) // zapisywania w zale¿nosci od wymaganej liczby sektorów
			{
				 	

						vector<char>temp_vec; // vector tymczasowy(pomocniczy do kopiowania)
						int liczba_iteracji = data.length() - temp_index;

						for (int g = 0; g < liczba_iteracji && g<32; g++) //przygotowanie vectora tymczasowego
						{

							temp_vec.push_back(data[temp_index]);
							temp_index++;

						}
						
						
						for (int i=0; i < 32; i++)
						{
							if (FAT_tab.empty_sectors()[i] == 0)
							{
								x = i;
								break;
							}

						}
															 // wyci¹gniecie indeksu wolnego sektora z FAT 
															//!!!!!UWAGA TABLICA ZMIENI SIE NA BIEZACO NIE TRZEBA DAWAC INDEKSU a - 1 ELEMENT TABLICY BEDZIE 1 WOOLNYM

						dysk[x].Fill_sec(temp_vec); // zapis do sektora wczesniej przygotowabego wektora

						FAT_tab.marker_set(x, 1); //ustawienie markera na "zajety" dla FAT
						FAT_tab.name_set(x, name); //ustawienie nazwy dla komorki w FAT
						FAT_tab.size_set(x, data.length()); //nadanie rozmiaru
						temp_alloc_vec.push_back(x); // ulokowanie wykorzystanych sektorow w wektorze alokacji

										

				

			}
			for (auto i : temp_alloc_vec)
			{
				FAT_tab.alloc_set(i, temp_alloc_vec);
			}

					//ELLSE PRZEJSC DALEJ

			}

			}

	void Delete(string name)
	{
	
		for (int i = 0; i < FAT_tab.file_serching(name).size(); i++)
		{

			cout << FAT_tab.file_serching(name)[i] << endl;

			FAT_tab.name_set(FAT_tab.file_serching(name)[i], "none");
			FAT_tab.marker_set(i,0);
		}
	}

	string Open(string name)
	{

		vector<int>temp_vec1 = FAT_tab.file_serching(name);
		string bufor;

		


	}

	void Show_FAT()
	{

		cout << "LP: NAZWA:		ROZMIAR:" << endl;

		for (int z=0;z<32;z++)
		{

			cout << z <<"   " << FAT_tab.name_out(z) << endl;
		}


	}

	void Show_Drive()
	{

		cout << "zawartosc dysku" << endl;
		cout << " " << endl;

		for (int z = 0; z < 32; z++)
		{

			for (int i = 0; i < 32; i++)
			{

				cout << dysk[z].sec[i];

			}
			cout << endl;
		}

		cout << endl;
	}
};





	



