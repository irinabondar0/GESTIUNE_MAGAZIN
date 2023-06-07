#ifndef PRODUS_H
#define PRODUS_H
#include <fstream>  //pentru fisiere
#include <string.h> //pentru strcmp
using namespace std;
class produs
{

    char cod[10];     //codul produsului
    char nume[30];    //numele produsului
    int an;           //anul de fabricatie
    char culoare[15]; //culoarea produsului
    int cantitate;    //nr produselor din stocul magazinului pentru fiecare model

public:
    int pret;         //pretul unui produs
    produs();          //constructorul
    void add_produs(); //functie ce adauga un produs in baza de date
    void scrie_fis(); //functie ce salveaza produsul introdus in fisier
    void afis_produs(); //functie ce afiseaza ultimul produs adaugat
    void afis_stoc(); //functie ce afiseaza stocul
    void modifica_produs (); //functie ce modifica stocul sau pretul unui produs
    int goleste_fis(char *fisier); //goleste fisierul
    void cauta_produs_dupa_nume(const char* nume_cautat); //cauta produse dupa nume
    void cautareCuloare(const char* CuloareCautata); //cauta produse dupa culoare
    void cautarePret(int PretCautat); //cauta produse dupa pret
    virtual ~produs();  //destructorul


};


#endif // PRODUS_H_INCLUDED
