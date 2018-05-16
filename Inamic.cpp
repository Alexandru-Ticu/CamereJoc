#include "Inamic.h"
#include <iostream>

using namespace std;

Inamic::Inamic(){
    this->viata = 100;
    this->atac = 1;
    this->exp = 10;
}

Inamic::Inamic(float viata, float atac, int exp)
{
    this->viata = viata;
    this->atac = atac;
    this->exp = exp;
}

ostream& operator<<(ostream& out, const Inamic& i){
    out<<"(viata: "<<i.viata<<", atac: "<<i.atac<<", exp: "<<i.exp<<")";
    return out;
}
