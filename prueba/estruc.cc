#include<iostream>
using namespace std;

    struct estruc
    {
        int codigo;
        int telefono;
        char nombres[30];
    }aux, aux2[3];

    struct estruc aux3;
    
    int main(){
        //aux.codigo=12300266;
        //aux.telefono=3163345;
        //aux2[0].codigo=12300177;
        //aux2[1].codigo=12300786;
        //cout<<sizeof(struct estruc);
        //cout<<aux.codigo;

        aux2[0].codigo=111;
        aux2[1].codigo=222;
        aux2[2].codigo=333;
        cout<<&aux2[0]<<endl;
        cout<<&aux2[1]<<endl;
        cout<<&aux2[2]<<endl;
        

        


    return 1;
    }
    


