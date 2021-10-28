



#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(){
srand(time(NULL));

int const VALOR=13;
int dado[VALOR]={};


char jugador1[3];
char jugador2[3];

int arranque;


int opcion;
    do
    {
        /*setColor(BLACK);
        setBackgroundColor(GREY); - rlutil*/

        cout << "REVENGE" << endl;
        cout << "-----------------------" << endl;
        cout << "1 - JUGAR" << endl;
        cout << "2 - ESTADISTICAS " << endl;
        cout << "3 - CREDITOS " << endl;

        cout << "-----------------------" << endl;
        cout << "0 - SALIR" << endl;
        cout << "-----------------------" << endl;
        cout << endl << "INGRESE OPCION: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "-----------------------" << endl;
            cout << "Ingrese jugador 1 solo tres caracteres: ";
            cin >> jugador1;
            cout << "Ingrese jugador 2 solo tres caracteres: ";
            cin >> jugador2;


            for(int j=0; j<12; j++){
            dado[j]+=1+rand()%(13-1);/*Rango entre 1 y 12*/
            }

            cout << endl << "------------------" << endl;
            cout << "PRESIONE 1 PARA INICIAR LA PARTIDA: ";
            cin >> arranque;


            switch(arranque){
            case 1:
                cout << "Doce caras jugador1: " << dado[0] << endl;
                cout << "Doce caras jugador2: " << dado[1] << endl;
                cout << endl << "------------------" << endl;

                if (dado[0]>dado[1])
                {
                cout << "Jugador 1 gana el saque!: ";
                    for(int t=0; t<4; t++){
                        cout << jugador1[t];
                    }
                    cout << endl << "------------------" << endl;
                }
                else
                {
                    cout << "Jugador 2 gana el saque: ";
                        for(int y=0; y<4; y++){
                        cout << jugador2[y];

                    }
                    cout << endl << "------------------" << endl;
                }

            break;

            }


        break;
        case 2:
        cout << "Estadisticas: ";
        break;
        case 3:
        cout << "Creditos: ";
        break;
        }
    break;
    }
    while(opcion!=0);







return 0;
}



