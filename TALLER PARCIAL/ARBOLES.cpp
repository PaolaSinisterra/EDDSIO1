#include<iostream>
#include<malloc.h>
using namespace std;

struct nodo
{
    int val=0;
    nodo *izq;
    nodo *dere;

};
nodo *raiz, *aux, *aux2;

int posicionar(){
    if(aux->val< aux2->val){
    if(aux2->izq!=NULL){
        aux2=aux2->izq; 
           posicionar();
    }
    else 
        aux2->izq=aux;
    }
    else if(aux->val > aux2->val){
        if(aux2->dere!=NULL){
        aux2=aux2->dere; 
           posicionar();
    }
    else
        aux2->dere=aux;
}
return 0;
}
int registrar(){
    aux=(struct nodo *)malloc(sizeof(struct nodo));
    cout<<"Valor: ";
    cin>>aux->val;
    aux->izq = aux->dere=NULL;

    if(raiz==NULL){
        raiz=aux;
        aux=NULL;
        free(aux);
    }
    else{
        posicionar();
    }

    return 0;
}

int preorden(nodo *recursive){
    cout<<"Valor: "<<recursive->val<<endl;
    if(recursive->izq!=NULL){
         preorden(recursive->izq);}
    if(recursive->dere!=NULL){
        preorden(recursive->dere);}
        return 0;
    

}

int recorrer(){
aux=raiz;
if(aux !=NULL){
    preorden(aux);
}

return 0;
}

int main(){
    int opc=0;
    do{

        cout<<"1. Registar"<<endl;
        cout<<"2. Recorrer"<<endl;
        cout<<"3. Salir"<<endl;
        cin>>opc;

        switch (opc)
        {
        case 1: registrar();
            break;
        case 2:recorrer();
            break;
        
        
        }


    }while (opc!=3);
    
    
return 0;
}
