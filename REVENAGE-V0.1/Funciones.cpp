#include <iostream>
#include <ctime>
#include "string.h"
#include <cstdlib>
#include "rlutil.h"
#include <windows.h>

using namespace std;
using namespace rlutil;

#include "funciones.h"

void menu(){
        cout << "REVENGE" << endl;
        cout << "-----------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS " << endl;
        cout << "3 - CREDITOS " << endl;

        cout << "-----------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << "-----------------------" << endl; }

void jugar(char sorteo1[], char sorteo2[]){
    srand(time(NULL));
    int const VALOR=13;
    int dado[VALOR]= {};
    int opcion, ganador_sorteo=0;
    char jugador1 [4];
    char jugador2 [4];



        cout << "-----------------------" << endl;
        cout << "Ingrese jugador 1, 3 caracteres: ";
        cin >> jugador1;
        cout << "Ingrese jugador 2, 3 caracteres: ";
        cin >> jugador2;
        cls();

    while(ganador_sorteo==0) {

        lanzamiento_dados6 (dado);/*funcion para tirar dados*/
        Sleep(1500);
        cout << "Dado de seis caras jugador1: " << dado[0] << endl;
        cout << "Dado de seis caras jugador2: " << dado[1] << endl;
        cout << endl << "------------------" << endl;

        if (dado[0]>dado[1]) {
            cout << "Jugador 1 gana el saque!: ";
            cout << jugador1;
            ganador_sorteo++;
            for(int x=0;x<5;x++){
                    sorteo1[x]=jugador1[x];
                    sorteo2[x]=jugador2[x];
                }
            cout << endl << "------------------" << endl;
        } else {
            if (dado[0]<dado[1]) {
                cout << "Jugador 2 gana el saque: ";
                cout << jugador2;
                ganador_sorteo++;
                for(int x=0;x<5;x++){
                    sorteo1[x]=jugador2[x];
                    sorteo2[x]=jugador1[x];
                }
                cout << endl << "------------------" << endl;
            } else {
                if(dado[0]==dado[1]) {
                    cout<<"se repite el sorteo"<<endl;
                    cout << endl << "------------------" << endl;
                }
            }
        }
    }
}
void lanzamiento_dados12 (int dado[])
    {
        int x;
        for( x=0; x<11; x++)
        {
            dado[x]=1+rand ()%12;
        }
    }
void lanzamiento_dados6 (int dado[])
    {
        int x;
        for( x=0; x<11; x++)
        {
            dado[x]=1+rand ()%6;
        }
    }

void ronda(int dadosj[], int orden [],int acumulador[], int totaldado12[], int dados_elegidos [],int contador_dados[]){
    srand(time(NULL));
    int const VALOR=13;
    int dado[VALOR]= {};
    int opcion, ganador_sorteo=0, eleccion,x;
    char jugador1 [4];
    char jugador2 [4];
    char sorteo1 [4];
    char sorteo2 [4];

    cout<<"------------------------------------"<<endl;
    lanzamiento_dados12 (dado);
    Sleep(1500);
    cout<<"Tirada de dados de 12 caras: "<<dado[0]<<"-"<<dado[1]<<endl;
    totaldado12[0]=dado[0]+dado[1];
    cout<<"Resultado tirada: "<<totaldado12[0]<<endl;
    cout<<"------------------------------------"<<endl;
    lanzamiento_dados6 (dado);
    Sleep(1500);
    cout<<"tirada de dados Stock: "<<endl;
        if(orden[0]==0){
            for(int x=0;x<dadosj[0];x++){
            cout<<dado[x]<<" - ";
            }
        }
            else{
                    for(int x=0;x<dadosj[1];x++){
                        cout<<dado[x]<<" - ";
                    }
                }

    cout<<endl<<"elegir opcion: "<<endl;
    cout << "-----------------------" << endl;
    cout << "1 - Elegir dados" << endl;
    cout << "0 - Pasar turno " << endl;
    for(int y=0;y<12;y++){
        dados_elegidos[y]=0;
    }
    cin>>eleccion;
    switch (eleccion){
    case 1:
        elegir( dadosj, dado, totaldado12,dados_elegidos, acumulador, contador_dados );
        break;
    case 0:
        break;
    }
}


void elegir(int dadosj[], int dado [], int totaldado12 [],int dados_elegidos[],int acumulador[], int contador_dados[]){
    int opcion;
    int bandera[12]{};
    for(int x=0;x<13;x++){
        contador_dados[x]=0;
    }
    cout<<"dado objetivo: "<<totaldado12[0]<<endl;
    cout<<endl << "Elegir dado, 1-2-3-4-5-6: " <<endl;
    cin>>opcion;
    while (opcion!= 0) {
        if(acumulador[0]<=totaldado12[0] && opcion!=0 ){
        switch(opcion) {
        case 1:
            if(bandera[0]==0) {
                acumulador[0]+=dado[0];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[0]++;
                contador_dados[0]++;
                dados_elegidos[0]=1;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 2:
            if(bandera[1]==0) {
                acumulador[0]+=dado[1];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[1]++;
                contador_dados[0]++;
                dados_elegidos[1]=2;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 3:
            if(bandera[2]==0) {
                acumulador[0]+=dado[2];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[2]++;
                contador_dados[0]++;
                dados_elegidos[2]=3;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 4:
            if(bandera[3]==0) {
                acumulador[0]+=dado[3];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[3]++;
                contador_dados[0]++;
                dados_elegidos[3]=4;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 5:
            if(bandera[4]==0) {
                acumulador[0]+=dado[4];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[4]++;
                contador_dados[0]++;
                dados_elegidos[4]=5;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 6:
            if(bandera[5]==0) {
                acumulador[0]+=dado[5];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[5]++;
                contador_dados[0]++;
                dados_elegidos[5]=6;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 7:
            if(bandera[6]==0) {
                acumulador[0]+=dado[6];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[6]++;
                contador_dados[0]++;
                dados_elegidos[6]=7;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 8:
            if(bandera[7]==0) {
                acumulador[0]+=dado[7];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[7]++;
                contador_dados[0]++;
                dados_elegidos[7]=8;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 9:
            if(bandera[8]==0) {
                acumulador[0]+=dado[8];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[8]++;
                contador_dados[0]++;
                dados_elegidos[8]=9;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 10:
            if(bandera[9]==0) {
                acumulador[0]+=dado[9];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[9]++;
                contador_dados[0]++;
                dados_elegidos[9]=10;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        case 11:
            if(bandera[10]==0) {
                acumulador[0]+=dado[10];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[10]++;
                contador_dados[0]++;
                dados_elegidos[10]=11;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
        case 12:
            if(bandera[11]==0) {
                acumulador[0]+=dado[11];
                cout<<"resultado de dados elegidos: "<<acumulador[0]<<endl;
                bandera[11]++;
                contador_dados[0]++;
                dados_elegidos[11]=12;
            } else {
                cout<<"dado ya ingresado"<<endl;
            }
            break;
        }
    }
    cin>>opcion;
    }
    cout<<endl<<"----------------------"<<endl;
}

void puntaje (int dadosj[], int totaldado12[],int dados_elegidos[],int acumulador[],int contador_dados [], int puntos [], int orden[]) {
    int x,p=0;

    if(acumulador[0]==totaldado12[0]) {
        cout<<"Los dados elegidos fueron: ";
        for(x=0; x<12; x++) {
            if(dados_elegidos[x]!=0) {
                cout<<dados_elegidos[x]<<" - ";
            }
        }
        cout<<endl<<"-----------------------"<<endl;
        if(orden[0]==0) {
            dadosj[0]=dadosj[0]-contador_dados[0];
            cout<<"Dados enviados al contrincante: "<<contador_dados [0]<<endl;
            dadosj[1]=dadosj[1]+contador_dados[0];
            if(dadosj[0]==0) {
                puntos[0]+=10000;
                p=10000;
                cout<<"puntos generados en la ronda: "<<p<<endl;
                cout<<"puntos acumulados: "<<puntos[0]<<endl;
            } else {
                puntos [0]+=contador_dados[0]*totaldado12[0];
                p=contador_dados[0]*totaldado12[0];
                cout<<"puntos generados en la ronda: "<<p<<endl;
                cout<<"puntos acumulados: "<<puntos[0]<<endl;
            }
        }

        else {
            if(orden[1]==0) {
                dadosj[1]=dadosj [1]-contador_dados[0];
                cout<<"Dados enviados al contrincante: "<<contador_dados[0]<<endl;
                dadosj[0]=dadosj[0]+contador_dados[0];
                if(dadosj[0]==0) {
                    puntos[0]+=10000;
                    cout<<"puntos generados en la ronda: "<<p<<endl;
                    cout<<"puntos acumulados: "<<puntos[1]<<endl;
                } else {
                    puntos [1]+=contador_dados[0]*totaldado12[0];
                    p=contador_dados[0]*totaldado12[0];
                    cout<<"puntos generados en la ronda: "<<p<<endl;
                    cout<<"puntos acumulados: "<<puntos[1]<<endl;
                }
            }
        }
            cout<<endl<<"-----------------------"<<endl;
    }
                else {
                    if(orden [0]==0) {
                        cout<<"Recibe 1 dado del contrincante: "<<endl;
                        dadosj[0]++;
                        dadosj[1]--;
                            if(dadosj[1]==0) {
                            puntos[1]+=10000;
                        }
                    } else {
                        if(orden[1]==0) {
                            cout<<"Recibe 1 dado del contrincante: "<<endl;
                            dadosj[1]++;
                            dadosj[0]--;
                            if(dadosj[0]==0) {
                                puntos[0]+=10000;
                            }
                        }
                    }
                    cout<<endl<<"-----------------------"<<endl;
                }
            }
bool volver ()
{
    int Opcion = 0;
    bool Opcion_Correcta = false;


    while (!Opcion_Correcta)
    {
       system("cls");
        cout << "|_____________________________________________________|" << endl;
        cout << "|      Usted esta a punto de salir                    |"<< endl;
        cout << "|                                                     |"<< endl;
        cout << "|      Esta seguro que desea salir?                   |"<< endl;
        cout << "|                  1. Salir                           |"<< endl;
        cout << "|                  0. Volver                          |"<< endl;
        cout << "|_____________________________________________________|" << endl;
        cout << "|                                                     |" << endl;
        cout << "|      Ingrese la opcion deseada:";
        cin >> Opcion;

        if (Opcion == 1)
        {
            Opcion_Correcta = true;
            return true;

        }
        if (Opcion == 0)
        {
             menu();
            Opcion_Correcta = true;
            return false;
        }
        system("cls");
        cout << " ingreso una opcion no valida, vuelva a intentarlo" << endl;
        cout << "Ingrese una tecla para continuar..." ;
        cin .get();
        cin.ignore();
    }
}

