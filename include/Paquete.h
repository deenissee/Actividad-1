#ifndef PAQUETE_H
#define PAQUETE_H
#include<iostream>

using namespace std;


class Paquete
{
    public:
        int id;
        string origen;
        string dest;
        int peso;
        Paquete *sig;

        Paquete();
        Paquete(int,string,string, int, Paquete*);

    protected:

    private:
};

#endif // PAQUETE_H
