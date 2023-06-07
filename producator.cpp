#include <iostream>
#include <string>
#include <fstream>
#include "producator.h"// include fisierul clasei
#include "produs.h"
#include <windows.h> // biblioteca pentru consola
#include <iomanip> // biblioteca pentru setw
#include <stdio.h>  //biblioteca pentru fflush
using namespace std;

producator::producator()
{
    nume_producator[30]=NULL;

}

producator::~producator()
{
    //
}

void producator::add_producator()
{
    cout<<"\n 7.Introduceti numele producatorului:";
    cin.getline(nume_producator,30);

}
void producator::scrie_fisier()
{
    ofstream fisier("fisierProduse.txt", ios::app);
    if (fisier.is_open())
    {
        fisier<<','<<nume_producator<<',';
        fisier<<'\n';
        fisier.close();
        cout << "\n  Datele au fost salvate cu succes in fisier.\n";

    }
    else
    {
        cout << "Eroare la deschiderea fisierului.\n";
    }
}



