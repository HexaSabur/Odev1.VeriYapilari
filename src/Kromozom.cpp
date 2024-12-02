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
#include "Kromozom.hpp"

Kromozom::Kromozom()
{
    this->head = 0;
    this->length = 0;
}
void Kromozom::addGen(Gen *gen)
{
    if (gen == nullptr)
        return;

    if (head == nullptr)
    {
        head = gen;
        gen->prev = nullptr;
    }
    else
    {
        Gen *current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = gen;
        gen->prev = current; // Set the prev pointer
    }
    gen->next = nullptr; // Ensure the new gen's next is null
    length++;
}
void Kromozom::printGen()
{
    Gen *temp = head;
    while (temp != 0)
    {
        cout << temp->harf;
        temp = temp->next;
    }
    // cout << " : bu kromozomun uzunlugu " << length;
    cout << endl;
}

/////////////// CHAT EKLENTISI
int Kromozom::getLength()
{

    int length = 0;

    Gen *current = head;

    while (current != nullptr)
    {

        length++;

        current = current->next;
    }

    return length;
}
Gen *Kromozom::getHead() // Düzeltilmiş sözdizimi
{
    return head;
}
