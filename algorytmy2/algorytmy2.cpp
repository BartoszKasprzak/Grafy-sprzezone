#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

//Funkcja do sprawdzenia czy jest sprzężony
int czysprzezony(vector<vector<int>> macierz, vector<int> vec, int i, int z)
{
	int x = 1;
	int y = 0;
	

	vector<int> vec1;
	for (int j = i + 1; j < z; j++)
	{
		int zliczenie = 0;
		//stworzenie vector dla kolejnego wierzcholka po i-tym
		for (int k = 0; k < z; k++)
		{
			if (macierz[j][k] == 1)
			{
				vec1.push_back(k);
			}
		}

		if (vec.size() != vec1.size())
		{
			if (vec.size() > vec1.size())
			{
				for (int l = 0; l < vec.size(); l++)
				{
					for (int m = 0; m < vec1.size(); m++)
					{
						if (vec[l] == vec1[m])
						{
							zliczenie++;
						}
					}
				}
				
				if (zliczenie > 0)
				{
					x = 0;
					vec1.clear();
					return x;
				}
				else
				{
					;
				}
			}
			else
			{
				for (int l = 0; l < vec1.size(); l++)
				{
					for (int m = 0; m < vec.size(); m++)
					{
						if (vec1[l] == vec[m])
						{
							zliczenie++;
						}
					}
				}
				
				if (zliczenie > 0)
				{
					x = 0;
					vec1.clear();
					return x;
				}
				else
				{
					;
				}
			}
		}
		else
		{
			for (int l = 0; l < vec1.size(); l++)
			{
				for (int m = 0; m < vec.size(); m++)
				{
					if (vec1[l] == vec[m])
					{
						zliczenie++;
					}
					else
					{
						;
					}
				}
			}
			
			if (zliczenie != 0 && zliczenie != vec.size())
			{
				x = 0;
				vec1.clear();
				return x;
			}
			else if(zliczenie > 0 && zliczenie != vec.size())
			{
				x = 0;
				vec1.clear();
				return x;
			}
			else
			{
				;
			}

		}
		vec1.clear();
	}
	return x;
}

//funkcja do sprawdzania czy liniowy
int czyliniowy(vector<vector<int>> macierz, int z)
{
	int liniowosc;
	for (int i = 0; i < z - 1; i++) 
	{
		for (int j = i + 1; j < z; j++)
		{
			
			for (int k = 0; k < z; k++)
			{
				
				if ((macierz[i][k] == macierz[j][k]) && macierz[i][k] == 1) 	
				{
					for (int p = 0; p < z; p++)
					{
						
						if (macierz[p][i] == 1 && macierz[p][j] == 1)
						{
							liniowosc = 0;
							return liniowosc;
						}
					} 					
				}
			}
		}
	}
	liniowosc = 1;
	return liniowosc;
}

int main()
{
	fstream plik;
	plik.open("Algorytm1.txt", std::ios::in);
	fstream plik1;
	plik1.open("Algorytm.txt", std::ios::out);
	fstream plikzapis;
	plikzapis.open("Algorytm1.txt", std::ios::in);
	fstream zliczenie;
	zliczenie.open("Algorytm1.txt", std::ios::in);

	if (plik.good() == true)
	{
//zczytanie ilosci wierzchołków
		int n = 0;
		char zmienna;
		string zliczenie1;
		int z = 0;
		while (!zliczenie.eof())
		{
			getline(zliczenie, zliczenie1, '\n');
			z++;
		}
		vector<int> mmacierz;
		char zapis = '0';
		int wartosc;
		
//TWORZENIE MACIERZY
		while (!plik.eof())
		{
			plik >> zmienna;
			wartosc = (int)zmienna - 48;
			mmacierz.push_back(wartosc);
		}
		mmacierz.erase(mmacierz.end() - 1);
		vector<vector<int>> macierz;
		int y = 0;

		for (int i = 0; i < z; i++)
		{
			vector<int> m;
			for (int j = 0; j < z; j++)
			{
				m.push_back(mmacierz[y]);
				y++;
			}
			macierz.push_back(m);
			m.clear();
		}
		
//SPRAWDZENIE CZY JEST 1GRAFEM
		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (macierz[i][j] > 1)
				{
					cout << "GRAF NIE JEST 1GRAFEM !!!!" << endl;
					cout << "GRAF NIE JEST GRAFEM SPRZEZONYM" << endl;
					return 0;
				}
				else
				{
					;
				}
			}
		}
		cout << "GRAF JEST 1GRAFEM" << endl;

//SPRAWDZENIE CZY JEST SPRZĘŻONY 
		int sprzez;
		
		int t = 0;
		for (int i = 0; i < z-1; i++)//z-1 poniewaz ostatni element zostanie juz sprawdzony z wszystkimi innymi 
		{
			vector<int> vecspr;
			for (int j = 0; j < z; j++)
			{
				if (macierz[i][j] == 1)
				{
					vecspr.push_back(j);
				}
			}
			sprzez = czysprzezony(macierz, vecspr, i, z);
			if (sprzez == 0)
			{
				cout << "GRAF NIE JEST SPRZEZONY" << endl;
				return 0;
			}
			else
			{
				;
			}
			vecspr.clear();
		}
		cout << "GRAF JEST SPRZEZONY" << endl;
		
//SPRAWDZENIE CZY JEST GRAFEM LINIOWYM
	
		int sprawdzliniowosc = czyliniowy(macierz, z);
		if (sprawdzliniowosc == 0)
		{
			cout << "GRAF NIE JEST LINIOWY" << endl;
		}
		else if (sprawdzliniowosc == 1)
		{
			cout << "GRAF JEST LINIOWY" << endl;
		}
		else
		{
			cout << "BLAD !!" << endl;
			return 0;
		}


//przeksztalcanie na graf pierwotny
		
		vector<vector<int>> krawedzie;
		int wierzcholek = 0;

		for (int i = 0; i < z; i++)
		{
			vector<int> dodanie;
			for (int j = 0; j < 2; j++)
			{
				dodanie.push_back(0);
				wierzcholek++;
			}
			krawedzie.push_back(dodanie);
			dodanie.clear();
		}
		
		int krawedz = 0;
		for (int i = 0; i < z; i++)
		{
			if (krawedzie[i][0] == 0)
			{
				krawedzie[i][0] = krawedz;
				krawedz++;
			}
			if (krawedzie[i][1] == 0)
			{
				krawedzie[i][1] = krawedz;
				krawedz++;
			}	
		}
		
		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (macierz[j][i] == 1)
				{
					krawedzie[j][1] = krawedzie[i][0];
				}
			}
		}

		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < z; j++)
			{
				if (macierz[i][j] == 1)
				{
					krawedzie[j][0] = krawedzie[i][1];
				}
			}
		}
	
		for (int i = 0; i < z; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cout << krawedzie[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

//przeindeksowanie
		vector<int> tylkowejscie;
		int tmp = 0;
		int tmp1 = 0; 

		for (int i = 0; i < z; i++)
		{
			tmp = 0; 
			tmp1 = krawedzie[i][1];
			for (int j = 0; j < z; j++)
			{
				if (tmp1 == krawedzie[j][0])
				{
					tmp++;
				}
			}
			if (tmp == 0)
			{
				tylkowejscie.push_back(krawedzie[i][1]);
			}
		}

		vector<vector<int>> graforyginalny;
		for (int i = 0; i < z; i++)
		{
			graforyginalny.push_back(krawedzie[i]);
		}
		for (int i = 0; i < tylkowejscie.size(); i++)
		{
			vector<int> pomocniczy;
			pomocniczy.push_back(tylkowejscie[i]);
			graforyginalny.push_back(pomocniczy);
		}
		sort(graforyginalny.begin(), graforyginalny.end());

		int ilosc = z + tylkowejscie.size();
		int id = 0;
		int wierzcholekwolny = 0;
		int pomocniczy = 0;

		for (int i = 0; i < ilosc - 1; i++)
		{
			pomocniczy = graforyginalny[i][0];
			graforyginalny[i][0] = id;

			for (int m = 0; m < ilosc; m++)
			{
				for (int n = 0; n < graforyginalny[m].size(); n++)
				{
					if (graforyginalny[m][n] == pomocniczy)
					{
						graforyginalny[m][n] = id;
					}
				}
			}
			id++;

			if (i + 1 == ilosc - 1)
			{
				if (graforyginalny[i][0] == graforyginalny[i + 1][0])
				{
					id--;
				}
				if (ilosc != z)
				{
					wierzcholekwolny = graforyginalny[i + 1][0];
					graforyginalny[i + 1][0] = id;
					
					for (int o = 0; o < ilosc; o++)
					{
						for (int p = 0; p < graforyginalny[o].size(); p++)
						{
							if (graforyginalny[o][p] == wierzcholekwolny)
							{
								graforyginalny[o][p] = id;
							}
						}
					}
				}
				else if ((ilosc == z) && graforyginalny[i+1][0] != graforyginalny[i][0])
				{
					for (int d = 0; d < z; d++)
					{
						if (graforyginalny[d][0] != graforyginalny[d][1])
						{
							wierzcholekwolny = graforyginalny[i + 1][0];
							graforyginalny[i + 1][0] = id;

							for (int o = 0; o < ilosc; o++)
							{
								for (int p = 0; p < graforyginalny[o].size(); p++)
								{
									if (graforyginalny[o][p] == wierzcholekwolny)
									{
										graforyginalny[o][p] = id;
									}
								}
							}
						}
						else
						{
							wierzcholekwolny = graforyginalny[i + 1][0];
							graforyginalny[i + 1][0] = id;

							for (int o = 0; o < ilosc; o++)
							{
								for (int p = 0; p < graforyginalny[o].size(); p++)
								{
									if (graforyginalny[o][p] == wierzcholekwolny)
									{
										graforyginalny[o][p] = id;
									}
								}
							}
						}
					}
				}
			}


			if (graforyginalny[i][0] == graforyginalny[i + 1][0])
			{
				id--;
			}
		}

		for (int i = 0; i < graforyginalny.size(); i++)
		{
			for (int j = 0; j < graforyginalny[i].size(); j++)
			{
				cout << graforyginalny[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

//przepisanie krawedzi na macierz
		vector<vector<int>> grafpierwotny;
		int zliczenie = 0;
		for (int i = 0; i < graforyginalny.size(); i++)
		{
			if (i == 0)
			{
				zliczenie++;
			}
			else if (graforyginalny[i][0] != graforyginalny[i - 1][0])
			{
				zliczenie++;
			}
		}
		
		for (int i = 0; i < zliczenie; i ++)
		{
			vector<int> wektor;
			for (int j = 0; j < zliczenie; j++)
			{
				wektor.push_back(0);
			}
			grafpierwotny.push_back(wektor);
		}

		for (int i = 0; i < zliczenie; i++)
		{
			for (int m = 0; m < graforyginalny.size(); m++)
			{
				if (graforyginalny[m].size() > 1)
				{
					for (int j = 0; j < zliczenie; j++)
					{
						if (graforyginalny[m][1] == j && graforyginalny[m][0] == i)
						{
							grafpierwotny[i][j]++;
						}
					}
				}

			}
		}

		for (int i = 0; i < zliczenie; i++)
		{
			for (int j = 0; j < zliczenie; j++)
			{
				cout << grafpierwotny[i][j];
			}
			cout << endl;
		}
		cout << endl;

// ZAPIS DO PLIKU 
		int enter = 0;
		if (plik1.good() == true)
		{
			for (int b = 0; b < zliczenie; b++)
			{
				for (int l = 0; l < zliczenie; l++)
				{
					plik1 << grafpierwotny[b][l];
					enter = l;
				}
				if (b != zliczenie - 1)
				{
					plik1 << endl;
				}
			}
		}
		else
		{
			cout << "plik zapisu nie zostal otworzony prawidlowo !! " << endl;
		}
		macierz.clear();
		mmacierz.clear();
		grafpierwotny.clear();
	}
	else
	{
		cout << "Plik nie został otworzony prawidłowo! ! !";
	}
	
}