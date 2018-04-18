#ifndef NODLS_H
#define NODLS_H

#include<iostream>

class NodLS
{
    friend class ListaSimpluInlantuita;
    int info;
    NodLS *urmator;

public:

    NodLS(NodLS *_urmator = NULL, int _info = 0);
    ~NodLS();
    NodLS(const NodLS &_deCopiat);
    void afisareNod();
};

#endif // NODLS_H
