#include "Caracter.h"
#include <iostream>

using namespace std;

Caracter::Caracter(){
    this->nrPlante = 0;
    int i = 19;
    this->potiuni = 1;
    this->atac = 40;
    this->viata = 1000;
    this->maxViata = 1000;
    this->exp = 0;
    this->nivel = 0;
    this->maxExp = 50;
    this->rucsac = new NodST[20];
    this->rucsac[19].setPlante(0);
    this->rucsac[19].setUrmator(NULL);
    for(i = 18; i>=0; i--)
    {
        this->rucsac[i].setPlante(0);
        this->rucsac[i].setUrmator(&this->rucsac[i+1]);
    }
}

void Caracter::lvlUp(){
    while(this->exp >= maxExp){
        this->maxViata += 1000;
        this->viata = this->maxViata;
        cout<<"Ati crescut in nivel!"<<endl;
        this->nivel ++;
        this->exp = this->exp - this->maxExp;
        this->maxExp = this->maxExp * 2;
    }
}

ostream& operator<<(ostream& out, const Caracter& c){
    out<<"Nivel: "<<c.nivel<<", maxExp: "<<c.maxExp<<", exp: "<<c.exp<<", atac: "<<c.atac<<", viata: "<<c.viata;
    return out;
}

void Caracter::afisareRucsac(){

    int k = 0;
    int i;
    for(i=0; i<20; i++)
    {
        if(this->rucsac[i].getPlante() != 0)
            k++;
    }
    if(k==0)
        cout<<"Nu aveti plante!"<<endl;
    else cout<<"Aveti "<<k<<" plante!"<<endl;
    cout<<"Aveti :"<<this->potiuni<<" potiuni!"<<endl;
}

void Caracter::folosestePotiune(){
    if(this->potiuni <= 0)
    {
        cout<<"Nu aveti potiuni!"<<endl;
    }
    else{
        cout<<"Ati folosit o potiune! ";
        this->potiuni--;
        this->viata = this->maxViata;
    }
}

void Caracter::crafteazaPotiuni(){
    int k=0;
    int i;
    for(i=0; i<=19; i++)
    {
        if(this->rucsac[i].getPlante() != 0)
        {
            k++;
            this->rucsac[i].setPlante(0);
            this->craft.addNod(&rucsac[i]);
        }
        if(this->craft.getCurent() == this->craft.getMaxim())
        {
            this->potiuni++;
            cout<<"Ati craftat o potiune! "<<endl;
            this->craft.popV();
            this->craft.popV();
            break;

        }
    }
}

int Caracter::getPlante(){
    int k = this->nrPlante;
    int i;
    for(i=0; i<20; i++)
    {
        if(this->rucsac[i].getPlante() != 0)
            k++;
    }
    return k;
}
