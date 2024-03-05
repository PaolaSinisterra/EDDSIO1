#include<iostream>
#include<malloc.h>
using namespace std;

struct nod
{
   int val=0;
   nod *sig;
};

nod *cab, *aux, *aux2;

int registrar(){

    if(cab==NULL){
         cab=(struct nod *)malloc(sizeof(struct nod));
         cout<<"Ingrese el valor del Nodo: ";
         cin>>cab->val;
         cab->sig=NULL;


    }else{
         aux=(struct nod *)malloc(sizeof(struct nod));
         cout<<"Ingrese el valor del Nodo: ";
         cin>>aux->val;
         aux->sig=NULL;
         aux2==cab;
         while(aux2->sig!=NULL)
            aux2=aux2->sig;
         aux2->sig=aux;
         aux2=aux=NULL;
         free(aux);
    }


return 0;
}

int mostrar(){
    
    for(aux=cab; aux!=NULL; aux=aux->sig){
    cout<<"Valor del Nodo: "<<aux->val<<endl;
    }
    return 0;
}
int main(){

    int opc=0;

    do{
        cout<<"Menu"<<endl;
        cout<<"1. REGISTRAR NODO"<<endl;
        cout<<"2. VER NODO"<<endl;
        cout<<"3. SALIR NODO"<<endl;
        cin>>opc;
        switch(opc){
            case 1: registrar(); break;
            case 2: mostrar(); break;
            case 3: cout<<"Adios"; break;
            default:cout<<"Opcion invalida";break;
        }
    }while (opc!=3);
    
    
}