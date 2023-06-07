#include <iostream>
#include <fstream>
#include "producator.h"
#include "produs.h"          // include fisierul unde se gaseste clasa
#include <stdio.h>          // librarie pentru fflush(stdin)
#include <windows.h>        //biblioteca pentru consola
#include <conio.h>          // biblioteca pentru getch()
#define COLOR_SELECTED 13
#define COLOR_DEFAULT 15
#define  ESC  0x1b          // defineste ESC ca iesire ( exit(0) )


using namespace std;

void Text (int op)
{
    HANDLE hConsole;
    hConsole=GetStdHandle(STD_OUTPUT_HANDLE);

    cout<<endl<<"   ";

    cout<<(char)201;        // colt stanga sus
    for(int i=0; i<45; i++) // linie tranversala
        cout<<(char)205;
    cout<<(char)187;        //colt dreapta sus
    cout << endl;           // randul urmator

    if(op==1)       // optiunea 1
        SetConsoleTextAttribute(hConsole, COLOR_SELECTED);
    cout<<"     1. Adauga produs   \n   ";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);

    if(op==2)       // optiunea 2
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);
    cout<<"  2. Afisare produs \n   ";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);

    if(op==3)       // optiunea 3
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);

    cout<<"  3. Afisare stoc \n";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);

    if(op==4)       // optiunea 4
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);

    cout<<"     4. Cautare produs dupa nume(model) \n";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);

    if(op==5)       // optiunea 5
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);

    cout<<"     5. Cautare produs dupa culoare\n";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);

    if(op==6)       // optiunea 6
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);
    cout<<"     6. Cautare produs dupa pret \n  ";

    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);
    if(op==7)       //optiunea 7
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);

    cout<<"   7. Modifica produs \n";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);
    if(op==8)       // optiunea 8
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);

    cout<<"     8. Goleste stoc \n   ";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);

    if(op==9)
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);

    cout<<"  9. Ghid de utilizare  \n   ";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);

    if(op==10)
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);

    cout<<" 10. Informatii autor  \n   ";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);

    if(op==11)
        SetConsoleTextAttribute(hConsole,COLOR_SELECTED);

    cout<<" 11. Iesire  \n   ";
    SetConsoleTextAttribute(hConsole,COLOR_DEFAULT);

    cout<<(char)200;         // colt stanga jos
    for(int i=0; i<45; i++)  // linie orizontala
        cout<<(char)205;
    cout<<(char)188;        // colt dreapta jos

}
int Optiune()
{
    int op=1;
    char c;
    do
    {
        system("cls");
        Text(op);           // afiseaza textul + optiunea activa
        if((c=getch())==0)  //asteapta apasarea unei taste
            c=getch();

        if( c==72)      // la apasarea sagetii sus cursorul se muta in sus
            op--;       // 72 - cod pentru sus

        if(c==80)       // la apasarea sagetii jos cursorul se muta in jos
            op++;       // 80 - cod pentru jos

        if(op==0)       // trecerea de la prima la ultima optiune
            op=11;

        if(op==12)       // trecerea de la ultima la prima optiune
            op=1;

        if(c==ESC)      // iesirea din program
            exit(0);
    }
    while(c!='\r');         // c!= enter
    return op;
}
int main()
{

    char fisier[]="fisierProduse.txt";
    producator pr;
    produs p;
    //reateDirectory("fisierProduse.txt", NULL);
    do
    {
        fflush(stdin);          //goleste bufferul
        switch( Optiune() )
        {
        case 1:
            cout<<"\n\n\n Adaugare produs\n\n";
            p.add_produs();
            pr.add_producator();
            p.scrie_fis();
            pr.scrie_fisier();
            getch();
            break;
        case 2:
            p.afis_produs();
            getch();
            break;
        case 3:
            p.afis_stoc();
            getch();
            break;
        case 4:
        {

            char numeCautat[15];
            cout << "\nIntroduceti numele produsului: ";
            cin.getline(numeCautat,15);
            p.cauta_produs_dupa_nume(numeCautat);

        }
        getch();
        break;
        case 5:
        {
            char CuloareCautata[15];
            cout << "\nIntroduceti culoarea pe care o cautati: ";
            cin.getline(CuloareCautata, 15);
            p.cautareCuloare(CuloareCautata);
        }
        getch();
        break;
        case 6:
        {
             int PretCautat;
             cout << "\nIntroduceti pretul pe care il cautati: ";
             cin>>PretCautat;
             p.cautarePret(PretCautat);
        }
        getch();
        break;
        case 7:
        {

            p.modifica_produs();

        }
        getch();
        break;

        case 8:
            if( p.goleste_fis(fisier)==0)
                cout<<"\nFisierul nu exista."<<endl;

            getch();
            break;


        case 9:
            cout<<"\n1.Optiunea <<Adauga produs>>"
                "\n         *permite adaugarea unui produs nou in stocul magazinului"
                "\n\n2.Optiunea <<Afisare produs>>"
                "\n         *ne permite sa vizualizam ultimul produs adaugat in lista"
                "\n\n3.Optiunea <<Afisare stoc>>  "
                "\n         *permite afisarea tuturor produselor"
                "\n\n4.Optiunea <<Cautare produs dupa nume(model)>> "
                "\n         *permite cautarea si afisarea unor produse dupa numele dorit"
                "\n\n5.Optiunea <<Cautare produs dupa culoare>> "
                "\n         *permite cautarea si afisarea unor produse dupa culoarea dorita"
                "\n\n6.Optiunea <<Cautare produs dupa pret>> "
                "\n         *permite cautarea si afisarea unor produse dupa pretul dorit"
                "\n\n7.Optiunea <<Modifica produs>> "
                "\n         *permite modificarea datelor referitoare la produs"
                "\n\n8.Optiunea <<Goleste stoc>> "
                "\n         *permite stergerea datelor din fisierul de intare,fisierul de iesire sau din baza de date a magazinului"
                "\n\n9.Optiunea <<Ghid de utilizare>>"
                "\n         *permite accesul la informatii despre utilizarea programului"
                "\n\n10.Optiunea <<Informatii autor>> "
                "\n         *permite utilizatorului sa acceseze datele referitoare la autorul programului"
                "\n\n11.Optiunea <<Iesire>> "
                "\n         *permite parasirea programului curent";

            getch();
            break;
        case 10:

            cout<<"\n\n   ================================================="<<endl;
            cout<<"   ----- Proiect Gestiunea unui magazin online -----"<< endl << endl;
            cout<<"     Proiect realizat de ->  Bondar Irina"<< endl;
            cout<<"     Universitatea       ->  Stefan cel Mare - Suceava"<< endl;
            cout<<"     Facultatea          ->  FIESC"<< endl;
            cout<<"     Specializarea       ->  Calculatoare"<< endl;
            cout<<"     Grupa               ->  3121"<< endl;
            cout<<"     Semigrupa           ->  A"<< endl;
            cout<<"   =================================================";


            getch();
            break;
        case 11:            // reprezinta iesirea din aplicatie
        {
            cout<<"\n\nApasati enter pentru iesirea din aplicatie !";
            cout<<endl;
            cout<<endl;
            return 0;
        }
        }


    }
    while(!0);

    return 0;
}


