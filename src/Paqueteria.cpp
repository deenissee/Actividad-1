#include "Paqueteria.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include<stdlib.h>

Paqueteria::Paqueteria()
{
    h=nullptr;
    //ctor
}
void Paqueteria::insertarInicio(int id, string origen, string dest, int peso)
{
    Paquete *tmp=new Paquete(id, origen,dest, peso,nullptr);

    if(!h)
    {
        h=tmp;
    }
    else
    {
        tmp->sig=h;
        h=tmp;
    }
}
void Paqueteria::eliminarInicio()
{
    Paquete *aux=h;

    if(aux==h)
    {
        h=h->sig;
        delete aux;
    }
}
void Paqueteria::mostrar()
{
    Paquete *aux=h;

    if(h)
    {
        while(aux)
        {
            cout<<"ID:"<<aux->id<<endl;
            cout<<"Origen:"<<aux->origen<<endl;
            cout<<"Destino:"<<aux->dest<<endl;
            cout<<"Peso:"<<aux->peso<<endl<<endl;
            aux=aux->sig;
        }
    }
    else
    {
        cout<<"Lista vacia"<<endl;
    }
}
void Paqueteria::guardarArchivo()
{
    ofstream archivo;
    archivo.open("prueba.txt", ios::out); //Abriendo el archivo

    if(archivo.fail())
    {
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }

    Paquete* aux=h;
        while(aux!=nullptr)//Escribir datos de los paquetes en el archivo
        {
            archivo<<aux->id<<","<<aux->origen<<","<<aux->dest<<","<<aux->peso<<endl;
            aux=aux->sig;
        }
    archivo.close(); //cerrar archivo

}
void Paqueteria::recuperar()
{
    //Abrir el archivo
    ifstream archivo("prueba.txt");
    if(archivo.fail())
    {
        cout<<"Error al abrir el archivo "<<endl;
        return;
    }

    if(archivo.is_open())
    {
        cout<<"Se agregaron los paquetes del archivo a la paqueteria"<<endl;
        //Recorrer el archivo línea por línea
        string texto;
    while(getline(archivo, texto))
        {
        //Se usará stringstream para almacenar los datos de la texto en un buffer en memoria que actuará como archivo simulado
        stringstream ss(texto);
        //Leer los campos de la línea separados por comas
        string idStr, origen, dest, pesoStr;
        getline(ss, idStr, ',');
        getline(ss, origen, ',');
        getline(ss, dest, ',');
        getline(ss, pesoStr, ',');

        /*Convertir los datos de texto a valores enteros
        (Numero de ID y peso)*/
        int id=stoi(idStr);
        int peso=stoi(pesoStr);

        //Insertar paquete en la lista
        insertarInicio(id, origen, dest, peso);
        }
    }
}
