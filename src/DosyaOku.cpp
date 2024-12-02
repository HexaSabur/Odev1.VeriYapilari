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
#include "DosyaOku.hpp"
#include "DNA.hpp"
#include <sstream>
DNA *dna = new DNA();
void DosyaOku::readLines(string filename)
{
    ifstream file(filename);
    string line;

    // sonradan anlatim eklemesi

    if (file.is_open())
    {
        while (getline(file, line))
        {
            // cout << "Okunan Satir: " << line << endl;

            // sepearating the line into char function
            // her satiri parca parca ayir ve kromozoma'ya ekle
            // separetinglines(string line , dna);
            separatingLines(line, dna); // Satırdaki kromozumlari ayır ve DNA'ya ekle
        }

        file.close();

        // DNA'yı yazdır
        //////////////////    dna->printDNA();

        // cout << "THE DNA" << endl;
        // dna->printDNA();

        // Belleği temizle
        // delete dna;
    }
    else
    {
        cout << "Unable to open file: " << filename << endl;
    }
}

// Satırdaki karakterleri işleyen fonksiyon (her satırı bir kromozom olarak ele alır)
void DosyaOku::separatingLines(string &line, DNA *dna)
{
    Kromozom *kromozom = new Kromozom();
    for (char harf : line)
    {
        // Eğer harf boşluk değilse, bir gen olarak ekle
        if (!isspace(harf))
        {
            Gen *gen = new Gen(harf);
            kromozom->addGen(gen);
        }
    }
    dna->addBD(new BD(kromozom));
    //  kromozom->printGen();
}

// Satırdaki her bir karakteri gen olarak işleyen fonksiyon
// void DosyaOku::separatingGen(string &line, Kromozom *kromozom)
// {
// }

/* separatingLinesintochars(string line,DNA* dna){
    every char is gen
    Kromozom* kromozom = new Kromozom();


    end of separating lines code
    }

    spratingGen(){
    while (separated chars)
    {
        Gen* gen = new Gen(char)
        // add gen to kromozom
        kromozom->addGen(gen);
    }
    Dna->addKromozom(kromozom);
    dna->length;
    kromozom->length;
}*/

// void DosyaOku::carpazlama(int krz1, int krz2)
// {
//     BD *temp1;
//     BD *temp2;
//     temp1 = dna->head;
//     temp2 = dna->head;

//     int times = 0;
//     while (times < krz1)
//     {
//         cout << times << endl;
//         temp1 = temp1->next;
//         times++;
//     }
//     while (times < krz2)
//     {
//         cout << times << endl;
//         temp2 = temp2->next;
//         times++;
//     }

//     temp1->khead->printGen();
//     temp2->khead->printGen();

//     cout << temp1->khead;
//     while (temp1 != NULL)
//     {

//         /* code */
//     }

//     // temp1->next->khead->printGen();
//     // Seçilen kromozomları çaprazla
//     // CARPAZLAMADA BIRINCI KROMOZOUMUN EGER CIFT ISE SOL TARAFINI AL VE IKINICI KROMOZOMUN SAG YARSINANA EKLE EGER O DA CIFT SAYIDAN OLUSUYORSA
//     // SONRA BIRINCI KROMOZOMUN SAG TARAFINI IKINCI KROMOZOMUN SOL TARAFINA EKLE
//     // EGE TEK SAYIDAN OLUSUYORSA ORDAKAI SAYI HIC BIR TARAFA EKLENMEDEN DAG VE SOL TARAFI ALINACAK
//     // Çaprazlanmış kromozomları DNA1 ve DNA2'ye ekle
// }
void DosyaOku::carpazlama(int krz1, int krz2)
{
    // Aynı kromozomların seçilmesini engelle
    if (krz1 == krz2)
    {
        cout << "Ayni kromozom numarasi secilemez!" << endl;
        cout << "Lutfen farkli bir kromozom numarasi girin: ";
        cin >> krz2;
        if (krz1 == krz2)
        {
            cout << "Hala ayni kromozom secildi. İslem iptal ediliyor." << endl;
            return;
        }
    }

    BD *temp1 = dna->head;
    BD *temp2 = dna->head;

    // Find chromosomes
    for (int i = 0; i < krz1 && temp1; i++)
        temp1 = temp1->next;
    for (int i = 0; i < krz2 && temp2; i++)
        temp2 = temp2->next;

    if (!temp1 || !temp2)
    {
        cout << "Invalid chromosome indices" << endl;
        return;
    }

    Kromozom *kromozom1 = temp1->khead;
    Kromozom *kromozom2 = temp2->khead;

    int len1 = kromozom1->getLength();
    int len2 = kromozom2->getLength();

    Kromozom *yeniKromozom1 = new Kromozom();
    Kromozom *yeniKromozom2 = new Kromozom();

    // First crossover part
    Gen *current1 = kromozom1->getHead();
    int index = 0;
    while (current1 != nullptr)
    {
        if (len1 % 2 == 1 && index == len1 / 2)
        {
            current1 = current1->next;
            index++;
            continue;
        }
        if (index < len1 / 2)
        {
            yeniKromozom1->addGen(new Gen(current1->getHarf()));
        }
        current1 = current1->next;
        index++;
    }

    // Second crossover part
    Gen *current2 = kromozom2->getHead();
    index = 0;
    while (current2 != nullptr)
    {
        if (len2 % 2 == 1 && index == len2 / 2)
        {
            current2 = current2->next;
            index++;
            continue;
        }
        if (index >= len2 / 2)
        {
            yeniKromozom1->addGen(new Gen(current2->getHarf()));
        }
        current2 = current2->next;
        index++;
    }

    // Repeat for second new chromosome
    current1 = kromozom1->getHead();
    index = 0;
    while (current1 != nullptr)
    {
        if (len1 % 2 == 1 && index == len1 / 2)
        {
            current1 = current1->next;
            index++;
            continue;
        }
        if (index >= len1 / 2)
        {
            yeniKromozom2->addGen(new Gen(current1->getHarf()));
        }
        current1 = current1->next;
        index++;
    }

    current2 = kromozom2->getHead();
    index = 0;
    while (current2 != nullptr)
    {
        if (len2 % 2 == 1 && index == len2 / 2)
        {
            current2 = current2->next;
            index++;
            continue;
        }
        if (index < len2 / 2)
        {
            yeniKromozom2->addGen(new Gen(current2->getHarf()));
        }
        current2 = current2->next;
        index++;
    }

    // Add new chromosomes to DNA
    BD *newBD1 = new BD(yeniKromozom1);
    BD *newBD2 = new BD(yeniKromozom2);

    dna->addBD(newBD1);
    dna->addBD(newBD2);

    cout << "New chromosomes after crossover:" << endl;
    yeniKromozom1->printGen();
    yeniKromozom2->printGen();
    cout << "/////////////////" << endl;
    // cout << "DNA after crossover:" << endl;
    //  dna->printDNA();
    //   Don't delete the new chromosomes since they're now part of the DNA
}
void DosyaOku::mutasyon(int kromozomIndex, int genIndex)
{
    // Kromozom dizisine ulaşmak için geçici işaretçi
    BD *temp = dna->head;

    // Belirtilen kromozom indexine ulaş
    for (int i = 0; i < kromozomIndex; i++)
    {
        if (temp == nullptr)
        {
            cout << "Gecersiz kromozom indeksi!" << endl;
            return;
        }
        temp = temp->next;
    }

    // Belirtilen kromozomun başına ulaştık
    Kromozom *kromozom = temp->khead;

    if (kromozom == nullptr)
    {
        cout << "Kromozom bulunamadi!" << endl;
        return;
    }

    // Kromozom uzunluğunu al
    int length = kromozom->getLength();

    // Geçersiz gen indeksi kontrolü
    if (genIndex < 0 || genIndex >= length)
    {
        cout << "Gecersiz gen indeksi!" << endl;
        return;
    }

    // İlgili geni bul
    Gen *current = kromozom->getHead();
    for (int i = 0; i < genIndex; i++)
    {
        if (current == nullptr)
        {
            cout << "Gecersiz gen indeksi!" << endl;
            return;
        }
        current = current->next;
    }

    // Geni mutasyona uğrat (harfi 'X' olarak değiştir)
    current->setHarf('X');

    // Mutasyondan sonra kromozomu yazdır
    cout << "Mutasyon tamamlandi! Guncellenmis kromozom: " << endl;
    kromozom->printGen();
    //  dna->addBD(new BD(kromozom));
    cout << "/////////////////" << endl;
    // dna->printDNA();
}

void DosyaOku::otomatikIslemler(string dosyaAdi)
{
    ifstream islemlerDosyasi(dosyaAdi); // Dosyayı aç
    if (!islemlerDosyasi.is_open())
    {
        cout << "Dosya acilamadi: " << dosyaAdi << endl;
        return;
    }

    string line;
    while (getline(islemlerDosyasi, line))
    {
        cout << "Okunan Satir: " << line << endl;

        // Satırı parçalamak için stringstream kullan
        stringstream ss(line);
        char islemTipi;
        int param1, param2;

        // Satır formatı: İşlemTipi Param1 Param2
        ss >> islemTipi >> param1 >> param2;

        if (islemTipi == 'C') // Çaprazlama işlemi
        {
            cout << "caprazlama: " << param1 << ", " << param2 << endl;
            carpazlama(param1, param2); // Çaprazlama fonksiyonunu çağır
        }
        else if (islemTipi == 'M') // Mutasyon işlemi
        {
            cout << "Mutasyon: " << param1 << ", " << param2 << endl;
            mutasyon(param1, param2); // Mutasyon fonksiyonunu çağır
        }
        else
        {
            cout << "Bilinmeyen islem: " << islemTipi << endl;
        }
    }

    islemlerDosyasi.close(); // Dosyayı kapat
    cout << "Islem tamamlandi!" << endl;
}
void DosyaOku::ekranaYaz()
{
    BD *temp = dna->head;
    cout << "Ekran ciktisi: ";

    while (temp != nullptr)
    {
        Kromozom *kromozom = temp->khead;
        if (kromozom == nullptr || kromozom->getHead() == nullptr)
        {
            temp = temp->next;
            continue;
        }

        // İlk harfi al
        Gen *firstGen = kromozom->getHead();
        char firstChar = firstGen->getHarf();
        char charToPrint = firstChar;

        // Önce son gene git
        Gen *current = kromozom->getHead();
        while (current->next != nullptr)
        {
            current = current->next;
        }

        // Sağdan sola doğru git ve ilk harften küçük olan ilk karakteri bul
        while (current != firstGen)
        {
            if (current->getHarf() < firstChar)
            {
                charToPrint = current->getHarf();
                break; // İlk küçük karakteri bulduk, döngüden çık
            }
            current = current->prev;
        }

        cout << charToPrint << " ";
        temp = temp->next;
    }

    cout << endl;
}
