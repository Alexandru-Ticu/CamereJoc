#include "NodLS.h"
#include <iostream>
#include "Inamic.h"


using namespace std;

NodLS::NodLS(){
//    cout<<"Apel constructor implicit "<<this;
    this->info = 0;
    this->urmator = NULL;
//    cout<<" Apel constructor implicit incheiat"<<endl;
}
NodLS::NodLS(NodLS *_urmator, int _info){
//    cout<<"\nApel constructor explicit(nod): "<<this;
    this->urmator = _urmator;
    this->info = _info;
    this->inamic = inamic;
//    cout<<" Apel constructor explicit incheiat(nod)"<<endl;
}

NodLS::NodLS(const NodLS &_deCopiat){
    cout<<"Apel constructor copiere: "<<this;
    if(&_deCopiat != NULL)
    {
        this->urmator = _deCopiat.urmator;
        this->info = _deCopiat.info;
    }
    else{
        cout<<"Apel constructor de copiere nereusit."<<endl;
    }
    cout<<"Apel constructor copiere incheiat."<<endl;
}

void NodLS::afisareNod(){
    cout<<"Informatia nod: "<<this->info<<", nod: "<<this<<endl;
}

NodLS::~NodLS(){
//    cout<<"Apel destructor(nod) "<<this;
//    cout<<" Apel destructor incheiat(nod)"<<endl;
}

NodLS& NodLS::operator = (const NodLS& deCopiat){
    if(this != &deCopiat)
    {
        this->urmator = deCopiat.urmator;
        this->info = deCopiat.info;
        this->inamic = deCopiat.inamic;
    }
      return *this;
}


bool NodLS::inamicViu(){
    if(this->inamic.getViata() > 0)
        return true;
    return false;
}

Inamic& NodLS::getInamic(){
    return this->inamic;
}
