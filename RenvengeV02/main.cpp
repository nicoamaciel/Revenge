#include <iostream>
#include <ctime>
#include <cstdlib>
#include "string.h"
#include "rlutil.h"


using namespace std;
using namespace rlutil;

#include "funciones.h"
int main()
{
    setColor(BLACK);
    setBackgroundColor(GREY);
    cls();


    string jugador1;
    string mostrarP1[15]={};
    string jugador2;
    string mostrarP2[15]={};
    int const VALOR = 13;
    int dado13[VALOR] = {};


    int opcion;//Opcion de inicio
    int sorteo=0; //Valor de saque jugador1 o jugador2
    int comando1[2]={};//VectorPrincipal suma o resta dados jugador1
    int comando3[2]={};//VectorPrincipal suma o resta dados jugador2
    int acuPuntajes[2]={};//Acumulador de puntajes


    int comando2=0;//Recibe resultado de milpuntos funcion que evalua si se saca o no mil puntos (jugador1)
    int comando4=0;//Recibe resultado de milpuntos funcion que evalua si se saca o no mil puntos (jugador2)

    int ganador=0;
    int mostrarMayor=0;
    string nombreMayor;



    do
    {
    comando1[1]=6; //Reinicio comando Vector jugador 1 muestra o no dados
    comando3[1]=6; //Reinicio comando Vector jugador 2 muestra o no dados
    int ronda1=1;
    int ronda2=1;
    acuPuntajes[1]=0;//Reinicio acumulador de puntajes p1
    acuPuntajes[2]=0;//Reinicio acumulador de puntajes p1

    ///Mostrar menu
    menu();

    cin >> opcion;
        switch(opcion){
        case 1:
            sorteo = arrancarJuego(jugador1,jugador2,dado13,mostrarP1,mostrarP2);
            Sleep(3000);
            cls();

            if(sorteo==1){
                for(int x=0; x<5; x++)
                {
                        cls();
                        if(sorteo==1){
                        cout << endl << "------------------" << endl;
                        cout << endl << "Es el turno del jugadxr " << mostrarP1[15] << " Ronda: " << ronda1;
                        cout << endl << "Puntaje acumulado: " << acuPuntajes[1] << endl;
                        jugando(comando1,acuPuntajes,comando3);
                        Sleep(2000);
                        comando2 = milPuntos(acuPuntajes[1]);
                        ronda1++;
                        sorteo=2;
                        }

                        if(comando2==1){
                        opcion=0;
                        break;
                        }

                        cls();

                        if(sorteo==2){
                        cout << endl << "------------------" << endl;
                        cout << endl << "Es el turno del jugadxr " << mostrarP2[15] << " Ronda: " << ronda2 ;
                        cout << endl << "Puntaje acumulado: " << acuPuntajes[2] << endl;
                        jugando2(comando3,acuPuntajes,comando1);
                        Sleep(2000);
                        comando4 = milPuntos(acuPuntajes[2]);
                        ronda2++;
                        sorteo=1;


                        }

                        if(comando4==1){
                        opcion=0;
                        break;
                        }

                }//Final ciclo ford



            }
            else{
                    for(int x=0; x<5; x++)
                    {
                        cls();
                        if(sorteo==2){
                        cout << endl << "------------------" << endl;
                        cout << endl << "Es el turno del jugadxr " << mostrarP2[15] << " Ronda: " << ronda2 ;
                        cout << endl << "Puntaje acumulado: " << acuPuntajes[2] << endl;
                        jugando2(comando3,acuPuntajes,comando1);
                        Sleep(2000);
                        comando4 = milPuntos(acuPuntajes[2]);
                        ronda2++;
                        sorteo=1;
                        }

                        if(comando4==1){
                        opcion=0;
                        break;
                        }

                        cls();

                        if(sorteo==1){
                        cout << endl << "------------------" << endl;
                        cout << endl << "Es el turno del jugadxr " << mostrarP1[15] << " Ronda: " << ronda1;
                        cout << endl << "Puntaje acumulado: " << acuPuntajes[1] << endl;
                        jugando(comando1,acuPuntajes,comando3);
                        Sleep(2000);
                        comando2 = milPuntos(acuPuntajes[1]);
                        ronda1++;
                        sorteo=2;
                        }

                        if(comando2==1){
                        opcion=0;
                        break;
                        }


                    }//Final ciclo ford

                }


                cout << endl << "---------------------" << endl;
                ganador = ganadorDelJuego(acuPuntajes, mostrarP1, mostrarP2);
                cout << endl << "---------------------" << endl;
                if(ganador==1 && acuPuntajes[1]>mostrarMayor){
                nombreMayor=mostrarP1[15];
                mostrarMayor = acuPuntajes[1];
                }
                if(ganador==2 && acuPuntajes[2]>mostrarMayor){
                nombreMayor=mostrarP2[15];
                mostrarMayor = acuPuntajes[2];
                }

            break;
        case 2:
            cout << "Estadisticas!";
            //Comprarador de maximos

            cout << " Maximo puntaje: " << mostrarMayor << " --- > jugador: " << nombreMayor << endl;



            cout << endl << "--------------" << endl;
            break;
        case 3:
            cls();
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
            cout << endl<<endl<<endl<<endl;
            break;

            }//Fin de switch




    }
    while (opcion!=0);


    return 0;
}


