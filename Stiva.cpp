#include "Stiva.h"

Stiva::Stiva()
{
    this->maxim = 2;
    this->curent = 0;
}

Stiva::~Stiva()
{

}

void Stiva::addNod(NodST* nod){
    this->varf = nod;
    this->curent++;
}

void Stiva::popV(){
    this->curent --;
    this->varf = this->varf->getUrmator();
}
