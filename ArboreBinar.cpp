#include "ArboreBinar.h"
#include "NodAB.h"
#include <iostream>

using namespace std;

ArboreBinar::ArboreBinar()
{

}

ArboreBinar::ArboreBinar(NodAB* inceput)
{
    this->inceput = inceput;
}

NodAB* ArboreBinar::creareArbore(int n){

    int NS, ND;
    NodAB* nodNou;
    if(n==0)
    {
        return NULL;
    }
    else{

        NS = n/2;
        ND = n-NS-1;
        nodNou = new NodAB();
        nodNou->nodS = ArboreBinar::creareArbore(NS);
        nodNou->nodD = ArboreBinar::creareArbore(ND);
        return nodNou;
    }
}

void ArboreBinar::afisarePreordine(NodAB* aux, int nivel){

    if(aux!=NULL){
        aux->setNivel(nivel);
        cout<<*aux<<endl;
        afisarePreordine(aux->nodS, nivel+1);
        afisarePreordine(aux->nodD, nivel+1);
    }
}
