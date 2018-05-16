#ifndef LISTASIMPLUINLANTUITA_H
#define LISTASIMPLUINLANTUITA_H

#include "NodLS.h"

class ListaSimpluInlantuita
{
    NodLS *inceput, *sfarsit;

public:

    //constructor implicit
    ListaSimpluInlantuita();

    //constructor explicit
    ListaSimpluInlantuita(NodLS *_inceput, NodLS *_sfarsit);

    //destructor
    ~ListaSimpluInlantuita();

    //constructor de copiere
    ListaSimpluInlantuita(const ListaSimpluInlantuita &_deCopiat);


    NodLS& getInceput(){
        return *this->inceput;
    }
    NodLS& getSfarsit(){
        return *this->sfarsit;
    }
    void afisareLista();

    void stergePrimulNod();
    void stergeUltimulNod();
    void stergeNodDupa(NodLS& nod);

    int getNrNoduri();
    NodLS& gasestePredecesor(NodLS& nod);

    void adaugaPrimulNod(NodLS& nod);
    void adaugaUltimulNod(NodLS& nod);
    void adaugaNodDupa(NodLS& nod, NodLS& deAdaugat);
    void adaugaNodInainte(NodLS& nod, NodLS& deAdaugat);

    ListaSimpluInlantuita& operator= (const ListaSimpluInlantuita&);
};

#endif // LISTASIMPLUINLANTUITA_H
