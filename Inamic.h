#ifndef INAMIC_H
#define INAMIC_H
#include <iostream>

using namespace std;

class Inamic
{
private:
    float viata, atac;
    int exp;
    int puncte;


public:
    Inamic(float, float, int, int);
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
    int getPuncte(){
        return this->puncte;
    }
    void setPuncte(int p){
        this->puncte = p;
    }

    friend ostream& operator<<(ostream&, const Inamic&);

};

#endif // INAMIC_H
