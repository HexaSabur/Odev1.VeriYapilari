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
#include "BD.hpp"

BD::BD(Kromozom *kromozom)
{
    this->next = 0;
    this->prev = 0;
    this->khead = 0;
    this->addKromozom(kromozom);
}

void BD::addKromozom(Kromozom *kromozom)
{
    if (khead == 0)
    {
        khead = kromozom;
    }
    else
    {
        BD *bd;
        bd->khead = kromozom;
        while (bd->next != 0)
        {
            bd = bd->next;
        }
        // bd->next->addKromozom() = kromozom;
        bd->next = new BD(kromozom);
    }
    // length++;
}