#include<iostream>
#include<map>
#include<vector>
#include<array>
#include"Fat_cell.h"

using namespace std;

class FAT
{
	friend class Drive;

private:

	array<Cell,32> FAT_TABLE;

//METODY OBS£UGI FAT


	// WEKTOR WOLNYCH SEKTOROW 
	array<int,32>empty_sectors()
	{
		array<int, 32>temp_array = { 0 };

		for (int i = 0; i < 32; i++)
		{
			if (FAT_TABLE[i].sector_marker == 0)
			{
				temp_array[i] = 0;

			}
			else
				temp_array[i] = 1;

		}

		return temp_array;
	}

	// WEKTOR SZUKANEGO PLIKU 
	vector<int>file_serching(string nazwa)
	{
		vector<int>temp_vec1;
		for (auto i : FAT_TABLE)
		{
			if (i.name == nazwa)
			{

				return i.allocation_vector;

			}

		}


	}

	// ZMIANA MARKERA W KOMORCE
	void marker_set(int a, bool d)
	{

		FAT_TABLE[a].sector_marker = d;

	}

	// NADANIE NAZWY DLA SEKTORA
	void name_set(int a, string name)
	{
		FAT_TABLE[a].name = name;

	}

	//NADANIE WEKTORA ALOKACJI DLA KOMORKI
	void alloc_set(int a,vector<int>vec1)
	{
		FAT_TABLE[a].allocation_vector=vec1;

	}

	// NADANIE ROZMIARU
	void size_set(int a, int b)
	{
		FAT_TABLE[a].size = b;

	}

	// ROZMIAR OUT
	int size_out(int a)
	{
		return FAT_TABLE[a].size;

	}

	// NAZWA OUT
	string name_out (int a)
	{
		return FAT_TABLE[a].name;

	}
};