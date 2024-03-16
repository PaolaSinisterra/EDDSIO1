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
  nodo* siguiente;
};

nodo* a=NULL;
nodo* b=NULL;

int registar(){
    nodo* cabeza=(nodo*)malloc(sizeof(nodo));

    cout<<"\nIngrese el ID del producto a registrar: ";
    cin>>cabeza->producto.id;

    cout<<"Ingrese el nombre del producto";
    cin>>cabeza->producto.nombre;

    cout<<"Ingrese la cantidad: ";
    cin>>cabeza->producto.cantidad;

    cout<<"Ingrese el precio por unidad del producto: ";
    cin>>cabeza->producto.precio;

    cabeza->siguiente=NULL;

    if (b==NULL)
    {
        a=b=cabeza;
    }else{
        b->siguiente=cabeza;
        b=cabeza;
    }
    
    
cout<<"El producto se registro exitosamente.\n";

return 0;
}

int mostrar(){
    nodo* produc=a;

    if(produc==NULL){
        cout<<
    }
}


