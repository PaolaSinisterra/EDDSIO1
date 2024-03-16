#include <iostream>
#include <malloc.h>

using namespace std;

struct Producto {
    int id;
    char nombre[50];
    int cantidad;
    float precio;
};

struct nodo
{
  Producto producto;
  nodo* siguiente
};

nodo* a=NULL;
nodo* b=NULL;

int registar(){
    nodo* nuevonodo=(nodo*)malloc(sizeof(nodo));

    cout<<"\nIngrese el ID del producto a registrar: ";
    cin>>nuevonodo->producto.id;

    cout<<""


return 0;
}


