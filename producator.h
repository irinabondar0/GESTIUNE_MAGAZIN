#ifndef PRODUCATOR_H
#define PRODUCATOR_HD
#include <fstream>  //pentru fisiere
#include <string.h> //pentru strcmp
using namespace std;
class producator
{
public:
    char nume_producator[30];//numele producatorului
    producator();   //constructorul
    void add_producator(); //functie ce adauga producatorul in baza de date
    void scrie_fisier(); //functie ce salveaza produsul introdus in fisier
    virtual ~producator(); //destructorul
};


#endif // PRODUCATOR_H_INCLUDED
