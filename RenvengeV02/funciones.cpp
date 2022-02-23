#include <iostream>
#include <ctime>
#include "string.h"
#include <cstdlib>
#include "rlutil.h"
#include <windows.h>

using namespace std;
using namespace rlutil;

#include "funciones.h"

void menu()
{
    cout << "REVENGE" << endl;
    cout << "-----------------------" << endl;
    cout << "1 - JUGAR" << endl;
    cout << "2 - ESTADISTICAS" << endl;
    cout << "3 - CREDITOS " << endl;
    cout << "-----------------------" << endl;
    cout << "0 - SALIR" << endl;
    cout << "-----------------------" << endl;
    cout << endl << "INGRESE OPCION: ";
}

int arrancarJuego (string jugador1, string jugador2, int dado13[], string mostrarP1[], string mostrarP2[])
{
    srand(time(NULL));
    //int const VALOR = 13;
    //int dado13[VALOR] = {};
    int ganador_sorteo=0;


    cout << endl << "Ingrese nombre del jugador 1: ";
    cin >> jugador1;
    cout << endl << "Ingrese nombre del jugador 2: ";
    cin >> jugador2;

    mostrarP1[15] = jugador1;
    mostrarP2[15] = jugador2;


        while(ganador_sorteo==0) {

        tirarDado13(dado13);/*funcion para tirar dados*/
        cout << endl << "------------------" << endl;
        cout << "Dado de seis caras jugador1: " << dado13[0] << endl;
        Sleep(2000);
        cout << "Dado de seis caras jugador2: " << dado13[1] << endl;
        Sleep(2000);
        cout << endl << "------------------" << endl;

        if (dado13[0]>dado13[1]) {
            Sleep(2000);
            cout << "Jugador 1 gana el saque!: ";
            cout << jugador1;
            ganador_sorteo++;
            return 1;
            cout << endl << "------------------" << endl;
        } else {
            if (dado13[0]<dado13[1]) {
                Sleep(2000);
                cout << "Jugador 2 gana el saque: ";
                cout << jugador2;
                ganador_sorteo++;
                return 2;
                cout << endl << "------------------" << endl;
            } else {
                if(dado13[0]==dado13[1]) {
                    Sleep(2000);
                    cout<<"se repite el sorteo"<<endl;
                    cout << endl << "------------------" << endl;
                }
            }
        }
    }

}

//Llena dados valores entre 1 y 12
void tirarDado12 (int vec[])
{

    for(int i=0; i<11; i++)
    {
    vec[i]= 1+ rand() % 12;/*Rango entre 1 y 12*/
    }

}
//Llena dados valores entre 1 y 6 ->> agregados para quitar o agregar a base de errores
void tirarDado13 (int vec[])
{

    for(int i=0; i<13; i++)
    {
    vec[i]= 1+ rand() % 6;/*Rango entre 1 y 6*/
    }

}

///jugador 1
void jugando(int comando1[], int acuPuntajes[], int comando3[]){
    srand(time(NULL));

    int const VALOR=12;
    int dado12[VALOR]={}; //DadoUsado para mostrar luego suma valor objetivo
    int valorObjetivo=0;
    int const STOCK=13;
    int dadoStock[STOCK]={}; //DadoUsado para valores de stock

    int opcion; //Opciones de eleccion de dados o salta turno


    //Dados de doce tirada multiple y suma de valor en valor objetivo
    tirarDado12 (dado12);
    cout << "Tirada de dados de 12 caras: " << dado12[0] <<"-"<< dado12[1] <<endl;
    valorObjetivo = dado12[0]+dado12[1];
    cout << "Valor objetivo: " << valorObjetivo <<endl;
    /** Importante comando comando1 deja visualizar o no lo dados**/
    //Tirada de dados de seis con ciclo for
    tirarDado13(dadoStock);
    cout << "Dados de stock: " << endl;
    for (int i=1; i<=comando1[1]; i++){
        cout <<endl;
        cout << i << " dado: " << dadoStock[i];
    }
    if(comando1[1]<1){
        cout << "Sin dados!" << endl;
        acuPuntajes[1] = 1;
    }


    cout <<endl;
    cout<<endl<<" Elegir opcion: "<<endl;
    cout << "-----------------------" << endl;
    cout << "1 - Elegir dados" << endl;
    cout << "0 - Pasar turno " << endl;
    cin >> opcion;




    switch(opcion)
    {
    case 1:
        elegirDados(dadoStock, valorObjetivo, comando1, acuPuntajes, comando3);
        //Elegir dados
        break;
    case 0:
        cout << endl << "Suma un dado!";
        comando1[1]++;
        //Pasar turno
        break;

    }


}
//Funcion principal de jugabilidad
void elegirDados (int dadoStock[], int valorObjetivo, int comando1[], int acuPuntajes[], int comando3[]){
int eleccion;
int yaSeleccionado[13]={};
//ValoresParaPuntaje
int compValorObjetivo=0;
int contadorDados=0;
int mostrarPuntaje=0;


int errores=0;

cout << "Eligir numero de dado o 0 para finalizar: ";
cin >> eleccion;
while(eleccion!=0)
    {
    switch(eleccion)
    {
    case 1:
        if(yaSeleccionado[0]==0){
        compValorObjetivo+=dadoStock[1];
        yaSeleccionado[0]++;
        contadorDados+=1;
        comando1[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }
        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }

        break;
    case 2:
        if(yaSeleccionado[1]==0){
        compValorObjetivo+=dadoStock[2];
        yaSeleccionado[1]++;
        contadorDados+=1;
        comando1[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }
        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }

        break;
    case 3:
        if(yaSeleccionado[2]==0){
        compValorObjetivo+=dadoStock[3];
        yaSeleccionado[2]++;
        contadorDados+=1;
        comando1[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }
        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }

        break;
    case 4:
        if(yaSeleccionado[3]==0){
        compValorObjetivo+=dadoStock[4];
        yaSeleccionado[3]++;
        contadorDados+=1;
        comando1[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }
        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }

        break;
    case 5:
        if(yaSeleccionado[4]==0){
        compValorObjetivo+=dadoStock[5];
        yaSeleccionado[4]++;
        contadorDados+=1;
        comando1[1]--;
        }

        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }

        break;
    case 6:
        if(yaSeleccionado[5]==0){
        compValorObjetivo+=dadoStock[6];
        yaSeleccionado[5]++;
        contadorDados+=1;
        comando1[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }


        break;
    case 7:
        if(yaSeleccionado[6]==0){
        compValorObjetivo+=dadoStock[7];
        yaSeleccionado[6]++;
        contadorDados+=1;
        comando1[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }


        break;
    case 8:
        if(yaSeleccionado[7]==0){
        compValorObjetivo+=dadoStock[8];
        yaSeleccionado[7]++;
        contadorDados+=1;
        comando1[1]--;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }


        else{
            cout << "Dado ya seleccionado" << endl;
        }
        break;
    case 9:
        if(yaSeleccionado[8]==0){
        compValorObjetivo+=dadoStock[9];
        yaSeleccionado[8]++;
        contadorDados+=1;
        comando1[1]--;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }

        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }

        break;
    case 10:
        if(yaSeleccionado[9]==0){
        compValorObjetivo+=dadoStock[10];
        yaSeleccionado[9]++;
        contadorDados+=1;
        comando1[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }


        break;
    case 11:
        if(yaSeleccionado[10]==0){
        compValorObjetivo+=dadoStock[11];
        yaSeleccionado[10]++;
        contadorDados+=1;
        comando1[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }

        break;
    case 12:
        if(yaSeleccionado[11]==0){
        compValorObjetivo+=dadoStock[12];
        yaSeleccionado[11]++;
        contadorDados+=1;
        comando1[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[1]+= mostrarPuntaje;
        break;
        }

        break;


    }
    cout << "Suma acumulada para valor objetivo: " << compValorObjetivo << endl;
        if(compValorObjetivo!=valorObjetivo){
            cout << "Eligir numero de dado o 0 para finalizar: ";
            cin >> eleccion;
        }
        else{
            break;
        }

    }

    //Configuracion mil puntos
    if(comando1[1]==0 && compValorObjetivo==valorObjetivo){
      mostrarPuntaje=10000;
      cout << endl << "Tirada magica! Suma 10000 puntos - Ganador!" << endl;
      cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
      acuPuntajes[1] = milPuntos(mostrarPuntaje);
    }
    else{
        if(compValorObjetivo==valorObjetivo){
        cout << "Tirada exitos! " << endl;
        comando3[1] += contadorDados;
        cout << "Dados enviados al rival: " << contadorDados << endl;;

        }
        else{
            cout << "Error suma un dado" << endl;
           errores = 7 - comando1[1];
           comando1[1]+= errores;
           comando1[1]++;
            }
        }
}
///jugador 2
void jugando2(int comando3[], int acuPuntajes[], int comando1[]){

 srand(time(NULL));

    int const VALOR=12;
    int dado12[VALOR]={}; //DadoUsado para mostrar luego suma valor objetivo
    int valorObjetivo=0;
    int const STOCK=13;
    int dadoStock[STOCK]={}; //DadoUsado para valores de stock

    int opcion; //Opciones de eleccion de dados o salta turno


    //Dados de doce tirada multiple y suma de valor en valor objetivo
    tirarDado12 (dado12);
    cout << "Tirada de dados de 12 caras: " << dado12[0] <<"-"<< dado12[1] <<endl;
    valorObjetivo = dado12[0]+dado12[1];
    cout << "Valor objetivo: " << valorObjetivo <<endl;

    //Tirada de dados de seis con ciclo for
    tirarDado13(dadoStock);
    cout << "Dados de stock: " << endl;
    for (int i=1; i<=comando3[1]; i++){
        cout <<endl;
        cout << i << " dado: " << dadoStock[i];
    }
    if(comando3[1]<1){
        cout << "Sin dados!" << endl;
        acuPuntajes[2] = 1;
    }


    cout <<endl;
    cout<<endl<<" Elegir opcion: "<<endl;
    cout << "-----------------------" << endl;
    cout << "1 - Elegir dados" << endl;
    cout << "0 - Pasar turno " << endl;
    cin >> opcion;



    switch(opcion)
    {
    case 1:
        elegirDados2 (dadoStock,valorObjetivo,comando3,acuPuntajes,comando1);
        break;
    case 0:
        cout << endl << "Suma un dado!";
        comando3[1]++;
        //Pasar turno
        break;

    }



}

void elegirDados2 (int dadoStock[], int valorObjetivo, int comando3[], int acuPuntajes[], int comando1[])
{
int eleccion;
int yaSeleccionado[13]={};
//ValoresParaPuntaje
int compValorObjetivo=0;
int contadorDados=0;
int mostrarPuntaje=0;


int errores=0;

cout << "Eligir numero de dado o 0 para finalizar: ";
cin >> eleccion;
while(eleccion!=0)
    {
    switch(eleccion)
    {
    case 1:
        if(yaSeleccionado[0]==0){
        compValorObjetivo+=dadoStock[1];
        yaSeleccionado[0]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;

        }
        break;
    case 2:
        if(yaSeleccionado[1]==0){
        compValorObjetivo+=dadoStock[2];
        yaSeleccionado[1]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }

        break;
    case 3:
        if(yaSeleccionado[2]==0){
        compValorObjetivo+=dadoStock[3];
        yaSeleccionado[2]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;

        }

        break;
    case 4:
        if(yaSeleccionado[3]==0){
        compValorObjetivo+=dadoStock[4];
        yaSeleccionado[3]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }


        break;
    case 5:
        if(yaSeleccionado[4]==0){
        compValorObjetivo+=dadoStock[5];
        yaSeleccionado[4]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }


        break;
    case 6:
        if(yaSeleccionado[5]==0){
        compValorObjetivo+=dadoStock[6];
        yaSeleccionado[5]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }

        break;
    case 7:
        if(yaSeleccionado[6]==0){
        compValorObjetivo+=dadoStock[7];
        yaSeleccionado[6]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }

        break;
    case 8:
        if(yaSeleccionado[7]==0){
        compValorObjetivo+=dadoStock[8];
        yaSeleccionado[7]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }

        break;
    case 9:
        if(yaSeleccionado[8]==0){
        compValorObjetivo+=dadoStock[9];
        yaSeleccionado[8]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }

        break;
    case 10:
        if(yaSeleccionado[9]==0){
        compValorObjetivo+=dadoStock[10];
        yaSeleccionado[9]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }

        break;

    case 11:
        if(yaSeleccionado[10]==0){
        compValorObjetivo+=dadoStock[11];
        yaSeleccionado[10]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }

        break;

    case 12:
        if(yaSeleccionado[11]==0){
        compValorObjetivo+=dadoStock[12];
        yaSeleccionado[11]++;
        contadorDados+=1;
        comando3[1]--;
        }
        else{
            cout << "Dado ya seleccionado" << endl;
        }

        if(compValorObjetivo==valorObjetivo){
        mostrarPuntaje = puntaje (compValorObjetivo, contadorDados);
        cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
        acuPuntajes[2]+= mostrarPuntaje;
        break;
        }

        break;


        }
        cout << "Acumulado para valor objetivo: " << compValorObjetivo << endl;
        if(compValorObjetivo!=valorObjetivo){
        cout << "Eligir numero de dado o 0 para finalizar: ";
        cin >> eleccion;
        }
        else{
            break;
        }

    }


    //Configuracion mil puntos
    if(comando3[1]==0 && compValorObjetivo==valorObjetivo){
      mostrarPuntaje=10000;
      cout << endl << "Tirada magica! Suma 10000 puntos - Ganador!" << endl;
      cout << "Puntos obtenidos: " <<  mostrarPuntaje << endl;
      acuPuntajes[2] = milPuntos(mostrarPuntaje);
    }
    else{
        if(compValorObjetivo==valorObjetivo){
        cout << "Tirada exitosa!" << endl;
        comando1[1] += contadorDados;
        cout << "Dados enviados al rival: " << contadorDados << endl;;
        }
        else{
            cout << "Error suma un dado" << endl;
           errores = 7 - comando3[1];
           comando3[1]+= errores;
           comando3[1]++;
            }
        }
}


//Acumula y retorna puntajes
int puntaje (int compValorObjetvio, int contadorDados){
int puntos=0;

puntos += compValorObjetvio*contadorDados;

return puntos;

}
//Verifica el ganador que saque 10000 puntos
int milPuntos (int mostrarPuntaje){
    if(mostrarPuntaje==10000){
    return 1;
    }
}


int ganadorDelJuego(int acuPuntajes[], string mostrarP1[], string mostrarP2[]){


    if(acuPuntajes[1]>acuPuntajes[2]){
    cout << endl << "Ganador " << mostrarP1[15] << " Puntos: " << acuPuntajes[1] << endl;
    return 1;

    }
    else{
        cout << endl << "Ganador "<< mostrarP2[15] << " Puntos: " << acuPuntajes[2] << endl;
    return 2;
    }

}














/**/


