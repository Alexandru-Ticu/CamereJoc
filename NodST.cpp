#include "NodST.h"
#include <iostream>

using namespace std;

NodST::NodST()
{
    this->plante = 0;
    this->urmatorul = NULL;
}

NodST::NodST(int plante, NodST* urmatorul){
    this->plante = plante;
    this->urmatorul = urmatorul;
}

NodST::~NodST()
{

}
