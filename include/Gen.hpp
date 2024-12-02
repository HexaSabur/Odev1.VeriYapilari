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
#ifndef GEN_HPP
#define GEN_HPP
#include <iostream>
using namespace std;
// kucuk node classi
class Gen
{
private:
public:
    char harf;
    Gen(char);
    Gen *next;
    Gen *prev;
    char getHarf();
    void setHarf(char yeniHarf);
};

#endif