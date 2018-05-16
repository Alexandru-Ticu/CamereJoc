#include "NodAB.h"
#include <iostream>

using namespace std;

NodAB::NodAB(){
    this->cheie = NodAB::nrNoduri;
    NodAB::nrNoduri++;
    this->nodD = NULL;
    this->nodS = NULL;
}

NodAB::NodAB(NodAB* s, NodAB* d)
{
    this->cheie = NodAB::nrNoduri;
    NodAB::nrNoduri ++;
    this->nodS = s;
    this->nodD = d;
}

NodAB::~NodAB()
{
    //dtor
}

NodAB::NodAB(const NodAB& deCopiat){
    this->cheie = deCopiat.cheie;
    this->nodD = deCopiat.nodD;
    this->nodS = deCopiat.nodS;
}

NodAB& NodAB::operator = (const NodAB& deCopiat){
    if(this != &deCopiat)
    {
        this->cheie = deCopiat.cheie;
        this->nodD = deCopiat.nodD;
        this->nodS = deCopiat.nodS;
    }
    return *this;
}

ostream& operator<<(ostream& out, const NodAB& nod){
    if(nod.nodD != NULL && nod.nodS != NULL)
        out<<"Nod: "<<nod.cheie<<", Nivel: "<<nod.nivel<<", nodS: "<<nod.nodS->cheie<<", nodD: "<<nod.nodD->cheie;
    else if(nod.nodD != NULL)
        out<<"Nod: "<<nod.cheie<<", Nivel: "<<nod.nivel<<", nodD: "<<nod.nodD->cheie;
    else if(nod.nodS != NULL)
        out<<"Nod: "<<nod.cheie<<", Nivel: "<<nod.nivel<<", nodS: "<<nod.nodS->cheie;
    else out<<"Nod: "<<nod.cheie<<", Nivel: "<<nod.nivel;
    return out;
}
