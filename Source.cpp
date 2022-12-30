#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Oyuncu {
public:
	// Oyuncunun �zelliklerini tutan de�i�kenler
	int enerji;
	int hirsizlik_seviyesi;
	int guc;
	int hiz;

	//Oyuncunun enerjisini azalrtan ve y�kselten fonksiyonlar
	void enerji_kaybi(int kayip) {
		enerji -= kayip;
	}
	void enerji_kazanc(int kazanc) {
		enerji += kazanc;
	}

	// Oyuncunun h�rs�zl�k seviyesini y�kselten fonksiyon
	void hirsizlik_seviyesi_artir(int artis) {
		hirsizlik_seviyesi += artis;
	}
};

class Hapishane : public Oyuncu {
public:
	//Hapishane s�n�f�n�n �zelliklerini tutan de�i�kenler
	int guvenlik;
	int kacis_yontemleri_sayisi;

	//Hapishane s�n�f�n�n g�venli�ini azaltan ve ka��� y�ntemleri say�s�n� artt�ran fonksiyonlar
	void guvenlik_azalt(int azalma) {
		guvenlik -= azalma;
	}
	void kacis_yontemleri_sayisi_artir(int artis) {
		kacis_yontemleri_sayisi += artis;
	}

	//Hapishane s�n�f�n�n g�venli�ini y�kselten fonksiyon
	void guvenlik_yukselt(int yukseltme) {
		guvenlik += yukseltme;
	}
};

int main() {
	setlocale(LC_ALL, "Turkish");

	srand(time(NULL)); //rastgele say� �retmek i�in seme se�iyoruz

	cout << "~~ HAP�SHANEDEN KA�I� OYUNU ~~" << endl;

	//Oyuncu ve hapishane s�n�flar�ndan nesneler olu�turuyoruz 
	Oyuncu oyuncu;
	Hapishane hapishane;

	//Oyuncu ve hapishane nesnelerinin �zelliklerini ilk de�erlerine at�yoruz
	oyuncu.enerji = 100;
	oyuncu.hirsizlik_seviyesi = 0;
	oyuncu.guc = 50;
	oyuncu.hiz = 75;
	hapishane.kacis_yontemleri_sayisi = 5;
	hapishane.guvenlik = 20;

	while (true) {
		cout << "Ka��� Y�ntemlerini Se�in:" << endl;
		cout << "1. K�pr�y� Kesin" << endl;
		cout << "2. K�pr�y� Onar�n " << endl;
		cout << "3. K�pr�den Ge�in " << endl;
		cout << "4. K�pr�y� Atlay�n " << endl;
		cout << "5. K�pr�y� Suya D���r�n" << endl;
		
		int choice;
		cin >> choice;

		if (choice == 1) {
			oyuncu.hirsizlik_seviyesi_artir(25); //H�rs�zl� seviyesi y�kselir
			hapishane.guvenlik_azalt(10); // g�venlik azal�r
			if (hapishane.guvenlik > 0) {
				cout << "K�pr�y� kesin, ama alarm �al�yor ve polis geliyor! " << endl;
				oyuncu.enerji_kaybi(50); // enerji kayb�
			}
			else {
				cout << "K�pr�y� kestin ve ka���� ba�ard�n" << endl;
				break;
			}
		}
		else if (choice == 2) {
			oyuncu.enerji_kazanc(10); // enerji kazan�
			hapishane.guvenlik_yukselt(5); // g�venlik y�kselir
			hapishane.kacis_yontemleri_sayisi_artir(1); // ka��� y�ntemleri say�s� artar
			cout << "K�pr�y� onard�n, ama alarm �al�yor ve polis geliyor! " << endl;
			oyuncu.enerji_kaybi(50); // enerji kayb�
		}
		else if (choice == 3) {
			oyuncu.enerji_kazanc(20); // enerji kazan�
			hapishane.guvenlik_azalt(5); // g�venlik azal�r
			if (hapishane.guvenlik > 0) {
				cout << "K�pr�den ge�tin, ama alarm �al�yor ve polis geliyor!" << endl;
				oyuncu.enerji_kaybi(50); // enerji kayb�
			}
			else {
				cout << "K�pr�den ge�tin ve ka���� ba�ard�n!" << endl;
				break;
			}
		}
		else if (choice == 4) {
			oyuncu.enerji_kazanc(5); // enerji kazan�
			hapishane.guvenlik_azalt(15); // g�venlik azal�r
			int x = rand() % 2; // 0 ile 1 aras�nda rastgele bir say� �retir
			if (x == 0) {
				if (hapishane.guvenlik > 0) {
					cout << "K�pr�y� atlad�n, ama alarm �al�yor ve polis geliyor!" << endl;
					oyuncu.enerji_kaybi(50); // enerji kayb�
				}
				else {
					cout << "K�pr�y� atlad�n ve ka���� ba�ard�n!" << endl;
					break;
				}
			}
			else {
				cout << "K�pr�y� atlamak i�in �ok y�ksek atlad�n ve yer d��t�n. Polis geliyor!" << endl;
				oyuncu.enerji_kaybi(75); // enerji kayb�
			}
		}
		else if (choice == 5) {
			oyuncu.enerji_kazanc(10); // enerji kazan�
			hapishane.guvenlik_azalt(20); // g�venlij azal�r
			int x = rand() % 2; // 0 ile 1 aras�nda rastgele bir say� �retir
			if (x == 0) {
				if (hapishane.guvenlik > 0) {
					cout << "K�pr�y� suya d���rd�n, ama alarm �al�yor ve polis geliyor!" << endl;
					oyuncu.enerji_kaybi(50); // enerji kayb�
				}
			}
			else {
				cout << "K�pr�y� suya d���rmek i�in �ok az miktarda su kulland�n ve ba�ar�s�z oldun. Polis geliyor! " << endl;
				oyuncu.enerji_kaybi(75); // enerji kayb�
			}
		}
		else {
			cout << "Ge�ersiz bir se�im yapt�n�z. Oyunu tekrar ba�lat�n." << endl;
		}

		//E�er oyuncunun enerjisi s�f�r�n alt�na d��erse, oyun biter
		if (oyuncu.enerji <= 0) {
			cout << "Oyunu kaybettin! Enerjin bitmi�." << endl;
			break;
		}

	}
	return 0;
}
