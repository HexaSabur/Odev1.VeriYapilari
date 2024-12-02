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
#ifndef BD_HPP
#define BD_HPP
#include "Kromozom.hpp"
// bu buyuk dugum lanet olsun
class BD
{
private:
    // BD *next;
    // BD *prev;

public:
    void addKromozom(Kromozom *);
    BD(Kromozom *);
    Kromozom *khead;
    BD *next;
    BD *prev;
};
#endif
