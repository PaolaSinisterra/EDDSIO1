#include<iostream>
#include<malloc.h>
using namespace std;

struct nodo
{
    int val=0;
    nodo *izq;
    nodo *der;
    int id;
    int naci;
    char nombre[50];
    char apellido[50];


};

nodo *raiz, *raiz2, *aux, *aux2;




int registrar(){

    aux = (nodo *)malloc(sizeof(nodo));
    cout<<"Ingrese el nombre del estudiante: ";
    cin>>aux->nombre;
    cout<<"Ingrese el apellido del estudiante: ";
    cin>>aux->apellido;
    cout<<"Ingrese el documento del estudiante: ";
    cin>>aux->id;
    cout<<"Ingrese la fecha de nacimiento del estudiante (DIA/MES/AÑO sin espacios): ";
    cin>>aux->naci;

   

    if(raiz==NULL){
        raiz=aux;
        aux=NULL;
    }
    else{
        posicionar();
    }

    return 0;
}

int posicionar() {
    if (raiz == NULL) {
        raiz = aux;
    } else {
        aux2 = raiz;
        while (aux2 != NULL) {
            if (aux->val < aux2->val) {
                if (aux2->izq != NULL) {
                    aux2 = aux2->izq;
                } else {
                    aux2->izq = aux;
                    break;
                }
            } 
            else if (aux->val > aux2->val) {
                if (aux2->der != NULL) {
                    aux2 = aux2->der;
                } else {
                    aux2->der = aux;
                    break;
                }
            }
        }
    }
    return 0;
}

int mostrar(nodo *raiz){

    if(raiz!=NULL){

    cout<<"LISTADO DE LOS ESTUDIANTES REGISTRADOS";

  
    
    cout<<"Nombre: "<<raiz->nombre<<endl;
    cout<< "Apellido: "<<raiz->apellido<<endl;
    cout<<"ID: "<<raiz->id;
    cout<<"Fecha de nacimiento (DIA/MES/AÑO): "<<raiz->naci;

    
    }

    return 0;
}

int buscar(){

    return 0;
}

int eliminar(){

    return 0;
}


int main(){

    int opc=0;

    do{

        cout<<"BIENVENIDO AL MENU"<<endl;
        cout<<"1. REGISTRAR"<<endl;
        cout<<"2. MOSTRAR"<<endl;
        cout<<"3. BUSCAR"<<endl;
        cout<<"4. ELIMINAR"<<endl;
        cout<<"INGRESE LA OPCION QUE DESEA REALIZAR: ";
        cin>>opc;

        switch (opc)
        {
        case 1: registrar();
            break;

        case 2: mostrar(raiz);
            break;

        case 3: buscar();
            break;

        case 4: eliminar();
            break;
        
        default: "OPCION NO VALIDA";
            break;
        }
        
    }while (opc!=4);
    

    return 0;
}