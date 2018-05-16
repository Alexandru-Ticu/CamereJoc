#ifndef NODAB_H
#define NODAB_H
#include <iostream>

using namespace std;

class NodAB
{

    friend class ArboreBinar;
    static int nrNoduri;
    int cheie, nivel;
    NodAB *nodS, *nodD;

    public:
        NodAB();
        NodAB(NodAB*, NodAB*);
        NodAB(const NodAB& deCopiat);
        NodAB& operator=(const NodAB&);
        virtual ~NodAB();
        int getCheie(){
            return this->cheie;
        }
        friend ostream& operator<<(ostream&, const NodAB&);
        void setNivel(int n){
            this->nivel = n;
        }
};

#endif // NODAB_H
