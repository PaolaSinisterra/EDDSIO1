#include<iostream>
using namespace std;

int main(){

    int a= 1;
    char b[2]={'b','c'};
    char *apuntador;
    char *apu2;

    apuntador=&b[0];
    apu2=&b[1];

    cout<<&a<<endl;
    cout<<"Posicion 0: " << &apuntador<<endl;
     cout<<"Posicion 1: " << &apu2<<endl;
    return 0;
}