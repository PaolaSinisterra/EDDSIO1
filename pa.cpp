// Librerías 
#include <iostream>
#include <string>

using namespace std;

// Estructuras
struct Nodo{
  int id; 
  string nombre;
  string apellido;
  int fechaNacimiento;

  Nodo *izquierda;
  Nodo *derecha;
  Nodo *padre;
};

struct NodoFecha{
  int fecha;

  NodoFecha *izquierda;
  NodoFecha *derecha;
  NodoFecha *padre;
};

// Prototipos
Nodo* crearNodo(int id, string nombre, string apellido, int fechaNacimiento, Nodo* padre);
void insertarNodo(Nodo*& arbol, int id, string nombre, string apellido, int fechaNacimiento, Nodo* padre);
void insertarNodoFecha(NodoFecha*& arbol, int fecha, NodoFecha* padre);

void inOrden(Nodo* arbol);
void preOrden(Nodo* arbol);
void postOrden(Nodo* arbol);

bool buscar(Nodo* arbol, int id);

void eliminar(Nodo* nodoAEliminar);
Nodo* minimo(Nodo* arbol);
void reemplazar(Nodo* arbol, Nodo* nuevoNodo);
void destruirNodo(Nodo* nodo);

// Árboles
Nodo* arbolId = NULL;
NodoFecha* arbolFecha = NULL;

// Implementación

// Crear nodo
Nodo* crearNodo(int id, string nombre, string apellido, int fechaNacimiento, Nodo* padre){
  Nodo* nuevoNodo = new Nodo();
  nuevoNodo->id = id;
  nuevoNodo->nombre = nombre;
  nuevoNodo->apellido = apellido;
  nuevoNodo->fechaNacimiento = fechaNacimiento;
  nuevoNodo->padre = padre;
  nuevoNodo->izquierda = NULL;
  nuevoNodo->derecha = NULL;

  return nuevoNodo;
}

// Insertar nodo en árbol ID
void insertarNodo(Nodo*& arbol, int id, string nombre, string apellido, int fechaNacimiento, Nodo* padre){
  
  if(arbol == NULL){
    Nodo* nuevoNodo = crearNodo(id, nombre, apellido, fechaNacimiento, padre);
    arbol = nuevoNodo;
  }
  else if(id <= arbol->id){
    insertarNodo(arbol->izquierda, id, nombre, apellido, fechaNacimiento, arbol);
  }
  else{
    insertarNodo(arbol->derecha, id, nombre, apellido, fechaNacimiento, arbol);
  }

}

// Insertar nodo en árbol fecha
void insertarNodoFecha(NodoFecha*& arbol, int fecha, NodoFecha* padre){

  if(arbol == NULL){
    NodoFecha* nuevoNodo = new NodoFecha();
    nuevoNodo->fecha = fecha;
    nuevoNodo->padre = padre;
    nuevoNodo->izquierda = NULL;
    nuevoNodo->derecha = NULL;

    arbol = nuevoNodo;
  }
  else if(fecha <= arbol->fecha){
    insertarNodoFecha(arbol->izquierda, fecha, arbol);
  }
  else{
    insertarNodoFecha(arbol->derecha, fecha, arbol);
  }

}

// Recorrido inorden
void inOrden(Nodo* arbol){
  
  if(arbol == NULL) return;

  inOrden(arbol->izquierda);

  cout << arbol->id << " ";

  inOrden(arbol->derecha);

} 

// Recorrido preorden
void preOrden(Nodo* arbol){

  if(arbol == NULL) return;

  cout << arbol->id << " ";

  preOrden(arbol->izquierda);

  preOrden(arbol->derecha);

}

// Recorrido postorden
void postOrden(Nodo* arbol){

  if(arbol == NULL) return;

  postOrden(arbol->izquierda);

  postOrden(arbol->derecha);

  cout << arbol->id << " ";

}

// Buscar nodo
bool buscar(Nodo* arbol, int id){
  
  if(arbol == NULL) return false;

  if(arbol->id == id) return true;

  if(id < arbol->id){
    return buscar(arbol->izquierda, id);
  }
  else{
    return buscar(arbol->derecha, id);
  }

}

// Eliminar nodo
void eliminar(Nodo* nodoAEliminar){

  if(nodoAEliminar->izquierda && nodoAEliminar->derecha){
    
    Nodo* menor = minimo(nodoAEliminar->derecha);
    nodoAEliminar->id = menor->id;
    eliminar(menor);

  }
  else if(nodoAEliminar->izquierda){
    
    reemplazar(nodoAEliminar, nodoAEliminar->izquierda);
    destruirNodo(nodoAEliminar);

  }
  else if(nodoAEliminar->derecha){

    reemplazar(nodoAEliminar, nodoAEliminar->derecha);
    destruirNodo(nodoAEliminar);

  }
  else{

    reemplazar(nodoAEliminar, NULL);
    destruirNodo(nodoAEliminar);

  }

}

// Encontrar nodo más izquierdo
Nodo* minimo(Nodo* arbol){

  if(arbol == NULL) return NULL;

  if(arbol->izquierda) return minimo(arbol->izquierda);

  return arbol;

}

// Reemplazar nodos
void reemplazar(Nodo* arbol, Nodo* nuevoNodo){

  if(arbol->padre){

    if(arbol->padre->izquierda == arbol) {
      arbol->padre->izquierda = nuevoNodo;
    }
    else if(arbol->padre->derecha == arbol){
      arbol->padre->derecha = nuevoNodo; 
    }

  }

  if(nuevoNodo) nuevoNodo->padre = arbol->padre;

}

// Destruir nodo
void destruirNodo(Nodo* nodo){

  nodo->izquierda = NULL;
  nodo->derecha = NULL;

  delete nodo;

}

// Menú
void menu(){

  int id;
  string nombre, apellido; 
  int fechaNacimiento;

  int opcion = 0;

  while(opcion != 5){

    cout << "Menú: " << endl;
    cout << "1. Insertar Nodo" << endl;
    cout << "2. Mostrar InOrden" << endl;
    cout << "3. Buscar Nodo" << endl;
    cout << "4. Eliminar Nodo" << endl;
    cout << "5. Salir" << endl;

    cin >> opcion;

    if(opcion == 1){
      
      // Pedir datos
      // Llamar insertarNodo

    }
    else if(opcion == 2){

      // Llamar inOrden

    }
    else if(opcion == 3){

      // Pedir ID
      // Llamar buscar

    }
    else if(opcion == 4){

      // Pedir ID
      // Llamar eliminar

    }

  }

}

int main(){

  menu();

  return 0;

}
