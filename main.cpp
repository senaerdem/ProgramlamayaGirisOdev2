/*****************************************************************************************************************************************************************
                                SAKARYA UNIVERSITY
                         BILGISAYAR MUHENDISLIGI BOLUMU
                               PROGRAMLAMAYA GIRIS

                         OGRENCI ADI.......: SENA NUR ERDEM
                         OGRENCI NUMARASI.....: G201210033
                         DERS GRUBU.......................: A GRUBU
 ******************************************************************************************************************************************************************/

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); //Renklendirme icin kullanilan fonksiyon

enum RENKLER //Gerekli renk kodlari
{
    LIGHTBLUE    = 9,
    LIGHTGREEN   = 10,
    LIGHTCYAN    = 11,
    LIGHTRED     = 12,
    LIGHTMAGENTA = 13,
    YELLOW       = 14,
};

class Karakter // Karakter sinifi
{
public:
    char harf; // A-Z arasinda bir deger alacak.
    int  renk; // Karakterin alacagi rengi belirten degisken; 9-14 arasinda bir deger alacak.
    int  adet;

    Karakter()
    {

    }
};

class Katar // Katar sinifi
{
public:
    Katar()
    {
        karakter_sayisi = 0; // katar sinifindan bir nesne olusturuldugunda karakter_sayisi degiskenine 0 degeri atanmalidir.
    }

    int karakter_ekle()
    {
        if (karakter_sayisi < 50) {
            RENKLER renk = RENKLER((rand() % 6) + 9); //rastgele renk secimi
            karakterler[karakter_sayisi] = Karakter();
            karakterler[karakter_sayisi].renk = renk;
            karakterler[karakter_sayisi].harf = (rand() % 25) + 65; //rastgele harf secim

            karakter_sayisi++; //Eklenmis hucre sayisini tutuyor
             return 0;
        }
        else
        {
            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "Ekleme islemi yapilamaz." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

        }
    }

    int karakter_cikar()
    {
        if (karakter_sayisi <= 0)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "Cikarilabilecek karakter kalmadi." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            return 0;
        }
        else
        {
            karakterler[--karakter_sayisi] = karakterler[99];
        }

        return 0;
    }

    void yazdir() // Yazdir fonksiyonu cagiriliyor, hucreleri ekrana cikaracak.
    {
        if (karakter_sayisi <= 0)
        {
            cout << " " << "Eleman sayisi= 0" << endl;
            cout << SOLUSTKOSE << DUZCIZGI << DUZCIZGI << DUZCIZGI << SAGUSTKOSE << endl;
            cout << DIKEYCIZGI << " " << " " << " " << DIKEYCIZGI << endl;
            cout << SOLALTKOSE << DUZCIZGI << DUZCIZGI << DUZCIZGI << SAGALTKOSE << endl;
            return;

        }
        else if (karakter_sayisi != 0 && karakter_sayisi <= 50)
        {
            cout << " " << "Eleman sayisi= " << karakter_sayisi << endl;
            cout << SOLUSTKOSE;

            for (int i = 0; i < karakter_sayisi; i++)
            {
                cout << DUZCIZGI << DUZCIZGI << DUZCIZGI << ASAGIAYRAC;
            }

            cout << endl;

            for (int i = 0; i < karakter_sayisi; i++)
            {
                cout << DIKEYCIZGI << " ";
                SetConsoleTextAttribute(hConsole, karakterler[i].renk);
                cout << karakterler[i].harf << " ";
                SetConsoleTextAttribute(hConsole, 15);
            }

            cout << DIKEYCIZGI << endl << SOLALTKOSE;

            for (int i = 0; i < karakter_sayisi; i++)
            {
                cout << DUZCIZGI << DUZCIZGI << DUZCIZGI << YUKARIAYRAC;
            }
            cout << endl;

        }
        else {
            cout << " " << endl;
        }

    }

private:

    int karakter_sayisi;

    //Gerekli karakter kodlari
    char    DUZCIZGI = 205;      // ═
    char    SOLUSTKOSE = 201;    //  ╔
    char    SAGUSTKOSE = 187;    // ╗
    char    DIKEYCIZGI = 186;    //   ║
    char    ASAGIAYRAC = 203;    // ╦
    char    SOLALTKOSE = 200;    //   ╚
    char    SAGALTKOSE = 188;    // ╝
    char    YUKARIAYRAC = 202;   //   ╩

    Karakter karakterler[100];
};

int main()
{
    int secim = 1;

    srand(time(NULL));

    Katar* katar = new Katar();



    while (true)
    { // Program giris ekrani
        cout << "Islem seciniz" << endl;
        cout << "1-Karakter ekle" << endl;
        cout << "2-Karakter cikar" << endl;
        cout << "3-Programdan cikis" << endl;
        cin >> secim;

        switch (secim)
        {
        case 1: //islem 1 secilirse
            cout << "Onceki hali: ";
            katar->yazdir(); //islem 1 gerceklesmeden onceki hali
            katar->karakter_ekle(); //islem 1 gerceklestirilir
            cout << "Sonraki hali: ";
            katar->yazdir(); //islem 1 sonucu ekrana yazdirilir
            cout << endl;
            continue;

        case 2: //islem 2 secilirse
            cout << "Onceki hali: ";
            katar->yazdir(); //islem 2 onceki hali
            katar->karakter_cikar(); //islem 2 gerceklestirilir
            cout << "Sonraki hali: ";
            katar->yazdir(); //islem 2 sonucu ekrana yazdirilir
            cout << endl;
            continue;

        case 3: //islem 3 secilirse
            delete katar; //programdan cikis yaptirilir
            return 0;
        default:

            cout << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "Boyle bir islem yapilamamaktadir. Lutfen gecerli bir secim yapiniz." << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

           
            continue;
        }
    }
    return 0;
}
