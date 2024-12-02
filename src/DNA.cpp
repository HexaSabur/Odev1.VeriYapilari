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
#include "DNA.hpp"
#include "BD.hpp"

DNA::DNA()
{
    this->head = 0;
    this->length = 0;
}
void DNA::printDNA()
{
    BD *temp = head;
    //  cout << temp << endl;
    while (temp != 0)
    {
        temp->khead->printGen();
        temp = temp->next;
    }
}

void DNA::addBD(BD *bd)
{
    if (head == 0)
    {
        head = bd;
    }
    else
    {
        BD *temp = head;
        while (temp->next != 0)
        {
            temp = temp->next;
        }
        temp->next = bd;
    }
    // length++;
}

// void BD::addKromozom(Kromozom *)
// {

//     // Add the kromozom to the DNA's internal storage
//     if (head == 0)
//     {
//         head = kromozom;
//     }
//     else
//     {
//         BD *BD = head;
//         while (BD->next != 0)
//         {
//             BD = BD->next;
//         }
//         BD->next = kromozom;
//     }
//     length++;
// }
