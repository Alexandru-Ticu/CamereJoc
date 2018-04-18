#include "ListaSimpluInlantuita.h"
#include <iostream>

using namespace std;

ListaSimpluInlantuita::ListaSimpluInlantuita(){
    cout<<"Apel constructor implicit: "<<this;
    this->sfarsit = new NodLS(NULL, 2);
    this->inceput = new NodLS(this->sfarsit, 1);
    cout<<" Apel constructor implicit incheiat"<<endl;
}

ListaSimpluInlantuita::ListaSimpluInlantuita(NodLS *_inceput, NodLS *_sfarsit){
    cout<<"Apel constructor explicit: "<<this;
    if(_inceput != NULL)
    {
        this->inceput = _inceput;
    }
    if(_sfarsit != NULL)
    {
        this->sfarsit = _sfarsit;
        this->sfarsit->urmator = NULL;
    }
    cout<<" Apel constructor explicit incheiat"<<endl;
}

ListaSimpluInlantuita::ListaSimpluInlantuita(const ListaSimpluInlantuita &_deCopiat){
    if(_deCopiat.inceput != NULL)
    {
        this->inceput = _deCopiat.inceput;
    }
    else{
        this->inceput = NULL;
        this->sfarsit = NULL;
    }
    if(_deCopiat.sfarsit != NULL)
    {
        this->sfarsit = _deCopiat.sfarsit;
    }
    else{
        this->sfarsit = NULL;
        this->inceput = NULL;
    }
}

ListaSimpluInlantuita::~ListaSimpluInlantuita(){
    cout<<"Apel destructor: "<<this;
    NodLS *nod;
    NodLS *aux;
    if(this->inceput != NULL && this->sfarsit!= NULL)
    {
        nod = this->inceput;
        while(nod != NULL)
        {
            aux = nod;
            nod = aux->urmator;
            delete aux;
        }
    }
    else {
        cout<<"\nLista este goala!\n";
    }
    this->inceput = NULL;
    this->sfarsit = NULL;
    cout<<" Apel destructor incheiat"<<endl;
}

void ListaSimpluInlantuita::afisareLista(){
    NodLS *aux;
    cout<<"inceput: "<<this->inceput<<"\nsfarsit: "<<this->sfarsit<<endl;
    if(this->inceput == NULL || this->sfarsit == NULL)
        cout<<"Lista este goala!"<<endl;
    else{
        for(aux = this->inceput; aux != NULL; aux = aux->urmator)
        {
            cout<<"Nodul: "<<aux<<" Informatia: "<<aux->info<<" Urmatorul: "<<aux->urmator<<endl;
        }
    }
}

void ListaSimpluInlantuita::stergePrimulNod(){
    if(this->inceput == NULL || this->sfarsit == NULL)
        cout<<"Lista este goala!"<<endl;
    else{
        NodLS *aux;
        aux = this->inceput;
        this->inceput = aux->urmator;
        delete aux;
    }
}

void ListaSimpluInlantuita::stergeUltimulNod(){
    NodLS *aux = &gasestePredecesor(*this->sfarsit);
    if(aux == this->inceput)
        this->stergePrimulNod();
    else
        if((this->inceput == NULL || this->sfarsit == NULL))
            cout<<"Lista este goala!"<<endl;
        else{
            cout<<"!!!!"<<endl;
            aux->urmator = NULL;
            delete this->sfarsit;
            this->sfarsit = aux;
        }
}

void ListaSimpluInlantuita::stergeNodDupa(NodLS& nod){
    if(&nod == this->sfarsit)
        cout<<"Nu exista nod dupa "<<&nod<<endl;
    else{
        NodLS *aux = nod.urmator;
        nod.urmator = nod.urmator->urmator;
        delete aux;
    }
}

int ListaSimpluInlantuita::getNrNoduri(){
    if(this->inceput == NULL || this->sfarsit == NULL)
        return 0;
    else{
        int k=0;
        NodLS *aux;
        for(aux = this->inceput; aux->urmator != NULL; aux = aux->urmator)
            k++;
        if(this->sfarsit != NULL && aux == this->sfarsit)
            k++;
        cout<<"\nNumar de noduri: "<<k<<endl;
        return k;
    }
}

void ListaSimpluInlantuita::adaugaPrimulNod(NodLS& nod){
    nod.urmator = this->inceput;
    this->inceput = &nod;
}

NodLS& ListaSimpluInlantuita::gasestePredecesor(NodLS& nod){
       if(this->inceput == &nod)
            return *this->inceput;
       if(this->inceput->urmator == &nod){
//            cout<<this->inceput<<"!!!"<<this->inceput->urmator<<"---"<<&nod<<endl;
            return *this->inceput;
       }
        else{
           NodLS *aux;
           for(aux = this->inceput; aux->urmator != &nod; aux = aux->urmator){}
//           cout<<"\nNodul: "<<aux<<"Informatia: "; aux->afisareNod();
           return *aux;
    }
}

void ListaSimpluInlantuita::adaugaUltimulNod(NodLS& nod){
    if(this->sfarsit == NULL || this->inceput == NULL)
    {
        this->inceput = &nod;
        this->sfarsit = &nod;
    }
    else{
        this->sfarsit->urmator = &nod;
        this->sfarsit = &nod;
        nod.urmator = NULL;
    }
}

void ListaSimpluInlantuita::adaugaNodDupa(NodLS& nod, NodLS& deAdaugat){
    NodLS *aux;
    if(this->inceput == NULL || this->sfarsit == NULL)
    {
        this->inceput = &deAdaugat;
        this->sfarsit = &deAdaugat;
    }
    else
        if(&nod == this->sfarsit) adaugaUltimulNod(deAdaugat);
        else{
            for(aux = this->inceput; aux != NULL; aux = aux->urmator)
            if(aux == &nod){
                deAdaugat.urmator = nod.urmator;
                cout<<"!!!!!";
                nod.urmator = &deAdaugat;
                break;
            }
            if(aux != &nod)
                cout<<"\nNodul nu a putut fi gasit!"<<endl;
        }

}

void ListaSimpluInlantuita::adaugaNodInainte(NodLS& nod, NodLS& deAdaugat){
    NodLS *aux, *aux2;
    if(this->inceput == NULL || this->sfarsit == NULL)
    {
        this->inceput = &deAdaugat;
        this->sfarsit = &deAdaugat;
    }
    else
        if(&nod == this->inceput) adaugaPrimulNod(deAdaugat);
        else{
            for(aux = this->inceput; aux != NULL; aux = aux->urmator)
            if(aux == &nod){
                aux2 = &gasestePredecesor(nod);
                aux2->urmator = &deAdaugat;
                deAdaugat.urmator = &nod;
                break;
            }
            if(aux != &nod)
                cout<<"\nNodul nu a putut fi gasit!"<<endl;
        }

}
