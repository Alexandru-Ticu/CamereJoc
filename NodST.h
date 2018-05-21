#ifndef NODST_H
#define NODST_H
#include <iostream>
using namespace std;

class NodST
{
    int plante;
    NodST* urmatorul;

    public:
        NodST();
        NodST(int, NodST* = NULL);
        ~NodST();
        void setPlante(int o){
            this->plante = o;
        }
        int getPlante(){
            return this->plante;
        }
        void setUrmator(NodST* u){
            this->urmatorul = u;
        }
        NodST* getUrmator(){
            return this->urmatorul;
        }
};

#endif // NODST_H
