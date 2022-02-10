#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED



#endif // FUNCIONES_H_INCLUDED

void menu ();
void jugar(char sorteo1[], char sorteo2[]);
void lanzamiento_dados12 (int dado []);
void lanzamiento_dados6 (int dado []);
void comienzo(int dado[]);
void ronda (int dadosj[], int orden [],int acumulador[], int totaldado12 [], int dados_elegidos [],int contador_dados[]);
void elegir(int dadosj[],int dado[],int totaldado12 [], int dados_elegidos[],int acumulador[],int contador_dados[]);
void puntaje (int dadosj[], int totaldado12 [],int dados_elegidos[],int acumulador[],int contador_dados [],int puntos [],int orden[]);
bool volver();
