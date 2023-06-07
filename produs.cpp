#include <iostream>
#include <string>
#include <fstream>
#include "produs.h"// include fisierul clasei
#include "producator.h"
#include <windows.h> // biblioteca pentru consola
#include <iomanip> // biblioteca pentru setw
#include <stdio.h>  //biblioteca pentru fflush
using namespace std;

produs::produs()
{
    nume[30]=NULL;
    cod[10]=NULL;
    an=0;
    culoare[15]=NULL;
    cantitate=0;
    pret=0;
}

produs::~produs()
{
    //
}

void produs::add_produs()
{
    cout<<"\n 1.Introduceti codul produsului : ";
    cin.getline(cod, 10);
    cout<<"\n 2.Introduceti modelul produsului : ";
    cin.getline(nume, 30);
    cout<<"\n 3.Introduceti culoarea produsului : ";
    cin.getline(culoare, 15);
    cout<<"\n 4.Introduceti anul de fabricatie : ";
    cin >> an;
    cin.ignore(); // Ignoram caracterul newline (\n) rămas în buffer după citirea anului.
    cout<<"\n 5.Introduceti pretul produsului : ";
    cin >> pret;
    cin.ignore();
    cout<<"\n 6.Introduceti cantitatea : ";
    cin >> cantitate;
    cin.ignore();// Ignoram caracterul newline (\n) rămas în buffer după citirea cantității.

}



void produs::scrie_fis()
{
    ofstream fisier("fisierProduse.txt", ios::app);
    if (fisier.is_open())
    {
        fisier<<cod << ',' << nume << ',' << culoare << ',' << an << ',' << pret << ',' << cantitate;
        //fisier.close();

    }
    else
    {
        cout << "Eroare la deschiderea fisierului.\n";
    }
}






void produs::afis_stoc()           // *fisier reprezinta fisirul de unde se iau datele pentru afisarea stocului
{
    producator pr;
    ifstream fisier("fisierProduse.txt");
    if (fisier.is_open())
    {
        cout << "\n\n========================================================================================================================";
        cout << "\n\n COD\tNUME\t\tCULOARE\t\tAN\t\tPRET\t\tCANTITATE(buc)\t\tPRODUCATOR\n";
        cout << "========================================================================================================================\n\n";
        while (fisier.getline(cod, 10, ','))
        {
            fisier.getline(nume, 30, ',');
            fisier.getline(culoare, 15, ',');
            fisier >> an;
            fisier.ignore();
            fisier >> pret;
            fisier.ignore();
            fisier >> cantitate;
            fisier.ignore();
            fisier.getline(pr.nume_producator, 30, ',');
            fisier.ignore();
            cout <<left<< setw(5) << cod;
            cout <<left<< setw(20) << nume;
            cout <<left<< setw(15) << culoare;
            cout <<left<< setw(15) << an;
            cout <<left<< setw(23) << pret;
            cout <<left<< setw(20) << cantitate;
            cout <<left<<setw (35) << pr.nume_producator<<endl;

        }
        cout << "========================================================================================================================\n";
    }
    else
    {
        cout << "Eroare la deschiderea fisierului.\n";
    }
}



void produs::modifica_produs ()       // fisier reprezinta fisierul cu baza de date
{

    char cod_cautat[10];
    char nume_cautat[30];
    bool produs_gasit = false;

    strcpy(cod_cautat, "");
    strcpy(nume_cautat, "");


    cout << "\nIntroduceti codul sau numele produsului pe care doriti sa-l modificati: ";

    cin.getline(cod_cautat, 10);


    ifstream fisier_citire("fisierProduse.txt");
    ofstream fisier_temp("temp.txt");

    if (fisier_citire.is_open() && fisier_temp.is_open())
    {
        producator pr;
        while (fisier_citire.getline(cod, 10, ','))
        {
            fisier_citire.getline(nume, 30, ',');
            fisier_citire.getline(culoare, 15, ',');
            fisier_citire >> an;
            fisier_citire.ignore();
            fisier_citire >> pret;
            fisier_citire.ignore();
            fisier_citire >> cantitate;
            fisier_citire.ignore();

            fisier_citire.getline(pr.nume_producator, 30, ',');
            fisier_citire.ignore();

            if (strcmp(cod, cod_cautat) == 0 || strcmp(nume, nume_cautat) == 0)
            {
                produs_gasit = true;

                float nou_pret, noua_cantitate;

                cout << "Introduceti noul pret (0 pentru a pastra pretul curent): ";
                cin >> nou_pret;
                cin.ignore();

                cout << "Introduceti noua cantitate (0 pentru a pastra cantitatea curenta): ";
                cin >> noua_cantitate;
                cin.ignore();

                if (nou_pret != 0)
                {
                    pret = nou_pret;
                }
                if (noua_cantitate != 0)
                {
                    cantitate = noua_cantitate;
                }

                fisier_temp << cod << ',' << nume << ',' << culoare << ',' << an << ',' << pret << ',' << cantitate << ',' << pr.nume_producator <<','<<'\n';

                cout << "Produsul a fost modificat cu succes.\n";
            }
            else
            {
                fisier_temp << cod << ',' << nume << ',' << culoare << ',' << an << ',' << pret << ',' << cantitate << ',' << pr.nume_producator << ','<<'\n';
            }
        }

        fisier_citire.close();
        fisier_temp.close();

        if (produs_gasit)
        {
            remove("fisierProduse.txt");
            rename("temp.txt", "fisierProduse.txt");
        }
        else
        {
            remove("temp.txt");
            cout << "Produsul nu a fost gasit. Cititi alt cod sau nume.\n";
        }
    }
    else
    {
        cout << "Eroare la deschiderea fisierelor.\n";
    }

}

void produs::cauta_produs_dupa_nume(const char* nume_cautat)
{
    bool produs_gasit = false;
    ifstream fisier("fisierProduse.txt");
    if (fisier.is_open())
    {
        cout << "\n\n========================================================================================================================";
        cout << "\n\n COD\tNUME\t\tCULOARE\t\tAN\t\tPRET\t\tCANTITATE\t\tPRODUCATOR\n";
        cout << "========================================================================================================================\n\n";
        producator pr;
        while (fisier.getline(cod, 10, ','))
        {
            fisier.getline(nume, 30, ',');
            fisier.getline(culoare, 15, ',');
            fisier >> an;
            fisier.ignore();
            fisier >> cantitate;
            fisier.ignore();
            fisier >> pret;
            fisier.ignore();
            fisier.getline(pr.nume_producator, 30, ',');
            fisier.ignore();
            if (strcmp(nume, nume_cautat) == 0)
            {
                produs_gasit = true;
                cout <<left<< setw(5) << cod;
                cout <<left<< setw(20) << nume;
                cout <<left<< setw(15) << culoare;
                cout <<left<< setw(15) << an;
                cout <<left<< setw(20) << cantitate;
                cout <<left<< setw(23) << pret;
                cout <<left<<setw (35) << pr.nume_producator<<endl;
            }
        }
        cout << "========================================================================================================================\n";
        fisier.close();
    }
    else
    {
        cout << "Eroare la deschiderea fisierului.\n";
    }

    if (!produs_gasit)
    {
        cout << "Produsul cu numele " << nume_cautat << " nu a fost gasit.\n";
    }
}


void produs::cautareCuloare(const char* CuloareCautata)
{
    bool produs_gasit = false;
    ifstream fisier("fisierProduse.txt");
    if (fisier.is_open())
    {
        cout << "\n\n========================================================================================================================";
        cout << "\n\n COD\tNUME\t\tCULOARE\t\tAN\t\tPRET\t\tCANTITATE\t\tPRODUCATOR\n";
        cout << "========================================================================================================================\n\n";
        producator pr;
        while (fisier.getline(cod, 10, ','))
        {
            fisier.getline(nume, 30, ',');
            fisier.getline(culoare, 15, ',');
            fisier >> an;
            fisier.ignore();
            fisier >> pret;
            fisier.ignore();
            fisier >> cantitate;
            fisier.ignore();
            fisier.getline(pr.nume_producator, 30, ',');
            fisier.ignore();
            if (strcmp(culoare, CuloareCautata) == 0)
            {
                produs_gasit = true;
                cout <<left<< setw(5) << cod;
                cout <<left<< setw(20) << nume;
                cout <<left<< setw(15) << culoare;
                cout <<left<< setw(15) << an;
                cout <<left<< setw(23) << pret;
                cout <<left<< setw(20) << cantitate;
                cout <<left<<setw (35) << pr.nume_producator<<endl;
            }
        }
        cout << "========================================================================================================================\n";
        fisier.close();
    }
    else
    {
        cout << "Eroare la deschiderea fisierului.\n";
    }

    if (!produs_gasit)
    {
        cout << "Produsul ce are culoarea " << CuloareCautata << " nu a fost gasit.\n";
    }



}

void produs::cautarePret(int PretCautat)
{

    bool produs_gasit = false;
    ifstream fisier("fisierProduse.txt");
    if (fisier.is_open())
    {
        cout << "\n\n========================================================================================================================";
        cout << "\n\n COD\tNUME\t\tCULOARE\t\tAN\t\tPRET\t\tCANTITATE\t\tPRODUCATOR\n";
        cout << "========================================================================================================================\n\n";
        producator pr;
        while (fisier.getline(cod, 10, ','))
        {
            fisier.getline(nume, 30, ',');
            fisier.getline(culoare, 15, ',');
            fisier >> an;
            fisier.ignore();
            fisier >> pret;
            fisier.ignore();
            fisier >> cantitate;
            fisier.ignore();
            fisier.getline(pr.nume_producator, 30, ',');
            fisier.ignore();
            if ( pret == PretCautat)
            {
                produs_gasit = true;
                cout <<left<< setw(5) << cod;
                cout <<left<< setw(20) << nume;
                cout <<left<< setw(15) << culoare;
                cout <<left<< setw(15) << an;
                cout <<left<< setw(23) << pret;
                cout <<left<< setw(20) << cantitate;
                cout <<left<<setw (35) << pr.nume_producator<<endl;
            }
        }
        cout << "========================================================================================================================\n";
        fisier.close();
    }
    else
    {
        cout << "Eroare la deschiderea fisierului.\n";
    }

    if (!produs_gasit)
    {
        cout << "Produsul cu pretul " << PretCautat << " nu a fost gasit.\n";
    }

}



int produs::goleste_fis(char *fisier)
{
    ifstream f;
    f.open(fisier, ios::out | ios::trunc );

    if(f.is_open())
    {
        cout<<"\n\nOperatiune realizata cu succes, fisierul este gol!";
        f.close();                      // inchide fisierul
        return 1;                       // returneaza 1 in cazul in care operatiunea de golire este efectuata cu succes
    }

    return 0;       // returneaza 0 in cazul in care operatiunea nu este efectuata cu succes
}
void produs::afis_produs()
{
    ifstream fisier("fisierProduse.txt");
    if (fisier.is_open())
    {
        cout << "\n\nUltimul produs adaugat:\n";
        producator pr;
        while (fisier.getline(cod, 10, ','))
        {
            fisier.getline(nume, 30, ',');
            fisier.getline(culoare, 15, ',');
            fisier >> an;
            fisier.ignore();
            fisier >> pret;
            fisier.ignore();
            fisier >> cantitate;
            fisier.ignore();
            fisier.getline(pr.nume_producator, 30, ',');
            fisier.ignore();
        }
        //cout << "\nCOD:\t\t" << cod << endl;
        cout << "\n\tNUME:\t\t" << nume << endl;
        cout << "\tCULOARE:\t" << culoare << endl;
        cout << "\tAN:\t\t" << an << endl;
        cout << "\tPRET:\t\t" << pret << endl;
        cout << "\tCANTITATE:\t" << cantitate << endl;
        cout << "\tPRODUCATOR:\t" << pr.nume_producator << endl;
        fisier.close();
    }
    else
    {
        cout << "Eroare la deschiderea fisierului.\n";
    }

}

