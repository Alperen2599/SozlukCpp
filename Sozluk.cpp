/*ALPEREN ÝNCÝ
 *18120205016
 */

#include "Sozluk.h"
#include "Kayit.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


ostream & operator<<(ostream & o, const Sozluk & s)
{
	if (s.toplamKayitSayisi == 0)
	{
		o << "Kayit yok" << endl;
		return o;
	}
	for (unsigned i = 0; i < s.toplamKayitSayisi; ++i)
	{
		o << s.kayitlar[i] << endl;

	}
	return o;
}

ofstream & operator<<(ofstream & out, const Sozluk & s)
{
	for (unsigned i = 0; i < s.toplamKayitSayisi; ++i)
	{
		out << "" << s.kayitlar[i] << endl;
	}
	return out;
}

ifstream & operator>>(ifstream & in, Sozluk & s)
{

	string kelime;
	string aciklama;
	string gecici;
	vector <string> aciklamalar;
	vector<Kayit> kayitlar;
	while (!in.eof())
	{
		getline(in, kelime);
		getline(in, gecici,'\n');
		getline(in, aciklama, '\n');
		while (aciklama != "_________________")
		{
			aciklamalar.push_back(aciklama);
			getline(in, aciklama, '\n');

		}
		Kayit k(kelime, aciklamalar);
		kayitlar.push_back(k);
		aciklamalar.clear();

	}
	Sozluk S1(kayitlar);
	s = S1;
	return in;

}


Sozluk::Sozluk()
{
	kayitlar = nullptr;
	toplamKayitSayisi = 0;
}

Sozluk::Sozluk(const Kayit & kayit)
{
	kayitlar = new Kayit[1];
	if (kayitlar == nullptr) {
		exit(-1);
	}
	kayitlar[0] = kayit;
	toplamKayitSayisi = 1;

}

Sozluk::Sozluk(const vector<Kayit>& kayitlar)
{
	toplamKayitSayisi = kayitlar.size();
	this->kayitlar = nullptr;
	this->kayitlar = new Kayit[toplamKayitSayisi];
	if (this->kayitlar == nullptr)
		exit(-1);


	vector<Kayit> temp;
	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		temp.push_back(kayitlar[i]);
	}


	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		for (unsigned j = i + 1; j < toplamKayitSayisi; ++j) {
			if (temp[i].erisimKayit(temp[j])) {
				temp[i] + temp[j];
				temp.erase(temp.begin() + j);
			}
		}
	}

	toplamKayitSayisi = temp.size();
	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		this->kayitlar[i] = temp[i];
	}
}


Sozluk::Sozluk(const Sozluk & other)
{
	toplamKayitSayisi = other.toplamKayitSayisi;
	kayitlar = nullptr;

	if (toplamKayitSayisi != 0)
	{
		kayitlar = new Kayit[toplamKayitSayisi];
		if (kayitlar == nullptr)
			exit(-1);
		if (memcpy(kayitlar, other.kayitlar, toplamKayitSayisi * sizeof(Kayit)) == nullptr)
			exit(-1);
	}
}

Sozluk::~Sozluk()
{
	if (kayitlar != nullptr)
		delete[] kayitlar;

}

const Sozluk & Sozluk::operator=(const Sozluk & other)
{
	if (this == &other)
		return *this;

	if (kayitlar != nullptr)
		delete[] kayitlar;

	toplamKayitSayisi = other.toplamKayitSayisi;

	kayitlar = new Kayit[toplamKayitSayisi];
	if (kayitlar == nullptr)
		exit(-1);

	if (memcpy(kayitlar, other.kayitlar, toplamKayitSayisi * sizeof(Kayit)) == nullptr)
		exit(-1);

	return *this;
}

Kayit & Sozluk::operator[](const string & kelime)
{
	unsigned girdi = 0;
	for (; girdi < toplamKayitSayisi; ++girdi) {
		if (kayitlar[girdi].getKelime() == kelime)
			return kayitlar[girdi];
	}
	cerr << "hataaa" << endl;
	exit(-1);
}
bool Sozluk::operator<(const Sozluk & digerSozluk)
{
	int aciklamasay1 = 0;
	int aciklamasay2 = 0;
	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		aciklamasay1 += kayitlar[i].sayac();
	}
	for (unsigned i = 0; i < digerSozluk.toplamKayitSayisi; ++i) {
		aciklamasay2 += digerSozluk.kayitlar[i].sayac();
	}
	if (aciklamasay1 < aciklamasay2)
		return true;
	else
		return false;
}

bool Sozluk::operator>(const Sozluk & digerSozluk)
{
	int aciklamaSayisi1 = 0;
	int aciklamaSayisi2 = 0;
	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		aciklamaSayisi1 += kayitlar[i].sayac();
	}
	for (unsigned i = 0; i < digerSozluk.toplamKayitSayisi; ++i) {
		aciklamaSayisi2 += digerSozluk.kayitlar[i].sayac();
	}
	if (aciklamaSayisi1 > aciklamaSayisi2)
		return true;
	else
		return false;

}
bool Sozluk::operator!=(const Sozluk & digerSozluk) {
	int aciklamaSayisi1 = 0;
	int aciklamaSayisi2 = 0;
	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		aciklamaSayisi1 += kayitlar[i].sayac();
	}
	for (unsigned i = 0; i < digerSozluk.toplamKayitSayisi; ++i) {
		aciklamaSayisi2 += digerSozluk.kayitlar[i].sayac();
	}
	if (aciklamaSayisi1 != aciklamaSayisi2)
		return true;
	else
		return false;
}
bool Sozluk::operator==(const Sozluk & digerSozluk)
{
	int aciklamasay1 = 0;
	int aciklamasay2 = 0;
	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		aciklamasay1 += kayitlar[i].sayac();
	}
	for (unsigned i = 0; i < digerSozluk.toplamKayitSayisi; ++i) {
		aciklamasay2 += digerSozluk.kayitlar[i].sayac();
	}
	if (aciklamasay1 == aciklamasay2)
		return true;
	else
		return false;
}
bool Sozluk::operator<=(const Sozluk & digerSozluk) {
	int aciklamaSayisi1 = 0;
	int aciklamaSayisi2 = 0;
	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		aciklamaSayisi1 += kayitlar[i].sayac();
	}
	for (unsigned i = 0; i < digerSozluk.toplamKayitSayisi; ++i) {
		aciklamaSayisi2 += digerSozluk.kayitlar[i].sayac();
	}
	if (aciklamaSayisi1 <= aciklamaSayisi2)
		return true;
	else
		return false;
}
bool Sozluk::operator>=(const Sozluk & digerSozluk) {
	int aciklamaSayisi1 = 0;
	int aciklamaSayisi2 = 0;
	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		aciklamaSayisi1 += kayitlar[i].sayac();
	}
	for (unsigned i = 0; i < digerSozluk.toplamKayitSayisi; ++i) {
		aciklamaSayisi2 += digerSozluk.kayitlar[i].sayac();
	}
	if (aciklamaSayisi1 >= aciklamaSayisi2)
		return true;
	else
		return false;
}
Sozluk & Sozluk::operator+(const Sozluk & digerSozluk)
{
	if (this == &digerSozluk)
		return *this;

	vector<Kayit> temp1, temp2, temp3;
	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		temp1.push_back(kayitlar[i]);
	}
	for (unsigned i = 0; i < digerSozluk.toplamKayitSayisi; ++i) {
		temp2.push_back(digerSozluk.kayitlar[i]);
	}

	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		for (unsigned j = 0; j < digerSozluk.toplamKayitSayisi; ++j) {
			if (temp1[i].erisimKayit(temp2[j])) {
				temp3.push_back(temp1[i] + temp2[j]);
				temp1.erase(temp1.begin() + i);
				temp2.erase(temp2.begin() + j);
			}
		}
	}

	for (unsigned i = 0; i < temp1.size(); ++i) {
		temp3.push_back(temp1[i]);
	}
	for (unsigned i = 0; i < temp2.size(); ++i) {
		temp3.push_back(temp2[i]);
	}
	toplamKayitSayisi = temp3.size();
	kayitlar = nullptr;
	kayitlar = new Kayit[toplamKayitSayisi];

	for (unsigned i = 0; i < toplamKayitSayisi; ++i) {
		this->kayitlar[i] = temp3[i];
	}
	return *this;
}
Sozluk & Sozluk::operator+=(const Sozluk & digerSozluk) {
	*this = *this + digerSozluk;
	return *this;
}

Sozluk & Sozluk::operator-=(const Kayit & kayit) {
	for (unsigned i = 0; i < toplamKayitSayisi; ++i)
		if (kayitlar[i].erisimKayit(kayit)) {
			kayitlar[i].aciklamasil();
			kayitlar[i].kelimesil();
		}
	return *this;
}

Sozluk & Sozluk::operator-=(const string & kelime)
{
	for (unsigned i = 0; i < toplamKayitSayisi; ++i)
		if (kayitlar[i].erisimString(kelime))
			kayitlar[i].aciklamasil();
	return *this;
}