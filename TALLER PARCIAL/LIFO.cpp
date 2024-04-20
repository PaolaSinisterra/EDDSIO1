/*
Tengo un parqueadero de callejón con ocupación para moto y carro. 
Los cuales se parquean en sistema lifo. Los carros tienen un valor de parqueo de 1000 y las motos de 500, 
pero al retirarlos cada movimiento adicional de vehículo cuesta 100 para carro y 50 para moto. 
Calcular el valor delegando en x momento de día
*/

#include <iostream>
using namespace std;
#include <malloc.h> 

struct carro{

int cantidad;
char nomPro [50];
char apePro[50];
char placa[50];
int ID;
carro *sig;

};

carro *cab, *aux;

struct moto{

int cantidad;	
char nomPro [50];
char apePro[50];
char placa[50];
int ID;
moto *sig2;

};

moto *cab2, *aux2;

void registrar();
void calcular();
void mostrar(); 
void retirar();

 int valorRetiro = 0;



void registrar(){

    int opc;

    cout<<"\n\tMENU\n";
    cout<<"\t\n1. Carro";
    cout<<"\t\n2. Moto\n";
    cout<<"\nDigite el tipo de vehiculo que desea registrar:";
    cin>>opc;


    if(opc==1){

    aux = (struct carro *)malloc(sizeof(struct carro)); 
    cout<<"\nDigite la placa del carro: ";
    cin>>aux->placa;
    cout<<"Digite el ID del carro: "<<endl;
    cin>>aux->ID;
    cout<<"Digite el nombre del usuario: ";
    cin>>aux->nomPro;
    cout<<"Digite el apellido del usuario: ";
    cin>>aux->apePro;



    if(cab==NULL){

      aux->cantidad=1;
      cab=aux;
      cab->sig=NULL;
    }

    else{

      aux->cantidad=aux->cantidad+1;
      aux->sig=cab;
      cab=aux;
    }

    aux=NULL;
    free(aux);

    }


    if(opc==2){

  aux2 = (struct moto *)malloc(sizeof(struct moto)); 	

  cout<<"\nDigite la placa de la moto: ";
    cin>>aux2->placa;
    cout<<"Digite el ID de la moto: ";
    cin>>aux2->ID;
    cout<<"Digite el nombre del usuario: ";
    cin>>aux2->nomPro;
    cout<<"Digite el apellido del usuario: ";
    cin>>aux2->apePro;


    if(cab2==NULL){

      cab2=aux2;
      cab2->sig2=NULL;
    }

    else{

      aux2->sig2=cab2;
      cab2=aux2;
    }

    aux2=NULL;
    free(aux2);
    }


}

void calcular(){
    int totalCarros = 0;
    int totalMotos = 0;
    int valorTotal = 0;
    // Nuevo valor para almacenar el valor total de las retiradas

    carro *temporalCarro = cab;
    while(temporalCarro != NULL){
        totalCarros++;
        temporalCarro = temporalCarro->sig;
    }

    moto *temporalMoto = cab2;
    while(temporalMoto != NULL){
        totalMotos++;
        temporalMoto = temporalMoto->sig2;
    }

    // Calcular el valor total del parqueadero sumando el valor de los vehículos y las retiradas
    valorTotal = totalCarros * 1000 + totalMotos * 500;
    valorTotal = valorTotal+valorRetiro;

    cout << "\nHay un total de " << totalCarros << " carros en el parqueadero.";
    cout << "\nHay un total de " << totalMotos << " motos en el parqueadero.";
    cout << "\nEl valor total del parqueadero en este momento, incluyendo las retiradas, es: " << valorTotal << " pesos." << endl;

}

void mostrar(){

  cout<<"\nMostrando los carros que hay en el parquadero:\n";

  aux=cab;
  while(aux!=NULL){

  cout<<"\nPlaca de carro: "<<aux->placa;
  cout<<"\nID de carro: "<<aux->ID;
  cout<<"Nombre del propietario: "<<aux->nomPro <<aux->apePro;
  aux=aux->sig;

  }

  cout<<"\n\nMostrando las motos que hay en el parquadero:\n";

  aux2=cab2;
  while(aux2!=NULL){

  cout<<"\nPlaca de moto: "<<aux2->placa;
  cout<<"\nID de moto: "<<aux2->ID<<"\n";
  cout<<"Nombre del propietario: "<<aux2->nomPro <<aux2->apePro;
  aux2=aux2->sig2;

  }
}


void retirar(){
    int opc;
    int id;
    bool found = false;
   

    cout<<"\n\tMENU DE RETIRO\n";
    cout<<"\n\t1. Retirar carro";
    cout<<"\n\t2. Retirar moto\n";
    cout<<"\nDigite el tipo de vehiculo que desea retirar: ";
    cin>>opc;

    cout<<"\nDigite el ID del vehículo que desea retirar: ";
    cin>>id;

    if(opc == 1) {
        carro *temporalCarro = cab;
        carro *anteriorCarro = NULL;
        while(temporalCarro != NULL){
            if(temporalCarro->ID == id){
                cout << "\nSe ha encontrado el carro con ID " << id << ". Retirando carro..." << endl;
                found = true;

                if (anteriorCarro == NULL) {
                    cab = temporalCarro->sig;
                } else {
                    anteriorCarro->sig = temporalCarro->sig;
                }

                valorRetiro = 100; // Costo de retirar un carro
                break; // Found the carro, no need to continue searching
            }
            anteriorCarro = temporalCarro;
            temporalCarro = temporalCarro->sig;
            free(anteriorCarro);
        }

        if(!found){
            cout << "\nNo se encontró ningún carro con el ID proporcionado." << endl;
        }

    } else if(opc == 2) {
        moto *temporalMoto = cab2;
        moto *anteriorMoto = NULL;
        while(temporalMoto != NULL){
            if(temporalMoto->ID == id){
                cout << "\nSe ha encontrado la moto con ID " << id << ". Retirando moto..." << endl;
                found = true;

                if (anteriorMoto == NULL) {
                    cab2 = temporalMoto->sig2;

                } else {
                    anteriorMoto->sig2 = temporalMoto->sig2;
                }

                valorRetiro = 50; // Costo de retirar una moto
                break; // Found the moto, no need to continue searching
            }
            anteriorMoto = temporalMoto;
            temporalMoto = temporalMoto->sig2;
            free(anteriorMoto);
        }

        if(!found){
            cout << "\nNo se encontró ninguna moto con el ID proporcionado." << endl;
        }

    } else {
        cout << "\nOpción inválida. Por favor seleccione una opción válida (1 o 2)." << endl;
    }

    // Mostrar el valor a pagar por el retiro
    cout << "El valor a pagar por el retiro es: " << valorRetiro << " pesos." << endl;
}

int main(){

  int opc=0;

  do{

  cout<<"\n\tMENU\n";

  cout<<"\n\t1. Registrar\n";
  cout<<"\t2. Calcular\n";
  cout<<"\t3. Mostrar\n";
  cout<<"\t4. Retirar\n";
  cout<<"\t5. Salir\n";
  cout<<"\nDigite la opcion que desea realizar: ";
  cin>>opc;

  switch(opc){

  case 1: 
    registrar(); break;

  case 2: 
    calcular(); break;

  case 3: 
    mostrar(); break;	

  case 4: 
    retirar(); break;
  case 5:
    cout<<"\nGracias por usar nuestro programa... Saliendo\n";	
      cout<<"...finalized...";
      break;

  default:

    cout<<"\nLa opcion que digitaste no se encuentra disponible, por favor digite la opcion nuevamente: \n";
    break;
  }

  }while(opc!=5);


  return 0;
}
