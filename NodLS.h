#ifndef NODLS_H
#define NODLS_H
#include "Inamic.h"


#include<iostream>

class NodLS
{

protected:

    friend class ListaSimpluInlantuita;
    int info;
    NodLS *urmator;
    Inamic inamic;

public:

    NodLS();
    NodLS(NodLS *_urmator, int _info);
    virtual ~NodLS();
    NodLS(const NodLS &_deCopiat);
    virtual void afisareNod();

    void setInamic(Inamic &i){
        this->inamic = i;
    }
    bool inamicViu();
    Inamic& getInamic();
    NodLS& getUrmator(){
        return *this->urmator;
    }

    NodLS& operator = (const NodLS&);
};

#endif // NODLS_H
