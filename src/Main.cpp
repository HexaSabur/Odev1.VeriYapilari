/**
 *   DOSYA ADI : G231210570
 *   BIR BAGLI LISTENIN ANLATIM ODEVI
 *   SAKARYA UNIVERSITESI BIGILISAYAR MUHENDISLIGI BOLUMU 2. SINIF KAYHAN HOCA 2C GRUBU
 *   1.ODEV
 *   Kodu oluşturduğunuz Tarih : 2024/11/26 DA BITII
 *   ADI : ABDUL SABUR ABDULRAZAQ A.MALIK
 *   NUMARASI : G231210570
 *   MAILI : G231210570@SAKARYA.EDU.TR
 */
#include <iostream>
#include "DosyaOku.hpp"

int main()
{
    DosyaOku dosyaOku;
    dosyaOku.readLines("./doc/DNA.txt");
    int choice;
    cout << "alttaki seceneklerden birini seciniz" << endl;
    cout << "1- Carpazlama" << endl;
    cout << "2- mutasyon" << endl;
    cout << "3- otomatik islemler" << endl;
    cout << "4- ekrana yaz" << endl;
    cout << "5- cikis" << endl;
    do
    {
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "carpazlama" << endl;
            int krz1, krz2;
            cin >> krz1;
            cin >> krz2;
            dosyaOku.carpazlama(krz1, krz2);
            break;
        case 2:
            cout << "mutasyon" << endl;
            int kromozomNo, genNo;

            // Kullanıcıdan değerleri al
            cout << "Kromozom numarasini girin: ";
            cin >> kromozomNo;

            cout << "Gen numarasini girin: ";
            cin >> genNo;

            // Mutasyon işlemini gerçekleştir
            dosyaOku.mutasyon(kromozomNo, genNo); // 0 tabanlı indekse çevir

            break;
        case 3:
            cout << "otomatik islemler" << endl;
            dosyaOku.otomatikIslemler("./doc/Islemler.txt");

            break;
        case 4:
            cout << "ekrana yaz" << endl;
            dosyaOku.ekranaYaz();
            break;
        case 5:
            cout << "cikis" << endl;
            break;
        default:
            cout << "Gecersiz secim, tekrar deneyin." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
