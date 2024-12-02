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
#ifndef DOSYAOKU_HPP
#define DOSYAOKU_HPP
#include "DNA.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DosyaOku
{
public:
    void readLines(string filename);
    void separatingLines(string &line, DNA *dna);
    //  void separatingGen(string &line, Kromozom *kromozom);
    void carpazlama(int, int);
    void mutasyon(int, int);
    void otomatikIslemler(string dosyaAdi);
    void ekranaYaz();
};

#endif
