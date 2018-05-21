#include <iostream>
#include "NodLS.h"
#include "ListaSimpluInlantuita.h"
#include "Caracter.h"
#include "Inamic.h"
#include <stdlib.h>
#include <string.h>
#include "NodAb.h"
#include "ArboreBinar.h"
#include "Stiva.h"

using namespace std;

int NodAB::nrNoduri = 1;
int scor = 0;

void ataca(Caracter&, Inamic&);
ListaSimpluInlantuita& initCamere(int n);
void joacaJoc(Caracter&, ListaSimpluInlantuita&);

int main()
{
    int i;
    Caracter caracterMain;
    ListaSimpluInlantuita lista;
    lista = initCamere(100);


    joacaJoc(caracterMain, lista);


//    NodAB* inceput = ArboreBinar::creareArbore(8);
//    ArboreBinar arbore(inceput);
//    cout<<*inceput<<endl;
//    arbore.afisarePreordine(inceput);

    return 0;
}

void joacaJoc(Caracter& caracterMain, ListaSimpluInlantuita& lista){
    char *s;
    int k=1;
    NodLS *nodCurent = new NodLS();
    nodCurent = &lista.getInceput();
//    nodCurent->afisareNod();

    while(nodCurent != &lista.getSfarsit()){

        while(nodCurent->inamicViu() && caracterMain.isAlive())
        {

            cout<<"Caracter: "<<caracterMain<<endl;
            if(nodCurent->getInamic().getViata() != 0)
                    cout<<"(Inamic "<<k<<") "<<nodCurent->getInamic()<<endl<<endl;
            cout<<"Urmatoarea actiune: "<<endl;
            cout<<"Ataca: (a)"<<endl;
            cout<<"Foloseste potiune ("<<caracterMain.getPotiuni()<<" potiuni): (f)"<<endl;
            cin>>s;
            if(strcmp(s, "a") == 0){
                system("cls");
                ataca(caracterMain, nodCurent->getInamic());
//                cout<<"Caracter: "<<caracterMain<<endl;
//                if(nodCurent->getInamic().getViata() != 0)
//                    cout<<"(Inamic "<<k<<") "<<nodCurent->getInamic()<<endl;
            }
            else if(strcmp(s, "f") == 0){
                caracterMain.folosestePotiune();
                cout<<"Mai aveti :"<<caracterMain.getPotiuni()<<" potiuni."<<endl<<endl;
//                cout<<"Caracter: "<<caracterMain<<endl;
//                if(nodCurent->getInamic().getViata() != 0)
//                    cout<<"(Inamic "<<k<<") "<<nodCurent->getInamic()<<endl;
            }
            else{
                cout<<"Comanda nerecunoscuta!"<<endl;
            }

        }
        if(!caracterMain.isAlive()){
                break;
            }
        else{
            cout<<"Inamic infrant!"<<endl;
            caracterMain.getRucsac()[k-1].setPlante(1);
            k++;
            scor = nodCurent->getInamic().getPuncte();
            cout<<endl<<"Urmatoarea actiune: "<<endl;
            cout<<"Afisati cursacul: (ar)"<<endl;
            cout<<"Inspectati caracterul: (ic)"<<endl;
            cout<<"Inaintati in camera urmatoare: (i)"<<endl;
            cout<<"Foloseste potiune ("<<caracterMain.getPotiuni()<<" potiuni): (f)"<<endl;
            cout<<"Craftati potiuni: (c)"<<endl;
            cin>>s;
            while(strcmp(s, "i") != 0){
                if(strcmp(s, "ar") == 0)
                    {
                        cout<<"Se afiseaza rucsacul! "<<endl;
                        caracterMain.afisareRucsac();
                        cout<<endl<<"Urmatoarea actiune: "<<endl;
                        cout<<"Afisati cursacul: (ar)"<<endl;
                        cout<<"Inspectati caracterul: (ic)"<<endl;
                        cout<<"Inaintati in camera urmatoare: (i)"<<endl;
                        cout<<"Foloseste potiune ("<<caracterMain.getPotiuni()<<" potiuni): (f)"<<endl;
                        cout<<"Craftati potiuni: (c)"<<endl;
                        cin>>s;
                    }
                else if(strcmp(s, "ic") == 0)
                    {
                        cout<<"Se afiseaza caracterul: "<<endl<<caracterMain<<endl;
                        cout<<endl<<"Urmatoarea actiune: "<<endl;
                        cout<<"Afisati cursacul: (ar)"<<endl;
                        cout<<"Inspectati caracterul: (ic)"<<endl;
                        cout<<"Inaintati in camera urmatoare: (i)"<<endl;
                        cout<<"Foloseste potiune ("<<caracterMain.getPotiuni()<<" potiuni): (f)"<<endl;
                        cout<<"Craftati potiuni: (c)"<<endl;
                        cin>>s;
                    }
                else  if(strcmp(s, "f") == 0){
                    caracterMain.folosestePotiune();
                    cout<<endl<<"Mai aveti :"<<caracterMain.getPotiuni()<<" potiuni."<<endl;
                    cout<<"Caracter: "<<caracterMain<<endl;
                    cout<<endl<<"Urmatoarea actiune: "<<endl;
                    cout<<"Afisati cursacul: (ar)"<<endl;
                    cout<<"Inspectati caracterul: (ic)"<<endl;
                    cout<<"Inaintati in camera urmatoare: (i)"<<endl;
                    cout<<"Foloseste potiune ("<<caracterMain.getPotiuni()<<" potiuni): (f)"<<endl;
                    cout<<"Craftati potiuni: (c)"<<endl;
                    cin>>s;
                }
                else if(strcmp(s, "c") == 0){
                    if(caracterMain.getPlante() > 1)
                        caracterMain.crafteazaPotiuni();
                    else{cout<<"Nu aveti destule plante!"<<endl;}
                    cout<<endl<<"Urmatoarea actiune: "<<endl;
                    cout<<"Afisati cursacul: (ar)"<<endl;
                    cout<<"Inspectati caracterul: (ic)"<<endl;
                    cout<<"Inaintati in camera urmatoare: (i)"<<endl;
                    cout<<"Foloseste potiune ("<<caracterMain.getPotiuni()<<" potiuni): (f)"<<endl;
                    cout<<"Craftati potiuni: (c)"<<endl;
                    cin>>s;
                }
                else{
                    cout<<"Comanda necunoscuta!"<<endl;
                    cin>>s;
                }
            }
        }
        system("cls");
            if(!caracterMain.isAlive()){
                break;
            }
        if(nodCurent != &lista.getSfarsit())
            nodCurent = &nodCurent->getUrmator();
    }
    if(!caracterMain.isAlive()){
        cout<<"Ati fost infrant!"<<endl;
        cout<<"Scor: "<<scor<<endl;
    }else{
        cout<<caracterMain<<endl;
        system("cls");
        cout<<"Ultima camera! "<<endl;
         while(nodCurent->inamicViu() && caracterMain.isAlive())
            {
                cout<<"Caracter: "<<caracterMain<<endl;
                if(nodCurent->getInamic().getViata() != 0)
                        cout<<"(Inamic "<<k<<") "<<nodCurent->getInamic()<<endl;
                cout<<endl<<"Urmatoarea actiune: "<<endl;
                cout<<"Ataca: (a)"<<endl;
                cout<<"Foloseste potiune ("<<caracterMain.getPotiuni()<<" potiuni): (f)"<<endl;
                cin>>s;
                if(strcmp(s, "a") == 0){
                    system("cls");
                    ataca(caracterMain, nodCurent->getInamic());
    //                cout<<"Caracter: "<<caracterMain<<endl;
    //                if(nodCurent->getInamic().getViata() != 0)
    //                    cout<<"(Inamic "<<k<<") "<<nodCurent->getInamic()<<endl;
                }
                else if(strcmp(s, "f") == 0){
                    system("cls");
                    caracterMain.folosestePotiune();
                    cout<<"Mai aveti :"<<caracterMain.getPotiuni()<<" potiuni."<<endl;
                }
                else{
                    cout<<"Comanda nerecunoscuta!"<<endl;
                }
            }
            if(!caracterMain.isAlive()){
                cout<<"Ati fost infrant!"<<endl;
                cout<<"Scor: "<<scor<<endl;
            }
            else{
                cout<<"Inamic infrant!"<<endl;
                k++;
                cout<<"Scor: "<<scor<<endl;
            }
    }
}

void ataca(Caracter& caracterMain, Inamic& inamic){

    caracterMain.lvlUp();
    if(inamic.getViata() > 0 && caracterMain.isAlive())
    {
        inamic.setViata(inamic.getViata() - caracterMain.getAtac());
        if(inamic.getViata() > 0)
        {
            caracterMain.setViata(caracterMain.getViata() - inamic.getAtac());
        }
        else{
            caracterMain.setExp(caracterMain.getExp() + inamic.getExp());
            inamic.setViata(0);
        }
    }
    else if(inamic.getViata() <= 0){
        cout<<"Inamicul a fost deja infrant!"<<endl;
    }else if(!caracterMain.isAlive()){
        cout<<"Ati fost infrant!";
        cout<<"Scorul: "<<scor<<endl;
    }
    caracterMain.lvlUp();
}

ListaSimpluInlantuita& initCamere(int n){
    int i;
    NodLS **camere = new NodLS*[n];
    camere[n-1] = new NodLS(NULL, n-1);
    Inamic *inamic = new Inamic[n];

    for(i=n-2; i>=0; i--)
    {
        camere[i] = new NodLS(camere[i+1], i);
    }

    for(i=0; i<=n-1; i++)
    {
        inamic[i].setAtac(i*100+10);
        inamic[i].setViata(100+i*10);
        inamic[i].setExp(i*10 + 25);
        inamic[i].setPuncte(i*10+100);
        camere[i]->setInamic(inamic[i]);
    }

    ListaSimpluInlantuita *lista = new ListaSimpluInlantuita(camere[0], camere[n-1]);
//    lista->afisareLista();
    return *lista;
}


void randFunc(){

        ListaSimpluInlantuita *lista = new ListaSimpluInlantuita();
    NodLS *nod1 = new NodLS(NULL, 3);
    NodLS *nod2 = new NodLS(NULL, 4);
    lista->afisareLista();

    cout<<"Adauga primul nod!"<<endl;
    lista->adaugaPrimulNod(*nod1);
    lista->afisareLista();
    lista->adaugaPrimulNod(*nod2);
    lista->afisareLista();

    cout<<"Sterge primul nod!"<<endl;
    lista->stergePrimulNod();
    lista->afisareLista();

    lista->stergePrimulNod();
    lista->afisareLista();

    lista->stergePrimulNod();
    lista->afisareLista();

    lista->stergePrimulNod();
    lista->afisareLista();

    NodLS *nod3 = new NodLS(NULL, 5);
    NodLS *nod4 = new NodLS(NULL, 6);
    NodLS *nod5 = new NodLS(NULL, 7);
    NodLS *nod6 = new NodLS(NULL, 8);
    cout<<"Adauga ultimul nod!"<<endl;
    lista->adaugaUltimulNod(*nod3);
    lista->afisareLista();
    lista->adaugaNodDupa(*nod3, *nod4);
    lista->afisareLista();
    lista->adaugaNodDupa(*nod4, *nod5);
    lista->afisareLista();

    cout<<"Adauga nod inainte!"<<endl;
    NodLS *nod7 = new NodLS(NULL, 9);
    NodLS *nod8 = new NodLS(NULL, 10);
    lista->adaugaNodInainte(*nod5, *nod7);
    lista->adaugaNodInainte(*nod4, *nod8);
    lista->afisareLista();
    cout<<"!!!"<<endl;
    lista->afisareLista();
    lista->stergeUltimulNod();
    cout<<"!!!"<<endl;
    lista->afisareLista();
    lista->stergeUltimulNod();
    cout<<"!!!"<<endl;
    lista->afisareLista();
    lista->stergeUltimulNod();
    cout<<"!!!"<<endl;
    lista->afisareLista();
    lista->stergeUltimulNod();
    cout<<"!!!"<<endl;
    lista->afisareLista();
    lista->stergeUltimulNod();
    cout<<"!!!"<<endl;
    lista->afisareLista();
    delete lista;

}
