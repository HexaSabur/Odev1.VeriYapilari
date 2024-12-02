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
#ifndef KROMOZOM_HPP
#define KROMOZOM_HPP
#include "GEN.hpp"

class Kromozom
{
private:
    int length;

public:
    Gen *head;
    Kromozom();
    void printGen();
    void addGen(Gen *);
    int getLength();
    Gen *getHead();
};
#endif