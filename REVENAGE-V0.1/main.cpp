#include <iostream>
#include <ctime>
#include <cstdlib>
#include "string.h"

#include "rlutil.h"
using namespace std;
using namespace rlutil;

#include "funciones.h"

int main(){
srand(time(NULL));
setColor(BLACK);
setBackgroundColor(GREY);
cls();
int const VALOR=13;
int dado[VALOR]={};
int acumulador [2]{};
int dadosj [2]{};
int orden [2]{};
int puntos [2]{};
int dados_elegidos[12]{};
int contador_dados[12]{};
int totaldado12 [2]{};
int opcion,vuelta=0,x,j, bandera=0;
float maximo;

    char jugador1 [4];
    char jugador2 [4];
    char sorteo1 [4];
    char sorteo2 [4];
    dadosj[0]=6;
    dadosj[1]=6;
    orden[0]=1;
    orden[1]=1;


    do
    {
    menu();
    cin>> opcion;
    cls();
        switch (opcion)
        {
        case 1:
            system("cls");
            puntos[0]=0;
            puntos[1]=0;
            dadosj[0]=6;
            dadosj[1]=6;
            jugar( sorteo1,  sorteo2);
            for (j=1;j<6;j++){
                    if(puntos[0]<10000 &&puntos[1]<10000){
                    cout<<"comienza la ronda  " <<j<<": el jugador "<<sorteo1<<"  total de puntos  "<< puntos[0]<<endl;
                    orden [0]=0;
                    ronda(dadosj, orden,acumulador,totaldado12,dados_elegidos, contador_dados);
                    puntaje (dadosj, totaldado12, dados_elegidos, acumulador, contador_dados, puntos, orden);
                    orden [0]=1;
                    acumulador[0]=0;
                    }
                    if(puntos[0]<10000 &&puntos[1]<10000){
                    cout<<"comienza la ronda  " <<j<<": el jugador.. "<<sorteo2<<"  total de puntos  "<< puntos[1]<<endl;
                    orden [1]=0;
                    ronda(dadosj,orden, acumulador, totaldado12, dados_elegidos, contador_dados);
                    puntaje (dadosj, totaldado12, dados_elegidos, acumulador, contador_dados, puntos, orden);
                    orden[1]=1;
                    acumulador[0]=0;
                    }
            }

            cout<<"ganador del juego fue"<<endl;
            if(puntos[0]>puntos[1]){
                cout<<sorteo1<<endl<<endl<<endl;
            }
            else{
                if(puntos[1]>puntos[0]){
                    cout<<sorteo2<<endl<<endl<<endl;
                }
            }
            break;
            case 2:
            system("cls");
            if(bandera==0) {
                if(puntos[0]>puntos[1]) {
                    cout << "---------Estadisticas:------------"<<endl;
                    cout<<" el ganador con mas puntos es:";
                    for(int p=0; p<4; p++) {
                        cout<<sorteo1[p];
                    }
                    cout<<endl;
                    maximo=puntos[0];
                    bandera=1;
                    cout<<" total de puntos de :"<<maximo<<endl;
                }
            } else {
                if(puntos[0]>maximo) {
                    maximo=puntos[0];
                    cout<<" total de puntos de :"<<maximo<<endl;
                }
            }
                if(bandera==0) {
                    if(puntos[1]>puntos[0]) {
                        cout << "---------Estadisticas:------------";
                        cout<<" el ganador con mas puntos es: ";
                        for(int p=0; p<4; p++) {
                            cout<<sorteo2[p];
                        }
                        cout<<endl;
                        maximo=puntos[1];
                        bandera=1;
                        cout<<" total de puntos de :"<<maximo<<endl;
                    }
                } else {
                    if(puntos[1]>maximo) {
                        maximo=puntos[1];
                        cout<<" total de puntos de :"<<maximo<<endl;
                    }
                }
            break;

            case 3:
           system("cls");
    cout << " _____________________________________________________" << endl;
    cout << "|                   CREDITOS                          |" << endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "|                 ALUMNOS Y LEGAJOS                   |"<< endl;
    cout << "|                                                     |"<< endl;
    cout << "|                 ARAMBURU IGNACIO, 24463             |"<< endl;
    cout << "|                 FROIMAN HERMAN, 25099               |"<< endl;
    cout << "|                 MACIEL NICOLAS, 24290               |"<< endl;
    cout << "|                 TOARA LEONARDO, 22245               |"<< endl;
    cout << "|_____________________________________________________|" << endl;
    cout << "||" << endl<<endl<<endl<<endl;
            break;
            volver();
            }
    }
        while(opcion!=0);

return 0;
}
