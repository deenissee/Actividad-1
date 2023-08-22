#include "Paquete.h"

Paquete::Paquete()
{
    id=0;
    origen="";
    dest="";
    peso=0;
    sig=nullptr;
    //ctor
}
Paquete::Paquete(int id, string origen, string dest, int peso,Paquete *sig)
{
    this->id=id;
    this->origen=origen;
    this->dest=dest;
    this->peso=peso;
    this->sig=sig;
}
