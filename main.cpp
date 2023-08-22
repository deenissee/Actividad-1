#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
#include "Paqueteria.h"

using namespace std;

int main()
{
    int opc, id;
    string origen, dest, narchivo;
    int peso;

    Paqueteria *pa=new Paqueteria();

    do{
        cout<<      "Menu"<<endl;
        cout<<"1-Agregar paquete"<<endl;
        cout<<"2-Eliminar paquete"<<endl;
        cout<<"3-Mostrar"<<endl;
        cout<<"4-Guardar"<<endl;
        cout<<"5-Recuperar"<<endl;
        cout<<"6-Salir"<<endl;
        cin>>opc;
        system("cls");

        switch(opc)
        {
            case 1:
                cout<<"Agregar paquete"<<endl;
                cout<<"ID:"<<endl;
                cin>>id;
                cout<<"Origen:"<<endl;
                cin>>origen;
                cout<<"Destino:"<<endl;
                cin>>dest;
                cout<<"Peso:"<<endl;
                cin>>peso;

                pa->insertarInicio(id,origen,dest,peso);
                system("cls");
                break;
            case 2:
                pa->eliminarInicio();
                break;
            case 3:
                pa->mostrar();
                system("pause");
                break;
            case 4:
                pa->guardarArchivo();
                cout<<"Se guardaron los datos en.txt"<<endl;
                break;
            case 5:
                pa->recuperar();
                break;
        }
    }while(opc!=6);
}

/*cout<<"Nombre del archivo:"<<endl;
                cin>>narchivo;
                pa->guardarArchivo(narchivo + ".txt");
                cout<<"Se guardaron los datos en "<<narchivo<<".txt"<<endl;
                break;

cout<<"Escribe el nombre del archivo a recuperar: ";
                cin>>narchivo;
                pa->recuperar(narchivo + ".txt");
                break;
                */
