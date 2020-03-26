#include "Kayit.h"
#include "Sozluk.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

ostream & operator<<(ostream & outStream, const Kayit & kayit)
{
	unsigned n = kayit.aciklama.size();
	outStream << kayit.kelime << endl;
	for (unsigned i = 0; i < n; ++i)
	{
		outStream << kayit.aciklama.at(i);
	}
	return outStream;
}

istream & operator>>(istream & inStream, Kayit & kayit)
{
	kayit.aciklama.clear();
	getline(inStream, kayit.kelime);
	string s;
	getline(inStream, s);
	while (s != "")
	{

		kayit.aciklama.push_back(s);
		getline(inStream, s);
	}
	return inStream;
}

Kayit::Kayit(const string & kelime, const string & aciklama)
{
	this->kelime = kelime;
	this->aciklama.push_back(aciklama);

}
Kayit::Kayit(const string & kelime, const vector<string> & aciklamalar)
{
	unsigned n = aciklamalar.size();
	this->kelime = kelime;
	for (unsigned i = 0; i < n; ++i) {
		aciklama.push_back(aciklamalar.at(i));
	}
}
const Kayit & Kayit::operator+(const Kayit & digerKayit)
{
	unsigned n = this->aciklama.size();
	if (this->kelime == digerKayit.kelime) {
		for (unsigned i = 0; i < n; ++i) {
			unsigned y = digerKayit.aciklama.size();
			for (unsigned j = 0; j < y; ++j)
				if (this->aciklama.at(i) == digerKayit.aciklama.at(j))
					break;
				else if (j == n - 1) {
					this->aciklama.push_back(aciklama.at(i));
					continue;
				}


		}

		return *this;

	}
	else {

		return *this;
	}
}
const Kayit & Kayit::operator+(const string & aciklama)
{
	int n = this->aciklama.size();
	for (int i = 0; i < n; ++i) {
		if (this->aciklama.at(i) == aciklama) {

			return *this;
		}

		this->aciklama.push_back(aciklama);

		return *this;
	}
	return *this;
}

const Kayit & Kayit::operator-(const string & aciklama)
{
	int n = this->aciklama.size();
	for (int i = 0; i < n; ++i) {

		if (this->aciklama.at(i) == aciklama) {
			this->aciklama.erase(this->aciklama.begin() + i);

			return *this;
		}
	}
	return *this;
}

bool Kayit::operator!()
{
	int n = this->aciklama.size();
	for (int i = 0; i < n; ++i)
		if (kelime == "" || this->aciklama.at(i) == "") {

			return true;

		}
	return false;
}


bool Kayit::operator==(const Kayit & digerKayit)
{
	int n = this->aciklama.size();
	if (kelime == digerKayit.kelime) {
		return true;
	}

	for (int i = 0; i < n; ++i) {
		if (this->aciklama.at(i) == digerKayit.kelime) {
			return true;
		}
		int y = digerKayit.aciklama.size();
		for (int i = 0; i < y; ++i) {
			return true;
		}
	}
	return false;
}



bool Kayit::operator==(const string & digerKelime)
{
	if (kelime == digerKelime)
	{
		return true;

	}
	else
	{
		return false;
	}

}

bool Kayit::erisimKayit(const Kayit & digerkayit) const
{
	if (kelime == digerkayit.kelime) {
		return true;

	}
	else
		return false;
}

bool Kayit::erisimString(const string & digerkelime) const
{
	if (kelime == digerkelime)
		return true;
	else
		return false;
}

string Kayit::getKelime()const
{
	return kelime;
}

void Kayit::aciklamasil()
{
	kelime.clear();

}

void Kayit::kelimesil()
{
	aciklama.clear();
	kelime.clear();
}

int Kayit::sayac()
{
	if (aciklama.size() == 0) {
		exit(-1);

	}
	else
		return aciklama.size();

}