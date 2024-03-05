#include<iostream>
using namespace std;

int main(){

    int a;
    int b=0;
    int c[4]={25,26,27,28};
    a=b;
    int *apunta=&a;
    *apunta=3;
    apunta=&b;
    *apunta=13;
    apunta=&c[a];
    *apunta=20;

    return 0;
}