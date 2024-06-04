#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
    Nodo *padre;
};

//Prototipos
void menu();

Nodo *crearNodo(int, Nodo *);

void insertarNodo(Nodo *&, int, Nodo *);

void mostrarArbol(Nodo *, int);

bool busqueda(Nodo *, int);

void preOrden(Nodo *);

void inOrden(Nodo *);

void postOrden(Nodo *);

void eliminar(Nodo *, int);

void eliminarNodo(Nodo *);

Nodo*minimo(Nodo *);

void reemplazar(Nodo* , Nodo *);

void destruirNodo(Nodo *);

Nodo *arbol=NULL;



int main(){

    menu();


    getch();
    return 0;
}

//Funcion de menu
void menu(){
    int dato, opcion, contador=0;

    do{
        cout<<"\t.:MENU:."<<endl;
        cout<<"1. Insertar un nuevo nodo"<<endl;
        cout<<"2. Mostrar arbol completo"<<endl;
        cout<<"3. Buscar un elemento en el arbol"<<endl;
        cout<<"4. Recorrer el arbol en pre-Orden"<<endl;
        cout<<"5. Recorrer el arbol en in-Orden"<<endl;
        cout<<"6. Recorrer el arbol en post-Orden"<<endl;
        cout<<"7. Eliminar un nodo del arbol"<<endl;
        cout<<"8. Salir"<<endl;
        cout<<"OPCION: ";
        cin>>opcion;

        switch (opcion)
        {
        case 1: cout<<"\nDigite un numero: ";
                cin>>dato;
                insertarNodo(arbol,dato, NULL);//Insertamos un nuevo nodo
                cout<<"\n";
                system("pause");
            break;

        case 2: cout<<"\nMostrando el arbol completo..."<<endl;
                mostrarArbol(arbol,contador);
                cout<<"\n";
                system("pause");
                break;
        
        case 3: cout<<"\nDigite el elemento a buscar: ";
                cin>>dato;
                if(busqueda(arbol,dato)==true){
                    cout<<"\nElemento "<<dato<<" ha sido encontrado en el arbol"<<endl;
                }
                else{
                    cout<<"\nElemento no encontrado\n";
                }
                cout<<"\n";
                system("pause");
                break;

        case 4: cout<<"\nRecorrido en Pre-Orden: \n";
                preOrden(arbol);
                cout<<"\n\n";
                system("pause");
                break;
        
        case 5: cout<<"\nRecorrido en In-Orden: \n";
                inOrden(arbol);
                cout<<"\n\n";
                system("pause");
                break;

        case 6: cout<<"\nRecorrido en Post-Orden: \n";
                postOrden(arbol);
                cout<<"\n\n";
                system("pause");
                break;

        case 7: cout<<"\nDigite el numero a eliminar: ";
                cin>>dato;
                eliminar(arbol,dato);
                cout<<"\n";
                system("pause");
                break;
        }
        system("cls");
    }while (opcion!=8);
   
    
}

//Funcion para crear nuevo nodo
Nodo *crearNodo(int n, Nodo *padre){
    Nodo *nuevo_nodo=new Nodo();

    nuevo_nodo->dato=n;
    nuevo_nodo->der=NULL;
    nuevo_nodo->izq=NULL;
    nuevo_nodo->padre;

    return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol

void insertarNodo(Nodo *&arbol, int n, Nodo *padre){

    if(arbol==NULL){//si el arbol esta vacip
        Nodo * nuevo_nodo=crearNodo(n, padre);
        arbol=nuevo_nodo;
    }
    else{//si el arbol tiene un nodo o mas
        int valorRaiz=arbol->dato;//obtenemos el valor de la raiz
        if(n<valorRaiz){//Si el elemento es enor a la raiz se inserta en la izquierda
            insertarNodo(arbol->izq,n, padre);
        }
        else{//si el elemneto es mayor a la raiz se oinserta a la derecha
            insertarNodo(arbol->der,n, padre);
        }
    }

}

//Funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbol,int cont){
    if(arbol==NULL){//Si el arbol esta vacio
       return;
    }
    else{
        mostrarArbol(arbol->der,cont+1);
        for(int i=0;i<cont;i++){
            cout<<"   ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq,cont+1); 
    }
}

//Funcion para buscar un elemento en el arbol
bool busqueda(Nodo *arbol, int n){
    if(arbol==NULL){//si el arbol esta vacio
        return false;
    }
    else if(arbol->dato==n){//Si el nodo es igual al elemento retorna verrdadero
        return true;
    }
    else if(n<arbol->dato){
        return busqueda(arbol->izq,n);
    }
    else{
        return busqueda(arbol->der,n);
    }
}

//Funcion para recorrer en Pre-Orden

void preOrden(Nodo *arbol){
    if(arbol==NULL){//Si el arbol esta vacio
    return;
    }
    else{
        cout<<arbol->dato<<" - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
}

//Funcion para recorrer en in-orden

void inOrden(Nodo *arbol){
    if(arbol==NULL){//Si el arbol esta vacio
    return;
    }
    else{
        inOrden(arbol->izq);
        cout<<arbol->dato<<" - ";
        inOrden(arbol->der);
    }
}

//Funcion para recorrer en Post-Orden
void postOrden(Nodo *arbol){
    if(arbol==NULL){//Si el arbol esta vacio
    return;
    }
    else{
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->dato<<" - ";
    }
}

//Funcion para eliminar
void eliminar(Nodo *arbol, int n){
    if(arbol==NULL){//si el arbol esta vacio
        return;
    }
    else if(n<arbol->dato){//Si el valor es menor
        eliminar(arbol->izq,n);//Busca por la izquierda
    }
    else if(n>arbol->dato){//Si el valor es mayor
        eliminar(arbol->der,n);//Busca por la derecha
    }
    else{//Si ya encontro el valor
        eliminarNodo(arbol);
    }
}

//Funcion para determinar el nodo mas izqierdo posible
Nodo *minimo(Nodo *arbol){
    if(arbol==NULL){//Si el arbol esta nulo
        return NULL;//retorna nulo
    }
    if(arbol->izq){//Si tiene hijo izquerdo
        return minimo(arbol->izq);//buscamos la parte izquierda
    }
    else{//Si no tiene hijo izquierdo
        return arbol;//retorna el mismo nodo
    }
}

//Funcion para reemplazar dos nodos
void reemplazar(Nodo *arbol, Nodo *nuevoNodo){
     if(arbol->padre){
         //arbol->padre hay que asignarle su nuevo hijo
        if(arbol->dato==arbol->padre->izq->dato){
            arbol->padre->izq=nuevoNodo;
        }
        else if (arbol->dato==arbol->padre->der->dato){
            arbol->padre->der=nuevoNodo;
        }
        {

        }
     }
     if(nuevoNodo){
        //Procedemos a asignarle su nuevo padre
        nuevoNodo->padre=arbol->padre;
     }
}

//Funcion para destruir un ndo
void destruirNodo(Nodo *nodo){
    nodo->izq=NULL;
    nodo->der=NULL;

    delete nodo;
}

//Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
    if(nodoEliminar->izq&&nodoEliminar->der){//Si tiene hijo derecho y tiene hijo izquierdo
      Nodo *menor=minimo(nodoEliminar->der);
      nodoEliminar->dato=menor->dato;
      eliminarNodo(menor);
    }
    else if(nodoEliminar->izq){//Si tiene hijo izquierdo
          reemplazar(nodoEliminar, nodoEliminar->izq);
          destruirNodo(nodoEliminar);
    }
    else if(nodoEliminar->der){//si tiene hijo derecho
        reemplazar(nodoEliminar, nodoEliminar->der);
        destruirNodo(nodoEliminar);
    }
    else{//Si el nodo no tiene hijos
        reemplazar(nodoEliminar, NULL);
        destruirNodo(nodoEliminar);
    }
}
