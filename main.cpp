#include "Sozluk.h"
#include "Kayit.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	Sozluk c;
	vector <string> aciklama1 = {"bir yerden bir yere gitmemize yardimci olan sey"};
	Kayit k1("tasit", aciklama1);
	vector<string> aciklama2 = {"eski tur binek"};
	Kayit k2("at", aciklama2);

	Sozluk c1(k1), c2(k2);

	vector<Kayit> v;
	v.push_back(k1);
	v.push_back(k2);
	Sozluk aley(v);
	Sozluk alp(v);

	cout << "iki kaydin toplamý: " << c1 + c2;
	
	if (c1 <= c2)
	{
		cout << "c1 c2 den kucuk veya esit ";
	}
	else if (c1 >= c2)
	{
		cout << "c1 c2 den buyuk veya esit";
	}
	else if (c1 == c2)
	{
		cout << "c1 ve c2 ayni sozluk";
	}
	else if (c1 != c2)
	{
		cout << "c1 ve c2 ayný sozluk degil";
	}
	else if (c1 < c2)
	{
		cout << "c1 c2 den kucuktur";
	}
	else if (c1 > c2)
	{
		cout << "c1 c2 den buyuktur";
	}
	
	c1 += c2;
	cout << c1;

	aley -= k1;

	cout << aley;

	alp -= "tasit";

	cout << alp;
	
	
	ifstream f;

	f.open("alp.txt");

	f >> c;

	cout << c;

	f.close();


	

	return 0;

}