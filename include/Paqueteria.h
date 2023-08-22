#ifndef PAQUETERIA_H
#define PAQUETERIA_H
#include "Paquete.h"
#include<iostream>

using namespace std;


class Paqueteria
{
    public:
        Paquete *h;
        Paqueteria(Paquete*);
        Paqueteria();

        void insertarInicio(int, string, string, int);
        void eliminarInicio();
        void mostrar();
        void guardarArchivo();
        void recuperar();

    protected:

    private:
};

#endif // PAQUETERIA_H
