#ifndef ARBOREBINAR_H
#define ARBOREBINAR_H
#include "NodAB.h"

class ArboreBinar
{

    int n;
    NodAB* inceput;

    public:
        ArboreBinar();
        ArboreBinar(NodAB*);
        static NodAB* creareArbore(int);
        void afisarePreordine(NodAB*, int = 0);

};

#endif // ARBOREBINAR_H
