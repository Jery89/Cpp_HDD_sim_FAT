#include<iostream>
#include<string>
#include<vector>
#include<array>

using namespace std;

class Sector
{
	friend class Drive;

private:

	array<char, 32>sec; // sektor posiada 32 komorki znakowe
	bool marker = false; // jelsi sektor jest pusty znak false, jelsi zajety true

	void Fill_sec(vector<char>vec1) // vec1 nie moze byc wiekszy niz 32
	{

		for (int i = 0; i < vec1.size(); i++)
		{
			sec[i] = vec1[i];

		}

		

	}




};