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
#include "Gen.hpp"

Gen::Gen(char harf)
{
    this->harf = harf;
    this->next = 0;
    this->prev = 0;
}
char Gen::getHarf() // chat eklentisi
{
    return harf;
}
void Gen::setHarf(char yeniHarf)
{
    harf = yeniHarf;
}