//#include "Heap.h"
//#include <iostream>
//
//using namespace std;
//Heap::Heap()
//{
//    this->marime = 0;
//}
//
//Heap::~Heap()
//{
//    //dtor
//}
//
//void Heap::schimba(int copil, int parinte){
//
//    NodH aux;
//    aux = nod[copil];
////    nod[copil] = nod[parinte];
//    nod[parinte] = aux;
//}
//
//int Heap::getParinte(int copil){
//
//    if(copil%2 == 0)
//        return (copil/2)-1;
//    else return copil/2;
//}
//
//int Heap::getStanga(int parinte){
//
//    return 2*parinte +1;
//}
//
//int Heap::getDreapta(int parinte){
//
//    return 2*parinte +1;
//}
//
//void Heap::addNod(NodH deAdaugat){
//
//    this->nod[this->marime++] = deAdaugat;
//    HeapS();
//}
//
//void Heap::HeapS(){
//
//    int copil = this->marime - 1;
//    int parinte = getParinte(copil);
//
//    while(nod[copil].scor > nod[parinte].scor && copil >= 0 && parinte >= 0){
//
//        schimba(copil, parinte);
//        copil = parinte;
//        parinte = getParinte(copil);
//    }
//}
//
//void Heap::afiseaza(){
//
//    for(int i = 0; i < this->marime; i++)
//        cout<<"Nume: "<<this->nod[i].nume<<endl<<"scor: "<<this->nod[i].scor<<endl;
//}
