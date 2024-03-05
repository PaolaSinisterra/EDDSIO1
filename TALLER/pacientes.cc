#include<iostream>
#include<malloc.h>
using namespace std;

struct pacientes
{
    int valor = 0;
    pacientes *siguiente;
};

pacientes *cabeza, *auxiliar1, *auxiliar2;

int registro(){
    if(cab==NULL){
        cabeza=(struct pacientes *)malloc(sizeof(struct pacientes));
    }
}
