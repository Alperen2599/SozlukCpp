#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

class Kayit
{
	// Kelime ve o kelimeye ait tum aciklamalari satir satir ekrana yazar.
	friend ostream& operator<<(ostream& outStream, const Kayit& kayit);

	// getline ile satýr satýr veri okunur. Ýlk satýr kelimedir, diðer her bir satýr bir açýklamadýr.
	// Boþ açýklama geldiðinde çýkar.

	friend istream& operator>>(istream& inStream, Kayit& kayit);

public:
	/* Sozlukteki her bir kayýt bir kelime ve o kelimeye ait aciklamalari icerir.
	Bu yapici(constructor) fonksiyon bir kelime icin tek bir aciklama metni alir.*/
	Kayit(const string & kelime = "", const string & aciklama = "");

	/* Bir kelimenin birden cok anlami/aciklamasi olabilir. Bu yapici aciklamalarin bir vektorunu alir.*/
	Kayit(const string & kelime, const vector<string> & aciklamalar);

	// Eger iki kaydin kelime degerleri esit ise aciklama vektorlerinin birlesim kumesi olusturulur.
	// Ayni aciklama yeni kayitta birden cok kez bulunamaz!
	const Kayit & operator +(const Kayit & digerKayit);

	// Bir kayita daha once o kayitta olmayan yeni bir anlam/aciklama eklenebilir. 
	const Kayit & operator +(const string & aciklama);

	// Bir kayitta bulunan anlam/aciklama cikartilabilir. Fonksiyon cikartilacak aciklamayi argüman olarak alýr.
	const Kayit & operator -(const string & aciklama);

	// Bir kayit bossa (kelime == "" veya hic aciklamasi yoksa) dogru yoksa yanlis donderir
	bool operator!();

	// Eger iki kaydin kelimeleri ayniysa veya kayitlar es anlamli kelimeler ise dogru donderir
	// Bir kelimenin aciklamasi tek bir kelime ise o kelime ile esanlamlidir.
	bool operator==(const Kayit & digerKayit);

	// Eger kaydin kelimesi verilen kelime ayniysa veya kayitlar es anlamli kelimeler ise dogru donderir
	// Bir kelimenin aciklamasi tek bir kelime ise o kelime ile esanlamlidir.
	bool operator==(const string & digerKelime);


	bool erisimKayit(const Kayit & digerkayit)const;
	bool erisimString(const string & digerkelime)const;
	string getKelime()const;
	void aciklamasil();
	void kelimesil();
	int sayac();

private:
	string kelime;
	vector<string> aciklama;
};
