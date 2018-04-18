#include "NodLS.h"
#include <iostream>

using namespace std;

//NodLS::NodLS(){
//    cout<<"Apel constructor implicit "<<this;
//    this->info = 0;
//    this->urmator = NULL;
//    cout<<" Apel constructor implicit incheiat"<<endl;
//}

NodLS::NodLS(NodLS *_urmator, int _info){
    cout<<"\nApel constructor explicit(nod): "<<this;
    this->urmator = _urmator;
    this->info = _info;
    cout<<" Apel constructor explicit incheiat(nod)"<<endl;
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
    cout<<"Informatia nod: "<<this->info<<endl;
}

NodLS::~NodLS(){
    cout<<"Apel destructor(nod) "<<this;
    cout<<" Apel destructor incheiat(nod)"<<endl;
}
