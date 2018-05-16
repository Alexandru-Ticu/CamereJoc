#ifndef STIVA_H
#define STIVA_H
#include "NodST.h"


class Stiva
{
    int maxim, curent;
    NodST* varf;

    public:
        Stiva();
        ~Stiva();
        int getCurent(){
            return this->curent;
        }
        int getMaxim(){
            return this->maxim;
        }
        void addNod(NodST*);

        NodST* getVarf(){
            return this->varf;
        }
        void popV();
};

#endif // STIVA_H
