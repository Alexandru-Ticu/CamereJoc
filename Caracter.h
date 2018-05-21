#ifndef CARACTER_H
#define CARACTER_H
#include <iostream>
#include "NodST.h"
#include "Stiva.h"

using namespace std;

class Caracter
{
protected:
    float viata, atac, maxViata;
    int exp, nivel, maxExp, potiuni, nrPlante;
    NodST *rucsac;
    Stiva craft;

public:
    Caracter();

    void setViata(float v){
        this->viata = v;
    }
    void setAtac(float a){
        this->atac = a;
    }
    void setExp(int e){
        this->exp = e;
    }

    float getViata(){
        return this->viata;
    }
    float getAtac(){
        return this->atac;
    }
    int getExp(){
        return this->exp;
    }

    void lvlUp();
    void afisareRucsac();

    void setPotiuni(int p){
        this->potiuni = p;
    }
    int getPotiuni(){
        return this->potiuni;
    }
    void folosestePotiune();
    friend ostream& operator<<(ostream&, const Caracter&);

    NodST* getRucsac(){
        return this->rucsac;
    }
    void crafteazaPotiuni();

    int getPlante();

    bool isAlive(){
        return (this->viata <= 0)?false:true;
    }
};

#endif // CARACTER_H
