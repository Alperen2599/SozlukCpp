#pragma once
#include "Kayit.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Sozluk
{
	// Sozlukteki kayitli kelime sayisini ve toplam aciklama sayisini ekrana yazdirir.
	friend ofstream & operator<<(ofstream & out, const Sozluk & s);
	friend ifstream & operator>>(ifstream & in, const Sozluk & s);
	friend ostream & operator<<(ostream & o, const Sozluk & s);
public:
	/*** CONSTRUCTORS ***/
	// bos bir sozluk oluturur.
	Sozluk();
	// tek bir kayittan olusan bir sozluk olusturur.
	Sozluk(const Kayit& kayit);
	// Bir kayit vektoru alir ve sozluk olusturur. Sozlukte her kayit sadece bir kez olabilir.
		// Eger vektor icinde ayni kayit sozcugu varsa bunlarýn aciklamalarýný birlestirir.
	Sozluk(const vector<Kayit> & kayitlar);
	//!!! Uc buyukleri unutmayin !!!
	Sozluk(const Sozluk & other); /*copy constructor*/
	~Sozluk(); /*destructor*/
	const Sozluk & operator=(const Sozluk & other); /*Assigment operator*/

//Verilen bir kelime degerine sahip Kaydi donderen subscript operatorunu asiri yukleyiniz

	Kayit& operator[](const string & kelime);

	// Iki sozlugu buyukluk acisindan karislatiran operatorleri asiri yukleyin
	bool operator <(const Sozluk & digerSozluk);
	bool operator >(const Sozluk & digerSozluk);

	// Karsilasirmalar toplam sozlukteki toplam aciklama sayisina gore yapilir
	// ==, !=, >, <, <=, >= operatorlerinin tamamýný asiri yukleyiniz
	bool operator==(const Sozluk & digerSozluk);
	bool operator<=(const Sozluk & digerSozluk);
	bool operator>=(const Sozluk & digerSozluk);
	bool operator!=(const Sozluk & digerSozluk);
	// Iki sozlugu birlestiren iki operandli + operatorunu asiri yukleyiniz. Birlesim sonunda ayni kayittan iki tane olmaz, aciklamalar bir kelime altina toplanir

		// bir kayit altinda birebir ayni aciklama iki veya daha cok kez bulunamaz
	Sozluk & operator+(const Sozluk & digerSozluk);
	// Iki sozlugu birlestiren += operatorunu asiri yukleyiniz. Birlesim sonunda ayni kayittan iki tane olmaz, aciklamalar bir kelime altina toplanir

		// bir kayit altinda birebir ayni aciklama iki veya daha cok kez bulunamaz
	Sozluk & operator+=(const Sozluk & digerSozluk);
	// Sozluk icindeki kelimede yer alan aciklamalari siler. Eger hic aciklama kalmamissa tum kelimeyi siler

	Sozluk & operator-=(const Kayit & kayit);
	// Sozluk icindeki kelimede yer alan TUM aciklamalari siler.
	Sozluk & operator-=(const string & kelime);
private:
	Kayit * kayitlar;
	unsigned int toplamKayitSayisi;
};