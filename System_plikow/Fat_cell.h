#include<iostream>
#include<string>
#include<vector>
#include<array>

using namespace std;


class Cell
{

	friend class FAT;
	friend class DRIVE;

	
private:
	
	string name="none"; // nazwa pliku
	vector<int>allocation_vector; //wektor allokacji - zawiera numery sektorów
	bool sector_marker = 0; // czy sektor jest zajety
	int size; // rozmiar pliku







};