#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Oyuncu {
public:
	// Oyuncunun özelliklerini tutan deðiþkenler
	int enerji;
	int hirsizlik_seviyesi;
	int guc;
	int hiz;

	//Oyuncunun enerjisini azalrtan ve yükselten fonksiyonlar
	void enerji_kaybi(int kayip) {
		enerji -= kayip;
	}
	void enerji_kazanc(int kazanc) {
		enerji += kazanc;
	}

	// Oyuncunun hýrsýzlýk seviyesini yükselten fonksiyon
	void hirsizlik_seviyesi_artir(int artis) {
		hirsizlik_seviyesi += artis;
	}
};

class Hapishane : public Oyuncu {
public:
	//Hapishane sýnýfýnýn özelliklerini tutan deðiþkenler
	int guvenlik;
	int kacis_yontemleri_sayisi;

	//Hapishane sýnýfýnýn güvenliðini azaltan ve kaçýþ yöntemleri sayýsýný arttýran fonksiyonlar
	void guvenlik_azalt(int azalma) {
		guvenlik -= azalma;
	}
	void kacis_yontemleri_sayisi_artir(int artis) {
		kacis_yontemleri_sayisi += artis;
	}

	//Hapishane sýnýfýnýn güvenliðini yükselten fonksiyon
	void guvenlik_yukselt(int yukseltme) {
		guvenlik += yukseltme;
	}
};

int main() {
	setlocale(LC_ALL, "Turkish");

	srand(time(NULL)); //rastgele sayý üretmek için seme seçiyoruz

	cout << "~~ HAPÝSHANEDEN KAÇIÞ OYUNU ~~" << endl;

	//Oyuncu ve hapishane sýnýflarýndan nesneler oluþturuyoruz 
	Oyuncu oyuncu;
	Hapishane hapishane;

	//Oyuncu ve hapishane nesnelerinin özelliklerini ilk deðerlerine atýyoruz
	oyuncu.enerji = 100;
	oyuncu.hirsizlik_seviyesi = 0;
	oyuncu.guc = 50;
	oyuncu.hiz = 75;
	hapishane.kacis_yontemleri_sayisi = 5;
	hapishane.guvenlik = 20;

	while (true) {
		cout << "Kaçýþ Yöntemlerini Seçin:" << endl;
		cout << "1. Köprüyü Kesin" << endl;
		cout << "2. Köprüyü Onarýn " << endl;
		cout << "3. Köprüden Geçin " << endl;
		cout << "4. Köprüyü Atlayýn " << endl;
		cout << "5. Köprüyü Suya Düþürün" << endl;
		
		int choice;
		cin >> choice;

		if (choice == 1) {
			oyuncu.hirsizlik_seviyesi_artir(25); //Hýrsýzlý seviyesi yükselir
			hapishane.guvenlik_azalt(10); // güvenlik azalýr
			if (hapishane.guvenlik > 0) {
				cout << "Köprüyü kesin, ama alarm çalýyor ve polis geliyor! " << endl;
				oyuncu.enerji_kaybi(50); // enerji kaybý
			}
			else {
				cout << "Köprüyü kestin ve kaçýþý baþardýn" << endl;
				break;
			}
		}
		else if (choice == 2) {
			oyuncu.enerji_kazanc(10); // enerji kazanç
			hapishane.guvenlik_yukselt(5); // güvenlik yükselir
			hapishane.kacis_yontemleri_sayisi_artir(1); // kaçýþ yöntemleri sayýsý artar
			cout << "Köprüyü onardýn, ama alarm çalýyor ve polis geliyor! " << endl;
			oyuncu.enerji_kaybi(50); // enerji kaybý
		}
		else if (choice == 3) {
			oyuncu.enerji_kazanc(20); // enerji kazanç
			hapishane.guvenlik_azalt(5); // güvenlik azalýr
			if (hapishane.guvenlik > 0) {
				cout << "Köprüden geçtin, ama alarm çalýyor ve polis geliyor!" << endl;
				oyuncu.enerji_kaybi(50); // enerji kaybý
			}
			else {
				cout << "Köprüden geçtin ve kaçýþý baþardýn!" << endl;
				break;
			}
		}
		else if (choice == 4) {
			oyuncu.enerji_kazanc(5); // enerji kazanç
			hapishane.guvenlik_azalt(15); // güvenlik azalýr
			int x = rand() % 2; // 0 ile 1 arasýnda rastgele bir sayý üretir
			if (x == 0) {
				if (hapishane.guvenlik > 0) {
					cout << "Köprüyü atladýn, ama alarm çalýyor ve polis geliyor!" << endl;
					oyuncu.enerji_kaybi(50); // enerji kaybý
				}
				else {
					cout << "Köprüyü atladýn ve kaçýþý baþardýn!" << endl;
					break;
				}
			}
			else {
				cout << "Köprüyü atlamak için çok yüksek atladýn ve yer düþtün. Polis geliyor!" << endl;
				oyuncu.enerji_kaybi(75); // enerji kaybý
			}
		}
		else if (choice == 5) {
			oyuncu.enerji_kazanc(10); // enerji kazanç
			hapishane.guvenlik_azalt(20); // güvenlij azalýr
			int x = rand() % 2; // 0 ile 1 arasýnda rastgele bir sayý üretir
			if (x == 0) {
				if (hapishane.guvenlik > 0) {
					cout << "Köprüyü suya düþürdün, ama alarm çalýyor ve polis geliyor!" << endl;
					oyuncu.enerji_kaybi(50); // enerji kaybý
				}
			}
			else {
				cout << "Köprüyü suya düþürmek için çok az miktarda su kullandýn ve baþarýsýz oldun. Polis geliyor! " << endl;
				oyuncu.enerji_kaybi(75); // enerji kaybý
			}
		}
		else {
			cout << "Geçersiz bir seçim yaptýnýz. Oyunu tekrar baþlatýn." << endl;
		}

		//Eðer oyuncunun enerjisi sýfýrýn altýna düþerse, oyun biter
		if (oyuncu.enerji <= 0) {
			cout << "Oyunu kaybettin! Enerjin bitmiþ." << endl;
			break;
		}

	}
	return 0;
}
