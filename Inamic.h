#ifndef INAMIC_H
#define INAMIC_H
#include <iostream>

using namespace std;

class Inamic
{
private:
    float viata, atac;
    int exp;


public:
    Inamic(float, float, int);
    Inamic();


    void setViata(float v){
        this->viata = v;
    }
    void setAtac(float a){
        this->atac = a;
    }
    void setExp(int e){
        this->exp = e;
    }

    float getViata(){
        return this->viata;
    }
    float getAtac(){
        return this->atac;
    }
    int getExp(){
        return this->exp;
    }

    friend ostream& operator<<(ostream&, const Inamic&);

};

#endif // INAMIC_H
