#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


 void menu();
 int arrancarJuego (string jugador1, string jugador2, int dado13[], string mostrarP1[], string mostrarP2[]);
 void tirarDado13 (int vec[]);
 void tirarDado12 (int vec[]);
 void jugando(int comando1[], int acuPuntajes[], int comando3[]);
 void jugando2(int comando3[], int acuPuntajes[], int comando1[]);
 void elegirDados (int dadoStock[], int valorObjetivo, int comando1[], int acuPuntajes[], int comando3[]);
 void elegirDados2(int dadoStock[], int valorObjetivo, int comando3[], int acuPuntajes[], int comando1[]);
 int puntaje (int compValorObjetvio, int contadorDados);
 int milPuntos (int mostrarPuntaje);
 int ganadorDelJuego(int acuPuntajes[], string mostrarP1[], string mostrarP2[]);



#endif // FUNCIONES_H_INCLUDED
