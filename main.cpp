#include <iostream>
#include "ListaSimpluInlantuita.h"

using namespace std;

int main()
{
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
    return 0;
}
